#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init_next(int next[],char *str, int len){
    next[0] = -1;
    int i, k = -1;
    for(i = 1; i < len ; i ++){
        while(k > -1 && str[k+1] != str[i]){
            k = next[k];
        }
        if(str[k+1] == str[i]){
            k = k + 1;
        }
        next[i] = k;
    }
}

int kmp(char *str_a, int str_a_len, char *str_b, int str_b_len){
    int next[str_b_len];
    init_next(next, str_b, str_b_len);
    int i, k = -1;
    for(i = 0 ; i < str_a_len ; i ++){
        while(k > -1 && str_b[k+1] != str_a[i]){
            k = next[k];
        }
        if(str_b[k+1] == str_a[i]){
            k = k + 1;
        }
        if(k == str_b_len-1){
            return i-str_b_len+1;
        }
    }
    return -1;
}

int strStr(char* haystack, char* needle) {
    int needle_len = strlen(needle);
    int haystack_len = strlen(haystack);
    if(needle_len <= 0){
        return 0;
    }
    if(haystack_len <= 0){
        return -1;
    }
    return kmp(haystack, haystack_len, needle, needle_len);
}

int main(){
    char str_a[] = "bacbababadababacambabacaddababacasdsd";
    char str_b[] = "ababaca";

    printf("%d\n", strStr(str_a, str_b));
    return 0;
}
