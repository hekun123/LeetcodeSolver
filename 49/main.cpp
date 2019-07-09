#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int cmp(const void *a, const void *b)
{
    return (int )(*(char*)a - *(char *)b);
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char*** groupAnagrams(char** strs, int strsSize, int** columnSizes, int* returnSize) {

    char ***returnAns = NULL;
    char **flagStr = NULL;
    int *returnCol = NULL;
    char *newStr    = NULL;
    int cnt = 0;
    int len = 0;
    int i, j, flag, flag_i;
    for(i = 0 ; i < strsSize; i ++){
        flag = 0;
        flag_i = 0;
        len = strlen(strs[i]);
        newStr = (char *)malloc(sizeof(char)*(len+1));
        memcpy(newStr, strs[i], strlen(strs[i])+1);
        qsort(newStr, strlen(newStr), sizeof(char), cmp);
        for(j = 0 ; j < cnt ; j ++){
            if(strcmp(newStr, flagStr[j]) == 0) {
                flag = 1;
                flag_i = j;
                break;
            }
        }
        if(!flag){
            cnt ++;
            returnAns = (char ***)realloc(returnAns, sizeof(char **)*cnt);
            returnAns[cnt-1] = NULL;

            flagStr = (char **)realloc(flagStr, sizeof(char*)*cnt);
            flagStr[cnt-1] = (char *)malloc(sizeof(char)*(strlen(newStr)+1));
            memcpy(flagStr[cnt-1], newStr, strlen(newStr)+1);

            returnCol = (int *)realloc(returnCol, sizeof(int)*cnt);
            returnCol[cnt-1] = 0;
            flag_i = cnt-1;
        }

        returnCol[flag_i] ++;
        returnAns[flag_i] = (char **)realloc(returnAns[flag_i], sizeof(char *)*returnCol[flag_i]);
        returnAns[flag_i][returnCol[flag_i]-1] = (char *)malloc(sizeof(char)*(strlen(strs[i])+1));
        memcpy(returnAns[flag_i][returnCol[flag_i]-1], strs[i], strlen(strs[i])+1);
        free(newStr);
    }
    for(int i = 0 ; i < cnt ; i ++){
        free(flagStr ++);
    }

    (*columnSizes) = returnCol;
    (*returnSize) = cnt;
    return returnAns;
}

int main(int argc, char** argv)
{
    char *abc[10]={
        "12312", "2314", "dfgsdf", "ateasdf", "asdf", "1231", "1231", "1231", "2314", "2314"
    };
    int *aaLen = NULL;
    char ***returnAsn = NULL;
    int n;
    returnAsn = groupAnagrams(abc, 10, (int **)&aaLen, &n);
    for(int i = 0 ; i < n ; i ++) {
        for(int j = 0 ; j < aaLen[i]; j ++){
            printf("%s\t", returnAsn[i][j]);
        }
        printf("\n");
    }
    return 0;
}
