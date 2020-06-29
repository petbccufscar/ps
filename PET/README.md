# Exercício URI 1070 - Seis Números Ímpares.
> O exercício 1070 tem por objetivo ler um valor X (inteiro e positivo) e imprimir os próximos 6 números ímpares consecutivos, um valor por linha, incluindo X caso ele seja ímpar.

Eu havia dividido esse exercício em duas partes: ler e conferir as propriedades de X, e imprimir os valores ímpares consecutivos a X. Contudo, o site URI dava que meu método de análise de X continha erros, mesmo eu tendo testado ele diversas vezes e ele funcionava perfeitamente no Visual Studio Code. Sendo assim, eu tive que simplificar ao máximo essa primeira parte do código para que o corretor do URI aceitasse o envio como correto. Portanto, irei postar aqui as duas formas que fiz, sendo a primeira a mais complexa que não foi aceita.

#### Primeira Parte: lendo e conferindo as propriedades de X.
* Nessa etapa eu decidi que a melhor maneira de conferir as propriedades de X seria definindo um variavel booleana que assumiria valor true quando todas as condições fossem atendidas. Esse código não foi aceito pelo URI, mesmo estando OK, ele apresentava "Wrong Answer 60%", contudo não mostrava os motivos dos erros. Optei por expor esse trecho de código, pois acredito que ele é bastante funcional para caso fosse necessário conferir as propriedades de X.
~~~python
condicoesX = False #Usando essa variável para ter controle sobre as condições de X (estritamente inteiro positivo);
while condicoesX == False: #Loop para que esses passos se repitam até que X atenda todas as condições;
    try:  #Usando try para conferir que o valor digitado seja um número e não um caracter, e evitando o encerramento precoce do programa em caso de caracter;
        x = int(input("Digite um número inteiro POSITIVO, por favor: ")) #Lendo X;
        if x < 0:  #Verificando se X é estritamente positivo;
            print("O número digitado é negativo!")
        else:
            condicoesX = True #Caso as condições de X sejam atendidas, o loop while é finalizado;
    except ValueError:
        print("Você digitou um valor inválido") #Essa linha se refere ao caso de um caracter inválido ter sido atribuído a X;
~~~

* Tornando o mais simples possível, apenas para atender os processos de correção do URI.
~~~python
x = int(input())#Apenas lendo x, sem conferir qualquer propriedade, partindo da hipótese de que X sempre seja inteiro e positivo;
~~~

#### Segunda parte: imprimindo os valores ímpares.
* Nessa etapa, decidi que a melhor forma para definir os 6 ímpares consecutivos a X era armazenando-os em um array, dessa forma eu conseguiria controlar a quantidade de números a serem impressos através da manipulação do comprimento do array e conseguiria imprimi-los em cada linha mais facilmente.
~~~python
impares = [] #Criando um array para futuramento atribuir os valores ímpares a ele;
while (len(impares)) < 6: #Criando um loop que se relaciona com o array "impares" para poder definir o limite(nesse caso 6 números) de impares a serem impressos posteriormente;
    if (x % 2) != 0:  #Verificando se X é ímpar, se sim ele é atribuido a "impares";
        impares.append(x)
    x = x + 1  #Aumentando o valor de X ao passo de uma unidade;
for i in impares:  #Utilizando um loop for para pecorrer cada valor presente em "impares" e imprimi-lo, estritamente em linhas separadas;
    print(i)
~~~


# Exercício URI 1142 - PUM.
> O objetivo desse programa é ler um número N, inteiro e positivo, esse N é o número de sentenças pré-definidas que serão impressas;

Novamente, eu optei por dividir esse exercício em duas parte: ler e conferir as propriedades de N, e imprimir as sentenças pré-definidas, conforme os valores de N. Analógo ao código do exercício 1070, o corretor do URI não aceitou a primeira parte do meu código.

#### Primeira parte: lendo e conferindo as propriedades de X.
* Nessa etapa eu fiz o mesmo processo do exercício 1070, pois as condições eram iguais, logo não vi necessidade em mudar um bloco de código que funcionava perfeitamente (não levando em conta o processo de correção do URI).
~~~python
condicoesN= False #Usando essa variável para ter controle sobre as condições de N (estritamente inteiro positivo);
while condicoesN == False: #Loop para que esses passos se repitam até que N atenda todas as condições;
    try:  #usando try para conferir que o valor digitado seja um número e não um caracter, e evitando o encerramento precoce do programa em caso de caracter;
        n = int(input("Digite um número inteiro POSITIVO, por favor: ")) #Lendo N;
        if n < 0: # Verificando se N é estritamente positivo;
            print("O número digitado é negativo!")
        else:
            condicoesN = True #Caso todas as condições de N sejam atendidas, o loop while é finalizado;
    except ValueError:
        print("Você digitou um valor inválido") #Essa linha se refere ao caso de um caracter inválido ter sido atribuído a N;
~~~

* Tornando o mais simples possível, apenas para atender os processos de correção do URI.
~~~python
n = int(input())#Apenas lendo N, sem conferir qualquer propriedade;
~~~

#### Segunda parte: imprimindo as sequências pré-definidas.
* Nesta etapa optei por utilizar de variáveis auxiliares que assumiriam novos valores conforme as sentenças iam sendo impressas e variando de acordo com o valor de N.
~~~python
x = 1 # Atribuindo o valor 1 a X para usar a variável no loop while até atingir o valor de N(valor correspondente as linhas que devem ser impressas);
#As variáveis a,b e c serão usados para impressão das linhas e assumiram valores crescentes em passo 4, mesma variação apresentado no exemplo dado;
a = 1
b = 2
c = 3
while x <= n: # Loop para ter controle sobre a quantidade de linhas de output que deveme ser impressas;
    print (str(a) + " " + str(b) + " " + str(c) + " PUM") #Convertendo as variáveis para string impede que a função print interprete o parâmetro dado como uma expressão, utilizei de strings com espaços para separar cada valor de variável;
    a += 4 #Fazendo a variação, de passo 4, com atribuição expandida para deixar o código mais limpo;
    b += 4
    c += 4
    x += 1 #Variando o X em passo 1 para definir o quantidade exata de linhas de output a serem impressas;
~~~
