#include <QCoreApplication>
#include <CAbase.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    /**
     * AUFGABE 2F
     * Konsolenprogramm
     */
    //Überprüfen, ob Konsolenprogramm noch läuft
    bool isRunning = true;
    //Unsere Eingabe wird in dieser Variable gespeichert
    int eingabe;
    //Zu Beginn des Programms wird ein Universum (30x30) erstellt
    CAbase gameOfLife(30,30);
    //Damit wir kein leeres Feld haben, füllen wir es mit Zufallszahlen aus 0 und 1
    gameOfLife.fillRandomValues();
    //und printen das Feld
    cout << "Nh: " << gameOfLife.getNx() << ";\t Nw: " << gameOfLife.getNy() << ";" << endl;
    gameOfLife.printCurrentRound();

    cout << endl;
    //Ab hier dann die Konsolenprogramm (do while-) Schleife
    do{
        //Zuerst werden die möglichen Optionen ausgegeben
           cout << "0. Exit" << endl;
           cout << "1. Evolve" << endl;
           cout << "2. Set Alive Cell" << endl;
           cout << "3. Reprint" << endl;
           cout << "4. Resize" << endl;
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
               //Es wird erneut eingegeben
               cin >> eingabe;
           }

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
               gameOfLife.advanceGameOfLife();
               cout << "Nh: " << gameOfLife.getNx() << ";\t Nw: " << gameOfLife.getNy() << ";" << endl;
               gameOfLife.printCurrentRound();
               cout << endl;
               break;
           case 2:
               int x;
               int y;
               int changeCell;
               //Falls 1 eingegeben wurde
               //wird eine x Koordinate eingegeben
               cout << "Geben Sie die x-Koordinate ein: " << endl;
               cin >> x;
               //Hier wieder Abfangen einer falschen Eingabe
               while(cin.fail() || x < 0 || x > gameOfLife.getNx()){
                   cin.clear();
                   cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                   cout << "Bitte x-Koordinate erneut eingeben !!!" << endl;
                   cin >> x;
               }
               //y-Koordinate wird eingelesen
               cout << "Geben Sie die y-Koordinate ein: " << endl;
               cin >> y;
               //selbe wie x --> Falsche Eingaben abfangen
               while(cin.fail() || y < 0 || y > gameOfLife.getNy()){
                   cin.clear();
                   cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                   cout << "Bitte y-Koordinate erneut eingeben !!!" << endl;
                   cin >> y;
               }
               //Den neuen Wert einlesen
               cout << "Geben Sie die neue Zahl ein: " << endl;
               cin >> changeCell;
               while(cin.fail() || changeCell < 0 || changeCell > 1){
                   cin.clear();
                   cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                   cout << "Bitte neue Zahl erneut eingeben !!!" << endl;
                   cin >> changeCell;
               }
               //Bei richtiger Eingabe wird die entsprechende Zelle gesucht
               //und der neue Wert wird dieser Zelle übergeben
               gameOfLife.setCellCurrent(x,y,changeCell);
               cout << "Zelle wurde geaendert" << endl;
               break;
           case 3:
               cout << "Nh: " << gameOfLife.getNx() << ";\t Nw: " << gameOfLife.getNy() << ";" << endl;
               gameOfLife.printCurrentRound();
               cout << endl;
               break;
           case 4:
               //Falls 1 eingegeben wurde
               //wird eine Breite eingegeben
               cout << "Geben Sie die Breite ein: " << endl;
               cin >> x;
               //Hier wieder Abfangen einer falschen Eingabe
               while(cin.fail() || x < 0 ){
                   cin.clear();
                   cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                   cout << "Bitte Breite erneut eingeben !!!" << endl;
                   cin >> x;
               }
               //y-Koordinate wird eingelesen
               cout << "Geben Sie die Laenge ein: " << endl;
               cin >> y;
               while(cin.fail() || y < 0){
                   cin.clear();
                   cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
                   cout << "Bitte Laenge erneut eingeben !!!" << endl;
                   cin >> y;
               }
               //Bei richtiger Eingabe wird die entsprechende Zelle gesucht
               //und der neue Wert wird dieser Zelle übergeben
               gameOfLife.resizeField(x,y);
               gameOfLife.fillRandomValues();
               cout << "Die Groeße des Feldes wurde geaendert" << endl;
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


    return a.exec();
}
