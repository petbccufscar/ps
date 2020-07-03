//Parênteses
#include <stdlib.h>
#include <stdio.h>

int main(){
  char *entrada;
  size_t tam;
  tam = 1005;
  entrada = malloc(sizeof(char) * tam);
  while(getline(&entrada, &tam, stdin) != EOF){
    int aux, i;
    aux = 0;
    i = 0;
    while(aux >= 0 && entrada[i] != '\0'){
      if(entrada[i] == '('){
        aux++;
      }
      else if(entrada[i] == ')'){
        aux--;
      }
      i++;
    }
    if(aux == 0)
      printf("correct\n");
    else
      printf("incorrect\n");
    free(entrada);
    entrada = malloc(sizeof(char) * tam);
  }
  return 0;
}
