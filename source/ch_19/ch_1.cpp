#include "../std_lib_facilities.h"

void suspicious(int size, int x)
{
	int* p = new int[size]; // memóriaterület lefoglalása intekre

	if(x == 0) throw std::exception(); // ha x nulla kivételt dob

	delete[] p;
}

int main()
try {

	suspicious(5, 0);

	return 0;

} catch (std::exception& e){
	std::cerr << "Error!\n";
	return 1;
}