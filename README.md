# Egzamino-isankstine-uzduotis
### Projekto aprašymas
Programa „TextAnalyser“ automatiškai analizuoja teksto failus:
- Skaičiuoja žodžių dažnį.
- Išrenka nuorodas (URL) ir domenus.
- Sudaro cross-reference lentelę, kurioje nurodomos žodžių pozicijos tekste.
Tai naudinga teksto analizei, informacijos surinkimui ir statistikai.
---
### Diegimo instrukcija 
1. Atsisiųskite visus failus.
2. Nukopijuokite projekto direktoriją į savo kompiuterį bei sukurkite build direktoriją <br>
    ```
   cd folder-direktorija
   mkdir build
   cd build
   ```
3. Su Cmake generuojame reikalingus projekto failus <br>
   ```
   cmake ..
   ```
4. Sukompiliuojame ir sukuriame failus <br>
   ```
   make
   ```
5. Paleidziame programą:
    ```
   ./TextAnalyser
   ```
---
### Programos naudojimas
* Jei norite prieš paleidžiant programą, galite pakeisti teksto failą, ` "tekstas.txt" ` jusu norimu tekstu. Jei ne, programa jeu turi maždaug 5000 žodžių apimties tekstą, galite naudoti jį. 
* Programa jau automatiskai apskaičiuos žodžių dažnį tekste, todėl jums reikia pasirinkti ar papildomai norėsite išrinkti nuorodas, arba sudaryti cross-reference tipo lentelę.
* Jei nepavyks atidaryti failų - programa jums praneš, kitu atveju matysite tekstą `Programa baige darba.`
* Rezultatų failai bus sukuriami `build` aplanke.
---
### Reikalavimai
- C++17 palaikymas
- CMake ≥ 3.10
- GNU Make arba kitą build sistemą
- Interneto prieiga (jei norima atnaujinti tlds failą)
---
### Programa
#### URL nuorodos 
Išrenkant nuorodas tekste, programa naudoja puslapyje `https://data.iana.org/TLD/tlds-alpha-by-domain.txt` esančius domenus; (Paskutinį kartą atnaujintas 2025 Gruodžio 16 07:07:02 UTC)
#### Rezultatų failai 
Visi rezultatai išvedami į skirtingus failus:
* `zodziai.txt` - visi žodžiai kurie kartojosi daugiau negu 1 kartą, ir jų dažnis
* `urls.txt` - visos rastos nuorodos
* `crossref.txt` - cross-reference tipo lentelė, matome žodį ir kuriose eilutėse jis buvo pastebėtas
#### Skyrybos ženklai 
Yra sukurta funkcija, kuri išrenkant žodžius panaikina skirybos ženklus, kad jie nebūtų išrinkti kaip atskiri žodžiai, ar kaip žodžio dalis.
