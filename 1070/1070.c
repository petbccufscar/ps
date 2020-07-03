#include <stdio.h>

int main()
{
   int X, i=0;
   scanf("%d", &X);
   printf("\n");
   if (X%2 == 0){
    for(i=0; i<6; i++){
        X = X+1;
        if(X%2 == 0){
            X = X+1;
        }
    printf("%d\n",X);
    }
   }
   else{
    for(i=0; i<6; i++){
      printf("%d\n",X);
      X = X+2;
    }
   }

    return 0;
}
