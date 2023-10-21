export module funcoes

// Função que realiza o cálculo da raiz utilizando o método da bisseção
export long double bissecao(double a, double b, double epsilon) {
  cout << endl << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-= Método da bisseção =-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;

  double aux = 1;
  double fa = f(a, aux), fb = f(b, aux);

  if ((fa * fb) > 0) {
    cout << "Intervalo inválido: função não muda de sinal entre a e b" << endl;
    return 0;
  }

  double x = 0;
  double fx = 0;
  int count = -1;
  double intervX = fabs(b - a);

  while (true) {
    count += 1;

    x = (a + b) / 2;
    fx = f(x, aux);
    fa = f(a, aux);
    fb = f(b, aux);

    if (fa * fx > 0)
      a = x;
    else
      b = x;

    cout << fixed;
    cout << setprecision(7);
    cout << left << setw(5) << "| " << setw(5) << "K =" << setw(5) << count
         << " | " << setw(5) << "X =" << setw(10) << x << " | " << setw(10)
         << "IntervX =" << setw(10) << intervX << endl;

    if (intervX < epsilon) {
      cout << endl << "CRITÉRIO DE PARADA ATINGIDO" << endl << endl;
      break;
    }

    intervX = intervX / 2;
  }

  cout << "Valor de X (Bisseção): " << x << endl << endl;
  return x;
}

//cabeçalho da função para calculo da posição falsa 


// Função que realiza o cálculo da raiz utilizando o método de Newton-Raphson
export long double newton(double a, double b, double epsilon) {
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

#endif