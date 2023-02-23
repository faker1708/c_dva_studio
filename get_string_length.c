
int get_string_length(char* s){
    // 输入char*
    int i = 0;  // length   
    char a = 0;
    int length = 0;
    
    while(1){
        a = s[i];
        if(a == 0){
            break;
        }else{

        i++;
        }

    }
    length = i;


    //printf("%d\n",i);
    return length;
}




int is_char_in_string(unsigned char a,unsigned char* string){
    // 如果有，则返回下标，否则返回-1
    int out = -2;
    int string_index = 0;
    unsigned char b = 0;
    while(1){
        b = string[string_index];
        if(b==0){
            out=-1;
            break;
        }else{
            if(a==b){
                out = string_index;
                break;
            }else{

            }
        }
        string_index++;
    }
    if(out >=0){
        // printf("a %d,b %d\n",a,b);
    }
    return out;
}

int is_

int is_string_array_equal(char** string_array,int length){
    int out = -2;
    // 不写了

    printf("dont call me.\n");
    exit(-1);




    return out;
}