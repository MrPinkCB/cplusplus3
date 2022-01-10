#pragma once
#include <iostream>
#include <vector>
using namespace std;

class movie {
private:
    char name[50], director[50], dueDate[50];
    int year;
    float rating;
    float price;
    int views;
    int renter; 
public:
    movie();
    void setName(string s);
    char* getName();

    void setDirector(string s);
    char* getDirector();

    void setdueDate(string s);
    char* getdueDate();    

    void setYear(int year);
    int getYear();
    
    void setRating(float rating);
    float getRating();

    void setPrice(float price);
    float getPrice();
    
    void setViews(int views);
    int getViews();
    
    void setRenter(int renter);
    int getRenter();    
    
    void addMovie(vector<movie> &catalogue);
    void browseMovies(vector<movie> &catalogue);
    void showMovie(movie);
    void changeMovie(vector<movie> &catalogue);
    void editMovie(movie& current);
    void deleteMovie(vector<movie> &catalogue);
    void save(string databasePath, vector<movie>& catalogue);
    void load(string databasePath, vector<movie> &catalogue);
    void sort(vector<movie> const &catalogue);
    void searchMovie(vector<movie> &catalogue);
    float calculateEarnings(vector<movie> &catalogue);
    void showMainMenu();
    void showLoadMenu();
    bool compare(movie& lhs, movie& rhs);
    ~movie(){}
};
