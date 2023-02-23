#include <stdio.h>
// #include <string.h>
#include <stdlib.h>


int get_string_length(char* s) {
    // 输入char*
    int i = 0;  // length
    char a = 0;
    int length = 0;

    while (1) {
        a = s[i];
        if (a == 0) {
            break;
        } else {

            i++;
        }

    }
    length = i;


    //printf("%d\n",i);
    return length;
}

int kernel(char *string){
    int out = 0;
out =     get_string_length(string);
return out;
}


int main() {
    //char str[1000];
    char* str = 0;
    str = malloc(sizeof(char) * 1000);

    while (1) {
        int rs = 0;
        rs = scanf("%s", str);
        if (rs == EOF) {
            break;
        }

    }
    //拿到最后的单词

    int out = 0;
    out = kernel(str);
    printf("%d",out);

    return 0;

}