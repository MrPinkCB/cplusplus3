#include "Header.h"
#include <iostream>
#include <string>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;
movie::movie(){
    name[0] = 0;
    dueDate[0] = 0;
    director[0] = 0;
    year = 0;
    rating = 0;
    views = 0;
    renter = 0;
    price = 0.0;
}

int movie::getYear() {
    return year;
}
void movie::setYear(int year) {
    this->year = year;
}
float movie::getRating() {
    return rating;
}
void movie::setRating(float rating) {
    this->rating = rating;
}
float movie::getPrice() {
    return price;
}
void movie::setPrice(float price) {
    this->price = price;
}
int movie::getViews() {
    return views;
}
void movie::setViews(int views) {
    this->views = views;
}
int movie::getRenter() {
    return renter;
}
void movie::setRenter(int renter){
    this->renter = renter;
}

void movie::addMovie(vector<movie> &catalogue) {
    cout << "\n\nAdding new entry...";
    movie newMovie;

    cout << "\nEnter Movie Details...\n";
    cout << "\nName: ";
    fgets(newMovie.name, 50, stdin);
    newMovie.name[strcspn(newMovie.name, "\n")] = 0; //strip trailing \n


    cout << "Director: ";
    fgets(newMovie.director, 50, stdin);
    newMovie.director[strcspn(newMovie.director, "\n")] = 0;

    cout << "Year: ";
    cin >> newMovie.year;

    cout << "Rating: ";
    cin >> newMovie.rating;

    cout << "Price: ";
    cin >> newMovie.price;

    cout << "Number of Rentals: ";
    cin >> newMovie.views;

    cout << "Renter ID:";
    cin >> newMovie.renter;

    cin.get();
    cout << "Due Date: ";
    fgets(newMovie.dueDate, 15, stdin);
    newMovie.dueDate[strcspn(newMovie.dueDate, "\n")] = 0;

    catalogue.push_back(newMovie);
}

void movie::browseMovies(vector<movie> &catalogue) {
    cout << "\n\nBrowsing through entries...";

    for (int i = 0; i < catalogue.size(); ++i) {
        char choice;
        cout << "\n\nMovie #" << i + 1 << "\n";
        showMovie(catalogue[i]);
        if (i < catalogue.size() - 1) {
            cout << "\nBrowse to next entry (Y/N)? ";
            cin >> choice;

            if (choice == 'N' || choice == 'n')
                break;
        }
        else {
            cout << "\nEnd Of Database";
            cout << "\nPress Enter to return to the menu";
            cin.get();
        }
    }

}

void movie::showMovie(movie current) {

    cout << "Name: " << current.name << "\n";
    cout << "Director: " << current.director << "\n";
    cout << "Year: " << current.year << "\n";
    cout << "Rating: " << current.rating << "\n";
    cout << "Price: " << current.price << "\n";
    cout << "Number of Rentals: " << current.views << "\n";
    cout << "Current Renter: " << current.renter << "\n";
    cout << "Due Date: " << current.dueDate << "\n";
}

void movie::changeMovie(vector<movie>& catalogue) {
    cout << "\n\nModifying entry...";
    int position;

    cout << "\n\nEnter position: ";
    cin >> position;

    if (position < 1 || position > catalogue.size()) {
        cout << "\nError! Out of Bounds:\n";
    }
    else {
        editMovie(catalogue[position - 1]);
    }

    cout << "\nFinished editing...\n";
}

void movie::editMovie(movie& current) {
    cout << "\nYou have selected the following movie:\n";
    char choice = 'N';
    int field = 0;

    cout << "Name: " << current.name << "\n";
    cout << "\nDo you want to edit this record (Y/N)?";
    cin >> choice;

    if (choice == 'Y' || choice == 'y') {

        char choice2 = 'Y';
        int field = 0;

        while (choice2 == 'Y' || choice2 == 'y') {

            cout << "Please enter the number corresponding to the field you wish to change: \n";
            cout << "1. Name";
            cout << "2. Director";
            cout << "3. Year";
            cout << "4. Rating";
            cout << "5. Price";
            cout << "6. Number of Rentals";
            cout << "7. Renter ID";
            cout << "8. Due Date";
            cin >> field;
            cin.get();

            switch (field) {
            case 1:
                cout << "New Name:";
                fgets(current.name, 50, stdin);
                current.name[strcspn(current.name, "\n")] = 0;
                break;

            case 2:
                cout << "New Director:";
                fgets(current.director, 50, stdin);
                current.director[strcspn(current.director, "\n")] = 0;
                break;
            case 3:
                cout << "New Year:";
                cin >> current.year;
                cin.get();
                break;
            case 4:
                cout << "New Rating:";
                cin >> current.rating;
                cin.get();
                break;
            case 5:
                cout << "New Price:";
                cin >> current.price;
                cin.get();
                break;
            case 6:
                cout << "Number of Rentals:";
                cin >> current.views;
                break;
            case 7:
                cout << "Renter ID:";
                cin >> current.renter;
                cin.get();
                // while ((ch = getchar()) != '\n' && ch != EOF);
                break;
            case 8:
                cout << "Due Date:";
                fgets(current.dueDate, 10, stdin);
                current.dueDate[strcspn(current.dueDate, "\n")] = 0;
                break;
            }

            cout << "\nDo you want to keep editing this record (Y/N)?";
            cin >> choice2;
            cin.get();
        }
    }

}

void movie::deleteMovie(vector<movie>& catalogue) {
    cout << "\n\nDelete entry...";
    int position;


    cout << "\n\nEnter position: ";
    cin >> position;

    if (position < 1 || position > catalogue.size()) {
        cout << "\nError! Out of Bounds:\n";
    }
    else {
        cout << "\nYou have selected the following movie:\n";
        char choice = 'N';

        movie current = catalogue[position - 1];

        cout << "Name: " << current.name << "\n";
        cout << "\nDo you want to delete this record (Y/N)?";
        cin >> choice;

        if (choice == 'Y' || choice == 'y') {
            catalogue.erase(catalogue.begin() + position - 1);
            cout << "\nEntry Removed...\n";
        }
        else {
            cout << "\nEntry NOT Removed...\n";
        }
    }
}

void movie::save(string databasePath, vector<movie>& catalogue) {
    cout << "\n\nSaving data...";

    ofstream outFile(databasePath, ios::binary);
    if (!outFile) {
        cout << "Error opening file.";
        exit(1);
    }

    if (!outFile) {
        cout << "\nError opening file.";
        exit(1);
    }
    outFile << catalogue.size();

    for (int i = 0; i < catalogue.size(); ++i) {
        outFile.write((char*)&catalogue[i], sizeof(movie));
    }


    if (!outFile.good()) {
        cout << "\n Error occured while saving file!\n";
    }
    else {
        cout << "\nSave Successful.\n";
    }


}

void movie::load(string databasePath, vector<movie>& catalogue) {
    cout << "\n\nLoading data\n";

    ifstream inFile(databasePath, ios::in | ios::binary);
    if (!inFile) {
        cout << "\nError opening file.";
        exit(1);
    }

    int numRecords;
    inFile >> numRecords;


    cout << "\nLoading " << numRecords << " records..\n";
    catalogue.resize(numRecords);
    for (int i = 0; i < catalogue.size(); ++i) {
        inFile.read((char*)&catalogue[i], sizeof(movie));
    }

    if (!inFile.good()) {
        cout << "\n Error occured while reading from file!\n";
    }

}

bool movie::compare(movie &lhs, movie &rhs) {
    return strcmp(lhs.name, rhs.name) < 0;
}

void movie::sort(vector<movie> const &catalogue) {
    cout << "\n\nSorting data..";
    sort(catalogue);

}

void movie::searchMovie(vector<movie>& catalogue) {
    cout << "\n\nSearching for movie";

    char name[50];
    int matches = 0;
    cout << "\nPlease enter an movie name to search for:";
    fgets(name, 50, stdin);
    name[strcspn(name, "\n")] = 0;

    for (int i = 0; i < catalogue.size(); ++i) {
        if (strstr(catalogue[i].name, name)) {
            showMovie(catalogue[i]);
            matches++;
        }
    }

    cout << "\nThere were " << matches << " match(es)\n";
}

float movie::calculateEarnings(vector<movie>& catalogue) {
    cout << "\n\nCalculating for earnings...";

    float total = 0.00;

    for (int i = 0; i < catalogue.size(); ++i) {
        total += (catalogue[i].price * (float)catalogue[i].views);

    }

    return total;
}

void movie::showMainMenu() {
    cout << "\nPlease choose an option:";
    cout << "\n1. Add new entry";
    cout << "\n2. Browse entries";
    cout << "\n3. Modify existing entry ";
    cout << "\n4. Delete entry";
    cout << "\n5. Save entries ";
    cout << "\n6. Sort entries";
    cout << "\n7. Search for entry";
    cout << "\n8. Calcuate total";
    cout << "\n9. Exit\n> ";
}

void movie::showLoadMenu() {
    cout << "\nWould you like to:";
    cout << "\n1. Load a previously saved library database";
    cout << "\n2. Load a new database\n> ";
}



