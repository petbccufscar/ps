#include<stdio.h>
#include<math.h>

int contaDigitos(int num){
    int digitos = 0;
    
    while (num) {
        num /= 10;
        digitos++;
    }
    
    return digitos;
}

int main(){

	int n, a , b, z;
	int i;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
	    scanf("%d %d", &a, &b);
		z = contaDigitos(b);
		z = pow(10,z);
        z = a%z;
		if(z == b){
		    printf("encaixa\n");
		}
		else
		    printf("nao encaixa\n");
	}
	return 0;
}
