#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Definir un vector de vectores de enteros
    vector<vector<int> > reports = {
        {1, 2, 3, 4},
        {5, 6, 7},
        {8, 9, 10, 11, 12}
    };

    // Iterar sobre cada fila y calcular su longitud
    for (size_t i = 0; i < reports.size(); ++i) {
        cout << "Length of row " << i << ": " << reports[i].size() << endl;
    }

    return 0;
}