#pragma once

#include "Table.h"
#include "Record.h"
#include "database.h"
#include "include/rapidjson/rapidjson.h"  // for json parsing
#include "include/rapidjson/document.h"   // for json parsing
#include "include/rapidjson/stringbuffer.h"  // for json parsing
#include <fstream>
#include <iostream>
#include <cmath>
#include <sstream>


Database* populateDatabase();
void listUsers(Database* db);
void listBusinesses(Database* db);
void userInfo(Database* db);
void businessInfo(Database* db);
void userReviews(Database* db);
void businessReviews(Database* db);
void userQuery(Database* db);

