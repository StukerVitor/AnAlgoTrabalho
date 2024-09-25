# Algoritmo MaxSubretângulo

Este projeto contém dois programas em C++ que implementam algoritmos para encontrar o subretângulo com a maior soma dentro de uma matriz. Cada programa lê uma matriz de um arquivo de entrada e calcula a soma máxima de todos os possíveis subretângulos. O primeiro algoritmo utiliza uma abordagem de força bruta, enquanto o segundo implementa uma solução otimizada usando o algoritmo de Kadane.

## Arquivos

- **sol_1.cpp**  
  Implementa uma solução de força bruta para encontrar a soma máxima de um subretângulo em uma matriz.  
  Ele itera por todos os possíveis subretângulos e calcula suas somas para determinar o máximo.

  ```txt
  Função MaxSubretangulo(matriz)
      maxSoma = -∞
      Para linhaInicial de 1 até N:
          Para linhaFinal de linhaInicial até N:
              Para colunaInicial de 1 até N:
                  Para colunaFinal de colunaInicial até N:
                      somaAtual = 0
                      Para linha de linhaInicial até linhaFinal:
                          Para coluna de colunaInicial até colunaFinal:
                              somaAtual += matriz[linha][coluna]
                      maxSoma = máximo(maxSoma, somaAtual)
      Retornar maxSoma
  ```

  Obs.: maxSoma = -∞ garante que mesmo uma soma muito negativa seja maior que -∞.

- **sol_2.cpp**  
  Usa o algoritmo de Kadane para otimizar o processo de encontrar a soma máxima do subretângulo.  
  Reduz a complexidade calculando somas cumulativas das colunas e aplicando o algoritmo de Kadane nelas.

  ```txt
  Função Kadane(arr)
      maxSoma = arr[0]
      somaAtual = arr[0]
      Para i de 1 até tamanho(arr):
          somaAtual = máximo(arr[i], somaAtual + arr[i])
          maxSoma = máximo(maxSoma, somaAtual)
      Retornar maxSoma

  Função MaxSubretangulo(matriz)
      maxSoma = -∞
      Para linhaInicial de 1 até N:
          Cria array somaColunas[N] = {0}
          Para linhaFinal de linhaInicial até N:
              Para coluna de 1 até N:
                  somaColunas[coluna] += matriz[linhaFinal][coluna]
              maxSoma = máximo(maxSoma, Kadane(somaColunas))
      Retornar maxSoma
  ```

## Uso

Ambos os arquivos seguem etapas semelhantes para execução:

### Entrada

A matriz de entrada é lida a partir de um arquivo localizado no diretório `in_out`. O arquivo deve ter a seguinte estrutura:

- A primeira linha contém o número inteiro `N`, representando o tamanho de uma matriz `N x N`.
- As próximas `N` linhas contêm `N` inteiros cada, representando os elementos da matriz.

**Exemplo de arquivo (in1):**

```txt
4
1 2 -1 4
-5 6 3 -2
3 2 -1 2
-1 3 4 1
```

## Saída

O programa imprime a maior soma de qualquer subretângulo encontrado dentro da matriz.

## Executando os Programas

### Abordagem de Força Bruta

```bash
g++ sol_1.cpp -o sol_1
./sol_1
```

### Abordagem Otimizada com Kadane

```bash
g++ sol_2.cpp -o sol_2
./sol_2
```

Certifique-se de que o arquivo de entrada (in1) esteja no diretório in_out antes de executar os programas.

## Comparação

### Força Bruta:

Complexidade de tempo O(N⁶) devido aos loops aninhados que verificam todos os possíveis subretângulos.

### Algoritmo de Kadane:

Complexidade de tempo O(N³) ao utilizar somas cumulativas das colunas e aplicar o algoritmo de Kadane no resultado.

## Dependências

C++11 ou superior
