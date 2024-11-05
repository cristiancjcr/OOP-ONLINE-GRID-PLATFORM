
// TEST TEST TEST TEST TEST

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Intrebare {
    
private:
    string textIntrebare;
    vector<string> optiuni;
    int raspunsCorect; // indexul răspunsului corect în vectorul de opțiuni

public:

    // constructor pentru inițializarea întrebării cu textul, opțiunile și răspunsul corect
    Intrebare(const string& text, const vector<string>& optiuni, int corect) 
        : textIntrebare(text), optiuni(optiuni), raspunsCorect(corect) {}

    // metodă pentru afișarea întrebării și a opțiunilor
    void afiseazaIntrebare() const {
            cout << textIntrebare << endl;
        for (size_t i = 0; i < optiuni.size(); ++i) {
                cout << i + 1 << ". " << optiuni[i] << endl;
        }
    }

    // metodă pentru verificarea răspunsului utilizatorului
    bool verificaRaspuns(int raspuns) const {
        return raspuns - 1 == raspunsCorect; // scădem 1 deoarece opțiunile încep de la 1 pentru utilizator
    }
};


class Test {
    
private:
    vector<Intrebare> intrebari;
    int scor; // pentru a ține scorul final

public:
    Test() : scor(0) {} // constructor ce inițializează scorul cu 0

    // metodă pentru adăugarea unei noi întrebări în test
    void adaugaIntrebare(const Intrebare& intrebare) {
        intrebari.push_back(intrebare);
    }

    // metodă pentru a începe testul și a calcula scorul
    void incepeTest() {
        for (const auto& intrebare : intrebari) {
            intrebare.afiseazaIntrebare();

            int raspuns;
            cout << "Raspuns: ";
            cin >> raspuns;

            if (intrebare.verificaRaspuns(raspuns)) {
                cout << "Corect!\n";
                scor++;
            } else {
                cout << "Gresit!\n";
            }
            cout << endl;
        }

        cout << "Gata test-ul ! Scorul tau este : " << scor << "/" << intrebari.size() << endl;
    }
};


int main() {
    // inițializăm testul
    Test test;

    // adăugăm câteva întrebări de exemplu
    test.adaugaIntrebare(Intrebare("Care este capitala Frantei?", {"Berlin", "Madrid", "Paris", "Roma"}, 2));
    test.adaugaIntrebare(Intrebare("Cat face 2 + 2?", {"3", "4", "5", "6"}, 1));
    test.adaugaIntrebare(Intrebare("Care este culoarea cerului?", {"Verde", "Albastru", "Rosu", "Galben"}, 1));
    test.adaugaIntrebare(Intrebare("Cate campionate mondiale are Romania ?", {"0", "2", "5", "8"}, 0));
    test.incepeTest();

    return 0;
}

// TEST TEST TEST TEST TEST
