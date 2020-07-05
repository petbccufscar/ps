#Explicação Exercicio 1120

O algoritmo desenvolvido começa com a importação de bibliotecas que serão utilizadas, como a **stdio.h** que permite que possamos utilizar funções de entrada e saída de dados, e a **string.h** que tem ferramentas que auxiliam na manipulação de strings. Temos a chamada da função que faz com que nosso programa rode, e que conterá todo codigo desse algoritmo.
```C
#include <stdio.h>
#include <string.h>

int main() {
```

Parte das variáveis que serão usadas estão declaradas a seguir:
- **n** é o digito que apresenta falha;
- **i** é utilizado para percorrer as posições do vetor que representam as sequências de números;
- **j** é utilizado para percorrer as posições do vetor que representa a saída do problema;
- **k** será o controle de um laço de repetição;
- **zero** contará quantos zeros aparecem na sequência;
- **count** verifica se tem mais de um valor ao menos para ser mostrado na saída;
- **snum** é a variável que receberá a sequência digitada pelo usuário.

```C
	int n, i, j, k, zero, count;
    char snum[101];
```
Para que o programa parasse quando tivesse a  entrada especificada no exercício, foi feito um laço que roda de forma infinita, mas devido a verificação de **n** igual a zero e(&&) **snum** na primeira possição igual a zero, quando verdadeira, ela executa um break, que força a  saída do laço anterior a ele.
```C
 	while(1){
		scanf("%d %s", &n, snum);
		if(n == 0 && snum[0] == '0') {
			break;
		}
```
E para armazenar a saída desejada, foi criado dentro deste laço a variável **cha**, e as demais variáveis, com exeção de **k**, foram iniciadas com zero.
```C
	char cha[101];
	
	i = 0;
	j = 0;
	zero = 0;
	count = 0;
```

Temos mais um laço que esta em loop infinito até que seja encontrado o "\0" da string **snum**, que tem um condicional para sua verificação, e um break que o tira do laço de repetição. Na linha cinco, temos a verificação do caracter de **snum** na posição **i** se ele é igual a **n** + 48, essa comparação de um número com um caracter é possivel, por causa da tabela ASCII, que converte a soma apresentada em um caracter da tabela, que na posição 48 até 58 são os números de 0 a 9, em formatado de caracter.

![](https://sites.google.com/a/liesenberg.biz/cjogos/_/rsrc/1259849455894/home/materiais-de-apoio/materiais-complementares/tabela-ascii/ascii.jpg)

Na linha seis, temos a atribuição de **i** em um. O else em seguida é para o caso em que um dígito de **snum** deve ser atribuido a **cha**. O condicional da linha dez é para **cont** ser incrementado em um, apenas uma vez. Na linha 14, é para ter a contagem de quantos zeros tiveram em **snum**, e por último temos o incremento de **i** e **j** em mais um.

```C
		while(1){
			if(snum[i] == '\0'){
				break;
			}
			else if(snum[i] == n + 48){
				i++;
			}
			else{
				cha[j] = snum[i];
				if(j == zero) {
					count++;
				}
				
				if(snum[i] == '0') {
					zero++; 
				}
				i++; 
				j++; 
			}
		}
```
Por fim, temos os condicionais que irão decidir qual será a saída do programa. Na linha um, temos a atribuição de "\0" a **cha** na última posição. Na linha dois, é a saída em que **j** é igual a zero, pois os dígitos digitados na entrada eram todos iguais ao dígito com defeito. Na linha cinco, é a situação em que tinha os dígitos com defeito seguido de vários zeros. Na linha oito, é a situação em que foi tirado apenas o número com defeito da sequência, para mostrar na dela o que é pedido, foi feito um laço com **k** igual a zero, pois **count** sempre será um, e então é imprimido caracter por caracter. Finalizando o algoritmo.
```C
		cha[j] = '\0';
		if(j == 0){ 
			printf("0\n");
		}
		else if(j == zero){ 
			printf("0\n"); 
		}
		else if(count > 0){
			for(k = count - 1; cha[k] != '\0'; k++){
				printf("%c", cha[k]);
			}
			printf("\n");
		}
	}
	return 0;
}
```
#Explicação Exercicio 1272

Analogamente ao exercicío 1120, a importação de bibliotecas e a primeira fução são as mesmas. Como seg
ue a baixo.
```C
#include <stdio.h>
#include <string.h>

int main() {
```
As variáveis que serão utilizadas estão sendo declaradas, e são:
- **n** a entrada que informa a quantidade de frases que serão digitadas pelo usuário
- **i** e **j** que são controladores para a quantidade de repetições de laços;
- **cont** é um auxiliar para determinar a posição no vetor que um caracter será inserido;
- **palavras** é uma string que conterá a frase digitada pelo usuário;
- **codigo** é uma string que será a mensagem decodificada;
- **esp** que é abreviamento de espaçamento, tem o conteúdo de um espaço em branco.

```C
	int n, i, j, cont;
	
	char palavras[52];
	char codigo[52];
	
	char esp = ' ';
```
Teremos respectivamente no código a leitura da quantidade de frases a serem lidas, um laço de repetição que irá se repetir **n** vezes e a leitura da frase.

```C
	scanf("%d\n", &n);

	for(i = 0; i < n; i++) {

		fgets(palavras, 52, stdin);
```

Essa parte do código é a principal. Na linha um, temos um laço que irá até o tamanho de **palavras** menos um, por causa do final da string ser o "\0" não utilizamos o tamanho total, verificamos de caracter para caracter. Na linha três, temos a condição de que o caracter de **palavra** na posição **j** seja diferente de **esp** e(&&) o  anterior seja igual a **esp**, logo identificamos a primeira letra de uma palavra, mas temos a situação em que **j** igual a zero, teria o problema de que ao verificar a posição anterior a zero, acessaríamos um dado incorreto, para resolver, colocamos um ou(||) entre **j** igual a zero e **j** diferente, assim quando **j** for zero responderia com um valor verdadeiro, desta forma solucionando o problema. Na linha cinco, tendo a expressão toda como verdadeira, atribuimos em **codigo** na posição **cont** o caracter correto, e em seguida atribuimos em **cont** mais um. Na linha nove atribuimos a **codigo** na última posição o "\0", para sinalizar o fim da string. Na linha 11, mostramos na tela a variável **codigo** com a mensagem secreta, finalizando o algoritmo.
```C
		for(j = 0, cont = 0; j < strlen(palavras) - 1; ++j) {
		    
			if(palavras[j] != esp && (!j || palavras[j - 1] == esp)) {

			    codigo[cont++] = palavras[j];
			 
			}
		}
		codigo[cont] = '\0';
		
		printf("%s\n", codigo);
	}
	
	return 0;
}
```
