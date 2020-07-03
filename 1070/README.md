## Exercício 1070

Primeiramente é necessário declarar uma variavel X do tipo inteiro, para receber um valor atribuido pelo usuário, e uma variavel i também do tipo inteiro, que vai funcionar como contador.

Com o comando scanf, o programa vai ler a entrada X após o usuario digita-la e pressionar a tecla **Enter**.

Após isso, o programa entrará em um condicional com loop de 6 repetições do tipo **FOR** (realizado pelo contador i), onde será averiguada se a entrada é um número par; Caso seja um número par, será adicionada uma unidade ao número para descobrimos seu primeiro sucessor ímpar, e imprimirá este valor na tela.

Em seguida, após o primeiro valor ímpar ser impresso na tela, será adicionado mais uma unidade, e verificaremos novamente após a adição
se o número é par ou impar. Caso seja par após a adição, cairá em outro if para adicionar mais uma unidade para torna-lo ímpar
e irá imprimi-lo em sequência.

Isto será feito para imprimir os 6 primeiros números impares, após ser informado um número par.

Se a entrada for ímpar (caso **Else**), basta adicionarmos 2 a cada ciclo do loop, pois todo ímpar pode ser escrito como um ímpar adicionado de
duas unidades, e assim será impresso na tela os 6 primeiros números ímpares, a partir de um número ímpar informado.

Isto será feito para imprimir os 6 primeiros números impares, após ser informado um número ímpar.
