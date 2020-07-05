int main() {
    int n, i, j, k, zero, count;
    char snum[101];
    
    while(1){
        
        scanf("%d %s",&n,snum);
        if(n == 0 && snum[0] == '0') {
            break;
        }
        
        char cha[101];
        
        i = 0;
        j = 0;
        zero = 0;
        count = 0;
        
        while(1){
            if(snum[i] == '\0'){
                break;
            }
            else if(snum[i] == n + 48){
                i++;
            }
            else{
                cha[j] = snum[i];
                if(j == zero) {
                    count++;
                }
                    
                if(snum[i] == '0') {
                    zero++;
                }
                i++;
                j++;
            }
            
        }
        
        cha[j] = '\0';
        
        if(j == 0){ 
            printf("0\n");
        }
        else if(j == zero){ 
            printf("0\n"); 
        }
        else if(count > 0){
            for(k = count - 1; cha[k] != '\0'; k++){
                printf("%c", cha[k]);
            }
            printf("\n");
        }
        else {
            printf("%s\n", cha);
        }
        
    }
    
    return 0;
}
