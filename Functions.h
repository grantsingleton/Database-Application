#pragma once

#include "Table.h"
#include "Record.h"
#include "database.h"
#include "rapidjson.h"  // for json parsing
#include "document.h"
#include "stringbuffer.h"
#include <fstream>
#include <iostream>
#include <cmath>


Database* populateDatabase();
void listUsers(Database* db);
void listBusinesses(Database* db);
void userInfo(Database* db);
void businessInfo(Database* db);
void userReviews(Database* db);
void businessReviews(Database* db);

