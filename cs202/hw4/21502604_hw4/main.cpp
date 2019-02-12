
/**
 * CS 202 - HW 4
 * A main file
 * Please make sure that your code compiles and runs with this main file
 */
 /*
* Title : Hash Tables, Graphs
* Author : Asuman Aydin
* ID : 21502604
* Section : 01
* Assignment : 4
* Description :
*/
#include "graph.h"
#include <cstring>
#include <iostream>

using namespace std;
void mainMenu(int option)
{
    Graph movies;
    string performerName;
    if(option == 1)
    {
        cout<< "Enter the performer's name" << endl;
        cin>> performerName;
        movies.getMovies(performerName);
    }
    else if(option == 2)
    {

    }
    else if(option == 3)
    {

    }
    else if(option == 4)
    {

    }
    else if(option == 5)
    {

    }
    else if(option == 6)
    {

    }
    else if(option == 7)
    {
        cout<< "GoodBye.." << endl;
    }
}

int main()
{
    int option;
    cout<< "Welcome to Movie DataSet" << endl;
    cout<< "Select an Option" << endl;
    cout<< "1- See movies of a performer"<< endl;
    cout<< "2- Delete performers who directed the movie in which s/he played" << endl;
    cout<< "3- Find performer(s) who played in highest number of movies" <<endl;
    cout<< "4- Find performer number of performers based on a given performer" << endl;
    cout<< "5- Find performer(s) who played in highest number of movies with a given performer" << endl;
    cout<< "6- Find director(s) who directed highest number of movies of a given performer" << endl;
    cout<< "7- Exit" << endl;
    cin>> option;
    mainMenu(option);
    while(option> 0 && option < 7)
    {
        cout<< "Welcome to Movie DataSet" << endl;
        cout<< "Select an Option" << endl;
        cout<< "1- See movies of a performer"<< endl;
        cout<< "2- Delete performers who directed the movie in which s/he played" << endl;
        cout<< "3- Find performer(s) who played in highest number of movies" <<endl;
        cout<< "4- Find performer number of performers based on a given performer" << endl;
        cout<< "5- Find performer(s) who played in highest number of movies with a given performer" << endl;
        cout<< "6- Find director(s) who directed highest number of movies of a given performer" << endl;
        cout<< "7- Exit" << endl;
        cin>> option;
        mainMenu(option);
    }

    return 0;
}
