#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;

char* intToRoman(int num) {
    char *ans = (char *)malloc(sizeof(char) * 10000);
    memset(ans, 0 , sizeof(ans));
    int len = 0, i = 0;
    int bit = -1, ten_bits = -1, hundred_bits = -1, thousand_bits = -1;
    bit = num % 10;
    num /= 10;
    ten_bits = num % 10;
    num /= 10;
    hundred_bits = num % 10;
    num /= 10;
    thousand_bits = num % 10;

    for(i = 0 ; i < thousand_bits ; i ++){
        strcat(ans, "M");
    }

    if( 0 <= hundred_bits && hundred_bits <= 3){
        for(i = 0 ; i < hundred_bits ; i ++){
            strcat(ans, "C");
        }
    }else if (hundred_bits == 4){
        strcat(ans, "CD");
    }else if(5 <= hundred_bits && hundred_bits <= 8){
        strcat(ans, "D");
        for(i = 0 ; i < (hundred_bits - 5) ; i ++){
            strcat(ans, "C");
        }
    }else if( hundred_bits == 9){
        strcat(ans, "CM");
    }

    if(0 <= ten_bits && ten_bits <= 3){
        for(i = 0 ; i < ten_bits ; i ++){
            strcat(ans, "X");
        }
    }else if ( ten_bits == 4){
        strcat(ans, "XL");
    }else if ( 5 <= ten_bits && ten_bits <= 8){
        strcat(ans, "L");
        for(i = 0 ; i < (ten_bits - 5) ; i ++){
            strcat(ans, "X");
        }
    }else if (ten_bits == 9){
        strcat(ans, "XC");
    }

    if( 0 <= bit && bit <= 3){
        for(i = 0 ; i < bit ; i ++){
            strcat(ans, "I");
        }
    }else if ( bit == 4){
        strcat(ans, "IV");
    }else if ( 5 <= bit && bit <= 8){
        strcat(ans, "V");
        for(i = 0 ; i < (bit - 5); i ++){
            strcat(ans, "I");
        }
    }else if ( bit == 9){
        strcat(ans, "IX");
    }

    return ans;
}

int main()
{
    printf("%s\n", intToRoman(3999));
    return 0;
}
