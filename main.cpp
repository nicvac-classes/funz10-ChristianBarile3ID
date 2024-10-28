#include <iostream>
#include <ctime>

using namespace std;

int entraPersone(int numPersone, int capacitaMax, int numPersoneEntranti) {
    int postiRimasti;

    postiRimasti = capacitaMax - numPersone;
    if (postiRimasti >= numPersoneEntranti) {
        numPersone = numPersoneEntranti;
    } else {
        numPersone = postiRimasti;
        cout << "Le persone che vogliono entrare sono troppe, ne sono entrate " << numPersone << endl;
    }
    
    return numPersone;
}

int esciPersone(int numPersone, int numPersoneUscenti) {
    if (numPersoneUscenti > numPersone) {
        numPersoneUscenti = numPersone;
        cout << "In palestra non ci sono così tante persone, ne usciranno " << numPersoneUscenti << endl;
        numPersone = 0;
    } else {
        numPersone = numPersone - numPersoneUscenti;
        cout << "Usciranno " << numPersoneUscenti << " persone" << endl;
    }
    
    return numPersone;
}

string leggiComando() {
    string op;

    do {
        cout << "Inserisci l'azione da compiere" << endl;
        cin >> op;
    } while (op != "P" && op != "E" && op != "U" && op != "A" && op != "R" && op != "X");
    
    return op;
}

int pulisciPalestra(int livelloPuliziaPerc) {
    int puliziaPalestra;

    cout << "Inserisci di quanto aumenta costantemente la pulizia della palestra: " << endl;
    cin >> puliziaPalestra;
    livelloPuliziaPerc = livelloPuliziaPerc + puliziaPalestra;
    
    return livelloPuliziaPerc;
}

int resetPalestra(int dato) {
    int x;

    x = 0;
    
    return x;
}

int usaAttrezzi(int livelloPuliziaPerc) {
    int diminuzione;

    diminuzione = rand() % 96 + 5;
    livelloPuliziaPerc = livelloPuliziaPerc - diminuzione;
    if (livelloPuliziaPerc < 0) {
        livelloPuliziaPerc = 0;
    }
    
    return livelloPuliziaPerc;
}

int main() {
    srand(time(0));   
    string azione;
    int numPersone, puliziaPalestra, capacitaMassima, livelloPuliziaPerc, capacitaMax, numPersoneEntranti, numPersoneUscenti;
    cout << "Quante persone ci sono in palestra?" << endl;
    cin >> numPersone;
    livelloPuliziaPerc = rand() % 101;
    cout << "Qual è la capacità massima della palestra?" << endl;
    cin >> capacitaMax;
    do {
        cout << "In palestra ci sono " << numPersone << " persone" << endl;
        cout << "Il livello di pulizia è: " << livelloPuliziaPerc << "%" << endl;
        cout << "La capacità massima della palestra è di " << capacitaMax << " persone" << endl;
        azione = leggiComando();
        if (azione == "P") {
            livelloPuliziaPerc = pulisciPalestra(livelloPuliziaPerc);
        }
        if (azione == "E") {
            do {
                cout << "Quante persone entrano in palestra?" << endl;
                cin >> numPersoneEntranti;
            } while (numPersoneEntranti < 0);
            numPersone = numPersone + entraPersone(numPersone, capacitaMax, numPersoneEntranti);
        }
        if (azione == "U") {
            do {
                cout << "Quante persone usciranno dalla palestra?" << endl;
                cin >> numPersoneUscenti;
            } while (numPersoneUscenti < 0);
            numPersone = esciPersone(numPersone, numPersoneUscenti);
        }
        if (azione == "A") {
            livelloPuliziaPerc = usaAttrezzi(livelloPuliziaPerc);
        }
        if (azione == "R") {
            cout << "Inserisci la nuova capacità massima" << endl;
            cin >> capacitaMax;
            livelloPuliziaPerc = rand() % 101;
            numPersone = resetPalestra(numPersone);
        }
    } while (azione != "X");
    return 0;
}




