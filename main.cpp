#include "mylib.h"

int main() {
    int a, b;
    cout << "Programa automatiskai suskaicius visus zodzius ir ju dazni." << endl;
    cout << "Ar norite papildomai?: "<< endl;
    cout << "Isrinkti visas nuorodas? (1) - Taip, (2) - Ne: ";
    cin >> a;
    cout << "S1udaryti cross-reference tipo lentele? (1) - Taip, (2) - Ne: ";
    cin >> b;

    if (a == 1) {
        auto tlds = loadTLDs("tlds-alpha-by-domain.txt"); // IANA TLD sąrašas
        findUrls("tekstas.txt", "urls.txt", tlds);
    }

    if (b == 1) {
        createCrossReference("tekstas.txt", "crossref.txt");
        cout << " Failas 'crossref.txt' sukurtas" << endl;
    }
    countWords("tekstas.txt", "zodziai.txt");
    
    cout << "Programa baige darba.\n";
    return 0;
}
