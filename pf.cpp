#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

// f(d) = a*d – d*ln(d)
double f(double x, double aux) {
  return  (aux * x - x * log(x));    
}

// Função que realiza o cálculo da raiz utilizando o método da posição falsa
long double posicaoFalsa(double a, double b, double epsilon, double aux, int count){
    double fa = f(a, aux), fb = f(b, aux),fx;

    if (fa * fb >0 ){
      cout << "Intervalo inválido: função não muda de sinal entre a e b" << endl;
    return 0;
  }

  double x ;

  double intervX = fabs(b-a);
  x =  (a*fb - b*fa)/(fb-fa);
  
  if (intervX > epsilon){ 
    

  x =  (a*fb - b*fa)/(fb-fa);

  fx = f(x, aux);

  
  cout << left << setw(5) << " | " << setw(5) << "K = " << setw(5) << count << " | " << setw(5) << "X = "<< setw(10)<< " | " << setw(10) << intervX << endl;

  ++count;

      if(fa * fx > 0 ){
    return posicaoFalsa(x, b, epsilon, aux, count );
  }
  else 
    return posicaoFalsa(a, x, epsilon, aux, count);    
  }

  cout << "CRITÉRIO DE PARADA ATINGIDO" << endl << endl;

return x;

}

int main() {
  double a = 2;
  double b = 3;
  double epsilon = 0.00001;
  int count = 0;
  int aux = 1;

  double x = posicaoFalsa(a, b, epsilon,aux,count);
  cout << "Valor de X (Posição Falsa): " << x << endl;

return 0;
}