#include "../std_lib_facilities.h"

int ga[10] = {1,2,4, 8, 16, 32, 64, 128, 256, 512};

//3
void f(int ai[], int n){
    //a
    int la[10];

    //b
    for(int i = 0; i<n; i++){
        la[i] = ga[i];
    }

    //c
    for(int i=0; i < n; i++){
        cout << la[i] << " ";
    }
    cout << "\n";

    //d
    int* p = new int[n];

    //e
    for(int i=0; i < n; i++){
        p[i] = ai[i];
    }

    //f
    for(int i=0; i < n; i++){
        cout << p[i] << " ";
    }
    cout << "\n";

    //g
    delete[] p;

}


int main(){
    //4.a
    f(ga,10);

    //4.b
    int aa[10] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};

    //4.c
    f(aa,10);




    return 0;
}