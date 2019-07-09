#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isMatch(char* s, char* p) {
    if(s == NULL || p == NULL) {
        return false;
    }
    int len1 = strlen(s);
    int len2 = strlen(p);
    if(len1 == 0 && len2 == 0) {
        return true;
    }
    if(len1 == 0){
        //*匹配一切
        int i = 0;
        for(i = 0 ; i < len2 ; i ++) {
            if(p[i] != '*') {
                return false;
            }
        }
        return true;
    }
    if(len1 <= 0 || len2 <= 0) {
        return false;
    }

    int i, j, flag = 0;
    int dp[len1+10][len2+10];   //变量静态开辟不能调试 调试使用全局开辟
    memset(dp, false, sizeof(dp));//数组开过大会导致超时
    if(s[0] == p[0] || p[0] == '?'){
        flag = 1;
        dp[0][0] = 1;
    }
    if(p[0] == '*') {
        dp[0][0] = 1;
    }
    for(i = 1 ; i < len1; i ++) {
        if(p[0] == '*'){
            dp[i][0] = dp[i-1][0];
        }else{
            dp[i][0] = 0;
        }
    }

    for(i = 1; i < len2 ; i ++) {
        if(p[i] == '*'){
            dp[0][i] = dp[0][i-1];
        }else if(((p[i] == '?')&&(flag == 0)) || ((p[i] == s[0]) && (flag == 0))) {
            dp[0][i] = dp[0][i-1];
            flag = 1; //s中第一个元素是否已经被p中的元素或者?匹配 被*匹配无所谓
        }else{
            dp[0][i] = 0;
        }
    }
    for(i = 1 ; i < len1; i ++) {
        for(j = 1; j < len2 ; j ++) {
            if(p[j] == '*'){
                dp[i][j] = dp[i-1][j-1] || dp[i][j-1] || dp[i-1][j];
            }else if(p[j] == '?') {
                dp[i][j] = dp[i-1][j-1];
            }else if(s[i] == p[j]){
                dp[i][j] = dp[i-1][j-1];
            }else {
                dp[i][j] = 0;
            }
        }
    }
    for(i = 0 ; i < len1; i ++) {
        for(j = 0 ; j < len2; j ++) {
            printf("%d,", dp[i][j]);
        }
        printf("\n");
    }
    return dp[len1-1][len2-1];
}

int main() {
    char a[] = "bbaaababbaaababababbb";
    char b[] = "*a*****bb";
    printf("%s\n", isMatch(a, b)?"true":"false");
    return 0;
}
