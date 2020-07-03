O objetivo do exercício 1240 do URI é, dado um valor n de testes, verificar se um número B encaixa no final de um número A.

Para isso recebemos, primeiramente, a quantidade de verificações n que devemos fazer:
```c
scanf("%d", &n); //espera a inserção de um valor n
```
Depois iniciamos um laço de repetição `for` para realizar cada uma dessas verificações e, dentro dele, recebemos os primeirios números A e B que serão testados:
```c
scanf("%d %d", &a, &b); // espera a inserção dos numeros A e B
```
Após isso utilizamos a seguinte lógica, dentro do laço `for`, para fazer cada verificação:
 
1. Contar quantos dígitos o numero B possui:

    ```c
    int contaDigitos(int b){
        int digitos = 0;
    
        while (b > 0){
            b /= 10;
                digitos++;
            }
        return digitos;
        }
    ```
  
    * Passando o número B para a função `contaDigitos()`, contamos quantos dígitos tem em B, dividindo o próprio B por 10, e utilizando uma variável auxiliar digitos, para contar quantas vezes isso é possível.
        
    * A função retorna a quantidade de dígitos de B para outra variável auxiliar z.
        ```c
        z = contaDigitos(b);
        ```

2. Elevar 10 a quantidade de dígitos do numero B:

    ```c
    z = pow(10,z); 
    ```

    * Elevamos 10 a pontencia de z, com o uso da função `pow`, importada da biblioteca padrão através do `math.h`, e guardamos esse valor na mesma variável auxiliar z.
        
3. Obter o resto da divisão entre o número A e 10^z:

    ```c
    z = a%z;
     ```
    
    * Utilizamos o operador `%` para encontrar o resto da divisão.       
    * Dessa forma, os dígitos de A que são maiores que a quantidade de dígitos de B, são eliminados. Por exemplo, se A = 51234 e B = 234, ao elevar 10^z, sendo z igual o número de dígitos de B, e dividirmos A por 1000(10³) temos como resto da divisao: 1234.
    * Assim, encontramos uma forma de comparar os números A e B e resolver o exercício.
  
4. Comparar se o resto dessa divisão é igual ao número B:
    ```c
    if(z == b)
        printf("encaixa\n");
    else
        printf("nao encaixa\n");
    ```
    * Se o resto da divisão é igual a B, B encaixa no final de A. E a saida do algoritmo exibe: "encaixa" 
    * Se não é igual a B, B não encaixa no final de A. E a saída do algoritmo exibe: "não encaixa".
        
* OBS: sempre utilizamos a variável auxilar z para armezanar os resultados de algumas operações, pois não iremos precisar das informações, anteriormente, armazenadas.

5. Então passamos para a próxima iteração do laço de repetição `for` que verificará os próximos número A e B, até que o número n de verificações seja atingido e o algoritmo encerrado.
