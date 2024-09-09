#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>

using namespace std;

//Funcion para leer los vectores
vector<int> readVectorFromFile(ifstream& file) {
    vector<int> vec;
    string line;
    
    if (getline(file, line)) {
        istringstream iss(line);
        int num;
        while (iss >> num) {
            vec.push_back(num);
        }
    }

    return vec;
}

//Bubble sort, sacado de: https://www.geeksforgeeks.org/bubble-sort-in-cpp/
void bubbleSort(vector<int>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
}

//Primero se leen los 3 vectores y luego se ordenan,
//tomando por separado el tiempo para cada vector
int main() {
    string filename = "vectores.txt";
    ifstream file(filename);

    if (file.is_open()) {
        int size;
        string line;

        // Leer el tamaño desde la primera línea
        if (getline(file, line)) {
            istringstream(line) >> size;
        }
        vector<int> random_vector = readVectorFromFile(file);
        vector<int> ordenado_vector = readVectorFromFile(file);
        vector<int> decreciente_vector = readVectorFromFile(file);

        file.close();

        cout << "Tamaño del vector: " << size << endl; 
        auto start = chrono::high_resolution_clock::now();
        bubbleSort(random_vector);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        cout << "Tiempo transcurrido para arreglo 1: " << elapsed.count() << " segundos." << endl;


        start = chrono::high_resolution_clock::now();
        bubbleSort(ordenado_vector);
        end = chrono::high_resolution_clock::now();
        elapsed = end - start;
        cout << "Tiempo transcurrido para arreglo 2: " << elapsed.count() << " segundos." << endl;


        start = chrono::high_resolution_clock::now();
        bubbleSort(decreciente_vector);
        end = chrono::high_resolution_clock::now();
        elapsed = end - start;
        cout << "Tiempo transcurrido para arreglo 3: " << elapsed.count() << " segundos." << endl;


        cout << "fin bubble sort" << endl;
    } else {
        cout << "No se pudo abrir el archivo para lectura." << endl;
    }

    return 0;
}