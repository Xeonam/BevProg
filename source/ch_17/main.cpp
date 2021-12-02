#include "../std_lib_facilities.h"

//4.
void print_array10(ostream &os, int *a) //csak 10 elemig írja ki
{
    for (int i = 0; i < 10; ++i) 
    {
        os << a[i] << "\n";
    }
}

//7.
void print_array(ostream& os, int*a, int n){
    for(int i = 0; i < n; ++i){
        os << a[i] << "\n";
    }
}
//10.
void print_vector(ostream& os, vector<int> v){
    for(int i = 0; i < v.size(); ++i){
        os << v[i] << "\n";
    }
}
int main()
{
    //1.
    int *intarray = new int[10]; // 10 int típusú helyet foglalunk le a free storeban.

    //2.
    for (int i = 0; i < 10; ++i)
    {
        cout << intarray[i] << " ";
    }

    //3.
    delete[] intarray; // Memóriaszivárogatás miatt kell.

    //5.
    cout << "\n-------5-------\n";
    int *intarray2 = new int[10];
    for (int i = 0; i < 10; ++i){
        intarray2[i] = 100 + i;
    }
    print_array10(cout, intarray2); //kiíratás
    delete[] intarray2;

    //6.
    cout << "-------6-------\n";
    int *intarray3 = new int[11];
    for (int i = 0; i < 11; ++i){
        intarray3[i] = 100 + i;    
    }
    print_array10(cout, intarray3); //az utolsó tagját nem fogja kiírni
    delete intarray3;

    //8.
    cout << "-------8-------\n";
    int* intarray4 = new int[20];
    for (int i = 0; i < 20; ++i){
        intarray4[i] = 100+i;
    }
    print_array(cout, intarray4, 20);
    delete intarray4;


    //10.
    cout << "-----v10-----\n";
    vector<int> intvector(10);
    for(int i = 0; i < intvector.size(); i++){
        intvector[i] = 100+i;
    }
    print_vector(cout,intvector);

    cout << "-----v11-----\n";
    vector<int> intvector2(11);
    for(int i = 0; i < intvector2.size(); i++){
        intvector2[i] = 100+i;
    }
    print_vector(cout,intvector2);

    cout << "-----v12-----\n";
    vector<int> intvector3(20);
    for(int i = 0; i < intvector3.size(); i++){
        intvector3[i] = 100+i;
    }
    print_vector(cout,intvector3);

    

    //SECOND PART
    cout << "SECOND PART" << "\n";
    //1.
    int i1 = 7;
    int* p1 = &i1;

    //2.
    cout << "----2----\n";
    cout << p1 << "\n";  //p1 értéke
    cout << *p1 << "\n"; //p1 melyik intre utal.
    
    //3.
    int* p2 = new int[7];
    for(int i = 0; i < 7; i++){
        p2[i] = pow(2,i);
    }
    //4.
    cout << "---4----\n";
    print_array(cout, p2, 7);
    cout << p2 << "\n";

    //5.
    int* p3 = p2;

    //6.
    p1 = p2;

    //7.
    p3 = p2;

    //8.
    cout << "----8----\n";
    cout << "p1: " << p1 << "\n";
    cout << "*p1: " << *p1 << "\n";
    cout << "p2: " << p2 << "\n";
    cout << "*p2: " << *p2 << "\n";
    
    //9.
    delete[] p2;

    //10.
    p1 = new int[10];
    for(int i = 0; i < 10; ++i){
        p1[i] = pow(2,i);
    }

    //11.
    p2 = new int[10];

    //12.
    cout << "---12---\n";
    for(int i = 0; i < 10; i++){
        p2[i] = p1[i];
    }
    print_array(cout, p2, 10);
    delete[] p1;
    delete[] p2;

    //13.

    cout << "----13----\n";
    vector<int> v1(10);
    for(int i = 0; i<v1.size(); i++){
        v1[i] = pow(2,i);
    }

    vector<int> v2(10);
    for(int i = 0; i<v2.size(); i++){
        v2[i] = v1[i];
    }
    print_vector(cout, v2);

    return 0;
}