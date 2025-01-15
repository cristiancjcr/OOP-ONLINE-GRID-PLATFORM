# OOP-Online-Grid-Platform

### Cerința problemei :
> **Platformă de grile online** - gestionarea întrebărilor și evaluarea răspunsurilor (problema numărul 23) .

## Descrierea metodei și modului de rezolvare a problemei
### 1. Analiza problemei
Platforma noastră de grile trebuie să permită crearea și gestionarea unui set de întrebări de tip grilă, unde fiecare întrebare are mai multe variante de răspuns.
Utilizatorii trebuie să poată răspunde la întrebări, iar platforma trebuie să evalueze răspunsurile și să calculeze un scor final.

De asemenea, o să folosim un model de programare orientată pe obiecte, pentru a face codul mai modular, reutilizabil și ușor de întreținut.

### 2. Concepte OOP aplicate :
**Încapsularea** : Vom folosi clase pentru a încapsula întrebările, testele și, opțional, utilizatorii. Fiecare clasă va avea variabile private, iar accesul la ele se va face prin metode publice (getters, setters și alte metode).

**Abstracția** : Prin intermediul claselor, abstractizăm complexitatea unei întrebări sau a unui test, ascunzând detaliile de implementare în spatele unor metode clare și simple de utilizat. Astfel, utilizatorul final al codului (fie un alt dezvoltator, fie chiar utilizatorul uman) nu trebuie să cunoască cum funcționează exact verificarea răspunsurilor.

**Polimorfismul** : În cazul în care vom dori să extindem proiectul, putem folosi polimorfismul pentru a adăuga mai multe tipuri de teste sau întrebări fără a modifica structura existentă. De exemplu, întrebări cu un singur răspuns corect sau mai multe răspunsuri corecte.

**Moștenirea** : Dacă vom avea mai multe tipuri de teste sau întrebări, putem crea clase derivate dintr-o clasă de bază, moștenind proprietăți comune și adăugând funcționalități specifice.

### 3. Modularizarea și separarea responsabilităților
Platforma noastră va fi împărțită în module logice, fiecare cu responsabilități bine definite :

**Modulul de întrebări** : Gestionarea fiecărei întrebări individuale, incluzând textul întrebării, opțiunile de răspuns și răspunsul corect.

**Modulul de test** : Gestionarea unui set de întrebări și orchestrarea întregului proces de testare, de la afisarea întrebărilor la evaluarea răspunsurilor și calcularea scorului.

**Modulul de utilizator (opțional)**  : Gestionarea detaliilor utilizatorilor și salvarea scorurilor pentru a oferi un feedback personalizat.

### 4. Fluxul de lucru al programului :
Programul va urma un flux clar și ușor de înțeles :

**Pasul 1** : Inițializarea unui set de întrebări (în cod sau citite dintr-un fișier)

**Pasul 2** : Afișarea fiecărei întrebări utilizatorului, împreună cu opțiunile de răspuns.

**Pasul 3** : Citirea răspunsului utilizatorului și verificarea dacă este corect.

**Pasul 4** : Calcularea și afișarea scorului final, oferind utilizatorului un feedback cu privire la performanța sa.

### 5. Ușurința extinderii
Un avantaj al programării orientate pe obiecte este ușurința cu care putem extinde programul : 

Dacă dorim să adăugăm întrebări de diferite tipuri (de exemplu, întrebări cu răspunsuri multiple sau întrebări deschise), putem crea noi clase care extind clasa de bază Intrebare.

Dacă vrem să extindem funcționalitățile pentru utilizatori (de exemplu, salvarea scorurilor pe termen lung), putem adăuga o bază de date simplă sau fișiere pentru persistența datelor.

## Idei principale pentru dezvoltarea finală a programului :

### 1. Adăugarea de nivele de dificultate pentru întrebări
Întrebările ar putea fi împărțite în categorii de dificultate ***(ușor, mediu, greu)***, iar utilizatorul poate selecta nivelul dorit la începutul testului.
> **Beneficii** : Testul devine mai flexibil, permițând utilizatorului să aleagă întrebările în funcție de nivelul său de cunoștințe.

### 2. Cronometrarea răspunsurilor - NEIMPLEMENTAT / ÎNCĂ SE IMPLEMEANTEAZĂ
Adăugarea unui cronometru care să limiteze timpul pentru a răspunde la întrebări. Dacă timpul expiră, utilizatorul nu va mai putea răspunde la întrebare și se va trece la următoarea.
> **Beneficii** : Adaugă un element de presiune și testează rapiditatea utilizatorului, crescând nivelul de dificultate.

### 3. Randomizarea ordinii întrebărilor și răspunsurilor
Pentru a face testul mai imprevizibil, întrebările și răspunsurile pot fi afișate într-o ordine aleatorie.
> **Beneficii** : Testul devine mai dinamic și previne posibilitatea de memorare mecanică a ordinii întrebărilor.

### 4. Salvarea scorurilor și evaluărilor într-un fișier
Scorurile și evaluările fiecărui utilizator pot fi salvate într-un fișier pentru a păstra un istoric al performanțelor.
> **Beneficii** : Utilizatorii pot avea un istoric al testelor și al scorurilor, fiind util pentru evaluarea progresului în timp.

### 5. Crearea unui meniu interactiv în command prompt
În loc să rulezi direct testul, poți adăuga un meniu care să permită utilizatorului să aleagă diferite opțiuni: începerea unui test, vizualizarea scorurilor, ieșirea din program etc.
> **Beneficii** : Oferă o interfață mai prietenoasă și clară pentru utilizatori.

### 6. Crearea de domenii
Domeniile permit organizarea întrebărilor în funcție de tematică, utilizatorul alegând unul la începutul testului.
> **Beneficii** : Oferă utilizatorilor control asupra testului, permițându-le să aleagă doar întrebări dintr-un domeniu de interes.

### 7. Selectarea unui număr de întrebări
Platforma va selecta automat numărul ales de întrebări din domeniul specificat.
> **Beneficii** : Flexibilitatea pentru utilizatori de a alege între teste scurte sau lungi, adaptându-se timpului și interesului lor.

### 8. Întrebări cu răspunsuri multiple - NEIMPLEMENTAT / ÎNCĂ SE IMPLEMEANTEAZĂ
Utilizatorul poate selecta mai multe opțiuni pentru a răspunde, iar verificarea corectitudinii va ține cont de toate răspunsurile corecte.
> **Beneficii** : Îmbunătățește testele, oferindu-le un nivel mai complex și mai realist de evaluare.

### 9. Verificarea răspunsurilor dintr-un test finalizat (din fișier) - NEIMPLEMENTAT / ÎNCĂ SE IMPLEMEANTEAZĂ
Platforma salvează răspunsurile și scorul într-un fișier; ulterior, utilizatorul poate vedea întrebările și răspunsurile corecte, alături de propriile răspunsuri.
> **Beneficii** : Utilizatorii pot învăța din greșelile făcute, având acces la un istoric detaliat al testului și al corectitudinii răspunsurilor.

## Contribuții
Proiect realizat de **Cristian Florin Cojocaru** (student **CR.2** - **UCV / FACE**). Contribuțiile sunt binevenite ! Dacă aveți sugestii de îmbunătățire a codului sau a documentației, vă rugăm să trimiteți un pull request.

## Licență
Acest proiect este licențiat sub [MIT License](LICENSE).
