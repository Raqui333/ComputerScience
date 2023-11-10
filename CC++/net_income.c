/*
  Realizar um programa em linguagem C que calcule o valor do salário
  bruto, levando em consideração os descontos de INSS e Imposto de Renda
*/

#include <stdio.h>

// IRPF table from 2023
float incomeTax(float income) {
  float tax = 0.0; // bellow 1903.99 it is tax free

  if (income >= 1903.99 && income <= 2826.65)
    tax = 0.075;
  else if (income >= 2826.66 && income <= 3751.05)
    tax = 0.15;
  else if (income >= 3751.06 && income <= 4664.68)
    tax = 0.225;
  else if (income > 4664.68)
    tax = 0.275;

  return income * tax;
}

// INSS table from 2023 after may
float pensionDeduction(float income) {
  float ded = 0.075;

  if (income >= 1320.01 && income <= 2571.29)
    ded = 0.09;
  else if (income >= 2571.30 && income <= 3856.94)
    ded = 0.12;
  else if (income >= 3856.95 && income <= 7507.49)
    ded = 0.14;
  else if (income > 7507.49)
    return 7507.49 * 0.14;

  return income * ded;
}

int main() {
  const float gross_income = 2000.00;

  float pded = pensionDeduction(gross_income);
  float itax = incomeTax(gross_income - pded);

  float net_income = gross_income;
  net_income -= pded; // INSS
  net_income -= itax; // IRRF

  printf("Salário Bruto: %.2f\n\nINSS -%.2f\nIRRF -%.2f\n\nSalário Líquido: "
         "%.2f\n",
         gross_income, pded, itax, net_income);

  return 0;
}