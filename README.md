# Karnaugh Map Generator

Este programa em C gera e exibe mapas de Karnaugh (de até 4 variáveis) com base nas seguintes entradas do usuário: o número de variáveis do mapa e a saída da tabela verdade. Foi desenvolvido como parte de um desafio proposto durante a disciplina de Sistemas Digitais.

## Como utilizar

### Pré-requisitos
Certifique-se de ter um compilador C instalado em seu sistema para executar o programa.

### Passos para execução
1. Clone o repositório em sua máquina local.
  ```sh
  git clone https://github.com/jsklcodes/karnaugh-map-generator.git
  ```
2. Abra o terminal na pasta onde o programa está localizado.
3. Compile o código usando um compilador C (por exemplo, GCC):
  ```sh
  gcc main.c -o k-map -lm
  ```
4. Execute o programa:
  ```sh
  ./k-map
  ```
5. Siga as instruções exibidas no terminal para inserir o número de variáveis e a saída da tabela verdade para gerar o mapa de Karnaugh correspondente.

### Detalhes Técnicos
O programa tem suporte para até 4 variáveis e aceita valores booleanos (0 ou 1) como entrada para a tabela verdade. Certifique-se de inserir os valores corretos para obter o resultado esperado.

## Contribuições
Contribuições são bem-vindas! Sinta-se à vontade para abrir issues relatando problemas, sugerir melhorias ou enviar pull requests para aprimorar este projeto.