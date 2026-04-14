#include <iostream>
using namespace std;

int** crearMatriz(int n, int m) {
    int** mat = new int*[n];
    for (int i = 0; i < n; i++)
        mat[i] = new int[m];
    return mat;
}

void llenarMatriz(int** mat, int n, int m) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> mat[i][j];
        }
}

void sumaFilas(int** mat, int n, int m) {
    for (int i = 0; i < n; i++) {
        int suma = 0;
        for (int j = 0; j < m; j++)
            suma += mat[i][j];
        cout << "Suma fila " << i << ": " << suma << endl;
    }
}

int mayorElemento(int** mat, int n, int m) {
    int mayor = mat[0][0];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mat[i][j] > mayor)
                mayor = mat[i][j];
    return mayor;
}

int** transponer(int** mat, int n, int m) {
    int** t = crearMatriz(m, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            t[j][i] = mat[i][j];
    return t;
}

void liberar(int** mat, int n) {
    for (int i = 0; i < n; i++)
        delete[] mat[i];
    delete[] mat;
}

int main() {
    int n, m;

    cout << "Filas: ";
    cin >> n;
    cout << "Columnas: ";
    cin >> m;

    int** matriz = crearMatriz(n, m);

    llenarMatriz(matriz, n, m);

    cout << "\n--- Suma de filas ---\n";
    sumaFilas(matriz, n, m);

    int mayor = mayorElemento(matriz, n, m);
    cout << "\nMayor elemento: " << mayor << endl;

    int** transpuesta = transponer(matriz, n, m);

    cout << "\n--- Matriz Transpuesta ---\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << transpuesta[i][j] << " ";
        }
        cout << endl;
    }

    liberar(matriz, n);
    liberar(transpuesta, m);

    return 0;
}
