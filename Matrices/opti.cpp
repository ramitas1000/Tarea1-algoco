#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <chrono>


using namespace std;

//Funcion auxiliar para leer las matrices
void leerMatrizDesdeArchivo(ifstream& archivo, vector<vector<int>>& matriz) {
    string linea;
    while (getline(archivo, linea)) {
        if (linea.empty()) break; 
        
        stringstream ss(linea);
        vector<int> fila;
        int numero;
        while (ss >> numero) {
            fila.push_back(numero);
        }
        matriz.push_back(fila);
    }
}

//Funcion base para leer las matrices
void leerMatrices(const string& nombreArchivo, vector<vector<int>>& matriz1, vector<vector<int>>& matriz2) {
    ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        string linea;

  
        while (getline(archivo, linea)) {
            if (linea == "Matriz 1:") {
                leerMatrizDesdeArchivo(archivo, matriz1);
            } else if (linea == "Matriz 2:") {
                leerMatrizDesdeArchivo(archivo, matriz2);
                break;
            }
        }
        archivo.close();
        cout << "Matrices leídas correctamente desde " << nombreArchivo << endl;
    } else {
        cout << "No se pudo abrir el archivo para leer." << endl;
    }
}

//Funcion para imprimir la matriz por pantalla
void imprimirMatriz(const vector<vector<int>>& matriz) {
    for (const auto& fila : matriz) {
        for (const auto& elemento : fila) {
            cout << elemento << " ";
        }
        cout << endl;
    }
}

//Funcion para transponer la matriz y facilitar el acceso a memoria
vector<vector<int>> transponerMatriz(const vector<vector<int>>& matriz, int n) {
    vector<vector<int>> traspuesta(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            traspuesta[j][i] = matriz[i][j];
        }
    }
    return traspuesta;
}

//Funcion para multiplicar con un pequeño cambio para aprovechar el funcionamiento
//de la arquitectura del computador
//Adaptado del algoritmo tradicional
vector<vector<int>> mulMatOpti(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2, int n) {
    vector<vector<int>> rslt(n, vector<int>(n, 0));
    vector<vector<int>> matriz2T = transponerMatriz(mat2,n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                rslt[i][j] += mat1[i][k] * matriz2T[j][k];
            }
        }
    }

    return rslt;
}

//Primero se leen ambas matrices y despues se multiplican y se mide el tiempo que demora
//la operacion

int main() {
    string nombreArchivo = "matrices.txt";
    
    vector<vector<int>> matriz1, matriz2,resultado;

    leerMatrices(nombreArchivo, matriz1, matriz2);

    int M = matriz1.size();

    

    cout << "Tamaño de la matriz: " << M << endl; 
    auto start = chrono::high_resolution_clock::now();
    resultado = mulMatOpti(matriz1,matriz2,M);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    cout << "Tiempo transcurrido para multiplicar: " << elapsed.count() << " segundos." << endl;
    
    //imprimirMatriz(resultado);
    return 0;
}