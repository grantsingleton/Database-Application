#ifndef TABLE_H
#define TABLE_H

#include "Record.h"
#include <vector>
#include <iterator>
#include <map>
#include <functional>

using namespace std;

class Table
{
	friend class Database;
private:
	vector<Record> records;
	vector<string> attributes;
	bool primaryKeyAssigned;
	string primaryKey;
	int primaryKeyIndex;

	int getAttributeIndex(string attribute);

public:
	void printTable(); //debug function
	Table(); //Good
	Table(const vector<string>& attributes); //Good
	~Table(); //Maybe good

	void addAttribute(string attribute); //Good
	void deleteAttribute(string attribute); //Good
	void insertRecord(Record record); //Good
	const vector<string>& getAttributes(); //Good //CHANGED FROM CONST TO NORMAL
	int getNumberRecords(); //Good
	vector<Record>::iterator getRecordIterator(); //Good
	vector<Record>& getRecords(); //Good
	void setKey(string attribute); //GOOD
	Table getCrossJoin(Table& other_table); //GOOD
	Table getNaturalJoin(Table& other_table);
	int getCount(string attribute); //Good
	string getMin(string attribute); //Good
	string getMax(string attribute); //Good
};

#endif
