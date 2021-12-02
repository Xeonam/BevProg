#include "../std_lib_facilities.h"

int main(){
    string name;
    int age{};
    std::cout << "Writing to the file \n";
    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Enter your age: ";
    std::cin >> age;

    //Fileba való írás
    string ofname = "vedes.txt";
    ofstream ost {ofname};
    if(!ost) error("Can't open ofile,", ofname);
    
    ost << name << '\n';
    ost << age;
    ost.close();

    //File beolvasása
    string inputname{};
    int inputage{};
    string ifname = "vedes.txt";
	ifstream ist {ifname};
	if (!ist) error("Can't open input file ", ifname);
    std::cout << "Reading from the file \n";
    ist >> inputname;
    ist >> inputage;
    ist.close(); //File bezárása

    //Konzolra való kiíratás
    std::cout << inputname << std::endl;
    std::cout << inputage << std::endl;



    return 0;
}