#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char **returnSet;
int cnt;

void dfs(char *pcS, int iSLen, int iIndex, char *pcTmpS, int iTmpSLen, int dig){
    if(dig == 4){
        if(iIndex == iSLen){
            pcTmpS[iTmpSLen++] = '\0';
            cnt ++;
            returnSet = (char **)realloc(returnSet, sizeof(char*)*cnt);
            returnSet[cnt-1] = (char*) malloc(sizeof(char)*iTmpSLen);
            for(int i = 0 ; i < iTmpSLen ; i ++){
                returnSet[cnt-1][i] = pcTmpS[i];
            }
            returnSet[cnt-1][iTmpSLen] = '\0';
        }
        return;
    }

    if(dig > 0){
        pcTmpS[iTmpSLen ++] = '.';
    }

    int iLeftLen = iSLen - iIndex;
    int num = 0;
    for(int i = 1 ; i <= 3 ; i ++){
        if(i > 1 && num == 0){
            break;
        }
        num *= 10;
        num += pcS[iIndex]-'0';
        iLeftLen --;
        if(iLeftLen <= (4-dig)*3 && num <= 255){
            pcTmpS[iTmpSLen++] = pcS[iIndex++];
            dfs(pcS, iSLen, iIndex, pcTmpS, iTmpSLen, dig+1);
        }
    }
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** restoreIpAddresses(char* s, int* returnSize) {
    returnSet = NULL;
    cnt = 0;
    int iSlen = strlen(s);
    if(iSlen < 4){
        (*returnSize) = 0;
        return NULL;
    }
    char *tmp = (char *)malloc(sizeof(char) * (iSlen+10));
    dfs(s, iSlen, 0, tmp, 0, 0);
    (*returnSize) = cnt;
    return returnSet;
}

int main(){

    char *s = "110001";
    char **ans = NULL;
    int ansCnt;
    ans = restoreIpAddresses(s, &ansCnt);
    for(int i = 0 ; i < ansCnt ; i ++){
        printf("%s\n", ans[i]);
    }
    return 0;
}
