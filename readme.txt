Por favor acesse o repositório no github ("https://github.com/Ferps53/controle_estoque_c"),
para uma documentação mais completa e o histórico de desenvolvimento

Ou acesse a README.md para ler a documentação em formato markdown!
 
Como foi desenvolvido

- Nós utilizamos um loop while como base do programa, pois o usuário vai interagir indefinidamente com o sistema até decidir sair.

- O menu é feito através de um switch-case para a definição da escolha das opções.

- São utilizados 3 vetores para guardar os valores dos produtos, pois os preços são double e os outros dois são int's. Dessa forma, é preciso salvar os códigos em um vetor e salvar o preço e a quantidade do produto no mesmo índice nos outros vetores, para assim ter uma forma de pesquisar o produto pelo código, recuperar o índice do mesmo, e por fim, acessar as propriedades do item através dos outros dois vetores.

- A variável indiceUltimoCodigoAdicionado salva o ultimo índice que foi adicionado nos vetores, para ser uma forma fácil de saber quantos produtos foram adicionados no sistema. Esta variável também tem a função de limitar os for loops, pois serve como limitador para evitar lixos de memória onde o vetor não alocou produtos.

- Como utilizamos de um switch-case, nós podemos utilizar a prática do early return (caminho das negativas), assim utilizamos de um break para sair de situações de falha do programa, um exemplo disso é, durante a pesquisa de um código, pois se ele não existe é escrito no console "O código inserido não existe" o que evita uma falha no sistema ao buscar por uma posição não existente no vetor. No caso do cadastro de um produto, é realizada a mesma ação, porém é realizada a verificação de códigos duplicados, pois por conta da nossa implementação, os códigos precisam ser únicos, assim evita o cadastro de duplicatas, que também iriam afetar a pesquisa nos vetores.
  Exemplo: 

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
