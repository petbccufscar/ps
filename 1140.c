//Tautograma
#include <stdlib.h>
#include <stdio.h>

int main(){
  char *entrada = NULL;
  size_t tam;
  tam = 1005;
  int frase_valida;
  do{
    if(entrada != NULL)
      free(entrada);
    entrada = malloc(sizeof(char)*tam);
    getline(&entrada, &tam, stdin);
    int primeira_letra, i, achou_letra_inicial;
    char letra_inicial;
    //Flag para verificar se achou primeira letra
    achou_letra_inicial = 0;
    //Flag para verificar se está analisando a primeira letra da palavra
    primeira_letra=1;
    //Flag que verifica se a frase é um tautograma até então
    frase_valida = 1;
    //Percorre o vetor entrada até o final ou até achar uma palavra que faça com que a frase não seja tautograma
    for(i=0; entrada[i] != '\0' && entrada[i] != '\n' && frase_valida == 1; i++){
      //Se a flag indicar que não achou a primeira letra ainda mas o caractere analisado for diferente de um espaço (for uma letra)
      if(achou_letra_inicial == 0 && entrada[i] != ' '){
        //Flag passa a indicar que achou a primeira letra
        achou_letra_inicial = 1;
        //Letra inicial recebe a primeira letra da primeira palavra da frase e será utilizada nas comparações
        letra_inicial = entrada[i];
      }
      //Se a primeira letra foi encontrada
      if(achou_letra_inicial == 1){
        //Se o caractere analizado no meio da frase for a primeira letra de uma palavra
        if(primeira_letra == 1 && entrada[i] != ' '){
          primeira_letra = 0;
          //Se a letra inicial não for igual a primeira letra da palavra analisada
          if(toupper(entrada[i]) != toupper(letra_inicial))
            //Não é um tautograma
            frase_valida = 0;
        }
        //Caso o caractere no meio da frase for um espaço
        else if(entrada[i] == ' '){
          //Indica o começo de uma nova palavra (próximo caractere será a primeira letra de uma palavra)
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
