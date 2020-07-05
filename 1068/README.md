# URI 1068 - Balanço de Parênteses I 
A partir de uma expressão dada, temos que mostrar na tela se o a quantidade de parêntes está correta ou incorreta. 
Desse modo: 
- a quantidade de parêntes abertos deve ser igual a quantidade de parênteses fechados; 
- todo parênteses fechado deve ter um outro parênteses aberto correspondente
- não pode haver parênteses fechado sem um previo parenteses aberto.

Exemplos de alguns possíveis casos:
- a+(b*c)-2-a está correto
- (a+b*(2-c)-2+a)*2 está correto
- (a*b-(2+c) está incorreto
- 2*(3-a)) está incorreto
- )3+b*(2-c)( está incorreto

## Modos de Solucionar
Inicialmente, para os casos iremos usar exemplos de forma simplificada para a explicação ficar mais didática, usando apenas os parênteses da expressão. 
- Então: (a+b*(2-c)-2+a)*2 é equivalente a (()).
#### Por meio de contadores
Nesse método, fazemos a verificação de um parêntereses por vez. Há também um contador de parêntes abertos, em que é usado para podermos achar pares de parênteses corretos, ou seja "()".

Este processo pode ser verificado no algoritmo abaixo:
1. Olhamos um parênteses por vez
2. Se encontrarmos um parênteses aberto, "(" incrementamos a quantidade de parênteses abertos em uma unidade, então ```aberto++```;
3. Se encontrarmos um parênteses fechado, ")" existem 2 possíbilidades:
3.1 Caso a quantidade de parênteses abertos seja zero, ```aberto == 0```, isso quer dizer que, existe um parênteses fechado mas nenhum aberto correspondente, portanto, a expressão é incorreta
3.2 Caso contrário, a quantidade de parênteses abertos seja maior zero, ```aberto > 0```, diminuímos a quantidade de parênteses abertos, assim encontramos um par correspondente
4. Repetimos os passos 2 e 3 até a expressão chegar ao fim
5. Ao final, se ```aberto > 0``` a expressão é inválida, caso contrário ela é válida

#### Usando Pilha
Uma das principais características de uma pilha é o fato que: o último elemento que entra é o primeiro elemento a sair(last in first out -LIFO). 
Usando essa ideia, retiramos elementos da pilha se o próximo elemento da expressão for um parênteses fechado, ```)```, e o último elemento da pilha for um parênteses aberto, ```(```, assim, formando um par.

Este processo pode ser visto do algoritmo abaixo.
1. Inicializamos a pilha ```P```.
2. Percorremos um parênteses por vez na expressão.
3. Se encontrarmos um parênteses aberto, ```(```, colocamos para dentro da pilha
4. Se encontrarmos um par"enteses fechado, ```)```, verificamos o elemento do topo da pilha, caso este elemento é um parênteses aberto, ```(```, retiramos ele do topo da pilha e continuamos a percorrer a expressão
4.1 Se não, a expressão é inválida.
5. Ao final, se a pilha ainda estiver elementos isso implica na expressão ser inválida, ao contrário se a pilha for vazia a expressão é verdadeira.

Um exemplo desta abordagem pode ser visto abaixo:
![exemplo](https://s3-us-west-2.amazonaws.com/me.shizuku.com/wp-content/uploads/2017/05/11184907/longest_valid_parentheses_stack.gif)
[fonte da imagem](http://me.shizuku.com/category/coding/algorithms/stack/)

Sendo n o tamanho da expressão temos:
Complexidade de tempo: ```O(n)```
Complexidade de espaço
- Pior caso de expressão válida: ```O(n)```
- Pior caso de expressão inválida: ```O(n)```






