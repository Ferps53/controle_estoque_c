#include <stdio.h>
#include <stdlib.h>

#define QUANTIDADE_MAXIMA_PRODUTOS 50

int main() {

  int codigosProdutos[QUANTIDADE_MAXIMA_PRODUTOS];
  double precosProdutos[QUANTIDADE_MAXIMA_PRODUTOS];
  int quantidadeProduto[QUANTIDADE_MAXIMA_PRODUTOS];

  int opcaoMenu = 0;
  while (opcaoMenu != 6) {

    // reinicia o valor da opcaoMenu
    opcaoMenu = 0;

    system("clear");

    printf("Menu - Gerenciador de Estoque\n");

    printf("1 - Adicionar um novo produto\n");
    printf("2 - Consultar um produto\n");
    printf("3 - Registrar a venda de um produto\n");
    printf("4 - Relatório de produtos\n");
    printf("5 - Gerar produtos para teste\n");
    printf("6 - Sair\n\n");

    scanf("%d", &opcaoMenu);
    switch (opcaoMenu) {

      // Funcionalidade de adicionar produtos
    case 1:
      printf("Funcionalidade ainda não implementada");
      break;

      // Funcionalidade de consultar dados de um produto
    case 2:
      printf("Funcionalidade ainda não implementada");
      break;

      // Funcionalidade de registrar vendas
    case 3:
      printf("Funcionalidade ainda não implementada");
      break;

      // Funcionalidade de gerar um relatório dos produtos
    case 4:
      printf("Funcionalidade ainda não implementada");
      break;

      // Funcionalidade de gerar produtos para testes
    case 5:
      printf("Funcionalidade ainda não implementada");
      break;
    case 6:
      system("clear");
      break;
    }
  }
  return 0;
}