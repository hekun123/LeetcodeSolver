#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int SIZE = 100;

char* minWindow(char* s, char* t) {

    int matchLen = 0;
    int sVisit[SIZE];
    int tVisit[SIZE];
    memset(sVisit, 0, sizeof(sVisit));
    memset(tVisit, 0, sizeof(tVisit));
    int sLen = strlen(s);
    int tLen = strlen(t);

    if(sLen <= 0 || tLen <= 0 || sLen < tLen){
        return "";
    }
    for(int i = 0 ; i < tLen ; i ++){
        tVisit[t[i]-'A'] ++;
    }

    int Left = 0;
    int Right = 0;
    int MinLen = sLen;
    int MinLeft = 0;
    int MinRight = 0;
    int match = 0;

    for(int i = 0 ; i < sLen ; i++){
        if(sVisit[s[i]-'A'] < tVisit[s[i]-'A']){
            matchLen ++;
        }
        if(matchLen == tLen){
            Right = i;
            int flag = 0;
            while(Left <= Right){
                if(sVisit[s[Left]-'A'] <= tVisit[s[Left]-'A']){
                    if(Right-Left < MinLen){
                        MinRight = Right;
                        MinLeft = Left;
                        MinLen = Right-Left+1;
                    }
                    sVisit[s[Left]-'A']--;
                    flag = 1;
                    match = 1;
                    matchLen --;
                }else{
                    sVisit[s[Left]-'A']--;
                }
                Left ++;
                if(flag)break;
            }
        }
        sVisit[s[i]-'A'] ++;
    }
    if(!match){
        return "";
    }
    char *ans = (char *)malloc(sizeof(char)*(MinLen+1));
    int cnt = 0;
    for(int i = 0 ; i < MinLen ; i ++){
        ans[cnt ++] = s[MinLeft+i];
    }
    ans[cnt] = '\0';
    return ans;
}

int main(){
    char s[] = {"aa"};
    char t[] = {"aaa"};
    printf("%s\n", minWindow(s, t));
    return 0;
}
