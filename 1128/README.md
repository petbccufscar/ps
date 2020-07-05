# URI 1128 - Ir e Vir
Nesse exercício é uma abstração para um problema de grafos, nele nos temos inicialmente 2 entradas ```N``` e ```M```, em que ```N``` é a quantidade de nos(intersecções) e ```M``` é a quantidade de conexões entre nós(número de ruas).

Cada rua tem sua própria descrição, dadas pelos números ```V```, ```W``` e ```P```, onde ```V``` e ```W``` indicam quais nós estão conectados; e ```P``` tem valor de 1 ou 2; se ```P = 1``` então a rua é de mão única, e vai de ```V``` para ```W```; se ```P = 2``` então a rua é de mão dupla, liga ```V``` e ```W```; e ```W``` e ```V```.

O objetivo é, a partir do grafo dado verificar se para cada dois nós, ```V``` e ```W```, existe uma conecção de  ```V``` para ```W``` e ```W``` para ```V```. 

Se o objetivo for válido para todos os nós do grafo então deveremos imprimir ```1```, se não imprimimos ```0```.
 - Exemplo de entrada com objetivo válido:
    - ```4 4```
    ```2 4 1```
    ```3 2 1``` 
    ```4 1 1```
    ```1 3 1```
     
    ![ex0](https://i.pinimg.com/750x/2c/f2/55/2cf255b0cfc45351713cb69b71d72b73.jpg)
 - Exemplo de entrada com objetivo inválido:
    - ```4 4```
    ```2 4 1```
    ```2 3 1``` 
    ```4 1 1```
    ```1 3 1```
  ![ex0](https://i.pinimg.com/750x/79/00/7b/79007b1df4c490214af497eeefcc2510.jpg)

## Modos de Solucionar
#### Usando Busca em Profundidade(DFS)
A busca em profundidade pode ser usada para encontrar componentes fortemente conexos em um grafo, que é um conjunto de vértices, em que para quaisquer vértices ```U``` e ```V``` no grafo existe um caminho e ```U``` para ```V``` e também de ```V``` para ```U```.

Este processo pode ser visto abaixo:
1. Preenchemos o grafo com os valores de entrada, fazendo
2. Definimos uma variável ```conectado = 1```, e realizamos a busca em profundidade para todos os nós do grafo.
3. Após a DFS, percorremos o vetor de visitados e verificamos se todos os elementos do vetor estão conectados.
3.1 Se todos os elementos do vetor estiverem conectados então, o valor de conectado se mantém.
3.2 Caso o contrário, o requisito de conexidade é quebrado, o valor de conectado é alterado e paramos de fazer a busca e a verificação do vetor de visitados.
4.Os passos 2 e 3 são repetidos até percorremos por todos os nós ou o requisito de conexidade seja quebrado.








