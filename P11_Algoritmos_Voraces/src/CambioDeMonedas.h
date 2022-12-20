#ifndef CAMBIO_DE_MONEDAS_H
#define CAMBIO_DE_MONEDAS_H
#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <map>
#include <cstring>

class CambioDeMonedas {
 public:
  CambioDeMonedas(std::string);
  CambioDeMonedas() { CambioDeMonedas::coins_ = {200, 100, 50, 20, 10, 5, 2, 1}; }
  std::vector<int> CoinChange (const double ammount);
  void PrintResult(double change, std::vector<int>);
 private:
  std::vector<int> coins_;
};
#endif  // CAMBIO_DE_MONEDAS_H
