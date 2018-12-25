#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int min(int a, int b){
    return a>b?b:a;
}

int minDistance(char* word1, char* word2) {
    int word1_len = strlen(word1);
    int word2_len = strlen(word2);

    int dp[word1_len+1][word2_len+1];

    for(int i = 0 ; i <= word1_len ; i ++){
        dp[i][0] = i;
    }
    for(int i = 0 ; i <= word2_len ; i ++){
        dp[0][i] = i;
    }

    for(int i = 1 ; i <= word1_len ; i ++){
        for(int j = 1; j <= word2_len; j ++){
            if(word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = min(min(dp[i-1][j-1]+1, dp[i][j-1]+1), dp[i-1][j]+1);
            }
        }
    }
    return dp[word1_len][word2_len];
}

int main(){
    char a[] = {"horse"};
    char b[] = {"ros"};

    printf("%d\n", minDistance(a, b));
    return 0;
}
