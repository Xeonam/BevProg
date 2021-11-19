#include "../std_lib_facilities.h"

int main(){
    int birth_year = 2002;
    //task 2: . Output your birth_year in decimal, hexadecimal, and octal form.
    cout << "Decimal:\t" << birth_year << "\n"
        << "Hexadecimal:\t" << hex << birth_year << "\n"
        << "Octal:\t\t" << oct << birth_year << "\n";

    cout << "\nAge: \n";
    cout << dec << 18 << "\t(Decimal)\n";

    //task 8
    int a, b, c, d;
    cin >> a >> oct >> b >> hex >> c >> d;
    //dec a, oct b, hex c, d

    //hexbe beolvassa a c,d-t -> majd kiíratjuk decbe
    //octba beolvassa a b-t -> majd kiirítjuk decbe
    //decbe beolvassa a a-t -> majd kiirítjuk decbe
    cout << a << '\t'<< b << '\t'<< c << '\t'<< d << '\n' ;

    //task 9
    cout << defaultfloat << 1234567.89 << "\t" << fixed << 1234567.89 << "\t" << scientific << 1234567.89 << "\n";

    //task 10

    cout << "|" << setw(8) << "Last name" << "\t|" << setw(8) << "First name" << "\t|" << setw(16) << "Telephone number" << "\t|" << setw(25) << "Email address" << "|\n";
    cout << "|" << setw(8) << "Kiss" << "\t|" << setw(8) << "János" << "\t|" << setw(16) << "06201234567" << "\t|" << setw(25) << "kisjani@gmail.com" << "|\n";
    cout << "|" << setw(8) << "Nagy" << "\t|" << setw(8) << "Bence" << "\t|" << setw(16) << "06201234568" << "\t|" << setw(25) << "nagybence@gmail.com" << "|\n";
    cout << "|" << setw(8) << "Balogh" << "\t|" << setw(8) << "Béla" << "\t|" << setw(16) << "06201234569" << "\t|" << setw(25) << "baloghbela@gmail.com" << "|\n";
    cout << "|" << setw(8) << "Lakatos" << "\t|" << setw(8) << "Dezső" << "\t|" << setw(16) << "06201234587" << "\t|" << setw(25) << "lakatosdezso@gmail.com" << "|\n";
    cout << "|" << setw(8) << "Oláh" << "\t|" << setw(8) << "György" << "\t|" << setw(16) << "06201234577" << "\t|" << setw(25) << "olahgyorgy@gmail.com" << "|\n";
    cout << "|" << setw(8) << "Horváth" << "\t|" << setw(8) << "Sándor" << "\t|" << setw(16) << "06201234577" << "\t|" << setw(25) << "horvathsandor@gmail.com" << "|\n";

    return 0;
}