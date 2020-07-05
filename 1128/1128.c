#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define V 2000

int G[V][V];
int visitados[V];

void conecta(int x, int y)
{
	G[x - 1][y - 1] = 1;
}

void dfs (int v, int e)
{
	int i;
	visitados[v] = 1;
	for (i = 0; i < e; i++)
	{
        //v não foi encontrado
		if (G[v][i] == 1 && visitados[i] == 0)
            dfs(i, e);
	}
}

int main()
{
	int i;
    int n, m, v, w, p;
	int conectado;

	while(1)
	{
        //preenche a matriz com -1
		memset(G, 0, sizeof(G)); 
        scanf("%d %d", &n, &m);

		if (n == 0 && m == 0) 
			break;
		else
		{
			//preenche o grafo
			for (i = 0; i < m; i++)
			{
				scanf("%d %d %d", &v, &w, &p);
				if (p == 1) 
					conecta(v, w);
				else // caso p==2
				{
					conecta(v, w);
					conecta(w, v);
				}
			}
			conectado = 1;
			for(i = 0; i < n; i++)
			{
				memset(visitados, 0, sizeof(visitados));
				dfs(i, n);
				for (v = 0; v < n; v++)
				{
					if (visitados[v] == 0)
					{
						conectado = 0;
						break;
					}
				}
				if (conectado == 0) 
                    break;
			}
		}
		printf("%d\n", conectado);
	}
	return 0;
}