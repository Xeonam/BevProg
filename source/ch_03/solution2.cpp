#include "../std_lib_facilities.h"

std::string getFirstName(){
    std::string firstName{}; //String típusú változó a névhez
    printf("Enter the name of the person you want to write to ");
    std::getline(std::cin, firstName);
    return firstName;
}

std::string getFriendName(){
    std::string friend_name{};
    printf(" Would you give me the name of one your friends? ");
    std::getline(std::cin, friend_name);
    return friend_name;
}

char getFriendSex(){
    std::string placeholder{}; 
    char friend_sex = 0;
    printf(" Is your friend male (m) or female (f)? ");
    std::getline(std::cin, placeholder); // a getline csak string alapú adatokat tud befogadni, ezért kell egy placeholder
    friend_sex = placeholder.at(0);     // a friend_sex chart átveszi a placeholder tartalmát -> a char az 1 karakter hosszú lehet, de a string típus miatt meg kell
    return friend_sex;                  //adnunk, hogy a 0. karakter kell // at.(1)-re errort dobna mert nincs olyan hosszú eleve string

}

void printSex(char friend_sex, std::string name){
    if (friend_sex == 'm')
        printf("If you see %s please ask him to call me.",name.c_str());
    else if(friend_sex == 'f')
        printf("If you see %s please ask her to call me.",name.c_str());
    else
        printf("Invalid input!");
}

int getFriendAge(){
    std::string placeholder{};
    int age{};
    printf("How old is your friend? ");
    std::getline(std::cin, placeholder);    //a getline csak string típust tud befogadni
    age = std::stoi(placeholder);           // az stoi -> String TO Integer átkonvertálja int típusba a placeholder stringet
    return age;
}

void printAge(int age){
    if (age < 12)
        printf("Next year you will be: %i", age+1);
    else if (age == 17)
        printf("Next year you will be able to vote.");
    else if (age >= 70)
        printf("I hope you are enjoying retirement.");
}

int main(){
    printf("Dear, %s\n", getFirstName().c_str());
    
    //task 2.
    printf("\tHow are you? I'm fine. I'm miss you very much.");
    
    //task 3.
    std::string friend_name = getFriendName();
    printf("Have you seen %s lately?", friend_name.c_str());

    //task 4.
    printSex(getFriendSex(),friend_name);

    //task 5.
    int age = getFriendAge();
    printf("I hear you just had a birthday and you are %i years old.", age);
    if (age <= 0 || age >= 110)
        simple_error("You're kidding!");
    
    //task 6.
    printAge(age);

    //task 7.
    printf("\nYours sincerely, \n\n");
    printf("Sidlóczki Balázs Ádám");

    return 0;
}