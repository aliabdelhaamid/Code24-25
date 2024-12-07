#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main(){

    // Abrir el archivo
    ifstream file("/Users/aliabdelhamid/Programación/Advent_Code/2024/reports.txt");
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }
    
    vector<vector<int> > reports;  // vector per a almacenar les files
    string line;

    while (getline(file, line)) { // llig el arxiu i plena el vector de reports
        stringstream ss(line);
        vector<int> fila;
        int num;
        while (ss >> num) {
            if (ss.fail()) {
                ss.clear();
        if (!fila.empty()) {
            reports.push_back(fila);
        }
                continue;
            }
            fila.push_back(num);
        }
        reports.push_back(fila);
    }

    int safe = 0; // me diu cuantes files son segures
    for (int i = 0; i < reports.size(); i++)
    {
        int size = reports[i].size(); // me diu les columnes de cada fila
        int checkFile = 0;
        for (int j = 0; j < size - 1; j++)
        {          
            if (abs(reports[i][j] - reports[i][j + 1]) == 1 || abs(reports[i][j] - reports[i][j + 1]) == 2 || abs(reports[i][j] - reports[i][j + 1]) == 3)
            {
                checkFile++; 
            }
        }
        if (checkFile == size - 1) // si tots els elementes cumplixen la condicio de dalt, aço sera cert
        {
            safe++;
        }
    }
    cout <<"El número total de reportes seguros es: "<< safe << '\n';

    return 0;
}