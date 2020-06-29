# Exercício 1087 - Dama
## Problema
O jogo de xadrez possui várias peças com movimentos curiosos: uma delas é a dama, que pode se mover qualquer quantidade de casas na mesma linha, na mesma coluna, ou em uma das duas diagonais, conforme exemplifica a figura abaixo:

 ![Peça dama](https://resources.urionlinejudge.com.br/gallery/images/problems/UOJ_1087.png)

O grande mestre de xadrez Kary Gasparov inventou um novo tipo de problema de xadrez: dada a posição de uma dama em um tabuleiro de xadrez vazio (ou seja, um tabuleiro 8 × 8, com 64 casas), de quantos movimentos, no mínimo, ela precisa para chegar em outra casa do tabuleiro?
Kary achou a solução para alguns desses problemas, mas teve dificuldade com outros, e por isso pediu que você escrevesse um programa que resolve esse tipo de problema.

### Entrada
A entrada contém vários casos de teste. A primeira e única linha de cada caso de teste contém quatro inteiros X1, Y1, X2 e Y2 (1 ≤ X1, Y1, X2, Y2 ≤ 8). A dama começa na casa de coordenadas (X1, Y1), e a casa de destino é a casa de coordenadas(X2, Y2). No tabuleiro, as colunas são numeradas da esquerda para a direita de 1 a 8 e as linhas de cima para baixo também de 1 a 8. As coordenadas de uma casa na linha X e coluna Y são (X, Y ).
O final da entrada é indicado por uma linha contendo quatro zeros.

### Saída
Para cada caso de teste da entrada seu programa deve imprimir uma única linha na saída, contendo um número inteiro, indicando o menor número de movimentos necessários para a dama chegar em sua casa de destino.

Exemplo de Entrada | Exemplo de Saída
-- |  ---
4 4 6 2 | 1
3 5 3 5 | 0
5 5 4 3 | 2
0 0 0 0 |

## Solução
A solução apresentada foi desenvolvida em linguagem C.

### Entrada
Inicialmente o código realizará a leitura das coordenadas iniciais (x1, y1) e finais (x2, y2) da peça dama. Dessa forma, temos a leitura de quatro inteiros: x1, x2, y1 e y2:

```c
scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
```

### Verificação do final da entrada
Como apresentado no problema, o final da entrada é indicado por uma linha contendo quatro zeros (0 0 0 0). Para realizar tal verificação, é necessário comparar os valores lidos de x1, y1, x2 e y2 com zero. Caso todos sejam 0, o código se encerra:

```c
if(x1==0 && y1==0 && x2==0 && y2==0){
      return 0;
}
```

### Saída
Tendo os valores de x1, x2, y1 e y2 armazenados, é necessário pensar na quantidade de casas que a peça dama pode se movimentar e em que situações ela realiza cada uma delas.
Como comentado no problema, a dama pode se mover qualquer quantidade de casas na mesma linha, na mesma coluna, ou em uma das duas diagonais, realizando 1 único movimento. Para se mover para qualquer outro destino, a dama realiza no máximo 2 movimentos, 1 na horizontal e 1 na vertical. Dessa forma, a dama pode realizar 0, 1 ou 2 movimentos para chegar ao destino final.

#### 0 movimentos
A dama realiza 0 movimentos somente quando permanece no mesmo lugar, ou seja,  quando a coordenada inicial é igual a coordenada final.

```c
if(x1==x2 && y1==y2){
      printf("0\n");
}
```

#### 1 movimento
Existem três possibilidades em que a dama realiza 1 único movimento para chegar ao seu destino:
1. Quando a posição inicial e final estão na mesma linha, ou seja, quando y1 = y2.
2. Quando a posição inicial e final estão na mesma coluna, ou seja, quando x1 = x2.
3. Quando a posição inicial e final estão na mesma diagonal. Podemos observar que quando isso ocorre, a distância verticial e horizontal da posição inicial da dama para a posição final, apresentam a mesma quantidade de casas. Assim, essa verificação é realizada da seguinte maneira: |x1-x2| = |y1-y2|. O módulo garante que os valores serão sempre positivos, pois estamos falando em distância.

```c
if(x1==x2 || y1==y2 || abs(x1-x2)==abs(y1-y2)){
      printf("1\n");
}
```

#### 2 movimentos
Quando ocorre qualquer caso que não esteja englobado nos casos comentados acima,  a dama realiza 2 movimentos para chegar ao seu destino, 1 movimento na horizontal e 1 movimento na vertical.

```c
else{
      printf("2\n");
}
```

# Exercício 1240 - Encaixa ou Não I
## Problema
Paulinho tem em suas mãos um pequeno problema. A professora lhe pediu que ele construísse um programa para verificar, à partir de dois valores inteiros A e B, se B corresponde aos últimos dígitos de A.

### Entrada
A entrada consiste de vários casos de teste. A primeira linha de entrada contém um inteiro N que indica a quantidade de casos de teste. Cada caso de teste consiste de dois inteiros A (1 ≤ A < 231 ) e B (1 ≤ B < 231) positivos.

### Saída
Para cada caso de entrada imprima uma mensagem indicando se o segundo valor encaixa no primeiro valor, confome exemplo abaixo.

Exemplo de Entrada | Exemplo de Saída
-- |  ---
4 |
5678690 78690 | encaixa
5434554 543 | nao encaixa
1243 1243 | encaixa
54 654 | nao encaixa

## Solução
A solução apresentada foi desenvolvida em linguagem C.

### Entrada
Inicialmente o código realizará a leitura de um inteiro n, que representará a quantidade de casos de teste, e  de inteiros positivos A e B. Como (1 ≤ A, B < 2³¹ ), eles serão do tipo long long int.

```c
scanf("%d", &n);
scanf("%lld %lld", &a, &b);
```

### Saída
Para realizar a comparação entre os últimos dígitos do número A e o número B, é necessário saber quantos caracteres o número B possui, permitindo armazenar a quantidade exata de caracteres de A que sejam iguais a quantidade de caracteres de B.

#### Int quantidade(long long int num)
A função realiza a contagem de caracteres de um número. A cada iteração do loop, o número passado por referência será dividido por 10, diminuindo 1 caractere do número total, e a variável quantidade, que armazena a quantidade de caractereres, será incrementada. O loop continuará enquanto restarem caracteres. Ao final, a variável quantidade é retornada.

```c
int quantidade(long long int num){
	int quantidade;

	while(num){
		num = num/10;
		quantidade++;
	}

	return quantidade;
}
```

#### Comparação entre os números
Para armazenar somente os n últimos dígitos de A, sendo n a quantidade de caracteres de B, iremos armazenar em A o resto da divisão de A por 10 elevado a quantidade de caracteres de B.
Para isso, utilizamos a função pow(x, y), que realiza x elevado a y e o operador %, que armazena o resto da divisão de dois valores.

```c
z = pow(10, quantidade(b));
a = a%z;
```

Finalmente realizamos a comparação do valor atual de A e B.

```c
if(a == b){
			printf("encaixa\n");
}else{
			printf("nao encaixa\n");
}
```
