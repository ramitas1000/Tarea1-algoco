#include <iostream>
#include <vector>
#include <fstream> 
#include <cstdlib> 
#include <ctime>

using namespace std;

//Funcion para crear vectores de numeros aleatorios
vector<int> vector_random(int size, int lower_bound = 0, int upper_bound = 1000) {
    srand(time(0));
    vector<int> random_vector;

    for (int i = 0; i < size; ++i) {
        int random_num = lower_bound + rand() % (upper_bound - lower_bound + 1);
        random_vector.push_back(random_num);
    }
    
    return random_vector;
}

//Funcion para crear un vector ordenado de manera creciente
vector<int> vector_ordenado(int size) {
    vector<int> ordenado;

    for (int i = 0; i < size; i++) {
        ordenado.push_back(i);
    }

    return ordenado;
}

//Funcion para crear un vector ordenado de manera decreciente
vector<int> vector_decreciente(int size) {
    vector<int> decreciente;

    for (int i = size - 1; i >= 0; i--) {
        decreciente.push_back(i);
    }

    return decreciente;
}

//Funcion para almacenar un vector en un archivo de texto
void Guardar_Vector(ofstream& file, const vector<int>& vec) {
    if (file.is_open()) {
        for (int num : vec) {
            file << num << " ";  
        }
        file << endl;  
    } else {
        cout << "No se pudo escribir en el archivo." << endl;
    }
}


//Primero se pide por consola que tipo de vector crear y el tamanio
//Luego se crean y se guardan en un archivo txt
int main() {
    int size,tipo;
    cin >> tipo;
    cin >> size;
    string filename = "vectores.txt";  
    vector<int> v1,v2,v3;

    if(tipo == 1){//random
        v1 = vector_random(size);
        v2 = vector_random(size);
        v3 = vector_random(size);
    }else if(tipo == 2){//ordenado
        v1 = vector_ordenado(size);
        v2 = vector_ordenado(size);
        v3 = vector_ordenado(size);
    }else{//ordenado inverso
        v1 = vector_decreciente(size);
        v2 = vector_decreciente(size);
        v3 = vector_decreciente(size);
    }
    
    ofstream file(filename);

    if (file.is_open()) {

        file << size << endl;
        Guardar_Vector(file, v1);
        Guardar_Vector(file, v2);
        Guardar_Vector(file, v3);

        file.close(); 
        cout << "Vectores creados" << endl;
    } else {
        cout << "No se pudo abrir el archivo para escritura." << endl;
    }

    return 0;
}
