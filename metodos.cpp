#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "metodos.hpp"
#include "auxiliares.hpp"

using namespace std;

// Função que realiza o cálculo da raiz utilizando o método da bisseção
long double bissecao(double a, double b, double aux, double epsilon, int *contador) {
  cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-= Método da bisseção =-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

  double fa = f(a, aux), fb = f(b, aux);

  if ((fa * fb) > 0) {
    cout << "Intervalo inválido: função não muda de sinal entre a e b" << endl;
    return 0;
  }

  double x = 0;
  double fx = 0;
  int count = -1;
  double intervX = fabs(b - a);
  double lastX = a;
  string quebra;

  while (true) {
    count += 1;

    x = (a + b) / 2;
    fx = f(x, aux);
    fa = f(a, aux);
    fb = f(b, aux);

    if (x > 2) {
      quebra = "SIM";
    } else {
      quebra = "NÃO";
    }
  
    cout << fixed;
    cout << setprecision(7);
    cout << left << setw(5) << "| " << setw(5) 
         << "K =" << setw(5) << count << " | " << setw(5) 
         << "X =" << setw(10) << x << " | " << setw(10)
         << "IntervX =" << setw(10) << intervX << " | " << setw(5)
         << "A =" << a  << " | " << setw(5)
         << "B =" << b << " | " << setw(10)
         << "Quebra? " << setw(10) << quebra << endl;

    if (fa * fx > 0)
      a = x;
    else
      b = x;

    lastX = x;

    if (intervX < epsilon) {
      cout << endl << "CRITÉRIO DE PARADA ATINGIDO" << endl << endl;
      break;
    }

    intervX = intervX / 2;
  }
  *contador = count;

  cout << "Valor de X (Bisseção): " << x << endl << endl;
  return x;
}

// Função que realiza o cálculo da raiz utilizando o método do posicao falsa
long double pf(long double a, long double b, double aux, double epsilon, int *contador) {
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-= Método da Posição falsa =-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

  long double fa = f(a, aux), fb = f(b, aux);

  if ((fa * fb) > 0) {
    cout << "Intervalo inválido: função não muda de sinal entre a e b" << endl;
    return 0;
  }

  long double x = 0;
  long double fx = 0;
  int count = -1;
  long double intervX;
  long double lastX = a;
  string quebra;

  while (true) {
    count += 1;

    fa = f(a, aux);
    fb = f(b, aux);
    x = ((a * fb) - (b * fa)) / (fb - fa);
    fx = f(x, aux);

    intervX = fabs(b - a);

    if (x > 2) {
      quebra = "SIM";
    } else {
      quebra = "NÃO";
    }

    cout << fixed;
      cout << setprecision(7);
      cout << left << setw(5) << "| " << setw(5) 
           << "K =" << setw(5) << count << " | " << setw(5)
           << "X =" << setw(10) << x << " | " << setw(10)
           << "IntervX =" << setw(10) << intervX << " | " << setw(5)
           << "A =" << a  << " | " << setw(5)
           << "B =" << b << " | " << setw(10)
           << "Quebra? " << setw(10) << quebra << endl;

    if (fa * fx > 0)
      a = x;
    else
      b = x;

    lastX = x;

    if (intervX < epsilon) {
      cout << endl << "CRITÉRIO DE PARADA ATINGIDO" << endl << endl;
      break;
    }
  }
  *contador = count;

  cout << "Valor de X (Posição Falsa): " << x << endl << endl;
  return x;
}

// Função que realiza o cálculo da raiz utilizando o método de Newton-Raphson
long double newton(double a, double chute, double epsilon, int *contador) {
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-= Método de Newton =-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

  int count = 1;
  double intervX;
  double x = (a + chute) / 2;
  x = fabs(x);
  double lastX = x;
  string quebra;

  while (true) {
    double x1 = x - (f(x, a) / fLinha(x, a));
    intervX = fabs(x1 - x);
    x1 = fabs(x1);

    if (x1 > 2) {
      quebra = "SIM";
    } else {
      quebra = "NÃO";
    }

    cout << fixed;
    cout << setprecision(7);
    cout << left << setw(5) << " | " << setw(5) 
         << "K = " << setw(5) << count << " | " << setw(5) 
         << "X = " << setw(10) << x1 << " | " << setw(10)
         << "IntervX = " << setw(10) << intervX << " | " << setw(5)
         << "Last X = " << lastX  << " | " << setw(5)
         << "Quebra? " << setw(10) << quebra << endl;

    lastX = x1;

    if (intervX < epsilon  ) {
      cout << endl << "CRITÉRIO DE PARADA ATINGIDO" << endl << endl;
      break;
    }

    x = x1;
    
    count += 1;
  }

  *contador = count;
  cout << "Valor de X (Newton): " << x << endl << endl;
  return x;
}

// Abordagem recursiva para posição falsa
// long double pfRecursiva(double a, double b, double epsilon, double aux, int count) {
//     double fa = f(a, aux), fb = f(b, aux),fx;

//     if (fa * fb >0 ){
//       cout << "Intervalo inválido: função não muda de sinal entre a e b" << endl;
//     return 0;
//   }

//   double x ;

//   double intervX = fabs(b-a);
//   x =  (a*fb - b*fa)/(fb-fa);

//   if (intervX > epsilon){ 


//   x =  (a*fb - b*fa)/(fb-fa);

//   fx = f(x, aux);


//   cout << left << setw(5) << " | " << setw(5) << "K = " << setw(5) << count << " | " << setw(5) << "X = "<< setw(10)<< " | " << setw(10) << intervX << endl;

//   ++count;

//       if(fa * fx > 0 ){
//     return pfRecursiva(x, b, epsilon, aux, count );
//   }
//   else 
//     return pfRecursiva(a, x, epsilon, aux, count);    
//   }

//   cout << "CRITÉRIO DE PARADA ATINGIDO" << endl << endl;

// return x;

// }
