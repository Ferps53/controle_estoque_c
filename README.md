<h1 align="center"> Controle de Estoque - Algoritmos 1 </h1> 

## Alunos: 
 - Felipe Brostolin Ribeiro 
 - Felipe Franzoi Adames

### GitHub: [Código Fonte do Projeto](https://github.com/Ferps53/controle_estoque_c)

Introdução:
Este trabalho tem como objetivo a criação de um programa em linguagem C
para controle de estoque. Utilize vetores ou matrizes para armazenar
informações sobre os produtos, como código (numérico), preço (decimal) e
quantidade em estoque (inteiro). O programa deve armazenar no máximo 50
produtos. O programa deve permitir ao usuário realizar as seguintes
operações:

## Requisitos do Programa:

O programa deve apresentar menu com as seguintes opções:

### Menu do programa

1) Adicionar novo produto (inserindo código, preço e quantidade).
O código deve ser único para cada produto.
2) Consultar informações sobre um produto (pesquisando por
código).
3) Registrar a venda de um produto (informando código e
quantidade vendida, atualizando o estoque).
4) Exibir um relatório com a lista de todos os produtos, seus
códigos, preços e quantidades em estoque.
5) Sair e fechar o programa

## Desenvolvimento do Programa:

- O programa deve ser desenvolvido em linguagem C, utilizando
conceitos como vetores, matrizes e menus.

- Somente é permitindo usar os conceitos vistos na disciplina de
Algoritmos 1. Ou seja, funções, estruturas e demais comandos não
vistos na disciplina, não podem ser usados.

## Como foi desenvolvido
- Nós utilizamos um loop while como base do programa, pois o usuário vai interagir indefinidamente com o sistema até decidir sair.

- O menu é feito através de um switch-case para a definição da escolha das opções.

- São utilizados 3 vetores para guardar os valores dos produtos, pois os preços são double e os outros dois são int's. Dessa forma, é preciso salvar os códigos em um vetor e salvar o preço e a quantidade do produto no mesmo índice nos outros vetores, para assim ter uma forma de pesquisar o produto pelo código, recuperar o índice do mesmo, e por fim, acessar as propriedades do item através dos outros dois vetores.

- A variável indiceUltimoCodigoAdicionado salva o ultimo índice que foi adicionado nos vetores, para ser uma forma fácil de saber quantos produtos foram adicionados no sistema. Esta variável também tem a função de limitar os for loops, pois serve como limitador para evitar lixos de memória onde o vetor não alocou produtos.

- Como utilizamos de um switch-case, nós podemos utilizar a prática do early return (caminho das negativas), assim utilizamos de um break para sair de situações de falha do programa, um exemplo disso é, durante a pesquisa de um código, pois se ele não existe é escrito no console "O código inserido não existe" o que evita uma falha no sistema ao buscar por uma posição não existente no vetor. No caso do cadastro de um produto, é realizada a mesma ação, porém é realizada a verificação de códigos duplicados, pois por conta da nossa implementação, os códigos precisam ser únicos, assim evita o cadastro de duplicatas, que também iriam afetar a pesquisa nos vetores. Exemplo: 
    ~~~C

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
        break; // Este break age diretamente no switch-case, fazendo com que saia da funcionalidade de cadastro
      }
    ~~~

