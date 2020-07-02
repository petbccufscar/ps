#include <stdio.h>
#include <stdlib.h>

//O programa utiliza busca em profundidade para verificar se eh possivel chegar do ponto inicial a qualquer ponto e se a partir de qualquer ponto eh possivel chegar no ponto inicial
int N, M;
int visitados[2001], grafo[2001][2001];

void Busca(int ponto)
{ //Busca em profundidade
    int i;
    if (visitados[ponto] == 1) //Se o ponto ja foi visitado, nada a ser feito
    {
        return;
    }
    else //Se nao, marca o ponto como visitado e visita os pontos com que tem ligacao recursivamente
    {
        visitados[ponto] = 1;
        for (i = 1; i <= N; i++)
        {
            if (grafo[ponto][i] && !visitados[i])
                Busca(i); //Chamada recursiva da funcao, a partir de cada um dos pontos com qual o ponto eh ligado
        }
    }
}

int main()
{
    int V, W, P;

    scanf("%d %d", &N, &M); //Le o numero de pontos e de conexoes
    while (N != 0)
    {
        int i, j, conectividade = 1;

        for (i = 1; i <= N; i++)
        {
            for (j = 1; j <= N; j++)
            {
                grafo[i][j] = 0;
            }
            visitados[i] = 0;
        } // Zera o vetor de visitados e a matriz de conexoes do grafo

        for (i = 1; i <= M; i++)
        {
            scanf("%d %d %d", &V, &W, &P);
            grafo[V][W] = 1;
            if (P == 2)
                grafo[W][V] = 1;
        }

        Busca(1); //Chama a funcao recursiva de busca para o ponto inicial, para preencher o vetor de visitados

        for (i = 1; i <= N; i++)
        {
            if (!visitados[i])
            {
                conectividade = 0;
            }
        } //Ve se eh possivel chegar do ponto inicial a qualquer ponto

        if (conectividade)
        { //Se eh possivel ir do inicial a qualquer ponto, inverte as conexoes do grafo
            for (i = 1; i <= N; i++)
            {
                visitados[i] = 0; //Zera novamente os vertices visitados
                for (j = i + 1; j <= N; j++)
                { //Para não repetir o ponto [i][j] e [j][i]
                    if (grafo[i][j] && grafo[j][i])
                    { //Se a conexao for nas duas direcoes, nao inverte
                        continue;
                    }
                    else if (grafo[i][j])
                    {
                        grafo[j][i] = 1;
                        grafo[i][j] = 0;
                    }
                    else if (grafo[j][i])
                    {
                        grafo[i][j] = 1;
                        grafo[j][i] = 0;
                    }
                }
            }

            Busca(1); //Busca agora se eh possivel chegar de qualquer ponto ao ponto incial
            for (i = 1; i <= N; i++)
            {
                if (!visitados[i])
                {
                    conectividade = 0;
                }
            } //Se eh possivel ir de qualquer ponto para o ponto inicial, o grafo eh conexo
        }

        printf("%d\n", conectividade);

        scanf("%d %d", &N, &M); // le a proxima entrada
    }
    return 0;
}
