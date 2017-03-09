//
// Created by mat on 08.03.17.
//

#include <iostream>
#include <fstream>
#include "Polybius.h"

using namespace std;
//TODO ./program plik-tekst.txt plik-szyfr.txt 1 - zrobić obsługę plików
int main(int argc, char* argv[]){
//    cout<< "przykładowy napis: SCISLE TAJNE: "<< endl;
//    string result= PolybiusCrypt("SCISLE TAJNE");
//    cout << result <<endl;
//    cout<< "zamieniam spowrotem: "<<endl;
//    string original = PolybiusDecrypt(result);
//    cout<< original << endl;
    if (argc!=3) return 0;
    fstream inputFile, outputFile;
    inputFile.open(argv[1], ios_base::out);
    if(!inputFile) return 0;
    outputFile.open(argv[2], ios_base::in | ios_base::app );
    if(!outputFile) return 0;

    char buff[256];
    if( (int)argv[3][0]=='1' ) // gry jako 3ci arg jest podana '1' to zakoduj
        while(!inputFile.eof()) {
            inputFile.getline(buff, 256);
            outputFile << PolybiusCrypt(buff) << endl;
            cout << "plik zaszyfrowany do: " << argv[2] << endl;
        }
    else{
        while(!inputFile.eof()){
            inputFile.getline(buff, 256);
            outputFile << PolybiusDecrypt(buff) <<endl;
            cout << "plik odszyfrowany do: " << argv[2] << endl;

        }
    }
    outputFile.close();
    inputFile.close();
    return 0;
}