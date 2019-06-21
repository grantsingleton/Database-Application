## Description

### Functionality
This is a simple application in C++ that allows a user to query data in the Yelp Dataset (view the yelp dataset online [here](https://www.yelp.com/dataset/challenge)). This is a huge set of JSON data which includes information about users, businesses, reviews, images, and chekins. This application is menu-based on the command line. The options are as follows:
1. List Users
2. List Businesses
3. User Information 
4. Business Information
5. User Reviews
6. Business Reviews
7. User Query

The user can make simple queries by selecting the different menu items. They can browse a list of all Yelp users (ten at a time). They can see all the information about a user by inputting their name. They can see all of the reviews that a user has made. In the same way, they can see a list of all businesses in the dataset, they can query information about a business, they can see all user reviews about a particular business. They can also perform a massive number of other queries using the "User Query" Option. This option gives the user the ability to perform a SQL query. They can build a new table with interesting information using this option.

## Implementation 

### Database API
The database API which powers this application was made by fellow students. Currently, the query speed is not optimized, but could easily be optimized by plugging in an optimized database API. 

## JSON Parsing
I used an open source JSON parsing API called *rapidjson*. The source and documentation can be found [here](https://github.com/Tencent/rapidjson/).

## The Menu
Once the data is parsed, the user receieves the menu and is able to query the data. For testing purposes, I used a subset of the data in order to speed up loading the database. With an optimized database this will not be necessary. The menu takes user input, applies a switch statment, and runs the corresponding function. Check out the source code on github [here](https://github.com/grantsingleton/Database-Application).

