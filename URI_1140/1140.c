#include<stdio.h>
#include<string.h>
#include <ctype.h>


int main()
{
    char entrada[1050];
    int flag=1;
    int i;
    
    fgets(entrada, sizeof(entrada), stdin);

	while(entrada[0] != '*'){
	    for (i = 0; i < strlen(entrada); i++)
			entrada[i]=tolower(entrada[i]);
		flag = 1;
		for (i = 1; i < strlen(entrada); i++)
		{
			if(entrada[i-1] == ' ' && entrada[0]!=entrada[i]){
				flag=0;
			}
		}
		if(flag)
		    printf("Y\n");
		else
		    printf("N\n");
		fgets(entrada, sizeof(entrada), stdin);
	}
	return 0;
}