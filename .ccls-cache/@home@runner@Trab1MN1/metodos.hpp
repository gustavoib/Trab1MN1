#ifndef METODOS_HPP
#define METODOS_HPP

#include "auxiliares.hpp" 

// Função que realiza o cálculo da raiz utilizando o método da bisseção

long double bissecao(double a, double b, double aux, double epsilon);

// Função que realiza o cálculo da raiz utilizando o método do posicao falsa
double pf(double a, double b, double aux, double epsilon);

// Função que realiza o cálculo da raiz utilizando o método de Newton-Raphson
long double newton(double a, double b, double epsilon);

#endif
