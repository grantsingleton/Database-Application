#include "Database.h"
using namespace std;
#include <iostream>

int main()
{
	Database a;
	Table b;
	a.addTable(b, "Test");
	cout << "Done" << endl;
	return 0;
}