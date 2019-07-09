#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* simplifyPath(char* path) {
    int pathLen = strlen(path);
    int i = 0;
    char *newPath = (char *)malloc(sizeof(char)*pathLen);
    int newPathPtr = 0;
    while(i < pathLen){
        if('/' == path[i]){
            if(i+1 < pathLen){
                if('.' == path[i+1]){
                    if(i+2<pathLen && '.' == path[i+2]){
                            if(i+3<pathLen && '/' != path[i+3]){
                                newPath[newPathPtr ++] = path[i ++];
                                while(i < pathLen && '/' != path[i]){
                                    newPath[newPathPtr ++] = path[i++];
                                }
                            }else{
                                if(newPathPtr > 0) newPathPtr --;
                                while(newPathPtr > 0 && '/' != newPath[newPathPtr]){
                                    newPathPtr --;
                                }
                                i ++; i ++; i ++;
                                //if(newPathPtr > 0 && '/' == newPath[newPathPtr]) newPathPtr --;
                            }

                    }else if( i+2 < pathLen && '/' != path[i+2]){
                        newPath[newPathPtr ++] = path[i ++];
                        while(i < pathLen && '/' != path[i]){
                            newPath[newPathPtr ++] = path[i++];
                        }
                    }else{
                        i ++; i ++;
                    }
                }else if('/' == path[i+1]){
                    i ++;
                }else{
                    newPath[newPathPtr ++] = path[i ++];
                    while(i < pathLen && '/' != path[i]){
                        newPath[newPathPtr ++] = path[i++];
                    }
                }
            }else{
                i ++;
            }
        }else{
            i++;
        }
    }
    if(0 == newPathPtr){
        newPath[newPathPtr++] = '/';
    }
    newPath[newPathPtr] = '\0';
    return newPath;
}

int main()
{
    printf("%s\n", simplifyPath("/hidden."));
    return 0;
}
