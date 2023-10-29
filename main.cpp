#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdlib.h>
#include "metodos.hpp"
#include "auxiliares.hpp"

using namespace std;

void defaultValues();
void customValues();

void menu() {
 int aux = system("clear");

  cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
  cout << "Escolha qual item você deseja executar:" << endl << endl
       << "[a] Testar os métodos implementados com valores padrão" << endl
       << "[b] Fornecer valores específicos para o parâmetro de ajuste de N "
          "aviões e a precisão desejada, para vizualizar os valores dos "
          "deslocamentos medidos nos aviões" << endl
       << "[c] Encerrar o programa" << endl;

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

void verificaVolta() {
  char item;
  cout << "Para voltar ao menu, aperte a tecla [m]" << endl;
  cin >> item;

  if (item == 'm') {
    menu();
  }
}

void customValues() {
  int n;

  cout << "Quantos aviões você deseja testar? " << endl;
  cin >> n;

  double epsilon;
  int c1, c2, c3;

  if (n > 1) {
    double parametrosAjuste[n];

    for (int i = 0; i < n; i++) {
      double p;
      cout << "Insira o valor do parâmetro de ajuste do " << i + 1 << "º avião " << endl;
      cin >> p;
      parametrosAjuste[i] = p;
    }

    cout << "Insira o valor da precisão desejada: " << endl;
    cin >> epsilon;

    int aux = system("clear");

    cout << "=-=-=-=-=-=-=-=-=-=-=-=-= Resultado dos Aviões =-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    for (int j = 0; j < n; j++) {
        long double intv1, intv2;
        double passo = 1;

        achaIntervalo(parametrosAjuste[j], intv1, intv2, passo);
        cout << intv1 << " " << intv2 << endl;
        long double raiz_bissecao = bissecao(intv1, intv2, parametrosAjuste[j], epsilon, &c1);
        long double raiz_pf = pf(intv1, intv2, parametrosAjuste[j], epsilon, &c2);
        long double raiz_newton = newton(parametrosAjuste[j], (intv1 + intv2) / 2, epsilon, &c3);

        cout << "| Raízes do " << j + 1 << "º avião: Bissecao = " << raiz_bissecao << ", PF = " << raiz_pf << ", Newton = " << raiz_newton << " |" << endl;

        cout << "Se desejar ver o quadro comparativo de cada método, digite [s]. Caso contrário, digite [n]" << endl;
        char item;
        cin >> item;

        if(item == 's'){
            exibeQuadroComparativo(intv1, intv2, epsilon, 1, (intv1 + intv2) / 2,
            raiz_bissecao, raiz_pf, raiz_newton, c1, c2, c3);
        }

    }
    cout << endl;
  } else {
    double parametroAjuste;

    cout << "Insira o valor do parâmetro de ajuste do avião " << endl;
    cin >> parametroAjuste;

    cout << "Insira o valor da precisão desejada: " << endl;
    cin >> epsilon;

    int aux = system("clear");

    cout << "=-=-=-=-=-=-=-=-=-=-=-=-= Resultado do Avião =-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

    long double intv1, intv2;
    double passo = 1;
    achaIntervalo(parametroAjuste, intv1, intv2, passo);
    long double raiz_bissecao = bissecao(intv1, intv2, parametroAjuste, epsilon, &c1);
    long double raiz_pf = pf(intv1, intv2, parametroAjuste, epsilon, &c2);
    long double raiz_newton = newton(parametroAjuste, (intv1 + intv2) / 2, epsilon, &c3);
    cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
    cout << "| Raízes do  avião: Bissecao = " << raiz_bissecao << ", PF = " << raiz_pf << ", Newton = " << raiz_newton << " |" << endl;

    cout << endl;

    cout << "Se desejar ver o quadro comparativo de cada método, digite [s]. Caso contrário, digite [n]" << endl;
    char item;
    cin >> item;

    if(item == 's'){
      exibeQuadroComparativo(intv1, intv2, epsilon, 1, (intv1 + intv2) / 2,
                             raiz_bissecao, raiz_pf, raiz_newton, c1, c2, c3);
    }
  }

  verificaVolta();
}

void defaultValues() {
    double a = 2;
    double b = 3;
    double epsilon = 0.00001;

    int c1, c2, c3;

    double x = bissecao(a, b, 1, epsilon, &c1);

    double y = pf(a, b, 1, epsilon, &c2);

    double z = newton(1, 2.5, epsilon, &c3);

    cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl << endl;

    cout << "Valor obtido pelo método da bisseção: " << x << endl << endl
       << "Valor obtido pelo método do posição falsa: " << y << endl << endl
       << "Valor obtido pelo método de Newton: " << z << endl << endl;

    cout << "Se desejar ver o quadro comparativo de cada método, digite [s]. Caso contrário, digite [n]" << endl;
    char item;
    cin >> item;

    if(item == 's'){
        exibeQuadroComparativo(a, b, epsilon, 1, 2.5, x, y, z, c1, c2, c3);
    }

  verificaVolta();
}

int main() {
  menu();
  return 0;
}
