#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Função para imprimir o mapa de Karnaugh de 2 variáveis
void print2VariableKMap(int *truthTableOutput);

// Função para imprimir o mapa de Karnaugh de 3 variáveis
void print3VariableKMap(int *truthTableOutput);

// Função para imprimir o mapa de Karnaugh de 4 variáveis
void print4VariableKMap(int *truthTableOutput);

// Função para imprimir o mapa correspondente com o número de variáveis
void printKarnaughMap(int numberOfVariables, int *truthTableOutput);

// Função para obter o número de variáveis do usuário
int getNumberOfVariables();

// Função para obter a saída do usuário
void getOutput(int numberOfVariables, int *outputArray);

// Função para imprimir a tabela verdade
void printTruthTable(int numberOfVariables, int *truthTable);

int main()
{

  int numberOfVariables = getNumberOfVariables();

  int truthTableSize = pow(2, numberOfVariables);
  int outputArray[truthTableSize];

  getOutput(numberOfVariables, outputArray);

#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif

  printTruthTable(numberOfVariables, outputArray);

  printKarnaughMap(numberOfVariables, outputArray);

  return 0;
}

void print2VariableKMap(int *truthTableOutput)
{
  printf("    B'| B \n");
  printf("A'| %d | %d |\n", truthTableOutput[0], truthTableOutput[1]);
  printf("-----------\n");
  printf("A | %d | %d |\n", truthTableOutput[2], truthTableOutput[3]);
}

void print3VariableKMap(int *truthTableOutput)
{
  printf("      B'  |   B \n");
  printf("  -----------------\n");
  printf("A'| %d | %d | %d | %d |\n", truthTableOutput[0], truthTableOutput[1], truthTableOutput[3], truthTableOutput[2]);
  printf("-------------------\n");
  printf("A | %d | %d | %d | %d |\n", truthTableOutput[4], truthTableOutput[5], truthTableOutput[7], truthTableOutput[6]);
  printf("  -----------------\n");
  printf("    C'|   C   | C'\n");
}

void print4VariableKMap(int *truthTableOutput)
{
  printf("      C'  |   C   \n");
  printf("  -----------------\n");
  printf("  | %d | %d | %d | %d | B'\n", truthTableOutput[0], truthTableOutput[1], truthTableOutput[3], truthTableOutput[2]);
  printf("A'--------------------\n");
  printf("  | %d | %d | %d | %d |   \n", truthTableOutput[4], truthTableOutput[5], truthTableOutput[7], truthTableOutput[6]);
  printf("------------------- B\n");
  printf("  | %d | %d | %d | %d |\n", truthTableOutput[12], truthTableOutput[13], truthTableOutput[15], truthTableOutput[14]);
  printf("A --------------------\n");
  printf("  | %d | %d | %d | %d | B'\n", truthTableOutput[8], truthTableOutput[9], truthTableOutput[11], truthTableOutput[10]);
  printf("  -----------------\n");
  printf("    D'|   D   | D'\n");
}

void printKarnaughMap(int numberOfVariables, int *truthTableOutput)
{
  printf("\n+------------------+");
  printf("\n| Mapa de Karnaugh |");
  printf("\n+------------------+\n\n");

  switch (numberOfVariables)
  {
  case 2:
    print2VariableKMap(truthTableOutput);
    break;
  case 3:
    print3VariableKMap(truthTableOutput);
    break;
  case 4:
    print4VariableKMap(truthTableOutput);
    break;
  }

  printf("\n");
}

int getNumberOfVariables()
{
  int numberOfVariables;
  do
  {
    printf("Digite o número de variáveis (2, 3 ou 4): ");
    if (scanf("%d", &numberOfVariables) != 1 || (numberOfVariables != 2 && numberOfVariables != 3 && numberOfVariables != 4))
    {
      printf("Por favor, digite uma destas opções: 2, 3 ou 4.\n");
      while (getchar() != '\n')
        ;
      continue;
    }
  } while (!(numberOfVariables == 2 || numberOfVariables == 3 || numberOfVariables == 4));

  return numberOfVariables;
}

void getOutput(int numberOfVariables, int *outputArray)
{
  int truthTableSize = pow(2, numberOfVariables);

  for (int i = 0; i < truthTableSize; i++)
  {
    printf("Digite o valor de saída para o caso %d: ", i);
    scanf("%d", &outputArray[i]);
  }
}

void printTruthTable(int numberOfVariables, int *outputArray)
{
  int rows = pow(2, numberOfVariables);

  printf("\n+----------------+");
  printf("\n| Tabela Verdade |");
  printf("\n+----------------+\n\n");

  printf("|");
  for (int i = 0; i < numberOfVariables; i++)
  {
    printf(" %c |", 'A' + i);
  }
  printf(" S |\n");

  for (int i = 0; i < rows; i++)
  {
    printf("|");
    for (int j = numberOfVariables - 1; j >= 0; j--)
    {
      printf(" %d |", (i >> j) & 1);
    }
    printf(" %d |\n", outputArray[i]);
  }
}
