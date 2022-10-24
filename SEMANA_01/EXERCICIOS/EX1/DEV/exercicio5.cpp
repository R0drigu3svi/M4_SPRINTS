#include <iostream>
#include <string>
using namespace std;
bool continuarMapeamento() {
  char resultado;
  cout << "Deseja continuar o mapeamento 1(sim) ou 0(nao):";
  cin >> resultado;

  if (resultado == '1') {
    return true;
  } else {
    return false;
  }
}

int main() {
  bool map = continuarMapeamento();
  if (map == true) {
    cout << "verdadeiro";
  } else {
    cout << "falso";
  }
}