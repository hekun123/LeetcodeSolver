#include <stdio.h>
#include <string.h>
#include <stdlib.h>
long long int reslt_len[40] = {1,2,5,14,41,122,365,1094,3281,
9842,29525,88574,265721,797162,2391485,7174454,
21523361,64570082,193710245,581130734,1743392201,
5230176602,15690529805,47071589414,141214768241,
423644304722,1270932914165,3812798742494,11438396227481,
34315188682442,102945566047325,308836698141974,926510094425921,
2779530283277762,8338590849833285,25015772549499854,75047317648499561,
225141952945498682,675425858836496045,2026277576509488134};
int cnt;
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

void dfs(char **array, int step, int n, char *str){
    if(step == 2*n){
        if(isValid(str)){
            cnt ++;
            memcpy(array[cnt-1], str, 2*n);
            array[cnt-1][2*n] = '\0';
        }
        return;
    }

    str[step] = '(';
    str[step+1] = '\0';
    dfs(array, step+1, n, str);

    if(step == 0)return;
    str[step] = ')';
    str[step+1] = '\0';
    dfs(array, step+1, n, str);
}

char** generateParenthesis(int n, int* returnSize) {
    int i;
    char **returnArray = NULL;
    returnArray = (char **)malloc(sizeof(char *)*reslt_len[n]);
    for(i = 0 ; i < reslt_len[n] ; i ++){
        returnArray[i] = (char *)malloc(sizeof(char ) * (2*n+1));
    }
    cnt = 0;
    char str[2*n+2];
    dfs(returnArray, 0, n, str);
    *returnSize = cnt;
    return returnArray;
}

int main(){
    //freopen("in.txt", "w+", stdout);
    int ans = 0;
    char **ans_array;
    ans_array = generateParenthesis(4, &ans);
    for(int i = 0 ; i < ans; i ++){
        printf("%s\n", ans_array[i]);
    }
    return 0;
}
