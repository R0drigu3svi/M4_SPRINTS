#include <iostream>
#include <string>
using namespace std;

int leituraSensor() {
  int sensor;
  cout << "Insira aqui um valor:";
  cin >> sensor;
  return sensor;
}

int main() {
  int valorInserido = leituraSensor();
  cout << "O valor inserido foi: " << valorInserido;
}