#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib> // Para srand() y rand()
#include <ctime>   // Para time()

using namespace std;

// Función para generar una matriz cuadrada de números aleatorios
void generarMatriz(int n, vector<vector<int>>& matriz) {
    for(int i = 0; i < n; i++) {
        vector<int> fila;
        for(int j = 0; j < n; j++) {
            int numAleatorio = rand() % 11; // Números entre 0 y 10
            fila.push_back(numAleatorio);
        }
        matriz.push_back(fila);
    }
}

// Función para guardar la matriz en un archivo de texto
void guardarMatriz(const string& nombreArchivo, const vector<vector<int>>& matriz1, const vector<vector<int>>& matriz2) {
    ofstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        //Guradar matriz 1
        archivo << "Matriz 1:" << endl;
        for(const auto& fila : matriz1) {
            for(const auto& num : fila) {
                archivo << num << " ";
            }
            archivo << endl;
        }
        //Guardar matriz 2
        archivo << endl << "Matriz 2:" << endl;
        for(const auto& fila : matriz2) {
            for(const auto& num : fila) {
                archivo << num << " ";
            }
            archivo << endl;
        }

        archivo.close();
        cout << "Matrices guardadas en " << nombreArchivo << endl;
    } else {
        cout << "No se pudo abrir el archivo para escribir." << endl;
    }
}

int main() {
    srand(time(0)); // Inicializa la semilla de los números aleatorios

    //Recibir por consola el tamaño de la matriz
    int n;
    cin >> n;

    vector<vector<int>> matriz1, matriz2;
    generarMatriz(n, matriz1);
    generarMatriz(n, matriz2);
    
    string nombreArchivo = "matrices.txt";
    guardarMatriz(nombreArchivo, matriz1, matriz2);

    return 0;
}
