#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include "Table.h"

using namespace std;
//
class Database 
{
private:
	//map to store all names/tables
	map<string, Table> database;
	string encodeTable(string tableName, Table& table);
	Table evaluateQuery(Table table, string statement);
	Table evaluateBooleanQuery(Table table1, Table table2, string op);
	string invertOperation(string);
	string concatenateWords(vector<string> words);

public:
	// Constructor
	Database();
	// Destructor
	~Database();
	// Adds a single table to the database with respective name
	void addTable(Table table, string name); //good
	// Remove a table from the database
	void dropTable(string name); //good
	// Saves a database to specified file
	void saveDatabase(string filename);//GOOD
	// Loads a database from specified file
	void loadDatabase(string filename);//GOOD
	//Returns a list of all table names from database
	vector<string> listTables(); //GOOD
	// Returns a vector of all Tables
	vector<Table*> getTables(); //GOOD

	// Query command
	Table query(vector<string> select, string from, string where);

	// SELECT vector takes a list of attributes to display. A vector of a single string "*" will signify to
	// keep all attributes
	//
	// FROM string will take the table name and perform the query on that table
	//
	// WHERE string must be in a proper format to function properly. Each statement beside an AND or OR operation
	// must be surrounded by parenthesis. In addition, the NOT operation can only be performed on a single evaluation.
	// Numbers should not use apostrophes, while strings should. See examples for an idea of what will work and what 
	// will not. The entire statement should not be within a single parenthesis set.
	//
	// Example Where Strings that Will Work:
	//
	// "Age <= 20"
	// "((Age > 20) OR (NOT Index = 1)) AND (Bool <> 'Yes')"  
	// "(Age <= 12) AND (NOT Index < 3) OR (Bool = 'Yes')"
	// 
	// Example Where Strings that Will NOT Work:
	//
	// "(Age <= 20)"
	// "NOT(Age <= 20)"
	// "Age > 20 AND Bool = 'Yes'"
	
};

#endif 
