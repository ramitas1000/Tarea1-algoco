#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>

using namespace std;

//Funcion para leer los vectores
vector<int> leerVector(ifstream& file) {
    vector<int> vec;
    string line;
    
    if (getline(file, line)) {
        istringstream iss(line);
        string vector_name;
        iss >> vector_name;  // Leer el nombre del vector (por ejemplo, "Random")
        int num;
        while (iss >> num) {
            vec.push_back(num);
        }
    }

    return vec;
}

//Funcion partition necesaria para quick sort
//sacada de: https://www.geeksforgeeks.org/quick-sort-algorithm/
int partition(vector<int> &vec, int low, int high) {
    int pivot = vec[high];

    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (vec[j] <= pivot) {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    swap(vec[i + 1], vec[high]);

    return (i + 1);
}

//Funcion recursiva de quick sort para dividir el problema
void quickSort(vector<int> &vec, int low, int high) {

    if (low < high) {
        int pi = partition(vec, low, high);

        quickSort(vec, low, pi - 1);
        quickSort(vec, pi + 1, high);
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
        vector<int> v1 = leerVector(file);
        vector<int> v2 = leerVector(file);
        vector<int> v3 = leerVector(file);

        file.close();
        
        cout << "Tamaño del vector: " << size << endl; 
        auto start = chrono::high_resolution_clock::now();
        quickSort(v1, 0, size-1);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        cout << "Tiempo transcurrido para arreglo 1: " << elapsed.count() << " segundos." << endl;


        start = chrono::high_resolution_clock::now();
        quickSort(v2, 0, size-1);
        end = chrono::high_resolution_clock::now();
        elapsed = end - start;
        cout << "Tiempo transcurrido para arreglo 2: " << elapsed.count() << " segundos." << endl;


        start = chrono::high_resolution_clock::now();
        quickSort(v3, 0, size-1);
        end = chrono::high_resolution_clock::now();
        elapsed = end - start;
        cout << "Tiempo transcurrido para arreglo 3: " << elapsed.count() << " segundos." << endl;

        cout << "fin quick sort" << endl;
    } else {
        cout << "No se pudo abrir el archivo para lectura." << endl;
    }

    return 0;
}