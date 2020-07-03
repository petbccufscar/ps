O objetivo do exercício 1140 do URI é saber se uma frase é Tautograma, ou seja, todas as palavras de uma frase começam com a mesma letra. Não importando se a mesma letra é maiúscula ou minúscula.

Inicialmente o algoritmo recebe uma frase através do comando `fgets`:
```c
fgets(entrada, sizeof(entrada), stdin); 
```
* O `fgets` é similar ao comando `scanf`, mas se difere, principamente, pela possibilidade de receber espaços em branco(' ') em uma única variável, nesse caso "entrada" é o nome da variável que recebe a frase. 

Após a primeira frase ser recebida um laço de repetição `while` é criado, para descobrir se cada frase é ou não um tautograma. 
```c
while(entrada[0] != '*')
```
* Se a primeira letra da frase é um  '*'(asterisco),  o laço é interrompido e o programa terminado, pois essa é a condição de parada descrita pelo enunciado.

Agora é iniciada, dentro do laço `while`, a lógica principal do algoritmo que consiste nos seguintes passos:

1. Criar um  laço de repetição `for` para tratar as palavras recebidas,
    ```c
    for (i = 0; i < strlen(entrada); i++)
			entrada[i]=tolower(entrada[i]);
    ```
	* Esse laço percorre todas as letras da frase, deixando-as minúsculas com a função `tolower()` que é importada de uma biblioteca padrão C através do `ctype.h`.
	* Assim, uma mesma letra não será diferente no caso de serem maiúscula e minúscula (ex: f = F), concordando com uma das condições do problema. 

2. Iniciar uma flag com 1(verdadeiro) para sinalizar se a frase é ou não um tautograma,
    ```c
    flag = 1;
    ```
    * Essa flag é iniciada em toda nova iteração dentro do laço de repetição `while`, para realizar as operações de cada iteração separadamente, ou seja, não influenciar no resultado de outra frase.   

3. Iniciar outro laço de repetição `for` para percorrer a frase,
    ```c
    for (i = 1; i < strlen(entrada); i++)
    ```
	* Esse é o laço  mais importante do problema, pois é nele que iremos verificar se a frase é um tautograma. 

4.  Dentro do laço anterior, verificar se uma letra é o inicio de uma palavra para compara-la à primeira letra da frase.
    ```c
    if(entrada[i-1] == ' ' && entrada[0]!=entrada[i]){
				flag=0;
    ```
	* Com o comando if, verificamos primeiro se o caracter anterior `entrada[i-1]` é um espaço em branco. Se sim, quer dizer que a letra atual entrada[i] é o inicio de uma palavra. 
	* Então seguimos para a outra comparação, para verificar se essa letra inicial `entrada[i]` é diferente da primeira letra da frase `entrada[0]`.
	* Se a letra inicial de uma palavra encontrada é diferente da primeira letra da frase, a flag de sinalização recebe 0(falso).

5. Após o algoritmo percorrer todo o laço `for` e verificar todas as primeiras letras de cada palavra da frase, verificamos a flag.
    ```c
	if(flag)
		printf("Y\n");
	else
		printf("N\n");
    ```
	* Se a flag for 1 a frase é um tautograma e a saída do algoritmo exibe  "Y" 
	* Se a flag for 0 a frase não é um tautograma saida exibe "N" .

6. O algoritimo recebe a próxima frase com o comando `fgets` novamente, e o primeiro laço de repetição  `while` é repetido, até que a frase recebida seja igual a '*' e o programa seja encerrado.
 