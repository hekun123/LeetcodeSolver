#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_ok(char *str_a, char *str_b, int len){
    int i;
    int flag = 1;
    for(i = 0 ; i < len ; i ++){
        if(str_a[i] != str_b[i]){
            flag = 0;
            break;
        }
    }
    return flag;
}

int strStr(char* haystack, char* needle) {
    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);
    if(needle_len <= 0){
        return 0;
    }
    if(haystack_len <= 0){
        return -1;
    }

    int i = 0;
    while(i < haystack_len){
        if(is_ok(&haystack[i], needle, needle_len)){
            return i;
        }
        i ++;
    }
    return -1;
}

int main(){
    char str_a[] = "";
    char str_b[] = "";
    printf("%d\n", strStr(str_a, str_b));
    return 0;
}
