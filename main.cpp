#include "Header.h"
#include <iostream>
#include <string>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;
int main() {
    movie m;
    vector<movie> catalogue;
    string databasePath = "database.txt";
    int choice = 0;
    ifstream p_file;
    float total = 0.00;

    m.showLoadMenu();
    cin >> choice;

    if (choice == 1)
        m.load(databasePath, catalogue);
    choice = 0;
    while (choice != 9) {
        m.showMainMenu();
        cin >> choice;
        cin.get();

        //call function for different options
        switch (choice) {
        case 1:
            m.addMovie(catalogue);
            break;

        case 2:
            m.browseMovies(catalogue);
            break;

        case 3:
            m.changeMovie(catalogue);
            break;

        case 4:
            m.deleteMovie(catalogue);
            break;

        case 5:
            m.save(databasePath, catalogue);
            break;

        case 6:
            m.sort(catalogue);
            break;

        case 7:
            m.searchMovie(catalogue);
            break;

        case 8:
            total = m.calculateEarnings(catalogue);
            cout << "\nStore has earned $" << total << "\n";
            break;
        case 9:
            break;

        default:
            cout << "\nError. Choice not found.";
        }
    }

    return 0;
}
