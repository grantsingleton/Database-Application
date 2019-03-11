#ifndef RECORD_H
#define RECORD_H

#include <string>
#include <vector>

using namespace std;

class Record 
{
private:
	// Vector to store all entries
	vector<string> entries;

public:
	friend class Table;
	// Constructor creates a record of size: 'size'
	Record(int size);

	// Returns the size of a record
	int getRecordSize();

	// Mutator sets entry at given index to: 'entry'
	void setEntry(int index, string entry);

	// Accessor reads entry at given index
	string getEntry(int index);
	
	// Overloaded operator
	bool operator== (const Record &record);
};

#endif 





