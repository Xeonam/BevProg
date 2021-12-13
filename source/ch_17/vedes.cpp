#include "../std_lib_facilities.h"

ostream& print_array(ostream& os,char* b,int a){ 
    os << "A tömb mérete: " << a << endl;
    for(int i=0; i<a ; i++){
            os << b[i] << endl;
    }
    return os;   
    
}





int main(){
    char* tomb =new char[20] {'a','b','c','d','e','f'};
    print_array(cout,tomb,20);   

    delete[] tomb;    //felszabadítjuk a lefoglalt memóriát
    return 0;
}