#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#define QUANTIDADE_MAXIMA_PRODUTOS 50

int main() {

  // Corrige acentuação nos printf
  setlocale(LC_ALL, "Portuguese");

  int codigosProdutos[QUANTIDADE_MAXIMA_PRODUTOS];
  double precosProdutos[QUANTIDADE_MAXIMA_PRODUTOS];
  int quantidadeProdutos[QUANTIDADE_MAXIMA_PRODUTOS];

  int opcaoMenu = 0;

  // Inicializa o indice na primeira posição do vetor
  int indiceUltimoCodigoAdicionado = 0;
  while (opcaoMenu != 5) {

    // Reinicia o valor da opcaoMenu
    opcaoMenu = 0;

    printf("Menu - Gerenciador de Estoque\n\n");

    printf("1 - Adicionar um novo produto\n");
    printf("2 - Consultar um produto\n");
    printf("3 - Registrar a venda de um produto\n");
    printf("4 - Relatório de produtos\n");
    printf("5 - Sair\n\n");

    printf("Escolha uma das opções acima: \n");

    scanf("%d", &opcaoMenu);
    switch (opcaoMenu) {

      // Funcionalidade de adicionar produtos
    case 1: {
      printf("Cadastro de Produto\n\n");

      printf("Escreva o código do produto: \n");
      int codigoProduto;
      scanf("%d", &codigoProduto);

      // Por conta da implementação não é possível ter dois códigos de produto
      // iguais
      int codigoExistente = 0;
      for (int i = 0; i < QUANTIDADE_MAXIMA_PRODUTOS; i++) {
        if (codigosProdutos[i] == codigoProduto) {
          codigoExistente = 1;
          break;
        }
      }
      if (codigoExistente) {
        printf("O codigo inserido já existe!\n\n");
        break;
      }

      codigosProdutos[indiceUltimoCodigoAdicionado] = codigoProduto;

      printf("Escreva o preço do produto, utilizando vírgula para separar os "
             "decimais: \n");
      double precoProduto;
      scanf("%lf", &precoProduto);
      precosProdutos[indiceUltimoCodigoAdicionado] = precoProduto;

      printf("Escreva a quantidade desse produto no estoque: \n");
      int quantidadeProduto;
      scanf("%d", &quantidadeProduto);
      quantidadeProdutos[indiceUltimoCodigoAdicionado] = quantidadeProduto;

      indiceUltimoCodigoAdicionado++;

      printf("Produto %d cadastrado com sucesso\n", codigoProduto);

      break;
    }

      // Funcionalidade de consultar dados de um produto
    case 2: {

      printf("Digite o código do produto que deseja pesquisar: \n");

      int codigoProduto;

      scanf("%d", &codigoProduto);
      int codigoExistente = -1;
      for (int i = 0; i < indiceUltimoCodigoAdicionado; i++) {
        if (codigosProdutos[i] == codigoProduto) {
          codigoExistente = i; // retorna o indice do produto no vetor de
                               // codigos
          break;
        }
      }
      if (codigoExistente == -1) {
        printf("O codigo inserido não existe!\n\n");
        break;
      }

      printf("Código \t Preço \t\tQuantidade\n");
      printf("%d \t", codigosProdutos[codigoExistente]);
      printf("R$%.2lf \t\t", precosProdutos[codigoExistente]);
      printf("%d\n\n", quantidadeProdutos[codigoExistente]);
    }

    break;

      // Funcionalidade de registrar vendas
    case 3: {
      printf("Digite o código do produto que deseja pesquisar: \n");

      int codigoProduto;

      scanf("%d", &codigoProduto);

      int codigoExistente = -1;
      for (int i = 0; i < QUANTIDADE_MAXIMA_PRODUTOS; i++) {
        if (codigosProdutos[i] == codigoProduto) {
          codigoExistente = i; // retorna o indice do produto no vetor de
                               // codigos

          break;
        }
      }
      if (codigoExistente == -1) {
        printf("O codigo inserido não existe!\n\n");
        break;
      }
      int qtdVendida;
      printf("Insira a quantidade de unidades vendidas: \n");
      scanf("%d", &qtdVendida);
      if (qtdVendida > quantidadeProdutos[codigoExistente]) {
        printf("A quantidade de itens é menor do que se pode vender\n");
        break;
      }
      quantidadeProdutos[codigoExistente] -= qtdVendida;
      printf("Venda registrada com sucesso!\n");

      break;
    }

      // Funcionalidade de gerar um relatório dos produtos
    case 4: {
      printf("Código \t Preço \t\t Quantidade\n");
      for (int i = 0; i < indiceUltimoCodigoAdicionado; i++) {
        printf("%d \t", codigosProdutos[i]);
        // Verifica o tamanho do número para atribuir a tabulação corretamente
        if (precosProdutos[i] < 100)
          printf("R$%.2lf \t\t\t", precosProdutos[i]);
        else
          printf("R$%.2lf \t\t", precosProdutos[i]);
        printf("%d\n", quantidadeProdutos[i]);
      }
      printf("\n");

      break;
    }
    case 5: {
      // cls limpa o terminal no windows
      system("cls");
      // cls limpa o terminal no linux
      system("clear");
      break;
    }

    default:
      printf("Valor digitado inválido!\n");
      printf("Tente novamente!\n");
      break;
    }
  }
  return 0;
}
