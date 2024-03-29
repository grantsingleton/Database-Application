#include "Functions.h"
#include "database.h"

using namespace std;

Database* populateDatabase()
{
	Database* db = new Database();

	/**********************************
	*       FILL BUSINESS TABLE       *
	***********************************/
	ifstream business_file;
	business_file.open("business.json");
	if (business_file.is_open())
	{
		// good to go
	}
	else
	{
		std::cout << "error: 'business.json' did not open" << endl;
		return db;
	}
	std::string line;
	const char* json_line;
	rapidjson::Document doc;
	vector<string> business_ids;  // vector for business id's

	Table* business_table = new Table({ "business_id", "name", "address", "city", "state", "postal_code", "stars", "review_count", "is_open", "categories" });

	for (int i = 0; i < 500; i++) // get 500 lines 
	{
		getline(business_file, line);
		json_line = line.c_str();
		doc.Parse(json_line);

		// Fill a record in the Table
		Record new_record(10);

		assert(doc.HasMember("business_id"));
		if (!doc["business_id"].IsNull())
		{
			new_record.setEntry(0, doc["business_id"].GetString());
			business_ids.push_back(doc["business_id"].GetString());
		}
		else
		{
			new_record.setEntry(0, "");
		}

		assert(doc.HasMember("name"));
		if (!doc["name"].IsNull())
		{
			new_record.setEntry(1, doc["name"].GetString());
		}
		else
		{
			new_record.setEntry(1, "");
		}

		assert(doc.HasMember("address"));
		if (!doc["address"].IsNull())
		{
			new_record.setEntry(2, doc["address"].GetString());
		}
		else
		{
			new_record.setEntry(2, "");
		}

		assert(doc.HasMember("city"));
		if (!doc["city"].IsNull())
		{
			new_record.setEntry(3, doc["city"].GetString());
		}
		else
		{
			new_record.setEntry(3, "");
		}

		assert(doc.HasMember("state"));
		if (!doc["state"].IsNull())
		{
			new_record.setEntry(4, doc["state"].GetString());
		}
		else
		{
			new_record.setEntry(4, "");
		}

		assert(doc.HasMember("postal_code"));
		if (!doc["postal_code"].IsNull())
		{
			new_record.setEntry(5, doc["postal_code"].GetString());
		}
		else
		{
			new_record.setEntry(5, "");
		}

		assert(doc.HasMember("stars"));
		if (!doc["stars"].IsNull())
		{
			new_record.setEntry(6, to_string(doc["stars"].GetDouble()));
		}
		else
		{
			new_record.setEntry(6, "");
		}

		assert(doc.HasMember("review_count"));
		if (!doc["review_count"].IsNull())
		{
			new_record.setEntry(7, to_string(doc["review_count"].GetInt()));
		}
		else
		{
			new_record.setEntry(7, "");
		}

		assert(doc.HasMember("is_open"));
		if (!doc["is_open"].IsNull())
		{
			new_record.setEntry(8, to_string(doc["is_open"].GetInt()));
		}
		else
		{
			new_record.setEntry(8, "");
		}

		assert(doc.HasMember("categories"));
		if (!doc["categories"].IsNull())
		{
			new_record.setEntry(9, doc["categories"].GetString());
		}
		else
		{
			new_record.setEntry(9, "");
		}

		// add record to Table
		business_table->insertRecord(new_record);
	}
	business_file.close();

	// add business table to database
	db->addTable(*business_table, "Business");


	/**********************************
	*         FILL USER TABLE         *
	***********************************/
	ifstream user_file;
	user_file.open("user.json");
	if (user_file.is_open())
	{
		// good to go
	}
	else
	{
		std::cout << "error: 'user.json' did not open" << endl;
		return db;
	}

	Table* user_table = new Table({ "user_id", "name", "review_count", "yelping_since", "useful", "funny", "cool", "elite", "friends", "fans", "average_stars" });

	vector<string> user_ids;

	for (int i = 0; i < 500; i++) // get 500 lines 
	{
		getline(user_file, line);
		json_line = line.c_str();
		doc.Parse(json_line);

		// Fill a record in the Table
		Record new_record(11);

		assert(doc.HasMember("user_id"));
		if (!doc["user_id"].IsNull())
		{
			new_record.setEntry(0, doc["user_id"].GetString());
			user_ids.push_back(doc["user_id"].GetString());
		}
		else
		{
			new_record.setEntry(0, "");
		}

		assert(doc.HasMember("name"));
		if (!doc["name"].IsNull())
		{
			new_record.setEntry(1, doc["name"].GetString());
		}
		else
		{
			new_record.setEntry(1, "");
		}

		assert(doc.HasMember("review_count"));
		if (!doc["review_count"].IsNull())
		{
			new_record.setEntry(2, to_string(doc["review_count"].GetInt()));
		}
		else
		{
			new_record.setEntry(2, "");
		}

		assert(doc.HasMember("yelping_since"));
		if (!doc["yelping_since"].IsNull())
		{
			new_record.setEntry(3, doc["yelping_since"].GetString());
		}
		else
		{
			new_record.setEntry(3, "");
		}

		assert(doc.HasMember("useful"));
		if (!doc["useful"].IsNull())
		{
			new_record.setEntry(4, to_string(doc["useful"].GetInt()));
		}
		else
		{
			new_record.setEntry(4, "");
		}

		assert(doc.HasMember("funny"));
		if (!doc["funny"].IsNull())
		{
			new_record.setEntry(5, to_string(doc["funny"].GetInt()));
		}
		else
		{
			new_record.setEntry(5, "");
		}

		assert(doc.HasMember("cool"));
		if (!doc["cool"].IsNull())
		{
			new_record.setEntry(6, to_string(doc["cool"].GetInt()));
		}
		else
		{
			new_record.setEntry(6, "");
		}

		assert(doc.HasMember("elite"));
		if (!doc["elite"].IsNull())
		{
			new_record.setEntry(7, doc["elite"].GetString());
		}
		else
		{
			new_record.setEntry(7, "");
		}

		assert(doc.HasMember("friends"));
		if (!doc["friends"].IsNull())
		{
			new_record.setEntry(8, doc["friends"].GetString());
		}
		else
		{
			new_record.setEntry(8, "");
		}

		assert(doc.HasMember("fans"));
		if (!doc["fans"].IsNull())
		{
			new_record.setEntry(9, to_string(doc["fans"].GetInt()));
		}
		else
		{
			new_record.setEntry(9, "");
		}

		assert(doc.HasMember("average_stars"));
		if (!doc["average_stars"].IsNull())
		{
			new_record.setEntry(10, to_string(doc["average_stars"].GetDouble()));
		}
		else
		{
			new_record.setEntry(10, "");
		}

		// add record to Table
		user_table->insertRecord(new_record);
	}
	user_file.close();

	// add user table to database
	db->addTable(*user_table, "User");

	/**********************************
	*        FILL REVIEW TABLE        *
	***********************************/
	ifstream review_file;
	review_file.open("review.json");
	if (review_file.is_open())
	{
		// good to go
	}
	else
	{
		std::cout << "error: 'review.json' did not open" << endl;
		return db;
	}

	Table* review_table = new Table({ "review_id", "user_id", "business_id", "stars", "useful", "funny", "cool", "text", "date" });

	bool validate_business, validate_user;

	for (int i = 0; i < 150000; i++) // get 200,000 reviewa. Not all will be applicable to the users and businesses we have.
	{
		getline(review_file, line);
		json_line = line.c_str();
		doc.Parse(json_line);
		
		// Fill a record in the Table
		Record new_record(9);

		new_record.setEntry(0, doc["review_id"].GetString());
		
		new_record.setEntry(1, doc["user_id"].GetString());

		new_record.setEntry(2, doc["business_id"].GetString());

		new_record.setEntry(3, to_string(doc["stars"].GetDouble()));

		new_record.setEntry(4, to_string(doc["useful"].GetInt()));

		new_record.setEntry(5, to_string(doc["funny"].GetInt()));
		
		new_record.setEntry(6, to_string(doc["cool"].GetInt()));

		if (!doc["text"].IsNull())
		{
			new_record.setEntry(7, doc["text"].GetString());
		}
		else
		{
			new_record.setEntry(7, "");
		}

		new_record.setEntry(8, doc["date"].GetString());

		// add record to Table
		review_table->insertRecord(new_record);
	}
	review_file.close();

	// add review table to database
	db->addTable(*review_table, "Review");


	/**********************************
	*       FILL CHECK IN TABLE       *
	***********************************/
	ifstream checkin_file;
	checkin_file.open("checkin.json");
	if (checkin_file.is_open())
	{
		// good to go
	}
	else
	{
		cout << "error: 'checkin.json' did not open" << endl;
		return db;
	}

	Table* checkin_table = new Table({ "business_id", "date" }); 

	for (int i = 0; i < 1000; i++) // get 1000 lines 
	{
		getline(checkin_file, line);
		json_line = line.c_str();
		doc.Parse(json_line);

		// Fill a record in the Table
		Record new_record(2);

		assert(doc.HasMember("business_id"));
		if (!doc["business_id"].IsNull())
		{
			new_record.setEntry(0, doc["business_id"].GetString());
		}
		else
		{
			new_record.setEntry(0, "");
		}

		assert(doc.HasMember("date"));
		if (!doc["date"].IsNull())
		{
			new_record.setEntry(1, doc["date"].GetString());
		}
		else
		{
			new_record.setEntry(1, "");
		}

		// add record to Table
		checkin_table->insertRecord(new_record);
	}
	checkin_file.close();

	// add checkin table to database
	db->addTable(*checkin_table, "Checkin");

	return db;
}

void listUsers(Database* db)
{
	vector<Table*> tables = db->getTables();
	vector<string> names = db->listTables();
	int index = -1;
	for (int i = 0; i < names.size(); i++)
	{
		if (names.at(i) == "User")
		{
			index = i;
		}
	}

	if (index == -1)
	{
		cout << "Error: in function 'listUsers', Table does not exist" << endl;
		return;
	}

	vector<Record> records = tables.at(index)->getRecords();
	
	char command;
	bool cont = true;
	int location = 0;
	while (cont)
	{
		// print 10 names
		for (int i = 0; i < 10; i++, location++)
		{
			cout << records.at(location).getEntry(1) << endl;
		}

		cout << "Print more names? (y/n)" << endl;
		cin >> command;

		// check continue condition
		if (command == 'y')
		{
			cont = true;
		}
		else
		{
			cont = false;
		}
	}
}

void listBusinesses(Database* db)
{
	vector<Table*> tables = db->getTables();
	vector<string> names = db->listTables();
	int index = -1;
	for (int i = 0; i < names.size(); i++)
	{
		if (names.at(i) == "Business")
		{
			index = i;
		}
	}

	if (index == -1)
	{
		cout << "Error: in function 'listBusinesses', Table does not exist" << endl;
		return;
	}

	vector<Record> records = tables.at(index)->getRecords();

	char command;
	bool cont = true;
	int location = 0;
	while (cont)
	{
		// print 10 names
		for (int i = 0; i < 10; i++, location++)
		{
			cout << records.at(location).getEntry(1) << endl;
		}

		cout << "Print more names? (y/n)" << endl;
		cin >> command;

		// check continue condition
		if (command == 'y')
		{
			cont = true;
		}
		else
		{
			cont = false;
		}
	}
}

void userInfo(Database* db)
{
	char command;
	bool cont = true;
	while (cont)
	{
		string user;
		cout << "Enter name of user: ";
		cin >> user;

		vector<string> select;
		select.push_back("*");
		string where_arg = "name = ";
		where_arg.append("'");
		where_arg.append(user);
		where_arg.append("'");

		Table user_data = db->query(select, "User", where_arg);

		vector<Record> records = user_data.getRecords();
		
		if (records.empty())
		{
			cout << "There is no user with the name " << user << " in the database" << endl;
		}
		else
		{
			cout << endl << endl;
			for (int i = 0; i < records.size(); i++)
			{
				cout << "Information about " << user << ":" << endl;
				cout << user << " has completed " << records.at(i).getEntry(2) << " reviews" << endl;
				cout <<  "Average star rating: " << (round( atof(records.at(i).getEntry(10).c_str()) * 100.0) / 100.0) << endl;
				cout << "Fans: " << records.at(i).getEntry(9) << endl;
				cout << "Cool rating: " << records.at(i).getEntry(6) << endl;
				cout << "Funny rating: " << records.at(i).getEntry(5) << endl;
				cout << "Useful rating: " << records.at(i).getEntry(4) << endl;
				cout << user << " has been yelping since " << records.at(i).getEntry(3) << endl;
				cout << endl << endl;
			}
		}

		cout << "Try another name? (y/n)" << endl;
		cin >> command;

		// check continue condition
		if (command == 'y')
		{
			cont = true;
		}
		else
		{
			cont = false;
		}
	}
}

void businessInfo(Database* db)
{
	char command;
	bool cont = true;
	while (cont)
	{
		string business;
		cout << "Enter name of business: ";
		cin.ignore();
		getline(cin, business);

		vector<string> select;
		select.push_back("*");
		string where_arg = "name = ";
		where_arg.append("'");
		where_arg.append(business);
		where_arg.append("'");

		Table user_data = db->query(select, "Business", where_arg);

		vector<Record> records = user_data.getRecords();

		if (records.empty())
		{
			cout << "There is no business with the name " << business << " in the database" << endl;
		}
		else
		{
			cout << endl << endl;
			for (int i = 0; i < records.size(); i++)
			{
				cout << "Information about " << business << ":" << endl;
				cout << "Address: " << records.at(i).getEntry(2) << endl;
				cout << "         " << records.at(i).getEntry(3) << ", " << records.at(i).getEntry(4) << " " << records.at(i).getEntry(5) << endl;
				cout << "Review count: " << records.at(i).getEntry(7) << endl;
				cout << "Star rating: " << (round( atof(records.at(i).getEntry(6).c_str()) * 100.0) / 100.0) << endl;
				cout << "Categories: " << records.at(i).getEntry(9) << endl;
				if (records.at(i).getEntry(8) == "1")
				{
					cout << "This business is closed" << endl;
				}
				else
				{
					cout << "This business is open" << endl;
				}
				cout << endl << endl;
			}
		}

		cout << "Try another business? (y/n)" << endl;
		cin >> command;

		// check continue condition
		if (command == 'y')
		{
			cont = true;
		}
		else
		{
			cont = false;
		}
	}
}

void userReviews(Database* db)
{
	char command;
	bool cont = true;
	while (cont)
	{
		string user;
		cout << "Enter name of user: ";
		cin >> user;

		vector<string> select;
		select.push_back("user_id");
		string where_arg = "name = ";
		where_arg.append("'");
		where_arg.append(user);
		where_arg.append("'");

		Table user_data = db->query(select, "User", where_arg);

		vector<Record> records = user_data.getRecords();

		for (int i = 0; i < records.size(); i++)
		{
			string user_id = records.at(i).getEntry(0);

			select.clear();
			select.push_back("*");
			where_arg = "user_id = '";
			where_arg.append(user_id);
			where_arg.append("'");

			Table user_reviews = db->query(select, "Review", where_arg);

			vector<Record> review_records = user_reviews.getRecords();

			for (int j = 0; j < review_records.size(); j++)
			{
				cout << endl << endl << "Business: ";

				select.clear();
				select.push_back("name");
				where_arg = "business_id = '";
				string business_id = review_records.at(j).getEntry(2);
				where_arg.append(business_id);
				where_arg.append("'");

				Table business_name = db->query(select, "Business", where_arg);

				vector<Record> name_record = business_name.getRecords();

				if (name_record.size() == 0)
				{
					cout << "Data not available for this business" << endl;
				}
				else
				{
					cout << "Busines: " << name_record.at(0).getEntry(0) << endl;
				}
				cout << "stars: " << review_records.at(j).getEntry(3) << endl;
				cout << "useful: " << review_records.at(j).getEntry(4) << endl;
				cout << "funny: " << review_records.at(j).getEntry(5) << endl;
				cout << "cool: " << review_records.at(j).getEntry(6) << endl;
				cout << "date: " << review_records.at(j).getEntry(8) << endl;
				cout << "Review: " << review_records.at(j).getEntry(7) << endl;
			}
		}


		cout << "Try another name? (y/n)" << endl;
		cin >> command;

		// check continue condition
		if (command == 'y')
		{
			cont = true;
		}
		else
		{
			cont = false;
		}
	}
}

void businessReviews(Database* db)
{
	string business;
	char command;
	bool cont = true;
	while (cont)
	{
		cout << "Enter name of business: ";
		cin.ignore();
		getline(cin, business);

		vector<string> select;
		select.push_back("business_id");
		string where_arg = "name = ";
		where_arg.append("'");
		where_arg.append(business);
		where_arg.append("'");

		Table business_data = db->query(select, "Business", where_arg);

		vector<Record> records = business_data.getRecords();

		if (records.size() > 0)
		{
			select.clear();
			select.push_back("*");
			where_arg = "business_id = ";
			where_arg.append("'");
			where_arg.append(records.at(0).getEntry(0));
			where_arg.append("'");

			Table review_table = db->query(select, "Review", where_arg);

			vector<Record> review_records = review_table.getRecords();

			cout << endl << "Reviews for " << business << ": " << endl << endl;
			for (int i = 0; i < review_records.size(); i++)
			{
				cout << "Stars: " << (round(atof(review_records.at(i).getEntry(3).c_str()) * 100.0) / 100.0) << endl;
				cout << review_records.at(i).getEntry(7) << endl << endl << endl;
			}
		}


		cout << "Try another name? (y/n)" << endl;
		cin.clear();
		cin >> command;

		// check continue condition
		if (command == 'y')
		{
			cont = true;
		}
		else
		{
			cont = false;
		}
	}
}

void userQuery(Database* db)
{
	vector<string> select;
	string select_string;
	string from;
	string where;
	cout << "Enter query in the following format: " << endl;
	cout << "select_arg1 select_arg2 select_arg3 etc.. (enter one at a time with whitespace between)" << endl;
	cout << "from arg (enter the name of the table) choose from {User, Business, Review, Checkin}" << endl;
	cout << "where arg: example: LHS = 'RHS' (be sure to include single quotes around RHS)" << endl;
	cout << "use parenthesis for multiple where args: examples:" << endl;
	cout << "(Age <= '12') AND (NOT Index < '3') OR (Bool = 'Yes')" << endl;
	cout << "((Age > '20') OR (NOT Index = '1')) AND (Bool <> 'Yes')" << endl << endl;

	cout << "SELECT ";
	cin.ignore();
	getline(cin, select_string);
	stringstream ss(select_string);
	string temp_string;

	while (ss >> temp_string)
	{
		select.push_back(temp_string);
	}

	cout << endl << "FROM ";	
	cin >> from;

	cout << endl << "Where ";
	cin.ignore();
	getline(cin, where);

	cout << endl << "------------------------------------------------------" << endl;

	Table queryTable = db->query(select, from, where);

	cout << "Table: SELECT ";
	for (int i = 0; i < select.size(); i++)
	{
		cout << select.at(i) << " ";
	}
	cout << endl;
	cout << "FROM " << from << endl;
	cout << "WHERE " << where << endl;
 	queryTable.printTable();

	cout << endl << "------------------------------------------------------" << endl;

}



