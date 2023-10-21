#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdlib.h>

import funcoes;

using namespace std;

void defaultValues();
void customValues();

// Função que realiza o cálculo da raiz utilizando o método do posicao falsa
long double pf(double a, double b, double epsilon) {
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-= Método da Posição falsa "
          "=-=-=-=-=-=-=-=-=-=-=-=-=-=-="
       << endl;

  double aux = 1;
  double fa = f(a, aux), fb = f(b, aux);

  if ((fa * fb) > 0) {
    cout << "Intervalo inválido: função não muda de sinal entre a e b" << endl;
    return 0;
  }

  double x = 0;
  double fx = 0;
  int count = -1;
  double intervX;

  while (true) {
    count += 1;

    fa = f(a, aux);
    fb = f(b, aux);
    x = (a * fb - b * fa) / (fb - fa);
    fx = f(x, aux);

    if (fa * fx > 0)
      a = x;
    else
      b = x;

    intervX = fabs(b - a);

    cout << fixed;
    cout << setprecision(20);
    cout << left << setw(5) << "| " << setw(5) << "K =" << setw(5) << count
         << " | " << setw(5) << "X =" << setw(10) << x << " | " << setw(10)
         << "IntervX =" << setw(10) << intervX << endl;

    if (intervX < epsilon) {
      cout << endl << "CRITÉRIO DE PARADA ATINGIDO" << endl << endl;
      break;
    }
  }

  cout << "Valor de X (Posição Falsa): " << x << endl << endl;
  return x;
}

void menu() {
  system("clear");
  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="
   << endl;
  cout << "Escolha qual item você deseja executar:" << endl << endl
       << "a) Testar os métodos implementados com valores padrão" << endl
       << "b) Fornecer valores específicos para o parâmetro de ajuste de N "
          "aviões e a precisão desejada, para vizualizar os valores dos "
          "deslocamentos medidos nos aviões"
       << endl
       << "c) Encerrar o programa" << endl;

  char item;
  cin >> item;

  if (item == 'a') {
    defaultValues();
  } else if (item == 'b') {
    customValues();
  } else if (item == 'c') {
    exit(0);
  }
}

void customValues() {
  int n;
  char item;
  cout << "Quantos aviões você deseja testar? " << endl;
  cin >> n;
  double epsilon;
  int parametrosAjuste[n];

  for (int i = 0; i < n; i++) {
    int p;
    cout << "Insira o valor do parâmetro de ajuste do " << i + 1 << "º avião "
         << endl;
    cin >> p;
    parametrosAjuste[i] = p;
  }

  cout << "Insira o valor da precisão desejada: " << endl;
  cin >> epsilon;

  cout << endl
       << "Selecione a forma que você deseja encontrar a raiz: " << endl
       << "a) Método da Bissecção" << endl
       << "b) Método da Posição Falsa" << endl
       << "c) Método de Newton" << endl;

  cin >> item;

  // if (item == 'a') {

  // } else if (item == 'b') {

  // } else if (item == 'c') {
  // }
}

void verificaVolta() {
  char item;
  cout << "Para voltar ao menu, aperte a tecla [m]" << endl;
  cin >> item;

  if (item == 'm') {
    menu();
  }
}

void defaultValues() {
  double a = 2;
  double b = 3;
  double epsilon = 0.00001;

  double x = bissecao(a, b, epsilon);

  double y = pf(a, b, epsilon);

  double z = newton(1, 2.5, epsilon);

  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl << endl;

  cout << "Valor obtido pelo método da bisseção: " << x << endl << endl
       << "Valor obtido pelo método do ponto fixo: " << y << endl << endl
       << "Valor obtido pelo método de Newton: " << z << endl << endl;

  verificaVolta();
}

int main() {
  menu();
  return 0;
}
