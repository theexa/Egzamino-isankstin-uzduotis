# Egzamino-isankstine-uzduotis
### Diegimo instrukcija 
1. Atsisiųskite visus failus.
2. Nukopijuokite projekto direktoriją į savo kompiuterį bei sukurkite build direktoriją <br>
    ```
   cd folder direktorija
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

