## Exercício 1142

Primeiramente é necessário declarar uma variavel N do tipo inteiro, para receber um valor atribuido pelo usuário(número de linhas), e uma variavel i também do tipo inteiro, que vai funcionar como contador, e uma variavel aux que funcionará para ajustar os valores em cada linha do printf inicializada no valor 1.

Com o comando scanf, o programa vai ler a entrada N após o usuario digita-la e pressionar a tecla **Enter**.

Após isso, o programa entrará em um loop de N repetições do tipo **FOR** (realizado pelo contador i), onde será impresso os valores de aux, aux+1, aux+2 e a palavra "PUM", após um ciclo, conforme demonstrada no exemplo de entrada e saída do exercício, percebemos que a diferença entre o primeiro elemento de 2 linhas consecutivas é de 4 unidades, por isso ao fim de cada ciclo, somamos 4 unidades ao valor de aux.

Assim, o cíclo irá imprimir o total de linhas digitadas com a sequência da forma desejada.
