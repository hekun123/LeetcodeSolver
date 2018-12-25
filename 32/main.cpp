#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int longestValidParentheses(char* s) {
    while(*s == ')')s = s+1;
    int len = strlen(s);
    if(len <= 1){
        return 0;
    }

    char para_stack[2*len];
    int i_stack[2*len];
    int pStA = 0, i;
    int max_len = -1, temp_len;

    para_stack[pStA] = ')';
    i_stack[pStA ++] = -1;
    for(i = 0 ; i < len ;i ++){

        para_stack[pStA] = s[i];
        i_stack[pStA ++] = i;

        if(s[i] == ')') {
            if(para_stack[pStA-2] == '('){
                pStA --;pStA --;
                //if(pStA <= 0)continue;
                temp_len = i - i_stack[pStA-1];
                if(temp_len > max_len){
                    max_len = temp_len;
                }
            }
        }
    }

    return max_len<0?0:max_len;
}

int main(){
    char *a = ")()())(((()()()(";
    printf("%d\n", longestValidParentheses(a));
    return 0;
}
