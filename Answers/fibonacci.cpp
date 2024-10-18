#include <iostream>

int fibonacci(int n) {
  if (n <= 1)
    return n;

  return fibonacci(n - 1) + fibonacci(n - 2);
}

bool is_this_fibonacci(int number) {
  bool answer = false;

  for (unsigned int i = 0; i <= number; ++i) {
    if (fibonacci(i) == number) {
      answer = true;
      break;
    }
  }

  return answer;
}

void print_answer(bool answer) {
  if (answer)
    std::cout << "Sim" << std::endl;
  else
    std::cout << "Não" << std::endl;
}

int main() {
  const int first_number = 33;
  const int second_number = 34;

  std::cout << "O Número '" << first_number << "' pertence a sequencia de fibonacci?\n";
  print_answer(is_this_fibonacci(first_number));

  std::cout << "O Número '" << second_number << "' pertence a sequencia de fibonacci?\n";
  print_answer(is_this_fibonacci(second_number));

  return 0;
}