#include "../std_lib_facilities.h"

struct Point{
    double x;
    double y;
};

//A két vektor egyenlő-e?
void is_equal(vector<Point> original_points, vector<Point> processed_points){
    if (original_points.size() != processed_points.size()){
        cout << "Something's wrong!";
    }
    for (int i = 0; i < original_points.size(); i++){
        if (original_points[i].x != processed_points[i].x){
            cout << "Something's wrong!\n";
            cout << original_points[i].x << " is not equal with " << processed_points[i].x << endl;

        }
        if (original_points[i].y != processed_points[i].y){
            cout << "Something's wrong!\n";
            cout << original_points[i].y << " is not equal with " << processed_points[i].y << endl;
        }
    }
};

int main()
try{
    double x,y;
    vector<Point> original_points; //Point típusú vektor az elemek tárolásához.
    
    ///HA EGY KÜLSŐ FILEBÓL AKARUNK 7 SZÁMOT BEKÉRNI //utána ismételt beolvasásnál csak meg kell nyitni a filet .opennel
    /*
    cout << "Please enter input file name: "; //Megkérdezzük melyik filet akarjuk megnyitni.
    string ifname;
    cin >> ifname; //Beolvassuk a file namet egy string változóba.
    ifstream ist {ifname}; //ist is an input stream for the file named name
    if(!ist) error("Can't open ifile,", ifname);

    while(ist >> x >> y){
        original_points.push_back(Point{x,y});
    }
    ist.close(); //Bezárjuk a filet.
    */

    //HA A FELHASZNÁLÓTÓL KÉRÜNK BE 7
    int szam = 0;
    while(szam !=7){
        cin >> x >> y;
        original_points.push_back(Point{x,y});
        ++szam;
    }
    
    //A beolvasott file értékeinek kiírása / A Felhasználó számai:
    for(const auto& point:original_points )
	{
		cout<<'('<<point.x<<", "<<point.y<<')'<<endl;
	}
    

    string ofname = "mydata.txt";
    ofstream ost {ofname};
    if(!ost) error("Can't open ofile,", ofname);

    for(const auto& point: original_points){
        ost << point.x << " " << point.y << endl; //output streambe kiíratjuk az elemeket.
    }
    ost.close(); //Bezárjuk a filet.
    
    vector<Point> processed_points; //Másik point típusú vektor szintén az adatok tárolására.

    //Ha a felhasználótól kérünk be számot meg kell adni az ifstreamet
    string ifname = "mydata.txt";
	ifstream ist {ifname};
	if (!ist) error("Can't open input file ", ifname);
    while(ist >> x >> y){
        processed_points.push_back(Point{x,y});
    }
    ist.close(); //Bezárjuk a filet.

    //Két vektor kiírása.
    cout << "Original points: \n";
    for(const auto& point:original_points )
	{
		cout<<'('<<point.x<<", "<<point.y<<')'<<endl;
	}

    cout << "Processed points: \n";
    for(const auto& point:processed_points )
	{
		cout<<'('<<point.x<<", "<<point.y<<')'<<endl;
	}
    
    // processed_points[2].x = 5; //Egy adott érték megváltoztatása csak, hogy ellenőrizzük a függvény működik-e
    is_equal(original_points, processed_points);
    
    return 0;

}catch(exception &e){
    cerr << "Error: " << e.what() << '\n';
    return -1;
}catch(...){
    cerr << "Some error.\n";
    return -2;
}
