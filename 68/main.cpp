#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *lineAssemble(char **words, int start, int end, int lineWordLen, int maxWidth){
    int padNum = end - start;
    int spaceNum = maxWidth - lineWordLen;
    int spaceArray[padNum+1];

    char *returnAns = (char *)malloc(sizeof(char)*(maxWidth+1));
    //memset(spaceArray, ' ', sizeof(char)*(maxWidth+1));
    int returnAnsPtr = 0;
    if(padNum == 0){
        spaceArray[0] = spaceNum;
    }else if(spaceNum % padNum){
        int num = spaceNum % padNum;
        int i;
        for(i = 0 ; i < num ; i ++){
            spaceArray[i] = spaceNum/padNum + 1;
        }
        for(; i < padNum ;i ++){
            spaceArray[i] = spaceNum/padNum;
        }
    }else{
        for(int i = 0 ; i < padNum ; i ++){
            spaceArray[i] = spaceNum/padNum;
        }
    }
    for(int i = 0 ; i <= padNum ; i ++){
        memcpy(returnAns+returnAnsPtr, words[start+i], strlen(words[start+i]));
        returnAnsPtr += strlen(words[start+i]);
        if(i != padNum || i == 0){
            for(int j = 0 ; j < spaceArray[i]; j ++){
                memcpy(returnAns+returnAnsPtr, " ", 1);
                returnAnsPtr += 1;
            }
        }
    }
    returnAns[maxWidth] = '\0';
    return returnAns;
}

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    int start = 0, end = 0;
    int lineWordLen = 0;
    int wordLen = 0;
    char **line = NULL;
    int cnt = 0;
    int wordNum = 0;
    for(int i = 0 ; i < wordsSize ; i ++){
        //printf("%s\n", words[i]);
        wordLen = strlen(words[i]);
        if(lineWordLen + wordLen + wordNum > maxWidth){
            end = i-1;
            //TODO:º∆À„
            line = (char **)realloc(line, sizeof(char*)*(cnt+1));
            line[cnt] = lineAssemble(words, start, end, lineWordLen, maxWidth);
            cnt ++;
            start = i;
            wordNum = 1;
            lineWordLen = wordLen;
        }else{
            wordNum += 1;
            lineWordLen += wordLen;
        }
    }
    if(end != wordsSize-1 || end == 0){
        end = wordsSize-1;
        line = (char **)realloc(line, sizeof(char*)*(cnt+1));
        char *returnAns = (char *)malloc(sizeof(char) * (maxWidth+1));
        int returnAnsPtr = 0;
        int leftSpace = maxWidth - lineWordLen;
        for(int i = start ; i < wordsSize; i ++){
            memcpy(returnAns+returnAnsPtr, words[i], strlen(words[i]));
            returnAnsPtr += strlen(words[i]);
            memcpy(returnAns+returnAnsPtr, " ", 1);
            returnAnsPtr += 1;
            leftSpace -= 1;
        }
        for(int i = 0 ; i < leftSpace ; i ++){
            memcpy(returnAns+returnAnsPtr , " ", 1);
            returnAnsPtr += 1;
        }
        returnAns[maxWidth] = '\0';
        line[cnt] = returnAns;
        cnt ++;
    }
    (*returnSize) = cnt;
    return line;
}

int main()
{
    char a[][1000] = {"a"};
    char *aPtr[1000];
    int n = 1;
    for(int i = 0 ; i < n; i ++){
        //printf("%d, %s\n", i, a[i]);
        aPtr[i] = a[i];
    }
    int cnt = 0;
    char **ans = fullJustify(aPtr, n, 1, &cnt);
    for(int i = 0 ; i < cnt ;i ++){
        printf("%s\n", ans[i]);
    }
    return 0;
}
