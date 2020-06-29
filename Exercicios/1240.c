#include <stdio.h>
#include <math.h>

int quantidade(long long int num){
	int quantidade;

	while(num){
		num = num/10;
		quantidade++;
	}

	return quantidade;
}

int main()
{
	//declaração de variáveis do tipo inteiro
	int n, z;
	long long int a, b; //64bits

	//leitura da quantidade de testes
	scanf("%d", &n);

	while(n--){
		//leitura dos dois inteiros a e b
		scanf("%lld %lld", &a, &b);

		//realiza 10 elevado a quantidade de elementos do número b
		z = pow(10, quantidade(b));
		//divide o numero a por 10 elevado a quantidade de elementos do número b e guarda em a o resto dessa divisão
		a = a%z;

		if(a == b){
			printf("encaixa\n");
		}else{
			printf("nao encaixa\n");
		}
	}

	return(0);
}
