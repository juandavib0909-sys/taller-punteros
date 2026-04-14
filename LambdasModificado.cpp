#include <iostream>
using namespace std;


typedef double (*Transformar)(double);
typedef double (*Combinar)(double, double);


double procesar(double* arr, int n,
                Transformar transformaciones[], int numTrans,
                Combinar combinar) {

    double resultado = 0;

    for (int i = 0; i < n; i++) {
        double valor = arr[i];

        
        for (int j = 0; j < numTrans; j++) {
            valor = transformaciones[j](valor);
        }

        
        resultado = combinar(resultado, valor);
    }

    return resultado;
}

int main() {
    int n = 3;

   
    double* datos = new double[n]{1.0, 2.0, 3.0};

    
    Transformar transformaciones[3];

    transformaciones[0] = [](double x) -> double {
        return x * 2;
    };

    transformaciones[1] = [](double x) -> double {
        return x + 3;
    };

    transformaciones[2] = [](double x) -> double {
        return x * x;
    };

    Combinar combinar = [](double a, double b) -> double {
        return a + b;
    };

    
    double resultado = procesar(datos, n, transformaciones, 3, combinar);

    cout << "Resultado final: " << resultado << endl;

    delete[] datos;
    return 0;
}
