
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
*/

#include "../std_lib_facilities.h"

struct Token {
	char kind;
	double value;
	string name;
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { } // ":" jelentése: inicializáljuk a változónkat
	Token(char ch, string s ) :kind(ch), name(s) { }
};

class Token_stream { //Ez adja a tokeneket
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { } //Ez inicializálja a classt

	Token get(); // Új token szerzése
	void unget(Token t) { buffer = t; full = true; } //Elmenti az adott tokent, hogy a gettel belehessen kérni újra

	void ignore(char); //Az adott chart fogja ignorálni
};

const char let = 'L';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';
const char set = 'S';

//Pre-declare
double squareroot();
double powerof();

Token Token_stream::get() //Egy karakter bekérése, majd token készítése
{
	if (full) { full = false; return buffer; }
	char ch;
	cin >> ch;
	switch (ch) {
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case ',':
		return Token(ch);
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget(); //ha számot találunk, akkor visszarakjuk, hogy az egész számot be tudjuk olvasni.
	double val;
	cin >> val; // az egész szám beolvasása
	return Token(number, val); //szám tipusú token visszaadása

	case '#':
	return Token(let);
	}
	default:
		if (isalpha(ch)) { //Megnézzük, hogy az adott char egy betű-e
			string s;		//Ha betű az első betűt belerakjuk a stringbe
			s += ch;
			while (cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch; //1. hiba
			cin.unget();
			if (s == "exit") return Token(quit); //2. hiba
			if (s == "sqrt"){
				double d = squareroot();
				if (d<=0) error("Cannot take the root of a negative number.");
				return Token(number, sqrt(d));
			}		
			if (s == "pow"){
				return Token(number, powerof());
			}
			return Token(name, s);
		}
		error("Bad token");
	}
}

void Token_stream::ignore(char c)
{
	if (full && c == buffer.kind) { //Ha televan a buffer és az olyannal van tele, amit ignorálni akarunk, akkor fut le ez
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin >> ch)
		if (ch == c) return; // visszaadjuk a karaktereket
}

struct Variable { // Névhez hozzárendelunk egy számot
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names; //változókat itt tároljuk el.

double get_value(string s) //A változó értékét kapjuk meg
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ", s);
}

void set_value(string s, double d) // Meglévő változónak az értékét újradefiniáljuk
{
	for (int i = 0; i <= names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ", s);
}

bool is_declared(string s) // Ellenőrizzuk, hogy van-e már ilyen nevű változó a vectorunkban
{
	for (int i = 0; i < names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts;

double expression();

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	double d = expression();
		
	t = ts.get();
	if (t.kind != ')') error("'(' expected");
		return d; //3. hiba Visszaadjuk a () között kiszámolt értéket
	}
	
	case '-':
		return -primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	default:
		error("primary expected");
	}
}

double term()
{
	double left = primary();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	double d = primary();
		if (d == 0) error("divide by zero");
		left /= d;
		break;
		}
		default:
			ts.unget(t);
			return left;
		}
	}
}

double expression()
{
	double left = term();
	while (true) {
		Token t = ts.get();
		switch (t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

double declaration() //Változó készítése
{
	Token t = ts.get();
	if (t.kind != 'a') error("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of ", name);
	double d = expression();
	names.push_back(Variable(name, d));
	return d;
}

double squareroot(){
	return primary();
}

double powerof(){
        Token t1 = ts.get();
        if(t1.kind != '(') {error("Expected '(' at the beginning of POW");}

        double base = expression();

        t1 = ts.get();
        if(t1.kind != ',') {error("Expected ',' between parameters in POW");}

        double exponent_d = expression();
        int exponent = (int)exponent_d;

        t1 = ts.get();
        if(t1.kind != ')') {error("Expected ')' at the end of POW");}

        return pow(base, exponent);
}


double statement()
{
	Token t = ts.get();
	switch (t.kind) {
	case let:
		return declaration();

	default:
		ts.unget(t);
		return expression();
	}
}

void clean_up_mess()
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";




void calculate()
{
	while (true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t = ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}




int main(){
try {
	names.push_back(Variable("k", 1000));
	calculate();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}}
