#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x1, x2, y1, y2; // variaveis de coordenadas
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    do
    {
        if (x1 == x2 && y1 == y2) // caso as coordenadas sejam iguais para os pontos inicial e final
        {
            printf("0\n");
        }
        // caso os pontos estejam respectivamente na linha horizontal, vertical ou diagonal
        else if ((x1 == x2 && y1 != y2) || (x1 != x2 && y1 == y2) || (x1 != x2 && y1 != y2) && (abs(x2 - x1) == abs(y2 - y1)))
        {
            printf("1\n");
        }
        else // para qualquer outro caso
        {
            printf("2\n");
        }
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    } while (x1 != 0);
    return 0;
}
