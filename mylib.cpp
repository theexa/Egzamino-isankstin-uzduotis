#include "mylib.h"

std::unordered_set<std::string> loadTLDs(const std::string& filename) {
    std::unordered_set<std::string> tlds;
    std::ifstream in(filename);
    if (!in) {
        std::cerr << "Nepavyko atidaryti TLD failo: " << filename << "\n";
        return tlds;
    }

    std::string tld;
    while (in >> tld) {
        std::transform(tld.begin(), tld.end(), tld.begin(),
                       [](unsigned char c){ return std::tolower(c); });
        tlds.insert(tld);
    }

    return tlds;
}

bool looksLikeDomain(const std::string& word, const std::unordered_set<std::string>& tlds) {
    size_t pos = word.rfind('.');
    if (pos == std::string::npos) return false;
    std::string tld = word.substr(pos + 1);
    std::transform(tld.begin(), tld.end(), tld.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return tlds.count(tld) > 0;
}

void findUrls(const std::string& inputFile, const std::string& outputFile,
              const std::unordered_set<std::string>& tlds) {
    std::ifstream in(inputFile);
    std::ofstream out(outputFile);

    if (!in || !out) {
        std::cerr << "Nepavyko atidaryti failų.\n";
        return;
    }

    std::string line;
    while (getline(in, line)) {
        std::stringstream ss(line);
        std::string token;
        while (ss >> token) {
            // Pašalinti skyrybos ženklus iš galo
            while (!token.empty() && ispunct((unsigned char)token.back())) token.pop_back();

            // Tikrinti: URL formos
            if (token.find("http://") == 0 || token.find("https://") == 0 || token.find("www.") == 0) {
                out << token << "\n";
            } else if (looksLikeDomain(token, tlds)) {
                out << token << "\n";
            }
        }
    }

    std::cout << "URL failas sukurtas: " << outputFile << "\n";
}

string cleanWord(string word) {
    // Remove ASCII punctuation
    word.erase(std::remove_if(word.begin(), word.end(),
        [](unsigned char c){ return std::ispunct(c); }), word.end());

    // Remove common Unicode quotes
    std::vector<string> quotes = {"'", "‘", "’", "‚", "‛", "\"", "“", "”"};
    for (auto& q : quotes) {
        size_t pos;
        while ((pos = word.find(q)) != string::npos)
            word.erase(pos, q.length());
    }

    // Convert to lowercase
    std::transform(word.begin(), word.end(), word.begin(),
                   [](unsigned char c){ return std::tolower(c); });

    return word;
}

void countWords(const string& inputFile, const string& outputFile) {
    ifstream in(inputFile);
    ofstream out(outputFile);
    if (!in) { cout << "Nepavyko atidaryti " << inputFile << "\n"; return; }
    if (!out) { cout << "Nepavyko sukurti " << outputFile << "\n"; return; }

    map<string, int> wordCount;
    string line;
    while (getline(in, line)) {
        line = std::regex_replace(line, std::regex(R"(https?://\S+|www\.\S+)"), ""); // remove URLs

        std::stringstream ss(line);
        string word;
        while (ss >> word) {
            word = cleanWord(word);
            if (!word.empty())
                wordCount[word]++;
        }
    }

    for (const auto& [w, count] : wordCount) {
        if (count > 1)
            out << w << " : " << count << "\n";
    }

    in.close();
    out.close();
}


//cross-reference
void createCrossReference(const string& inputFile, const string& outputFile) {
    ifstream in(inputFile);
    ofstream out(outputFile);
    if (!in) { cout << "Nepavyko atidaryti " << inputFile << "\n"; return; }
    if (!out) { cout << "Nepavyko sukurti " << outputFile << "\n"; return; }

    map<string, int> wordCount;
    map<string, std::set<int>> crossRef;
    string line;
    int lineNumber = 0;

    while (getline(in, line)) {
        lineNumber++;
        std::stringstream ss(line);
        string word;

        while (ss >> word) {
            // Skip URLs
            if (word.find("http://") == 0 || word.find("https://") == 0 || word.find("www.") == 0)
                continue;

            word = cleanWord(word);
            if (word.empty()) continue;

            wordCount[word]++;
            crossRef[word].insert(lineNumber);
        }
    }

    for (const auto& [word, lines] : crossRef) {
        if (wordCount[word] > 1) {
            out << word << " -> ";
            for (int ln : lines) out << ln << " ";
            out << "\n";
        }
    }

    in.close();
    out.close();
}
