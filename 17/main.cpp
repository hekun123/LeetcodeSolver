#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
#include <malloc.h>

char num_2[] = {'a', 'b', 'c'};
char num_3[] = {'d', 'e', 'f'};
char num_4[] = {'g', 'h', 'i'};
char num_5[] = {'j', 'k', 'l'};
char num_6[] = {'m', 'n', 'o'};
char num_7[] = {'p', 'q', 'r', 's'};
char num_8[] = {'t', 'u', 'v'};
char num_9[] = {'w', 'x', 'y', 'z'};

int cnt;
void depose(char** returnStr, char *str, char *digits, int digits_len, int step){
    if(step == digits_len){
        if(digits[step] == '2'){
            for(int i = 0 ; i < 3 ; i ++){
                str[step] = num_2[i];
                str[step+1] = '\0';
                memcpy(returnStr[cnt ++], str, digits_len+2);
            }
        }
        if(digits[step] == '3'){
            for(int i = 0 ; i < 3 ; i ++){
                str[step] = num_3[i];
                str[step+1] = '\0';
                memcpy(returnStr[cnt ++], str, digits_len+2);
            }
        }
        if(digits[step] == '4'){
            for(int i = 0 ; i < 3 ; i ++){
                str[step] = num_4[i];
                str[step+1] = '\0';
                memcpy(returnStr[cnt ++], str, digits_len+2);
            }
        }
        if(digits[step] == '5'){
            for(int i = 0 ; i < 3 ; i ++){
                str[step] = num_5[i];
                str[step+1] = '\0';
                memcpy(returnStr[cnt ++], str, digits_len+2);
            }
        }
        if(digits[step] == '6'){
            for(int i = 0 ; i < 3 ; i ++){
                str[step] = num_6[i];
                str[step+1] = '\0';
                memcpy(returnStr[cnt ++], str, digits_len+2);
            }
        }
        if(digits[step] == '7'){
            for(int i = 0 ; i < 4 ; i ++){
                str[step] = num_7[i];
                str[step+1] = '\0';
                memcpy(returnStr[cnt ++], str, digits_len+2);
            }
        }
        if(digits[step] == '8'){
            for(int i = 0 ; i < 3 ; i ++){
                str[step] = num_8[i];
                str[step+1] = '\0';
                memcpy(returnStr[cnt ++], str, digits_len+2);
            }
        }
        if(digits[step] == '9'){
            for(int i = 0 ; i < 4 ; i ++){
                str[step] = num_9[i];
                str[step+1] = '\0';
                memcpy(returnStr[cnt ++], str, digits_len+2);
            }
        }
    }

    if(digits[step] == '2'){
        str[step] = 'a';
        depose(returnStr, str, digits, digits_len, step + 1);
        str[step] = 'b';
        depose(returnStr, str, digits, digits_len, step + 1);
        str[step] = 'c';
        depose(returnStr, str, digits, digits_len, step + 1);
    }
    if(digits[step] == '3'){
        str[step] = 'd';
        depose(returnStr, str, digits, digits_len, step + 1);
        str[step] = 'e';
        depose(returnStr, str, digits, digits_len, step + 1);
        str[step] = 'f';
        depose(returnStr, str, digits, digits_len, step + 1);
    }
    if(digits[step] == '4'){
        str[step] = 'g';
        depose(returnStr, str, digits, digits_len, step + 1);
        str[step] = 'h';
        depose(returnStr, str, digits, digits_len, step + 1);
        str[step] = 'i';
        depose(returnStr, str, digits, digits_len, step + 1);
    }
    if(digits[step] == '5'){
        str[step] = 'j';
        depose(returnStr, str, digits, digits_len, step + 1);
        str[step] = 'k';
        depose(returnStr, str, digits, digits_len, step + 1);
        str[step] = 'l';
        depose(returnStr, str, digits, digits_len, step + 1);
    }
    if(digits[step] == '6'){
        str[step] = 'm';
        depose(returnStr, str, digits, digits_len, step + 1);
        str[step] = 'n';
        depose(returnStr, str, digits, digits_len, step + 1);
        str[step] = 'o';
        depose(returnStr, str, digits, digits_len, step + 1);
    }
    if(digits[step] == '7'){
        str[step] = 'p';
        depose(returnStr, str, digits, digits_len, step + 1);
        str[step] = 'q';
        depose(returnStr, str, digits, digits_len, step + 1);
        str[step] = 'r';
        depose(returnStr, str, digits, digits_len, step + 1);
        str[step] = 's';
        depose(returnStr, str, digits, digits_len, step + 1);
    }
    if(digits[step] == '8'){
        str[step] = 't';
        depose(returnStr, str, digits, digits_len, step + 1);
        str[step] = 'u';
        depose(returnStr, str, digits, digits_len, step + 1);
        str[step] = 'v';
        depose(returnStr, str, digits, digits_len, step + 1);
    }
    if(digits[step] == '9'){
        str[step] = 'w';
        depose(returnStr, str, digits, digits_len, step + 1);
        str[step] = 'x';
        depose(returnStr, str, digits, digits_len, step + 1);
        str[step] = 'y';
        depose(returnStr, str, digits, digits_len, step + 1);
        str[step] = 'z';
        depose(returnStr, str, digits, digits_len, step + 1);
    }
}

char** letterCombinations(char* digits, int* returnSize) {
    char **returnBuf;
    if (digits == NULL || digits == "") {
		*returnSize = 0;
		return NULL;
	}
    int i;
    int digits_len = strlen(digits);
    if(digits_len == 0){
        *returnSize = 0;
		return NULL;
    }
    int ret_size = 1;
    for( i = 0 ; i < digits_len ; i ++){
        if((digits[i] == '7') || (digits[i] == '9')){
            ret_size *= 4;
        }else{
            ret_size *= 3;
        }
    }

    returnBuf = (char **)malloc(sizeof(int *)*ret_size);
    for(i = 0 ; i < ret_size ; i ++){
        returnBuf[i] = (char *)malloc(sizeof(char) * 30);
    }
    cnt = 0;
    char *str = (char *)malloc(sizeof(char) * digits_len);
    depose(returnBuf, str, digits, digits_len - 1, 0);

    *returnSize = ret_size;
    return returnBuf;
}

int main()
{
    char *ans = "";
    int ans_len = 0;
    char ** abc = letterCombinations("", &ans_len);
    for(int i = 0 ; i < ans_len ; i ++){
        printf("%s\n", abc[i]);
    }
    return 0;
}
