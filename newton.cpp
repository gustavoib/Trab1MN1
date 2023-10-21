#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

// Função que realiza o cálculo da raiz utilizando o método de Newton-Raphson
long double newton(double a, double b, double epsilon) {
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-= Método de Newton "
          "=-=-=-=-=-=-=-=-=-=-=-=-=-=-="
       << endl;

  int count = 1;
  double intervX;
  double x = (a + b) / 2;

  while (true) {
    double x1 = x - (f(x, a) / fLinha(x, a));
    intervX = fabs(x1 - x);

    cout << fixed;
    cout << setprecision(20);
    cout << left << setw(5) << "| " << setw(5) << "K =" << setw(5) << count
         << " | " << setw(5) << "X =" << setw(10) << x << " | " << setw(10)
         << "IntervX =" << setw(10) << intervX << endl;

    if (intervX < epsilon) {
      cout << endl << "CRITÉRIO DE PARADA ATINGIDO" << endl << endl;
      break;
    }
    x = x1;
    count += 1;
  }

  cout << "Valor de X (Newton): " << x << endl << endl;
  return x;
}
