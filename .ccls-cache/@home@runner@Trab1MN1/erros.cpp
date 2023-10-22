#include <iostream>
#include <cmath>

double calcularErroRelativo(double valorAnterior, double valorAtual) {
    if (valorAnterior != 0.0) {
        return std::abs(valorAtual - valorAnterior) / std::abs(valorAnterior);
    } else {
        // Lidar com o caso em que o valor anterior é zero (para evitar divisão por zero)
        if (valorAtual == 0.0) {
            return 0.0; // Ambos são zero, então o erro relativo é zero.
        } else {
            return std::numeric_limits<double>::infinity(); // O valor anterior é zero, mas o valor atual não é.
        }
    }
}