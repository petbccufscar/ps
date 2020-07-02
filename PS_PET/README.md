# Balanço de Parênteses I (#1086)

A implementação da solução deste problema, em termos de código, é relativamente simples. O grande desafio é compreender o **conceito** por trás do problema, e entender como as **convenções utilizadas** garantem uma resolução válida.

Resumidamente, o enunciado nos pede um programa que verifique se os parênteses em uma expressão matématica fornecida foram empregados de maneira correta.

As seguintes condições são as mais importantes para o entendimento do problema:

1.  **"[...]todo parênteses que fecha deve ter um outro parênteses que abre correspondente e não pode haver parênteses que fecha sem um prévio parenteses que abre[...]"**

2. **"[...]a quantidade total de parenteses que abre e fecha deve ser igual."**

De uma maneira intuitiva, nós já utilizamos essas condições para achar pares de parênteses que abrem e fecham de maneira correta. Entretanto, é necessário explicitar isso em forma de código para criarmos um algoritmo.
## Explicação da solução
A solução proposta analisa a expressão da esquerda para a direita e  utiliza uma variável auxiliar inteira denominada **aux** para armazenar informações  de parênteses que abrem e fecham, com as seguintes convenções:

* **incrementando aux**: indica que um parênteses que abre '**(**' foi encontrado
* **decrementando aux**: indica que um parênteses que fecha '**)**' foi encontrado

Ao efetuar as ações descritas acima enquanto analisamos a expressão da direita para a esquerda para identificar os parênteses, a variável **aux** assume valores que possuem os seguintes significados:
* **aux > 0**:  indica o número de parênteses que foram abertos mas não foram fechados **até o momento**
* **aux == 0**:  indica que, **até aquele momento**, todos os parênteses que foram abertos também foram fechados
* **aux == -1 **:  indica um parênteses que foi fechado sem que antes existisse seu par de parênteses aberto **(condição que torna expressão inválida)**
#### Exemplo:
**((2 + 5) x 56 + 7) x (60 + 81) + 2) * 56(**

* Começamos com **aux==0**
* Encontramos 2 parênteses que abrem, incrementando aux duas vezes (**aux == 2**).
* Após isso, encontramos 2 parênteses que fecham e decrementamos aux duas vezes (**aux==0**).
* Encontramos 1 parênteses que abre, incrementando aux uma vez (**aux == 1**).
* Encontramos 1 parênteses que fecha, decrementando aux uma vez (**aux == 0**).

Até então temos **aux==0**, que significa que **todos os parênteses abertos foram fechados de fato até o momento**. Porém, posteriormente nos deparamos com um problema a se considerar:

* Encontramos 1 parênteses que fecha, decrementando aux uma vez (**aux == -1**).

**O próximo parênteses seria um que abre. Porém se simplesmente incrementarmos aux, iremos obter aux==0 com um significado diferente do proposto, visto que o parênteses que fecha apareceu antes de seu par que abre, violando a condição 1 do enunciado.**

Para resolver isso, **em nenhum momento, podemos prosseguir com a análise da expressão caso aux seja igual a -1**, já que é uma violação da condição que define uma expressão como válida.

Assim, devemos parar com a análise e obtemos **aux==-1**, verificando que isso torna a expressão inválida.

Nesse sentido, conclui-se que para que uma expressão seja válida, é necessário que **aux** seja igual a 0, sem que em nenhum momento da análise **aux** tenha sido igual a -1.

No caso de uma outra análise que nos dê um valor de **aux > 0** no final, significa que temos  parênteses que abrem e que não foram fechados, tornando também a expressão inválida. Nessa situação, a análise pode ocorrer até o final, pois o problema descrito anteriormente **(violação da condição 1)** não ocorreria.

#### Exemplo:
**((8 + 21) * 95 (**

Nesse caso, o valor final de **aux** após analisar toda a expressão seria aux == 2, indicando que existem 2 parênteses abertos que não fecham, tornando a expressão inválida.

## Explicação do código

No início da função **main** são definidas algumas váriáveis necessárias ao nosso programa. Dentre elas estão **entrada** (buffer de entrada de dados), **tam** (tamanho máximo do buffer de entrada). Inicialmente utiliza-se **malloc** para alocar um espaço para a entrada inicial.

```c
char *entrada;
size_t tam;
tam = 1005;
entrada = malloc(sizeof(char) * tam);
```

 Após isso, temos um **while** mais externo servirá para ler as diversas expressões
da entrada padrão e armazená-la em **entrada** através da função **getline**.

```c
while(getline(&entrada, &tam, stdin) != EOF){
```

Dentro deste **while** há um laço mais interno onde reside a lógica principal do programa. Esse **while** servirá para percorrer o vetor **entrada**, a fim de encontrar os tipos de parênteses e efetuar os respectivos incrementos e decrementos na variável inteira **aux**, que inicia-se com 0. Também temos a variável inteira **i** que servirá como índice para iterar sobre os caracteres de **entrada**.

```c
  int aux, i;
  aux = 0;
  i = 0;
```  

A condição deste **while** indica que o vetor **entrada** será percorrido enquanto **aux** for maior ou igual a 0 e enquanto não tiver lido o caractere especial **/0**, que indica o fim da cadeia de caracteres. Em outras palavras, o laço somente será interrompido quando **aux** for igual a -1, indicando uma **violação da condição 1 do enunciado**, ou então quando chegar no final da expressão.  

```c
  while(aux >= 0 && entrada[i] != '\0'){
    if(entrada[i] == '('){
      aux++;
    }
    else if(entrada[i] == ')'){
      aux--;
    }
    i++;
  }
```
Dentro desse laço, verificamos que existem duas condições. A primeira verifica se o caractere que está sendo lido é um parênteses que abre. Nesse caso, como explicado anteriormente, deve-se incrementar a variável **aux**.

Já a outra condição verifica se o caractere é um parêntesis que fecha. Nessa situação, deve-se decrementar a variável **aux**.

No final do laço incrementa-se o índice **i**.

```c
if(aux == 0)
  printf("correct\n");
else
  printf("incorrect\n");
free(entrada);
entrada = malloc(sizeof(char) * tam);   
```
Após o programa sair do laço anterior, verifica-se se a variável **aux** é igual a zero. Caso seja, imprime-se a palavra correct. Caso contrário, a palavra incorrect vai para a saída padrão, como solicitado pelo enunciado do problema.

Por fim, utiliza-se o free para tornar disponível o espaço na memória apontado por **entrada**, e outro espaço é alocado para **entrada** para a próxima leitura do **while** mais externo.


# Flores Florescem da França (#1140)

O entendimento da resolução deste problema é simples e intuitivo. A maior dificuldade se dá em formular um código que coloque esse entendimento abstrato em termos práticos de um programa em C.

De maneira geral, o enunciado pede que verifiquemos se uma frase pode ser classificada como um tautograma ou não.

Um tautograma é definido como:

* **"[...] um caso especial de aliteração, que é a ocorrência da mesma letra no início de palavras adjacentes."**

De maneira mais simples, é preciso determinar se a frase fornecida possui todas suas palavras iniciadas com a mesma letra.

## Explicação da solução
Intuitivamente, a solução proposta percorre a frase da esquerda para a direita, analisando cada caractere, identificando o início de uma palavra e **comparando a primeira letra de cada palavra com a primeira letra da primeira palavra da frase.**

Caso encontre qualquer palavra cuja primeira letra seja diferente da primeira letra da primeira palavra, o programa utliza uma mudança no valor de uma variável para indicar que a frase não é um tautograma, parando de percorrer a frase.

Caso a frase seja percorrida sem que o valor dessa variável mude, a frase é classificada como tautograma.

## Explicação do código
Antes de entrar em detalhes de código, é interessante explicar o significado atribuído a algumas variáveis importantes, bem como suas funções:


* **(int) primeira_letra**: variável inteira usada para indicar se o caractere que será analisado deverá ser interpretado como a primeira letra de uma palavra. O valor 1 indica que o programa deve interpretar a próxima letra como a primeira letra de uma nova palavra. O valor 0 indica que a próxima letra não é a primeira letra de uma nova palavra.
* **(int) achou_letra_inicial**: variável inteira usada para indicar se o programa já encontrou a primeira letra da primeira palavra da frase (caractere que não seja um espaço). O valor 1 indica que encontrou essa letra inicial. O valor 0 indica que ainda não encontrou.
* **(int) frase_valida**: variável inteira usada para indicar se a frase percorrida é um tautograma ou não. O valor 1 indica que a frase é um tautograma. O valor 0 indica que não é.
* **(char) letra_inicial**: variável que armazena a primeira letra da primeira palavra da frase e servirá de referência para comparações com outras palavras.

No início da função **main** são definidas algumas váriáveis necessárias ao nosso programa. Dentre elas estão o ponteiro **entrada** (aponto para buffer de entrada de dados) que é iniciado com valor NULL, **tam** (tamanho máximo do buffer de entrada), e as variáveis **frase_valida**, **primeira_letra**, **i** (contador) e **achou_letra_inicial**.

```c
int main(){
  char *entrada = NULL;
  size_t tam;
  tam = 1005;
  int frase_valida, primeira_letra, i, achou_letra_inicial;
  char letra_inicial;
```
Depois disso, existe um laço **do{} while;** que servirá para ler várias entradas de frases. No início desse laço, existe um **if** para verificar se a variável entrada possui o valor diferente de **NULL**. Caso essa condição seja satisfeita, o programa libera o espaço alocado na memória apontado pelo ponteiro entrada através da função **free**, garantindo que o espaço no buffer de entrada seja liberado corretamente a cada iteração desse laço.

```c
do{
  if(entrada != NULL)
    free(entrada);
```

Após essa verificação, o programa utiliza a função **malloc** para alocar um espaço na memória que será utilizado como um buffer de entrada, e a função **getline** para ler a linha inteira da entrada padrão do programa (lê a frase, em outras palavras), passando as variáveis **entrada**, **tam**, e passando também o ponteiro **stdin**, que faz a função ler da entrada padrão do programa.

Nas linhas seguintes, são inicializadas as variáveis **achou_letra_inicial** com valor igual a 0 indicando que a primeira letra da frase não foi encontrada, **primeira_letra** com valor igual 1 indicando que a próxima letra a ser encontrada será a primeira letra de uma palavra, e a flag **frase_valida** que começa com valor 1 e irá mudar para 0 assim que se encontre uma palavra que torne a frase inválida.

```c
entrada = malloc(sizeof(char)*tam);
getline(&entrada, &tam, stdin);

achou_letra_inicial = 0;
primeira_letra=1;
frase_valida = 1;
```

Depois disso, o programa utiliza um **for** para percorrer a frase. A condição desse for indica que enquanto não for encontrado um caractere **\0** ou **\n** no vetor entrada, e enquanto a flag **frase_valida** estiver com o valor igual a 1, a frase continuará sendo percorrida. Em outras palavras, o programa sairá dessa laço **quando chegar no final da frase** ou quando o **valor de frase_valida for igual a zero**.

```c
for(i=0; entrada[i] != '\0' && entrada[i] != '\n' && frase_valida == 1; i++)
```

No início desse **for** existe uma condição que serve para verificar se o programa achou um primeiro caractere da frase que não seja um espaço, e sim uma letra. Para isso, é necessário verificar se o valor da variável **achou_letra_inicial** até o momento é igual a zero, e se o caractere atual **entrada[i]** é diferente de um espaço. Caso isso seja verdade, muda-se o valor da variável **achou_letra_inicial** para 1, e armazena-se essa primeira letra encontrada na frase na variável **letra_inicial** que será utilizada nas futuras comparações com as letras iniciais das outras palavras na frase.

```c
  if(achou_letra_inicial == 0 && entrada[i] != ' '){
    achou_letra_inicial = 1;
    letra_inicial = entrada[i];
  }
```

Nas linhas seguintes, há outro **if** onde serão executadas outras condições caso a primeira letra da frase tenha sido encontrada.


 Devemos lembrar que cada caractere do vetor **entrada** pode ser uma letra ou um espaço. Para descobrirmos se o caractere é de fato a primeira letra da palavra, precisamos distinguir , de alguma forma, a primeira letra da palavra, com as demais letras dessa mesma palavra.

A primeira condição verifica se o próximo caractere esperado é a primeira letra de uma palavra, utilizando a variável **primeira_letra**, e se o caractere é de fato uma letra e, não um espaço.

```c
  if(achou_letra_inicial == 1){
    if(primeira_letra == 1 && entrada[i] != ' '){
```

Essa variável **primeira_letra** irá mudar para 1 todas as vezes que um espaço é encontrado na frase. Isso ocorre, pois o espaço em uma frase indica a separação entre uma palavra e outra. Mudando-se essa variável de zero para 1, temos uma forma de saber que houve uma separação entre palavras e, quando for encontrada uma próxima letra, será a primeira letra dessa próxima palavra. Essa mudança ocorre no próximo **else if**.

```c
  else if(entrada[i] == ' '){
    primeira_letra=1;
  }
```

Assim, todas as vezes que **primera_letra** for igual a 0, o programa saberá que os próximos caracteres a serem analisados não serão a primeira letra de uma palavra. Com essa diferenciação, é possível determinar o que será feito em cada um dos casos.

Ateriormente, no primeiro **if**, o valor da variável **primeira_letra** deve ser 1 e o caractere **entrada[i]** deve ser diferente de espaço. Caso isso seja verdadeiro, muda-se novamente o valor de **primeira_letra** para zero, indicando que os próximos caracteres não serão a **primeira letra** de uma palavra.

Finalmente, existe outro **if** para  verificar se essa primeira letra da palavra analisada é diferente da primeira letra da primeira palavra encontrada na frase (variável **letra_inicial**). Caso as letras sejam diferentes, a flag **frase_valida** tem seu valor alterado para zero, indicando que a frase não é um tautograma. Caso sejam iguais, o valor de **frase_valida** permanece inalterado (igual a 1).

```c
    if(primeira_letra == 1 && entrada[i] != ' '){
      primeira_letra = 0;
      if(toupper(entrada[i]) != toupper(letra_inicial))
        frase_valida = 0;
    }
```

Dessa maneira, termina-se o **for** que percorre a frase. No final desse laço, existe uma última verificação que serve para imprimir a saída esperada analisando as variáveis **frase_valida** e **achou_letra_inicial**. Essa verificação só é feita caso a entrada não tenha como primeiro caractere o asterisco ('*') que, de acordo com o enunciado, deve servir para finalizar a leitura das frases na entrada do programa.

```c
  if(entrada[0] != '*'){
    if(frase_valida && achou_letra_inicial)
      printf("Y\n");
    else
      printf("N\n");
  }
```

No final, o fim do laço mais externo é alcançado. O programa apenas sairá desse laço quando receber o caractere * na entrada. Caso contrário, continuará analisando cada frase recebida na entrada.

```c
}while(entrada[0] != '*');
```
