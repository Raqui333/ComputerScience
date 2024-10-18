#include <iostream>
#include <regex>

int how_much_A(std::string string) {
  int count = 0;

  for (auto& character : string) {
    if (std::regex_match(std::string(&character, 1), std::regex("[aA]")))
      count++;
  }

  return count;
}

int main() {
  const std::string first_string = "Amanda adora assistir aventuras animadas";
  const std::string second_string = "O tempo mudou e trouxe frio e neve";

  std::cout << "Existem " << how_much_A(first_string) << " 'A's" << std::endl;
  std::cout << "Existem " << how_much_A(second_string) << " 'A's" << std::endl;

  return 0;
}