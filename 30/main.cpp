#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_{
    char *str;
    int times;
    struct node_ *next;
}word_node;

typedef struct visit_{
    char *str;
    int visit_time;
    struct visit_ *next;
}word_visit;

int hash_size = 100;
word_node **word_directory;
word_visit **word_visit_directory;

int hash_(char *str){
    int i;
    int hash_val = 0;
    for(i = 0 ; i < (int)strlen(str); i ++){
        hash_val = (hash_val + str[i])%hash_size;
    }
    return hash_val%hash_size;
}

int insert_visit(word_visit **pHead, char *str){
    int str_len = strlen(str);
    int hash_val = hash_(str);
    if(hash_val > hash_size)return -1;

    word_visit *ptr = pHead[hash_val];
    word_visit *temp;
    if(pHead[hash_val] == NULL){
        pHead[hash_val] = (word_visit *)malloc(sizeof(word_visit));
        pHead[hash_val]->str = (char *)malloc(str_len+1);
        memcpy(pHead[hash_val]->str, str, str_len+1);
        pHead[hash_val]->visit_time = 1;
        pHead[hash_val]->next = NULL;
        return 1;
    }else{
        while(ptr->next){
            if(strcmp(ptr->str, str) == 0){
                ptr->visit_time ++;
                return ptr->visit_time;
            }
            ptr = ptr->next;
        }
        if(strcmp(ptr->str, str) == 0){
            ptr->visit_time ++;
            return ptr->visit_time;
        }else{
            temp = (word_visit *)malloc(sizeof(word_visit));
            temp->str = (char *)malloc(str_len+1);
            memcpy(temp->str, str, str_len+1);
            temp->visit_time = 1;
            temp->next = NULL;
            ptr->next = temp;
            return 1;
        }
    }
    return 0;
}

void free_visit(word_visit **pHead){
    int i;
    word_visit *ptr, *tmp;
    for(i = 0 ; i < hash_size; i ++){
        ptr = pHead[i];
        if(ptr != NULL){
            while(ptr){
                tmp = ptr;
                ptr = ptr->next;
                free(tmp);
            }
        }
        pHead[i] = NULL;
    }
}

int find_word(word_node **pHead, char *str){
    int hash_val = hash_(str);
    word_node *ptr = pHead[hash_val];

    if(ptr == NULL){
        return -1;
    }else{
        while(ptr){
            if(strcmp(ptr->str, str) == 0){
                return ptr->times;
            }
            ptr = ptr->next;
        }
        return -1;
    }
}

void construct_word(word_node **pHead, char **words, int wordsSize){
    int i;
    int hash_val;
    int word_len;
    word_node *ptr;
    for(i = 0 ; i < wordsSize ; i ++){
        hash_val = hash_(words[i]);
        word_len = strlen(words[i]);
        ptr = pHead[hash_val];
        if(pHead[hash_val] == NULL){
            pHead[hash_val] = (word_node *)malloc(sizeof(word_node));
            pHead[hash_val]->str = (char *)malloc(word_len+1);
            memcpy(pHead[hash_val]->str, words[i], word_len+1);
            pHead[hash_val]->times = 1;
            pHead[hash_val]->next = NULL;
            continue ;
        }else{
            while(ptr->next){
                if(strcmp(ptr->str, words[i]) == 0){
                    ptr->times ++;
                    break;
                }
                ptr = ptr->next;
            }
            if(ptr->next == NULL){
                if(strcmp(ptr->str, words[i]) == 0){
                    ptr->times ++;
                    continue;
                }else{
                    word_node *temp = (word_node *)malloc(sizeof(word_node));
                    temp->str = (char *)malloc(word_len+1);
                    memcpy(temp->str, words[i], word_len+1);
                    temp->times = 1;
                    temp->next = NULL;
                    ptr->next = temp;
                }
            }
        }
    }
}

char *get_sub_str(char *str, int len){
    int i;
    char *sub_str = (char *)malloc(sizeof(char)*len+1);
    for(i = 0 ; i < len ; i ++){
        sub_str[i] = str[i];
        if(str[i] == '\0')break;
    }
    sub_str[i] = '\0';
    return sub_str;
}

int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
    int i, j, cnt, flag, s_len;
    if(s == NULL){
        *returnSize = 0;
        return NULL;
    }
    s_len = strlen(s);
    if(s_len <= 0 || wordsSize <= 0){
        *returnSize = 0;
        return NULL;
    }
    int *ans = (int *)malloc(sizeof(int)*wordsSize);

    word_directory = (word_node **)malloc(sizeof(word_node *)*hash_size);
    word_visit_directory = (word_visit **)malloc(sizeof(word_visit *)*hash_size);
    for(i = 0 ; i < hash_size ; i ++){
        word_directory[i] = NULL;
        word_visit_directory[i] = NULL;
    }
    construct_word(word_directory, words, wordsSize);

    cnt = 0;
    int word_len = strlen(words[0]);
    for(i = 0 ; i <= s_len-word_len*wordsSize ; i ++){
        free_visit(word_visit_directory);

        flag = 1;
        for(j = 0 ; j < wordsSize ; j ++){
            char *sub_str = get_sub_str(s+i+j*word_len, word_len);
            int visit_time = insert_visit(word_visit_directory, sub_str);
            int word_time = find_word(word_directory, sub_str);
            free(sub_str);
            if(visit_time > word_time){
                flag = 0;
                break;
            }
        }
        if(flag){
            ans[cnt ++] = i;
        }
    }
    *returnSize = cnt;
    return ans;
}

int main(){
    freopen("input.txt", "r", stdin);

    char *a = "baauxdthqwzuleorburxbkrksgpgchndjqygttnmsnidtwuutotwylhqtwyvfoboebvxukjozrssqonjcifctmsmktkphlelmbkinwxnnrhfhwokfwmaihptazkjmowargifchusybxgyosfkgfupunpvyahowhgdsnhbhbakziipcpzivtyrjpnjqwxogftaubbbcdmdnwspmtajpaayrpjjogyworwiszmxfacswxkkqkthmwhdnqnbzlzncxxxxjwclywixguosoxemfizvxduicjmajlzujbgizofgivyytdmanmxkrsuvdixmwwjfzpnzfvhpsfqnkcnxqljjfffkoezkbircxfdecktwslkcozceklqrrvchzdtclkhkrmotzjqrvctlbvrojhfcejjgmcizmrjgezzdlrwgvptxnknyssawejcsnnsbgdhmdjroanwyfpvuzistcssidwbqjvrsyzediytklpisgfminebsyvabsdtdylvzmccuaygnnrgwwsemzhezdgbvkuykhwltyqpaoyndptzlodxnndmqkplwmlivjwpjmgjcexftshhgmgvzkkpwbcupqelzacloiuqptwkofrurasrkegiflcvbgichknvuiojdmwrrpoipizbmijrtlouuwydimadwoozamtrcjatrbvdjewcsnymjxrujrxhgniiabaemcxddugnzfrtsqfdnyxypwfvmpgorgsdkrjpmrclwwgomnublrbaqiycxeqqmkwwbflnwqatmijavfdgzehpmhtlljcxvyvwdgmbyowmximsnrzmvidjpwvchxbcxwzaenbfbyraggtvxuivelevkbxryauvwvxcibhlbbmjhfeebozfcgamhzdizxfxsdzcgjohkasrhwxinzpphpboogwpeemyjnbpwryirqzaozibazshotveautgyhgjuhytyybrodtecdgccalqugwwcrecykltujoujpmzsfewlmanmleiscewukzsvknpwbjftxflfliqxkdlwjuqmamglnagyoxwrgdkgkwlvgbuqggoqaeeatkngktgascszicfsasqivkbbqprswvvphivueeuwgoxotejvwzerjhtcwmuukrjtahnelkctyaktgtpduvwdcrhaeevqvgjvnzbajgujggfmzurtroyvfivlmsdhznfomipxolgwrllshcnysnvavrnjlrtmgadsisrzfxvylgqslftfsohqhxzvoshuskodefclexjrgbmtgfabvirffscvnjrfwhkcomqumzmudypjfpmczdjgwlbjxuqvdbxrpnmdpyxsyoddeqfdvpmtcpczkvunyuhpjvtytssthywnqdqlscfvsjweertelauuxnvqhpjonhbdlurfywcshzymqsqdumzszukhkwxzdbdqxuwxsaqzzonrigufswxssjbcfaeldhdadzyxaqwbgmtpspwkntegc";

//    printf("%d\n", strlen(a));
    char **b;
    b = (char **)malloc(sizeof(char *)*300);
    for(int i = 0 ; i < 300; i ++){
        b[i] = (char *)malloc(sizeof(char)*100);
    }
    int n;
    int ans, *ans_num;
    scanf("%d", &n);
    for(int i = 0 ; i < n ; i ++){
        scanf("%s", b[i]);
    }

    ans_num = findSubstring(a, (char **)b, n, &ans);

    for(int i = 0 ; i < ans; i ++){
        printf("%d\t", ans_num[i]);
    }
    printf("\n");

    return 0;
}




























//
//int is_ok;
//
//bool str_cmp(char *a, char *b){
//    if(a == NULL || b == NULL){
//        return 0;
//    }
//
//    int i = 0, flag = 1;
//    while(true){
//        if(a[i] == '\0' && b[i] != '\0'){
//            flag = 0;
//            break;
//        }
//        if(b[i] == '\0'){
//            flag = 1;
//            break;
//        }
//        if(a[i] != b[i]){
//            flag = 0;
//            break;
//        }
//        i++;
//    }
//    return flag;
//}
//
//void permutation_str(char *s, char *pattern, char **words, int wordsSize, bool *visit, int step){
//    if(step == wordsSize){
//        is_ok = 1;
//        return;
//    }
//
//    int i;
//    for(i = 0 ; i < wordsSize ; i ++){
//        if(visit[i])continue;
//        int pattern_len = strlen(pattern);
//        strcat(pattern, words[i]);
//        if(str_cmp(s, pattern)){
//            visit[i] = true;
//            permutation_str(s+pattern_len, pattern+pattern_len, words, wordsSize, visit, step+1);
//            visit[i] = false;
//        }
//        pattern[pattern_len] = '\0';
//        if(is_ok)return;
//    }
//
//}
//
//int* findSubstring(char* s, char** words, int wordsSize, int* returnSize) {
//
//    if(s == NULL){
//        *returnSize = 0;
//        return NULL;
//    }
//    int i, s_len;
//    s_len = strlen(s);
//    if(s_len <= 0){
//        *returnSize = 0;
//        return NULL;
//    }
//    int *ans_num = (int *)malloc(sizeof(int)*s_len);
//    char pattern[s_len];
//    if(wordsSize <= 0){
//        *returnSize = 0;
//        return NULL;
//    }
//    bool visit[wordsSize];
//    int word_len = strlen(words[0]);
//    memset(visit, false, wordsSize);
//    memset(pattern, 0, s_len);
//
//    int s_i = 0;
//    int cnt = 0;
//
//    for(s_i = 0 ; s_i <= s_len - word_len*wordsSize ; s_i ++){
//        for(i = 0 ; i < wordsSize ; i ++){
//            int pattern_len = strlen(pattern);
//            strcat(pattern, words[i]);
//            is_ok = 0;
//            if(str_cmp(s+s_i, pattern)){
//                visit[i] = true;
//                permutation_str(s+s_i+pattern_len, pattern+pattern_len, words, wordsSize, visit, 1);
//                visit[i] = false;
//            }
//            pattern[pattern_len] = '\0';
//            if(is_ok)break;
//        }
//        if(is_ok){
//            ans_num[cnt ++] = s_i;
//            is_ok = 0;
//        }
//    }
//    *returnSize = cnt;
//    return ans_num;
//
//}
//

