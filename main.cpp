#include <vector>
#include <iostream>
#include <algorithm>
#include"QUOTE.h"
using namespace std;
int main(int argc, char**argv)
{
	Quote b1("Áú×åI", 128);
	//bulk_quote b2(string("Áú×åII"), 128.0, 10, 0.7);
	print_total(cout, b1, 10);
	//print_total(cout, b2, 10);
	system("pause");
	return 0;
}
