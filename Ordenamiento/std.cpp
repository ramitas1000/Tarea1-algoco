#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
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

//Funcion main, el sort estandar se importa desde la libreria algorithm
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
        vector<int> v1 = readVectorFromFile(file);
        vector<int> v2 = readVectorFromFile(file);
        vector<int> v3 = readVectorFromFile(file);

        file.close();

        cout << "Tamaño del vector: " << size << endl; 
        auto start = chrono::high_resolution_clock::now();
        sort(v1.begin(),v1.end());
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        cout << "Tiempo transcurrido para arreglo 1: " << elapsed.count() << " segundos." << endl;


        start = chrono::high_resolution_clock::now();
        sort(v2.begin(),v2.end());
        end = chrono::high_resolution_clock::now();
        elapsed = end - start;
        cout << "Tiempo transcurrido para arreglo 2: " << elapsed.count() << " segundos." << endl;


        start = chrono::high_resolution_clock::now();
        sort(v3.begin(),v3.end());
        end = chrono::high_resolution_clock::now();
        elapsed = end - start;
        cout << "Tiempo transcurrido para arreglo 3: " << elapsed.count() << " segundos." << endl;


        cout << "fin sort standard" << endl;
    } else {
        cout << "No se pudo abrir el archivo para lectura." << endl;
    }

    return 0;
}
