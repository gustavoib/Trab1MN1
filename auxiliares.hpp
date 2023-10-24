#ifndef AUXILIARES_HPP
#define AUXILIARES_HPP

// f(d) = a*d – d*ln(d)
double f(double x, double aux);

// Retona a derivada da função: (aux - 1) - log(x)
double fLinha(double x, double aux);

// Função que encontra o intervalo
void achaIntervalo(double a, long double &x1, long double &x2, double passo);


#endif