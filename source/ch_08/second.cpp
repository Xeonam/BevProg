#include "../std_lib_facilities.h"

void swap_v(int a, int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
    std::cout << "x = " << a << " ";
    std::cout << "y = " << b << '\n';
}
void swap_r(int& a, int& b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}
/* Ez a függvény nem jó, mert konstans értéket nem tudunk megváltoztatni.

void swap_cr(const int& a, const int& b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}
*/ 

int main(){
    //1. féle próbák:
    
    int x = 7;
    int y = 9;
    swap_v(x,y);
    printf("Első függvény hatása: ");
    std::cout << "x = " << x << " ";
    std::cout << "y = " << y << '\n';
    // a függvényen belül az értékek megcserélődnek, de mivel
    // csak másolva vannak az értékeik a main függvényen belül
    // nincsenek hatással egymásra
    swap_r(x,y);
    printf("Második függvény hatása: ");
    std::cout << "x = " << x << " ";
    std::cout << "y = " << y << '\n';
    // mivel referencia alapján másoljuk az értékét
    // itt is hatással van a függvény az x és y változóra.
    //--------------------------------------------------------
    
    //2. féle próbák:
    swap_v(7,9);
    //Lefut, de mint az első példában itt a mainen belül nem
    //történik változás

    //swap_r(7,9)
    //Nem fut le, mert a referenciával egy adott memóriában elfoglalt
    //helyre tudunk mutatni, itt pedig nem olyan értékeket adunk meg.
    //------------------------------------------------------------
    
    //3. féle próbák:
    /*
    const int cx = 7;
    const int cy = 9;
    swap_v(cx, cy);
    swap_r(cx, cy);

    Ezek a példák nem futnak le, mert a  függvények int típusú értéket
    várnak itt pedig const int típusúakat próbálunk megadni.   
    */
    //--------------------------------------------------------------
    
    //4. féle próbák:
    /*
    double dx = 7.7;
    double dy = 9.9;
    swap_v(dx, dy);
    swap_r(7.7, 9.9);

    Ugyan az történik, mint az imént. Double típusúra nem fog működni.
    */
    return 0;
}