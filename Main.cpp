#include "database.h"
#include "Functions.h"

using namespace std;
#include <iostream>

int main()
{
	/* This fills a database (db) with 4 tables:
	 * Busines, User, Review, and Checkin. 
	 * Each table is a subset (1000 records) of
	 * the yelp dataset */
		Database* db = populateDatabase();

	int command;

	while (1)
	{
		// print menu
		cout << "Select one of the following options:" << endl;
		cout << "1) List Users" << endl;
		cout << "2) List Businesses" << endl;
		cout << "3) User information" << endl;
		cout << "4) Business information" << endl;
		cout << "5) User Reviews" << endl;
		cout << "6) Business Reviews" << endl;
		cout << "7) User Query" << endl;

		// get command
		cin.clear();
		cin >> command;

		// process command
		switch (command)
		{
		case 1: listUsers(db);
			break;

		case 2: listBusinesses(db);
			break;

		case 3: userInfo(db);
			break;

		case 4: businessInfo(db);
			break;

		case 5: userReviews(db);
			break;

		case 6: businessReviews(db);
			break;

		case 7: userQuery(db);
			break;

		default: cout << "Entry invalid..." << endl;
		}
	}
	return 0;
}
