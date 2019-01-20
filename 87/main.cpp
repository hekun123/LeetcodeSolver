#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isScramble(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    if(len1 != len2){
        return false;
    }

    int numa = 0, numb = 0;
    for(int i = 0 ; i < len1; i ++){
        numa += s1[i];
        numb += s2[i];
    }
    if(numa != numb){
        return false;
    }

    if(strcmp(s1, s2) == 0){
        return true;
    }else{
        if(len1 <= 1){
            return false;
        }
    }

    char leftS1[len1+2], rightS1[len1+2];
    char leftS2[len2+2], rightS2[len2+2];
    for(int i = 1; i < len1; i ++){
        strncpy(leftS1, s1, i); leftS1[i] = '\0';
        strncpy(rightS1, s1+i, len1-i); rightS1[len1-i] = '\0';
        strncpy(leftS2, s2, i); leftS2[i] = '\0';
        strncpy(rightS2, s2+i, len2-i); rightS2[len2-i] = '\0';

        if(isScramble(leftS1, leftS2) && isScramble(rightS1, rightS2))
            return true;

        strncpy(leftS2, s2, len2-i); leftS2[len2-i] = '\0';
        strncpy(rightS2, s2+len2-i, i); rightS2[i] = '\0';

        if(isScramble(leftS1, rightS2) && isScramble(rightS1, leftS2))
            return true;
    }
    return false;
}


int main(){
    char a[100] = "abc";
    char b[100] = "cab";
    printf("%s\n", isScramble(a, b)?"YES":"NO");
    return 0;
}
