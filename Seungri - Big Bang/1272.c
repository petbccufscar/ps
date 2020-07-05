#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n, i, j, cont;
	
	char palavras[52];
	char codigo[52];
	
	char esp = ' ';
	
	scanf("%d\n", &n);

	for(i = 0; i < n; i++) {

		fgets(palavras, 52, stdin);

		
		for(j = 0, cont = 0; j < strlen(palavras) - 1; ++j) {
		    

		    
			if(palavras[j] != esp && (!j || palavras[j - 1] == esp)) {

			    codigo[cont++] = palavras[j];
			 
			}
		}
		codigo[cont] = '\0';
		
		printf("%s\n", codigo);
		
	}
	
	return 0;

}
