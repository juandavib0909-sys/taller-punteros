#include <iostream>
using namespace std;


typedef double (*Transformar)(double);
typedef double (*Combinar)(double, double);


double procesar(double* arr, int n,
                Transformar transformar,
                Combinar combinar) {
    
    double resultado = 0;

    for (int i = 0; i < n; i++) {
        double valorTransformado = transformar(arr[i]);
        resultado = combinar(resultado, valorTransformado);
    }

    return resultado;
}

int main() {
    int n = 5;

    double* datos = new double[n]{1.5, 2.0, 3.5, 4.0, 5.5};


    Transformar transformar = [](double x) -> double {
        return x * 2;
    };

    Combinar combinar = [](double acumulado, double valor) -> double {
        return acumulado + valor;
    };


    double resultado = procesar(datos, n, transformar, combinar);

    cout << "Resultado final: " << resultado << endl;


    delete[] datos;

    return 0;
}
