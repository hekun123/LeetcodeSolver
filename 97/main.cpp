#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool isInterleave(char* s1, char* s2, char* s3) {
    int len1, len2, len3;
    len1 = strlen(s1);
    len2 = strlen(s2);
    len3 = strlen(s3);
    if(len3 != len1 + len2){
        return false;
    }

    bool dp[len1+1][len2+1];
    //bool dp[100][100];
    memset(dp, false, sizeof(dp));

    dp[0][0] = true;
    for(int i = 0 ; i < len1; i ++){
        dp[i+1][0] = dp[i][0] && (s1[i] == s3[i]);
    }
    for(int i = 0; i < len2 ; i ++){
        dp[0][i+1] = dp[0][i] && (s2[i] == s3[i]);
    }


    for(int i = 1 ; i <= len1 ; i ++){
        for(int j = 1 ; j <= len2; j ++){
            dp[i][j] = (dp[i-1][j] && (s1[i-1] == s3[i+j-1]))
                        || (dp[i][j-1] && (s2[j-1] == s3[i+j-1]));
        }
    }
    return dp[len1][len2];
}

int main(){
    char *s1 = "";
    char *s2 = "";
    char *s3 = "a";
    printf("%s\n", isInterleave(s1, s2, s3) == true? "YES" : "NO");
    return 0;
}
