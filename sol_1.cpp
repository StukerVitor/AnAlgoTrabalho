#include <iostream>
#include <vector>
#include <climits>
#include <fstream>

using namespace std;

int MaxSubretangulo(vector<vector<int>> &matriz)
{
    int N = matriz.size();
    int maxSoma = INT_MIN;

    // Percorre todas as possíveis linhas iniciais
    for (int linhaInicial = 0; linhaInicial < N; linhaInicial++)
    {
        // Para cada linha inicial, percorre todas as possíveis linhas finais
        for (int linhaFinal = linhaInicial; linhaFinal < N; linhaFinal++)
        {
            // Para cada par de linhas (linhaInicial, linhaFinal), calcula as somas das colunas entre essas linhas
            for (int colunaInicial = 0; colunaInicial < N; colunaInicial++)
            {
                for (int colunaFinal = colunaInicial; colunaFinal < N; colunaFinal++)
                {
                    int somaAtual = 0;

                    // Calcula a soma de todos os elementos dentro do sub-retângulo (linhaInicial, colunaInicial) até (linhaFinal, colunaFinal)
                    for (int linha = linhaInicial; linha <= linhaFinal; linha++)
                    {
                        for (int coluna = colunaInicial; coluna <= colunaFinal; coluna++)
                        {
                            somaAtual += matriz[linha][coluna];
                        }
                    }

                    // Atualiza a soma máxima se a soma atual for maior
                    maxSoma = max(maxSoma, somaAtual);
                }
            }
        }
    }

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
