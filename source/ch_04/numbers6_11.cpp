#include "../std_lib_facilities.h"


int main(){

    double x{};
    double min{};
    double max{};
    std::string unit{};

    constexpr double cm_to_m = 0.01;
    constexpr double in_to_m = 0.0254;
    constexpr double ft_to_m = 0.3048;

    vector<double> values;

    double sum{};

    bool valid = true; // a helyes szám-egység miatt hozzuk létre

    printf("Give me a number with unit (cm, in, ft or m): ");
    while(std::cin >> x >> unit){
        if(unit != "cm" && unit != "in" && unit != "ft" && unit != "m"){
            printf("Not valid unit!\n");
            valid = false; // ha nem érvényes az egység 
        }
        if(unit == "cm"){
            x = x*cm_to_m;
        }
        else if(unit == "ft"){
            x = x*ft_to_m;
        }
        else if(unit == "in"){
            x = x*in_to_m;
        }
        
        if (valid){ // csak akkor fut bele, ha helyes értékeket adtunk meg
            values.push_back(x);

            if (max < x){
            max = x;
            printf("The largest so far.\n");
            }
            else if(min > x){
            min = x;
            printf("The smallest so far.\n");
            }
        }
        valid = true;

        printf("Give me a number with unit (cm, in, ft or m): ");
    }

    sort(values);
    printf("\nThe values: \n");
    for(auto x: values){
        sum += x;
        printf("%.2f meter(s)\n", x);
    }
    printf("\n\nThe smallest number: %.2f meter(s).\n", min);
    printf("The largest number: %.2f meter(s).\n", max);
    printf("The number of values: %li.\n", values.size());
    printf("The sum of values: %.2f meter(s).\n", sum);


    return 0;
}