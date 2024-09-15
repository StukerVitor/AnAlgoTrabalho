#include <iostream>
#include <vector>
#include <climits>
#include <fstream>

using namespace std;

// Função que implementa o algoritmo de Kadane para encontrar a soma máxima de uma submatriz unidimensional
int Kadane(vector<int> &arr)
{
    // Inicializa a soma máxima como o primeiro elemento do vetor
    int maxSoma = arr[0], somaAtual = arr[0];

    // Itera sobre o vetor a partir do segundo elemento
    for (int i = 1; i < arr.size(); ++i)
    {
        // Atualiza a soma atual: escolhe entre iniciar um novo subarray em arr[i] ou
        // continuar o subarray atual incluindo arr[i]
        somaAtual = max(arr[i], somaAtual + arr[i]);

        // Atualiza a soma máxima se a soma atual for maior
        maxSoma = max(maxSoma, somaAtual);
    }

    // Retorna a soma máxima encontrada
    return maxSoma;
}

// Função para encontrar a soma máxima de um sub-retângulo em uma matriz bidimensional
int MaxSubretangulo(vector<vector<int>> &matriz)
{
    // Número de linhas (e colunas) da matriz (assume-se uma matriz NxN)
    int N = matriz.size();

    // Inicializa a soma máxima como o menor valor possível de int
    int maxSoma = INT_MIN;

    // Percorre todas as possíveis linhas iniciais para o sub-retângulo
    for (int linhaInicial = 0; linhaInicial < N; ++linhaInicial)
    {
        // Vetor que vai armazenar a soma acumulada das colunas entre a linha inicial e a linha final
        vector<int> somaColunas(N, 0);

        // Percorre todas as possíveis linhas finais, a partir da linha inicial
        for (int linhaFinal = linhaInicial; linhaFinal < N; ++linhaFinal)
        {
            // Para cada linha, acumula os valores da matriz em 'somaColunas'
            for (int coluna = 0; coluna < N; ++coluna)
            {
                somaColunas[coluna] += matriz[linhaFinal][coluna];
            }

            // Usa o algoritmo de Kadane para encontrar a maior soma de um subarray
            // na soma das colunas entre linhaInicial e linhaFinal
            maxSoma = max(maxSoma, Kadane(somaColunas));
        }
    }

    // Retorna a soma máxima encontrada
    return maxSoma;
}

int main()
{
    // Definindo o caminho do arquivo
    string filePath = "in_out/in1";

    // Abrindo o arquivo
    ifstream inFile(filePath);

    if (!inFile)
    {
        cerr << "Erro ao abrir o arquivo " << filePath << endl;
        return 1;
    }

    // Lendo a matriz do arquivo
    int N;
    inFile >> N;

    vector<vector<int>> matriz(N, vector<int>(N));

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            inFile >> matriz[i][j];
        }
    }

    // Fechando o arquivo
    inFile.close();

    // Executando o algoritmo e exibindo o resultado
    int resultado = MaxSubretangulo(matriz);
    cout << "Maior soma de subretângulo: " << resultado << endl;

    return 0;
}
