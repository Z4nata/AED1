#include <stdio.h>
 
int main() {
 
    int t;
    scanf("%d", &t);
    while ( t<1 || t>1000){
        scanf("%d", &t);
        
    }
    printf("%d\n", t*2*2);
 
    return 0;
}
