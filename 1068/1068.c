#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int i, aberto, count;
    char expressao[1001];
    
    while (scanf("%s",expressao) != EOF)
    {
        aberto = 0;
        for (i=0; i < strlen(expressao); i++)
        {
            if (expressao[i] == "(")
                aberto++;
            if (expressao[i] == ")")
            {
                if (aberto == 0)
                {
                    printf("incorrect\n");
                    break;
                }
                else
                    aberto--;
            }
        }
        if (aberto > 0)
            printf("incorrect\n");
        else
            printf("correct\n");
    }
    return 0;
}