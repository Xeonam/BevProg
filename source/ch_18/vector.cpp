#include "../std_lib_facilities.h"

vector<int> gv = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512};

void f(vector<int> v){
    //3.a
    vector<int> lv(v.size());

    //3.b
    for(int i = 0; i <gv.size(); i++){
        lv[i] = gv[i];
    }

    //3.c
    for(int i = 0; i < lv.size(); i++){
        cout << lv[i] << " ";
    }

    //3.d
    vector<int> lv2 = v;

    //3.e
    cout << "\n";
    for(int i = 0; i < lv2.size(); i++){
        cout << lv2[i] << " ";
    }
    cout << "\n";

}

int main(){
    //4.a
    f(gv);

    //4.b
    vector<int> vv = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};

    //4.c
    f(vv);

    return 0;
}