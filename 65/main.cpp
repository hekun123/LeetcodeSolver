#include <stdio.h>
#include <string.h>
#include <stdlib.h>

bool isExponentNumOk(char *num){
    int numLen = strlen(num);
    if(numLen == 0){
        return false;
    }
    int flag = 1;
    int isLittle = 0;
    int i;
    for(i = 0 ; i < numLen; i ++){
        if(num[i] == '-' || num[i] == '+' ){
            if(i != 0){
                flag = 0;
                break;
            }
            if(i+1 == numLen){
                flag = 0;
                break;
            }
        }else if(num[i] == '.'){
            flag = 0;
            isLittle = 1;
            break;
        }else if(num[i] < '0' || num[i] > '9'){
            flag = 0;
            break;
        }
    }
    if(isLittle && i+1 != numLen){
        flag = 1;
        i ++;
        for(; i < numLen ; i ++){
            if(num[i] != '0'){
                flag = 0;
            }
        }
    }
    return flag;
}

bool isNumber(char* s) {
    while(*s == ' '){
        s++;
    }
    int sLen = strlen(s);
    int i;
    for(i = sLen -1 ; i >= 0; i --){
        if(s[i] != ' '){
            s[i+1] = '\0';
            break;
        }
    }
    sLen = i+1;
    if(sLen == 0){
        return false;
    }
    int flag = 1;
    int isExponent = 0;
    int isLittle = 0;
    for(i = 0 ; i < sLen ; i ++){
        if(s[i] == '-' || s[i] == '+'){
            if(i != 0){
                flag = 0;
                break;
            }
        }else if(s[i] == '.'){
            if(isLittle){
                flag = 0;
                break;
            }
            if(i == 0 && i+1 == sLen){
                flag = 0;
                break;
            }else if(i == 0){
                if(s[i+1]<'0' || s[i+1] >'9'){
                    flag = 0;
                    break;
                }
            }else if (i+1 == sLen){
                if(s[i-1] < '0' || s[i-1] > '9'){
                    flag = 0;
                    break;
                }
            }else{
                if(s[i-1] == '-' || s[i-1] == '+'){
                    if(s[i+1] < '0' || s[i+1] > '9'){
                        flag = 0;
                        break;
                    }
                }
                if(s[i+1] == 'e'){
                    if(s[i-1] < '0' || s[i-1] > '9'){
                        flag = 0;
                        break;
                    }
                }
            }
            isLittle = 1;
        }else if(s[i] == 'e'){
            if(i == 0){
                flag = 0;
                break;
            }else if(s[i-1] == '-' || s[i-1] == '+'){
                flag = 0;
                break;
            }else{
                break;
            }
        }else if(s[i] < '0' || s[i] > '9'){
            flag = 0;
            break;
        }
    }
    if(!flag){
        return false;
    }
    if(i != sLen){
        i ++;
        flag = isExponentNumOk(s+i);
    }
    return flag;
}

int main()
{
    char a[] = "-e23";
    printf("%s\n", isNumber(a)?"yes":"no");
    return 0;
}
