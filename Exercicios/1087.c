#include <stdio.h>
#include <stdlib.h>

int main()
{
	//declaração de variáveis do tipo inteiro
	int x1, x2, y1, y2;

  while(1){
    //leitura  das coordenadas iniciais e finais
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    //verificar se é o final da entrada
    if(x1==0 && y1==0 && x2==0 && y2==0){
      return 0;
    }

    if(x1==x2 && y1==y2){ //se a coordenada inicial é igual a coordenada final, andar 0 casas
      printf("0\n");
    }else if(x1==x2 || y1==y2 || abs(x1-x2)==abs(y1-y2)){ //se a coordenada final está na diagonal, vertical ou horizontal da coordenada inicial, andar 1 casa
      printf("1\n");
    }else{ //se a coordenada final não está na diagonal, vertical ou horizontal da coordenada inicial, andar 2 casas
      printf("2\n");
    }
  }

	return(0);
}
