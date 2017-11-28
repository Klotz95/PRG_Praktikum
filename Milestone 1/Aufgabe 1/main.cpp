#include <QCoreApplication>
#include <iostream>
#include <stdlib.h>

using namespace std;

/**
 * AUFGABE 1E
 * Diese Methode printet das dynamische Array A2
 * Wird in dem Konsolenprogramm verwendet.
 */
void printMatrixA2(int *A2){
    for(int i = 0; i < 30*30; ++i){
        if(i % 30 == 0){//Zeile ist 30 lang
            cout << endl;// Nach jeder Zeile einen Zeilenumbruch
        }
            // Printen der jeweiligen Zelle im Array
            // Damit nicht alles nebeneinander steht (leerer String, Platzhalter)
            cout << A2[i] << " ";
    }
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    /**
     * Aufgabe 1B
     */
    //Statisches Array mit 30x30 Einträgen
    //2-dimensional
    int A1[30][30];
    //Dynamisches Array mit 900 Einträgen
    //1-dimensional
    int *A2 = new int[30*30];
    //Zufallsgenerator initialisieren
    srand(time(NULL));
    //Array A1 wird mit 2 for-schleifen durchlaufen
    //und es werden Zufallszahlen gesetzt
    for(int i = 0; i < 30; ++i){
        for(int j = 0; j < 30; j++){
            //Zufallszahlen von 1 bis 9 (zwischen 0 und 10) werden den Feldern zugewiesen
            //Modulo 9 bedeutet, dass die Zahlen 0,...,8 dargestellt werden
            //Anschließend +1 damit von 1,...,9
            A1[i][j] = rand() % 9 + 1;
        }
    }
    /**
     * AUFGABE 1C
     */
    //Array A2 wird ebenfalls mit 2 for-schleifen durchlaufen
    //und es wird die Einträge von A1 in A2 kopiert
    for(int i = 0; i < 30; ++i){
        for(int j = 0; j < 30; j++){
            //Eine Zeile ist 30 Einträge lang
            //Für den ersten Eintrag der ersten Zeile gilt: A2[0*30 + 0] = A2[0] , A1[0][0]
            //Für den ersten Eintrag der zweiten Zeile gilt: A2[1*30 + 0] = A2[30] , A1[30][0]
            A2[i*30 + j] = A1[i][j];
        }
    }

    /**
     * AUFGABE 1D
     * Konsolenprogramm
     */
    //Überprüfen, ob Konsolenprogramm noch läuft
    bool isRunning = true;
    //Unsere Eingabe wird in dieser Variable gespeichert
    int eingabe;
    //Zu Beginn des Programms wird (wie in der Aufgabe) die Matrix A2 in die Konsole ausgegeben
    printMatrixA2(A2);

    cout << endl;
    //Ab hier dann die Konsolenprogramm (do while-) Schleife
    do{
        //Zuerst werden die möglichen Optionen ausgegeben
           cout << "0. Exit" << endl;
           cout << "1. Change Cell" << endl;
           cout << "2. Reprint" << endl;
           //Eingabe wird gelesen
           cin >> eingabe;
           //Solange die Eingabe KEIN Integer ist
           while(cin.fail()){
               //So muss der User erneut eingeben
               cout << "Bitte erneut eingeben !!!" << endl;
               //Die vorherige Eingabe wird gelöscht
               cin.clear();
               //Die alte Eingabe wird ignoriert
               cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
               cout << "0. Exit" << endl;
               cout << "1. Change Cell" << endl;
               cout << "2. Reprint" << endl;
               //Es wird erneut eingegeben
               cin >> eingabe;
           }
           //Variablen für Zellenänderung
           //x = x-Koordinate
           //y = y-Koordinate
           //changeCell = der Wert, der neu in die Matrix an Position (x,y) eingetragen wird
           int x, y, changeCell = 0;
           //switch case Anweisung, um die Eingabe abzufragen
           switch (eingabe) {
           case 0:
               //Falls 0 eingegeben wurde
               //so wird das Konsolenprogramm beendet
               //isRunning wird am Ende der Schleife abgefragt
               //und die Schleife bricht dann ab
               //weil isRunning nicht mehr true ist
               isRunning = false;
               break;
           case 1:
               //Falls 1 eingegeben wurde
               //wird eine x Koordinate eingegeben
               cout << "Geben Sie die x-Koordinate ein: " << endl;
               cin >> x;
               //Hier wieder Abfangen einer falschen Eingabe
               //x darf nur im Bereich von 0  bis 29 liegen
               //da wir mit A2[x*30 + y] arbeiten
               while(cin.fail() || x < 0 || x > 29){
                   cin.clear();
                   cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                   cout << "Bitte x-Koordinate erneut eingeben !!!" << endl;
                   cin >> x;
               }
               //y-Koordinate wird eingelesen
               cout << "Geben Sie die y-Koordinate ein: " << endl;
               cin >> y;
               //selbe wie x --> Falsche Eingaben abfangen
               while(cin.fail() || y < 0 || y > 29){
                   cin.clear();
                   cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                   cout << "Bitte y-Koordinate erneut eingeben !!!" << endl;
                   cin >> y;
               }
               //Den neuen Wert einlesen
               cout << "Geben Sie die neue Zahl ein: " << endl;
               cin >> changeCell;
               //Der neue Wert darf nur zwischen 0 und 10 sein
               //damit der Wertebereich wie in Aufgabe 1b eingehalten wird
               while(cin.fail() || changeCell < 1 || changeCell > 9){
                   cin.clear();
                   cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                   cout << "Bitte neue Zahl erneut eingeben !!!" << endl;
                   cin >> changeCell;
               }
               //Bei richtiger Eingabe wird die entsprechende Zelle gesucht
               //und der neue Wert wird dieser Zelle übergeben
               A2[x*30 + y] = changeCell;
               cout << "Zelle wurde geaendert" << endl;
               break;
           case 2:
               //Falls 2 eingegeben wurde
               //so wird die Matrix A2 wieder ausgegeben
               printMatrixA2(A2);
               cout << endl;
               break;
           default:
               //Falls irgendeine ZAHL (kein Buchstabe) eingegeben wurde
               //dann wird der User gebeten, erneut einzugeben
               cout << "Bitte erneut eingeben" << endl;
               break;
           }
    }
    while(isRunning);
    cout << "Konsolenprogramm beendet" << endl;

    //Speicher wieder freigeben, da A2 dynamisch
    delete []A2;
    return a.exec();
}
