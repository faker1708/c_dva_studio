
#include <stdio.h>
#include <stdlib.h>


int main() {
    //char str[1000];
    char* str = 0;
    str = malloc(sizeof(char) * 1000);

    while (1) {
        int rs = 0;
        rs = scanf("%s", str);
        if (rs == EOF) {
            break;
        }else{
            printf("%d",str);
        }

    }
    return 0;

}