#include <stdio.h>

int main()
{
    int N,i=0,aux=1;
    scanf("%d", &N);
    for(i=0;i<N;i++){
        printf("%d %d %d PUM\n",aux,aux+1,aux+2);
        aux = aux+4;
    }



    return 0;
}
