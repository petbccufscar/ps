//Tautograma
#include <stdlib.h>
#include <stdio.h>

int main(){
  char *entrada = NULL;
  size_t tam;
  tam = 1005;
  int frase_valida, primeira_letra, i, achou_letra_inicial;
  char letra_inicial;
  do{
    if(entrada != NULL)
      free(entrada);

    entrada = malloc(sizeof(char)*tam);
    getline(&entrada, &tam, stdin);

    achou_letra_inicial = 0;
    primeira_letra=1;
    frase_valida = 1;

    for(i=0; entrada[i] != '\0' && entrada[i] != '\n' && frase_valida == 1; i++){
      if(achou_letra_inicial == 0 && entrada[i] != ' '){
        achou_letra_inicial = 1;
        letra_inicial = entrada[i];
      }
      if(achou_letra_inicial == 1){
        if(primeira_letra == 1 && entrada[i] != ' '){
          primeira_letra = 0;
          if(toupper(entrada[i]) != toupper(letra_inicial))
            frase_valida = 0;
        }
        else if(entrada[i] == ' '){
          primeira_letra=1;
        }
      }
    }
    if(entrada[0] != '*'){
      if(frase_valida && achou_letra_inicial)
        printf("Y\n");
      else
        printf("N\n");
    }
  }while(entrada[0] != '*');
  return 0;
}
