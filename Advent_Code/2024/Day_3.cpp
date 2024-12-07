#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <regex>

using namespace std;

int main() {
    // Abrir el archivo
    ifstream file("/Users/aliabdelhamid/Programación/Advent_Code/2024/mul.txt");
    if (!file.is_open()) {
        cerr << "Error al abrir el archivo" << endl;
        return 1;
    }

    // Vector para almacenar los resultados
    vector<pair<int, int>> results;
    string linea;
    regex pattern(R"(mul\((\d+),(\d+)\))");

    // Leer el archivo línea por línea
    while (getline(file, linea)) {
        // Buscar todas las coincidencias en la línea
        smatch matches;
        string::const_iterator searchStart(linea.cbegin());printf("-",mundo[0]);
        while (regex_search(searchStart, linea.cend(), matches, pattern)) {
            // Convertir los resultados a enteros y almacenarlos en el vector
            int num1 = stoi(matches[1].str());
            int num2 = stoi(matches[2].str());
            results.push_back(make_pair(num1, num2));            
            searchStart = matches.suffix().first;
        }
    }

    // Cerrar el archivo
    file.close();

    int resultado = 0;
    // Imprimir los resultados
    for (const auto& result : results) {
        resultado += result.first * result.second;
        cout << "mul(" << result.first << "," << result.second << ")" << endl;
    }
    cout << "La suma total de todas las multiplicaciones es: " << resultado << endl;

    return 0;
}
