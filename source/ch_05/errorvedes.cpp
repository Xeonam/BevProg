#include "../std_lib_facilities.h"
int main()
    try{
        //1. Cout << "Success!\n";
        cout << "1. Success!\n"; // Nagybetű volt a cout.

        //2. cout << "Success!\n;
        cout << "2. Success!\n"; // Lemaradt egy:  ".
        
        //3. cout << "Success" << !\n"
        cout << "3. Success" << "!\n"; // Nyitó " és ; lemaradt.

        //4. cout << success << '\n';
        std::string success = "4. Success!";
        cout << success << '\n';  // Nem volt success változó definiálva.

        //5. string res = 7; vector<int> v(10); v[5] = res; cout << "Success!\n";
        int res = 7; // a vector<int> csak int típusú értékeket tud tárolni, ezért a "res" változónak is ilyen típust kell megadni.
        vector<int> v(10);
        v[5] = res;
        cout << "5. Success!\n";

        //6. vector<int> v(10); v(5) = 7; if (v(5)!=7) cout << "Success!\n";
        vector<int> v2(10);
        v2[5] = 7;           // () helyett [] zárójelek kellenek.
        if (v2[5] == 7){     // Itt is.
            cout << "6. Success!\n";
        }

        //7. if (cond) cout << "Success!\n"; else cout << "Fail!\n";
        bool cond = true; // bool típusú cond változót kell létrehozni.
        if (cond){ // Mert a feltételben ilyen változónév szerepel
            cout << "7. Success!\n";
        }
        else{
            cout << "Fail!\n";
        }

        //8. bool c = false; if (c) cout << "Success!\n"; else cout << "Fail!\n";
        bool c = true;  // c változót igazra kell állítani.
        if (c){
            cout << "8. Success!\n"; 
        }
        else{
            cout << "Fail!\n";
        }

        //9. string s = "ape"; boo c = "fool"<s; if (c) cout << "Success!\n";
        string s = "ape";
        bool c2 = "aa"<s; // bool típusúnak kell lennie, olyan stringre kell cserélni a "fool"-t aminek a számértéke rövidebb mint az "ape"-nek.
        if (c2){    // Pl.: "ey" nem lenne jó, de az "aa" jó.
            cout << "9. Success!\n";
        }

        //10. string s = "ape"; if (s=="fool") cout << "Success!\n";
        string s2 = "fool";  // Az if ág miatt az s2 stringet át kell írni "fool"-ra.
        if (s2=="fool"){
            cout << "10. Success!\n";
        }

        //11. string s = "ape"; if (s=="fool") cout < "Success!\n";
        string s3 = "fool";  // if ág miatt s3-at megint át kell írni "fool"-ra.
        if (s3=="fool"){    
            cout << "11. Success!\n";   // egy db  "<" lemaradt.
        }

        //12. string s = "ape"; if (s+"fool") cout < "Success!\n";
        string s4 = "fool";
        if (s4 == "fool"){ // 2 string összefűzése nem fog igaz/hamis értékkel visszatérni
            cout << "12. Success!\n"; // Egy < lemaradt.
        }

        //13. vector<char> v(5); for (int i=0; 0<v.size(); ++i) ; cout << "Success!\n"; 
        vector<char> v3(5);
        for (int i=0; i<v.size(); ++i){ // 0 helyett az i ciklusváltozót kell a vektor hosszához hasonlítani, különben 0 esetén végtelen ciklusba keveredünk.
            cout << "13. Success!\n";
            i += 1;
        }

        //14. vector<char> v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n";
        vector<char> v4(5);
        for (int i=0; i<=v.size(); ++i){ // Nincs benne hiba.
            cout << "14. Success!\n";
        }

        //15. string s = "Success!\n"; for (int i=0; i<6; ++i) cout << s[i];
        printf("15. ");
        string s5 = "Success!\n";
        for (int i=0; i<10; ++i){ // Ha a ciklus 6-ig megy, akkor csak az első 6 karaktert írná ki.
            cout << s5[i];
        }

        //16. if (true) then cout << "Success!\n"; else cout << "Fail!\n";
        if (true){
            cout << "16. Success!\n";   //Cpp-ben nincs olyan keyword, hogy "then".
        
        }
        else{
            cout <<"Fail!\n";
        }

        //17. int x = 2000; char c = x; if (c==2000) cout << "Success!\n";
        int x = 2000;
        //char c3 = static_cast<char>(x);  // Achar kevesebb bitben tárolódik mint az int, ezért nem fogja a pontos értéket visszaadni.
        int c3 = x;
        if (c3 == 2000){
            cout << "17. Success!\n";
        }

        //18. string s = "Success!\n"; for (int i=0; i<10; ++i) cout << s[i];
        printf("18. ");
        string s6 = "Success!\n";
        for (int i = 0; i <= 8; ++i){ // Elég lenne 8-ig menni. Mert 8 karakterből áll a szó.
            cout << s6[i];
        }

        //19. vector v(5); for (int i=0; i<=v.size(); ++i) ; cout << "Success!\n";
        vector<int> v5(5); // Meg kell adnunk, hogy milyen típusú lesz a vektorunk.
        for (int i=0; i<v5.size(); ++i){ // <= helyett érdemesebb <-et használni, hogy ne kapjunk majd "range errort".
            cout << "19. Success!\n";
        }

        //20. int i=0; int j = 9; while (i<10) ++j; if (j<i) cout << "Success!\n";
        int i = 0;
        int j = 9;
        while (i<=j){ // 9-ig fogja kiíratni.
            if (j>i){ // Amíg a j nagyobb és eleget tesz a feltételnek fogja kiírni.
                cout << "20. Success!\n";
            }
            ++i; // Növeljük i értékét.
        }

        //21.  int x = 2; double d = 5/(x–2); if (d==2*x+0.5) cout << "Success!\n";
        int x2 = 2;
        int d2 = 5/(x2-1); // int-re kell állítani double helyett, illetve -2 helyett -1-et vonunk ki.
        if (d2== 2*(x2+0.5)){ // Zárójel.
            cout << "21. Success!\n";
        }

        //22. string<char> s = "Success!\n"; for (int i=0; i<=10; ++i) cout << s[i];
        printf("22. ");
        string s7 = "Success!\n"; // ?? Egy string nem lehet char.
        for (int i=0; i<=8; ++i){
            cout << s7[i];
        }

        //23. int i=0; while (i<10) ++j; if (j<i) cout << "Success!\n";
        int i2 = 0;
        int j2 = 0; // Eddig nem volt deklarálva.

        while (i2<10){
            if (j2<i2){ // Mivel a j2 értékét nem változatom mindig ki fog íródni.
                cout << "23. Success!\n";
            }
            i2++;
        }

        //24. double x = 4; double d = 5/(x–2); if (d=2*(x/2)+0.5) cout << "Success!\n";
        double x3 = 4;
        double d3 = 5/(x3-2);
        if (d3==2*(x3/4)+0.5){ // /2 helyett /4-el jön ki az igaz if ág.
            cout << "24. Success!\n";
        }

        //25. cin << "Success!\n";
        cout << "25. Success!\n"; //Vagy beolvassunk cin-nel majd kiíratjuk.

        //Védése feladata
        vector<int> szamok = {1,2,3,4,5};
        for(int i = 0; i <= szamok.size(); i++){
            if (i >= szamok.size()) error("Range hiba található a vectorban.");
            std::cout << i+1 << ". szám: " <<  szamok[i] << '\n';
        }

        
        keep_window_open();
        return 0;
    }

    catch (exception &e){

        cerr << "error: " << e.what() << '\n';
        keep_window_open();
        return 1;
    }
    catch (...){
        cerr << "Oops: unknown exception!\n";
        keep_window_open();
        return 2;
}