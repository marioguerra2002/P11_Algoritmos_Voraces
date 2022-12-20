
#include "CambioDeMonedas.h"

int main(int argc, char const *argv[]) {
  if (argc == 3) {
    double change_to_process{ std::stod (argv[2])};
    std::string option = argv[1];
    CambioDeMonedas cambio(option);
    cambio.PrintResult(change_to_process, cambio.CoinChange(change_to_process));

  } else {
    double change_to_process{ std::stod (argv[1]) };
    CambioDeMonedas cambio;
    cambio.PrintResult(change_to_process, cambio.CoinChange(change_to_process));
  }
}
