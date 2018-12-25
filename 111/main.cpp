#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void test(int m, int n, int o, int ****returnV){
    int ***V = (int ***)malloc(sizeof(int **)*m);
    for(int i = 0 ; i < m; i ++){
        V[i] = (int **)malloc(sizeof(int *)*n);
        for(int j = 0 ; j < n ; j  ++){
            V[i][j] = (int *)malloc(sizeof(int ) * o);
            for(int k = 0 ; k < o ; k ++){
                V[i][j][k] = i*100 + j*10 + k;
            }
        }
    }
    (*returnV) = V;
}

class A{
public :
    virtual fun() const = 0;
};

class B : public A{
public :
    virtual fun(){
        cout << "this is B!" << endl;
    }
};

class C : public A{
public :
    virtual fun(){
        cout << "this is C!" << endl;
    }
};

int main(){

    A *ptr;
    B b;
    C c;
    ptr = &b;
    ptr->fun();
    ptr = &c;
    ptr->fun();
    return 0;
}
