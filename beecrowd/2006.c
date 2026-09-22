#include <stdio.h>
 
int main() {
    
    int t,cont=0;
    int vet[5];
    
    scanf("%d", &t);
    
    while (t<0 || t>4){
        scanf("%d", &t);
    }
   
   for (int i=0; i<5; i++){
       
       scanf("%d", &vet[i]);
       if (vet[i] <0 || vet[i]>4){
            scanf("%d", &vet[i]);
        }
        if(vet[i] == t) cont++;
   }
    
   
    
    printf("%d\n", cont);
    
    
    
    
 

 
    return 0;
}
