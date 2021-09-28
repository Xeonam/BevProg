#include <iostream>
#include "../std_lib_facilities.h"

int main(){
    //task 1.
    std::string firstName{}; //String típusú változó a névhez
    std::cout << "Enter the name of the person you want to write to ";
    std::cin >> firstName;
    std::cout << "Dear " << firstName << ","  << std::endl;

    //task 2.
    std::cout << "\tHow are you? I'm fine. I'm miss you very much.";

    //task 3.
    std::string friend_name{};
    std::cout << " Would you give me the name of one your friends? ";
    std::cin >> friend_name;

    std::cout << "Have you seen " << friend_name << " lately?" << std::endl;

    //task 4.
    char friend_sex = 0;
    std::cout << "Is your friend male (m) or female (f)? ";
    std::cin >> friend_sex;
    if (friend_sex=='m')
        std::cout << "If you see " << friend_name << " please ask him to call me." << std::endl;
    else if (friend_sex == 'f')
         std::cout << "If you see " << friend_name << " please ask her to call me." << std::endl;

    //task 5.
    int age{};
    std::cout << "How old is your friend? ";
    std::cin >> age;

    std::cout << "I hear you just had a birthday and you are " << age << " years old." << std::endl;

    if (age <= 0 || age >= 110)
        simple_error("You're kidding!");

    //task 6.
    if (age < 12)
        std::cout << "Next year you will be: " << age + 1 << std::endl;
    else if (age == 17)
        std::cout << "Next year you will be able to vote." << std::endl;
    else if (age >= 70)
        std::cout << "I hope you are enjoying retirement." << std::endl;
    
    //task 7.
    std::cout << std::endl << "Yours sincerely," << std::endl << std::endl;
    std::cout << "Sidlóczki Balázs Ádám" << std::endl;

    return 0;
}