# Database_Application

This is a menu-based application with the following interface:

1) List Users
2) List Businesses
3) User Information 
4) Business Information
5) User Reviews
6) Business Reviews
7) User Query

They have the following functionality:

1) Lists the users first names 10 at a time. Press 'y' to see 10 more names, 'n' to go back to main menu.

2) Lists Business names 10 at a time. Press 'y' to see 10 more names, 'n' to go back to main menu.

3) Enter the name of a user and you will see all the information on each user in the dataset with that name.

4) Enter the name of a business and you will see all information on each business with that name. 

5) Enter the name of a user and you will see all of their reviews that are in the dataset.

6) Enter the name of a business and you will see all of the reviews on that business that are in the dataset.

7) This option allows the user the freedom to build any table they want out of the dataset. When the user selects
   this option, they are given specific instructions on how to enter their query. Once the query is submitted, the
   program will print out the table. This option allows the most freedom for exploring the dataset. Any query that 
   the dataset supports is possible with this option. 
   
NOTES: 

JSON PARSING: For json parsing, I used 'rapidjson' an opensource Github program. I have included the '/include' folder, which contains the header files needed to run our Yelp dataset application. 

RUNNING THE PROGRAM: Filling the database takes roughly 2 minutes. The program reads in 500 businesses, 500 users, and 150,000 reviews (this can be adjusted in the source code). This also makes querying the reviews very slow since it has to search through 150,000 reviews. In order to have useful data, we must read in a lot of reviews, otherwise no reviews will be found for the users and businesses in our database. Not every user and business will have a review in the database. If you type in a business or user, and there is no reviews for them, please try another business or user until there are reviews. 
