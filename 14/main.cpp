#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

char * findComPrefix(char* a, char *b){
    int i = 0, j = 0 ;
    int len_a = strlen(a), len_b = strlen(b);
    char *ans;
    while(i < len_a && j < len_b){
        if(a[i] == b[j]){
            i++;j++;
        }else{
            break;
        }
    }
    if(i == 0)return "";
    ans = (char *)malloc(sizeof(char) * i);
    strncpy(ans, a, i);
    ans[i] = '\0';
    return ans;
}
char* longestCommonPrefix(char** strs, int strsSize) {
    int i = 0;
    char *p = strs[i ++];
    while(i < strsSize){
        p = findComPrefix(p, strs[i ++]);
        if(p == "")break;
    }
    return p;
}


int main()
{
    char **p=new char*[10];
    for (int i=0;i<=10;++i){
        p[i]=new char[10];
    }
    char **q = p;
    *q = "a";
    *(++q) = "a";
    *(++q) = "flight";
    *(++q) = "regrgasdf";
    printf("%s\n%s\n%s\n", *p, *(p+1), *(p+2));
    printf("%s\n", longestCommonPrefix(p, 2));
    return 0;
}
