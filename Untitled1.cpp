#include <iostream>
using namespace std;

double cuadrado(double x) { return x * x; }
double doble(double x) { return 2 * x; }
double inverso(double x) { return (x != 0) ? 1 / x : 0; }

void aplicar(double* arr, int n, double (*func)(double)) {
    for (int i = 0; i < n; i++)
        arr[i] = func(arr[i]);
}

int main(){
int n;
cout << "Tamano del arreglo: ";
cin >> n;

double* arr = new double[n];

for (int i = 0; i < n; i++) {
    cout << "Elemento " << i << ": ";
    cin >> arr[i];
}

int opcion;
cout << "1. Cuadrado\n2. Doble\n3. Inverso\nOpcion: ";
cin >> opcion;

switch (opcion) {
    case 1: aplicar(arr, n, cuadrado); break;
    case 2: aplicar(arr, n, doble); break;
    case 3: aplicar(arr, n, inverso); break;
}

for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

delete[] arr;
return 0;

}
