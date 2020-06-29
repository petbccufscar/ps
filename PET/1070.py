x = int(input())

impares = [] #Criando um array para futuramento atribuir os valores impares a ele;
while (len(impares)) < 6: #Criando um loop que se relaciona com o array "impares" para poder definir o limite(nesse caso 6 números) de impares a ser impresso posteriormente;
    if (x % 2) != 0:  #Verificando se X é ímpar, se sim ele atribuido a "impares";
        impares.append(x)
    x = x + 1  #Aumentando o valor de X ao passo de uma unidade;
for i in impares:  #Utilizando um loop for para pecorrer cada valor presente em "impares" e imprimi-lo, estritamente em linhas separadas;
    print(i)