#include "MovieTree.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <istream>
#include <sstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) //you need to include a txt file for this to work!
{
    MovieTree* MovieTree1 = new MovieTree();
    string read, line, title;
    string ranking, year, stock;
    ifstream file;
    stringstream iss;
    file.open(argv[1]);
    
    bool programRun = true; //this is mandatory in order to run the menu - Chase Kregor
    
    while(!file.eof()) //Read all the way to end of file
    {
        getline(file, ranking, ',');
        
        getline(file, title, ',');
        
        getline(file, year, ',');
        
        getline(file, stock);
        
        MovieTree1->addMovieNode(atoi(ranking.c_str()), title, atoi(year.c_str()), atoi(stock.c_str()));
    }
    
    
    string user_command, user_input;
    
    
    while (programRun == true) //cant be just while true, fixed this - Chase Kregor
    {
        cout << "======Main Menu======" << endl;
        cout << "1. Find a movie" << endl;
        cout << "2. Rent a movie" << endl;
        cout << "3. Print the inventory" << endl;
        cout << "4. Delete a movie" << endl;
        cout << "5. Count the movies" << endl;
        cout << "6. Quit" << endl;
        cin>>user_command;
        cin.clear();
        cin.ignore(10000, '\n');
        
        switch (atoi(user_command.c_str()))
        {
            case 1:
            {
                cout << "Enter title:" << endl;
                getline(cin, user_input);
                MovieTree1->findMovie(user_input);
                break;
            }
                
            case 2:
            {
                cout << "Enter title:" << endl;
                getline(cin, user_input);
                MovieTree1->rentMovie(user_input);
                break;
            }
                
            case 3:
            {
                MovieTree1->printMovieInventory();
                break;
            }
                
            case 4:
            {
                cout << "Enter title:" << endl;
                getline(cin, user_input);
                MovieTree1->deleteMovieNode(user_input);
                break;
            }
            case 5:
            {
                cout<<"Tree contains: "<<MovieTree1->countMovieNodes()<<" movies."<< endl;
                break;
            }
            case 6:
            {
                cout << "Goodbye!" << endl;
                programRun = false;
                return 0;
            }
                
        }
    }
    return 0;
}

