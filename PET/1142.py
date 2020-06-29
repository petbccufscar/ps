n = int(input())

x = 1 # Atribuindo o valor 1 a X para usar a variável x no loop while até atingir o valor de n(valor correspondente as linhas que devem ser impressas);
#As variáveis a,b e c serão usados para impressão das linhas e assumiram valores crescentes em passo 4, mesma variação apresentado no exemplo dado;
a = 1
b = 2
c = 3
while x <= n: # Loop para ter controle sobre a quantidade de linhas de output que deveme ser impressas;
    print (str(a) + " " + str(b) + " " + str(c) + " PUM") #Convertendo as variáveis para string impede que a função print interprete o parâmetro dado como uma expressão, utilizei de strings com espaços para separar cada valor de variável;
    a += 4 #Fazendo a variação, de passo 4, com atribuição expandida para deixar o código mais limpo;
    b += 4
    c += 4
    x += 1 #Variando o X em passo 1 para definir o quantidade exata de linhas de output a ser impressas;Ta