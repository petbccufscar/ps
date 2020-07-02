# Exercício 1087 - Dama

<div style="text-align:center"><img src="https://resources.urionlinejudge.com.br/gallery/images/problems/UOJ_1087.png" alt="Tabuleiro" /></div>

- # O que é o problema da Dama?
    O problema da dama, é um problema relacionado a determinar quantos movimentos vão ser necessários para mover a peça "Dama" de uma posição inicial para uma posição final.
    Dentro de um tabuleiro 8x8, ou seja, com 64 posições compostas por uma coordenada vertical e uma coordenada horizontal, sendo que ambas essas coordenadas vão de 1 a 8.
    A peça "Dama", em cada um de seus movimentos, pode se mover de 1 a 8 posições, porém apenas em apenas uma direção por movimento, isto é, verticalmente, horizontalmente ou na diagonal.
    O objetivo do problema é, portanto, determinar qual o mínimo de movimentos que a peça "Dama" deve realizar para ir de uma posição do tabuleiro até outra.

- # O que é a entrada do problema?
    A entrada do programa é composta por uma ou mais linhas, cada qual corresponde a um caso de teste.
    Cada caso de teste é composto por quatro números inteiros separados por um espaço em branco entre si.
    Em cada caso de teste, os dois primeiros números são as coordenadas iniciais da Dama e os dois números seguintes são as coordenadas da posição em que se quer chegar.
    Um caso de teste em que todas as coordenadas são 0 corresponde ao encerramento dos casos de teste, isto é, o fim da execução do programa.

- # O que é a saída do problema?
    Para cada caso de teste, o programa apresenta uma linha de saída de valor 0, 1 ou 2, que corresponde ao número de movimentos necessários para que a Dama seja movida da posição correspondente às coordenadas iniciais até a posição correspondente às coordenadas finais.
    No caso de teste em que as coordenadas são todas 0, não é apresentada saída, apenas encerra-se a execução.

- # Qual é a lógica da solução?
    Para resolver o problema, segue-se o príncipio de que independente da posição inicial, a "Dama" consegue mover-se a qualquer outra posição do tabuleiro em no máximo 2 movimentos, já que:
    Para mover-se para a mesma posição em que está, ela não precisa realizar nenhum movimento, portanto, 0 movimentos;
    Para mover-se para uma posição que esteja em sua linha horizontal, em sua linha vertical ou em uma de suas diagonais, ela só precisa de 1 movimento;
    Para mover-se a qualquer outra posição, ela primeiro precisa se mover de modo a ficar na horizontal,vertical ou diagonal dessa posição, com 1 movimento, e então, em mais 1 movimento ela alcança a posição final, isto é, 2 movimentos.
    Então, para determinar quantos movimentos vão ser necessários para ir de uma posição inicial para uma posição final, basta identificar qual desses casos descritos se aplica.

- # Como o código faz essas checagens para aplicar essa solução?
    O código lê o primeiro caso de teste, em seguida, para aplicar essa lógica de resolução, o código primeiro decompõe cada caso de teste em uma posição inicial e uma posição final.
    ```c
    int x1, x2, y1, y2; // variaveis de coordenadas
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    ```
    Em seguida, ele compara as duas posições de maneira que:
    Se as duas posições são iguais, não é necessário nenhum movimento, então a resposta é 0;
    ```c
    if (x1 == x2 && y1 == y2) // caso as coordenadas sejam iguais para os pontos inicial e final
    {
        printf("0\n");
    }
    ```
    Se as duas posições são diferentes, mas possuem o mesmo valor de coordenada vertical ou o mesmo valor de coordenada horizontal, corresponde a uma posição na linha vertical ou na linha horizontal, respectivamente, portanto, a resposta é 1;
    Se as duas posições são diferentes, mas a diferença entre os valores das posições verticais e a diferença das posições horizontais for igual, então a posição é uma diagonal, e portanto, a resposta é 1. Essa diferença é calculada pelo módulo da subtração;
    ```c
    // caso os pontos estejam respectivamente na linha horizontal, vertical ou diagonal
    else if ((x1 == x2 && y1 != y2) || (x1 != x2 && y1 == y2) || (x1 != x2 && y1 != y2) && (abs(x2 - x1) == abs(y2 - y1)))
    {
        printf("1\n");
    }
    ```
    Se a comparação entre as posições não se encaixa em nenhum dos casos anteriores, então serão necessários dois movimentos e a resposta é 2.
    ```c
    else // para qualquer outro caso
    {
        printf("2\n");
    }
    ```
    
    Ao final da comparação, o programa imprime a resposta e se prepara para ler o próximo caso de teste, até que seja fornecido o caso de teste composto apenas por 0s que indica o fim do programa.

# Exercício 1128 - Ir e Vir

- # O que é o problema do "Ir e Vir"?

    O problema "Ir e Vir" descreve uma situação em que há intersecções em uma cidade e estas intersecções podem ser ligadas por ruas de mão simples ou mão dupla.
    O desafio é, dado o número de intersecções e quais as ruas, ou seja, como as intersecções estão ligadas, determinar se é possível partir de qualquer intersecção e visitar qualquer outra intersecção, isto é, se cumpre o requisito de conexidade.
    Uma rua de mão simples entre duas intersecções A e B, significa que é possível ir de A até B. Uma rua de mão dupla entre A e B significa que é possível ir de A até B e de B até A.

- # O que é a entrada do problema?

    A entrada do programa é composta de 1 ou mais linhas, em que cada conjunto de linhas determina um caso de teste.
    Cada conjunto de linhas é composto por:
    Uma linha com dois inteiros N e M que correspondem ao número de intersecções e número de ruas respectivamente e M linhas com três números inteiros V, W e P, que correspondem à descrição de uma rua, que vai da intersecção V até a intersecção W e é de mão simples se P = 1 ou mão dupla se P = 2;
    Um caso de teste que se inicie por N e M iguais a 0 corresponde ao encerramento dos casos de teste, ou seja, o sinal de que a execução deve ser finalizada.
    
- # O que é a saída do problema?

    Para cada caso de teste, o programa imprime uma linha com o valor 1 caso seja possível, a partir das ruas fornecidas, partir de qualquer intersecção e visitar qualquer uma das outras intersecções e imprime 0 se não for possível.
    No caso de teste de encerramento não é imprimida nenhuma saída, apenas finalizado o programa.
    
- # Qual é a lógica da solução?

    Para resolução do problema, utiliza-se a premissa de que se é possível alcançar qualquer intersecção a partir da primeira intersecção e se é possível alcançar a primeira intersecção à partir de qualquer outra, então o requisito de conexidade é atendido.
    Portanto, a partir da primeira intersecção, verifica se todas as outras intersecções são alcançáveis, em caso afirmativo, verifica também se a partir de todas as intersecções é possível alcançar a primeira intersecção. Caso também seja possível, então o requisito de conexidade é cumprido.
    
- # Como o código faz essas checagens para aplicar essa solução?

    O código lê a primeira linha do primeiro caso de teste, para em seguida aplicar a lógica da resolução.
    ```C
    scanf("%d %d", &N, &M); //Le o numero de intersecções e de ruas
    ```
    A lógica é aplicada da seguinte forma:
    O código zera o vetor visitados nas N primeiras posições para prepará-lo para ser usado depois e também as NxN posições da matriz rua.
    ```C
    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= N; j++)
        {
            rua[i][j] = 0;
        }
        visitados[i] = 0;
    } // Zera o vetor de visitados e a matriz de ruas
    ```
    A partir do N e M lidos na primeira linha do caso de teste, lê as M linhas seguintes para preencher a matriz rua de modo que rua[V][W] = 1 indica que é possível ir da intersecção V até a intersecção W.
    ```C
    for (i = 1; i <= M; i++)
    {
        scanf("%d %d %d", &V, &W, &P);
        rua[V][W] = 1;
        if (P == 2) //Se P = 2 a rua é de mão dupla, então deve ser possível ir nos dois sentidos
            rua[W][V] = 1;
    }
    ```
    O código então chama a função Busca para a primeira intersecção. A função Busca preenche o vetor de visitados com o valor 1 nas posições correspondentes ás intersecções que são alcançáveis à partir da primeira posição.
    ```C
    Busca(1); //Chama a funcao recursiva de busca para a intersecção inicial, para preencher o vetor de visitados
    ```
    A chamada da função Busca é feita recursivamente até que não seja possível alcançar mais nenhuma intersecção diferente das já alcançadas.
    ```C
    void Busca(int ponto)
    { //Busca em profundidade
        int i;
        if (visitados[ponto] == 1) //Se a intersecção ja foi visitado, nada a ser feito
        {
            return;
        }
        else //Se nao, marca a intersecção como visitado e visita os pontos com que tem ligacao recursivamente
        {
            visitados[ponto] = 1;
            for (i = 1; i <= N; i++)
            {
                if (rua[ponto][i] && !visitados[i])
                    Busca(i); //Chamada recursiva da funcao, a partir de cada um dos pontos com qual o ponto eh ligado
            }
        }
    }
    ```
    Depois de terminar a chamada de Busca para a primeira intersecção, verifica se todas as primeiras N posições do vetor visitados tem valor 1, ou seja, se foi possível alcançar todas as intersecções a partir da primeira, em caso negativo, muda a variável de conexidade para falso e não executa o resto dos passos para este caso de teste.
    ```C
    for (i = 1; i <= N; i++)
    {
        if (!visitados[i])
        {
            conexidade = 0;
        }
    } //Ve se eh possivel chegar da intersecção inicial a qualquer outra intersecção
    ```
    Então, zera novamente as N primeiras posições do vetor visitados e em seguida inverte as ruas, isto é:
    Se rua[V][W] = 1 e rua[W][V] = 1, não faz nada;
    ```C
    if (rua[i][j] && rua[j][i])
    { //Se a conexao for nas duas direcoes, nao inverte
        continue;
    }
    ```
    Se rua[V][W] = 1 e rua[W][V] = 0, então rua [W][V] = 1 e rua[V][W] = 0;
    ```C
    else if (rua[i][j])
    {
        rua[j][i] = 1;
        rua[i][j] = 0;
    }
    else if (rua[j][i])
    {
        rua[i][j] = 1;
        rua[j][i] = 0;
    }
    ```
    Essa inversão é realizada para utilizar a mesma lógica de busca a partir da primeira intersecção, porém com as ruas que vão até a intersecção ao invés das que partem dela.
    Em seguida, executa novamente a função de Busca a partir da primeira intersecção.
    ```C
    Busca(1); //Busca agora se eh possivel chegar de qualquer ponto à intersecção incial
    ```
    Ao final da execução, isto é, quando a função é executada recursivamente até que não seja possível visitar nenhuma intersecção ainda não visitada, o vetor visitados estará com valor 1 nos índices das intersecções alcançadas.
    Se o vetor visitados tem valor 1 nas N primeiras posições, então conclui-se que o requisito de conexidade é cumprido, caso contrário, a váriável conexidade recebe o valor 0.
    ```C
    for (i = 1; i <= N; i++)
    {
        if (!visitados[i])
        {
            conexidade = 0;
        }
    } //Se eh possivel ir de qualquer intersecção para a intersecção inicial, possui requisito de conexidade
    ```
    Ao final, imprime-se o valor da variável conexidade, que iniciou com 1 e mudou para 0 caso o requisito não seja cumprido.
    Após imprimir, lê a primeira linha do próximo caso de teste, até que essa primeira linha seja composta por dois 0s, caso em que a execução é finalizada.
    ```C
    scanf("%d %d", &N, &M); // le a proxima entrada
    ```