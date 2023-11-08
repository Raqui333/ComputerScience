/*
  Author: Kleber Silva (Raqui333)
  Creation Date: 11/07/2023 (mm/dd/yyyy)
  Description: An academic code for the course of computer science 2023
  License: WTFPL (Do What The Fuck You Want To Public License)
*/

// Implemente um programa em C/C++, que leia e armazene 20 valores e retorne
// qual foi o valor máximo e o mínimo atingido naquele determinado dia

#include <cstdlib>
#include <iostream>
#include <time.h> // for randomize purposes

int getMaxValue(int *list_of_values, size_t size) {
  int current_max = 0;
  for (unsigned int i = 0; i <= size; ++i) {
    if (list_of_values[i] > current_max)
      current_max = list_of_values[i];
  }
  return current_max;
}

int getMinValue(int *list_of_value, size_t size) {
  int current_min = list_of_value[0];
  for (unsigned int i = 0; i <= size; ++i) {
    if (list_of_value[i] < current_min)
      current_min = list_of_value[i];
  }
  return current_min;
}

int main(int argc, char **argv) {
  srand(time(NULL));

  int input_values[19]; // zero-prefixed
  size_t size = sizeof(input_values) / sizeof(int);

  std::cout << "Lista de valores do dia: " << std::endl;

  // random initalize
  for (unsigned int i = 0; i <= size; ++i) {
    input_values[i] = rand() % 50 + 1;
    std::cout << input_values[i] << (i != size ? ", " : "\n");
  }

  std::cout << "\nValor máximo no dia: " << getMaxValue(input_values, size)
            << std::endl;

  std::cout << "Valor mínimo no dia: " << getMinValue(input_values, size)
            << std::endl;

  return 0;
}
