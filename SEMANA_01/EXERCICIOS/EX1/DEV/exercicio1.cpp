#include <iostream>
#include <string>
using namespace std;
int percentual(int valor, int min, int max) {
  return (valor - min) * 100 / (max - min);
}

int main() { printf("%i", percentual(50, 0, 200)); }