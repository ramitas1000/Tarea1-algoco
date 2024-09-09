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
        iss >> vector_name; 
        int num;
        while (iss >> num) {
            vec.push_back(num);
        }
    }

    return vec;
}

//Funcion para juntar los vectores
//Sacado de: https://www.geeksforgeeks.org/merge-sort/
//junto con la funcion recursiva mergeSort
void merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    vector<int> L(n1), R(n2);

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

//Funcion recursiva de ordenamiento 
//sacada de: https://www.geeksforgeeks.org/merge-sort/
void mergeSort(vector<int>& arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


//Primero se leen los 3 vectores y luego se ordenan,
//tomando por separado el tiempo para cada vector
int main() {
    string filename = "vectores.txt";
    ifstream file(filename);

    if (file.is_open()) {
        int size;
        string line;

        if (getline(file, line)) {
            istringstream(line) >> size;
        }


        vector<int> v1 = leerVector(file);
        vector<int> v2 = leerVector(file);
        vector<int> v3 = leerVector(file);

        file.close();

        cout << "Tamaño del vector: " << size << endl; 
        auto start = chrono::high_resolution_clock::now();
        mergeSort(v1, 0, size-1);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed = end - start;
        cout << "Tiempo transcurrido para arreglo 1: " << elapsed.count() << " segundos." << endl;


        start = chrono::high_resolution_clock::now();
        mergeSort(v2, 0, size-1);
        end = chrono::high_resolution_clock::now();
        elapsed = end - start;
        cout << "Tiempo transcurrido para arreglo 2: " << elapsed.count() << " segundos." << endl;


        start = chrono::high_resolution_clock::now();
        mergeSort(v3, 0, size-1);
        end = chrono::high_resolution_clock::now();
        elapsed = end - start;
        cout << "Tiempo transcurrido para arreglo 3: " << elapsed.count() << " segundos." << endl;


        cout << "fin merge sort" << endl;


    } else {
        cout << "No se pudo abrir el archivo para lectura." << endl;
    }

    return 0;
}

