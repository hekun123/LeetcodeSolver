#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool isValid(char* s) {
    int i, flag, ptr;
    int s_len = strlen(s);
    char *bracket_stack = (char *)malloc(sizeof(char)*s_len);

    flag = 1;
    ptr = 0;
    for(i = 0 ; i < s_len; i ++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            bracket_stack[ptr ++] = s[i];
        }
        if(s[i] == ')'){
            if(bracket_stack[ptr-1] != '('){
                flag = 0;
                break;
            }else{
                ptr--;
            }
        }else if(s[i] == ']'){
            if(bracket_stack[ptr-1] != '['){
                flag = 0;
                break;
            }else{
                ptr--;
            }
        }else if(s[i] == '}'){
            if(bracket_stack[ptr-1] != '{'){
                flag = 0;
                break;
            }else{
                ptr--;
            }
        }
    }
    if(ptr != 0){
        flag = 0;
    }
    return flag;
}

int main(){
    char ans[] = "({[]}";
    printf("%s\n", isValid(ans)==0?"false":"true");
    return  0;
}
