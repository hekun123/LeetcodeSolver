#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int lengthOfLastWord(char* s) {
    int strLen, i, returnAns;
    char *sPtr = NULL;
    strLen = strlen(s);
    sPtr = s+strLen-1;
    while(*sPtr == ' '){
        *sPtr = '\0';
        sPtr--;
    }
    strLen = strlen(s);

    returnAns = 0;
    for(i = strLen-1; i >= 0; i --){
        if( ('A' <= s[i] && s[i] <= 'Z')
        || ('a' <= s[i] && s[i] <= 'z')){
            returnAns++;
        }else{
            break;
        }
    }
    return returnAns;
}

int main()
{
    char a[] = "a  ";
    printf("%d\n", lengthOfLastWord(a));
    return 0;
}
