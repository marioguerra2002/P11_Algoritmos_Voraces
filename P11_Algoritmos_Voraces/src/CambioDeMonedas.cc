#include "CambioDeMonedas.h"
CambioDeMonedas::CambioDeMonedas(std::string opcion) {
  if (opcion == "-b") {
    CambioDeMonedas::coins_ = {500000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1}; // billetes
  }
}
std::vector<int> CambioDeMonedas::CoinChange (const double ammount_double) {
  std::vector<int> result;  // conjunto de la solución
  int suma = 0; // suma de los elementos de S
  int ammount = ammount_double * 100;
  while (suma != ammount) {
    for (auto i : CambioDeMonedas::coins_) {
      if (suma + i <= ammount) {
        auto it = std::find(CambioDeMonedas::coins_.begin(), CambioDeMonedas::coins_.end(), i);
        if (it == CambioDeMonedas::coins_.end()) {
          result.clear();  // No se ha encontrado la moneda
          return result;
        }
        result.push_back(i);
        suma += i;
        break;
      }
    }
  }
  return result;
}

void CambioDeMonedas::PrintResult(double change, std::vector<int> result) {
  if (result.empty()) {
    std::cout << "No existe solución" << std::endl;
    return;
  }
  auto it = std::find(CambioDeMonedas::coins_.begin(), CambioDeMonedas::coins_.end(), 500);
  if (change >= 5) {
    std::cout << "Numero de monedas o billetes: " << result.size() << std::endl;
  } else if (it != CambioDeMonedas::coins_.end()) {
    std::cout << "Numero de monedas: " << result.size() << std::endl;
  }
  std::cout << "Para devolver " << change  << " euros de cambio, se necesitan las siguientes monedas: ";
  std::map <int, int> coins_map;
  for (auto i : result) {
    coins_map[i]++;
  }
  for (auto i : coins_map) {
    if (i.first % 100 == 0) {
      std::cout << i.second << "x" << i.first / 100 << "€    ";

    } else if (i.first % 10 == 0){
      std::cout << i.second << "x" << i.first / 10 << "¢     ";
    } else {
      std::cout << i.second << "x" << i.first << "¢    ";
    }
  }
  std::cout << std::endl;
}
