#ifndef DATABASE_H
#define DATABASE_H

#include <string>
#include "Table.h"

using namespace std;

class Database 
{
private:
	//map to store all names/tables
	map<string, Table> database;
	string encodeTable(string tableName, Table& table);
	Table evaluateQuery(Table table, string statement);
	Table evaluateBooleanQuery(Table table1, Table table2, string op);
	string invertOperation(string);

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
	
};

#endif 
