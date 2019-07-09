#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numDecodings(char* s) {
    int iSLen = strlen(s);
    if(iSLen <= 0){
        return 0;
    }

    if(s[0] == '0'){
        return 0;
    }

    int dp[iSLen+1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 1 ; i < iSLen+1; i ++){
        dp[i] = dp[i-1];
        if('0' == s[i-1]) dp[i] = 0;
        if( i > 1 && ('1' == s[i-2] || ('2' == s[i-2] && s[i-1] <= '6'))){
            dp[i] += dp[i-2];
        }
    }
    return dp[iSLen];
}

int main(){
    char *s = "120012";
    printf("%d\n", numDecodings(s));
    return 0;
}
