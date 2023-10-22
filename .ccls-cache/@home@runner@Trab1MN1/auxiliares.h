
#ifndef AUXILIARES_H
#define AUXILIARES_H


// f(d) = a*d – d*ln(d)
double funcao(double x, double aux);

// Retona a derivada da função: (aux - 1) - log(x)
double fLinha(double x, double aux);

// Função que encontra o intervalo
void achaIntervalo(double a, double &x1, double &x2, double passo);




#endif