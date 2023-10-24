#include "auxiliares.hpp"
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <stdlib.h>
using namespace std;

// f(d) = a*d – d*ln(d)
double f(double x, double aux) { 
  return aux * x - x * log(x); 
}

// derivada da função anterior
double fLinha(double x, double aux) { 
  return (aux - 1) - log(x); 
}

// função para encontrar novos intervalos
// Função para encontrar um intervalo com raiz
void achaIntervalo(double a, long double &x1, long double &x2, double passo) {  
  if (a <= 0) {
    x1 = 1e-10;
  }
  else {
    x1 = 1;
  }
  
  x2 = x1 + passo;
  
  while (f(x1, a) * f(x2, a) >= 0) {
    x1 = x2;
    x2 = x2 + passo;
  }
}


// int main() {
//     double parametro_a = 1.0; // Valor do parâmetro 'a'
//     double passo = 1; // Tamanho do passo, definido como um com base no
//     intervalo sujerido no item d.

//     double intervalo1, intervalo2;
//     achaIntervalo(parametro_a, intervalo1, intervalo2, passo);

//     return 0;
// }
