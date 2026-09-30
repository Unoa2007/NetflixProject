#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
using namespace std;

const int MOVIE_COUNT = 6;

struct Movie {
    string title;
    string genre;
    int ratingTotal;
    int ratingCount;
};

int getChoice(int minimum, int maximum) {
    int choice;

    while (true) {
        cin >> choice;

        if (cin.fail() || choice < minimum || choice > maximum) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter " << minimum << "-" << maximum << ": ";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }
    }
}

int main() {
    Movie movies[MOVIE_COUNT] = {
        {"Extraction", "Action", 0, 0},
        {"The Gray Man", "Action", 0, 0},
        {"Murder Mystery", "Comedy", 0, 0},
        {"The Mitchells vs. the Machines", "Comedy", 0, 0},
        {"Marriage Story", "Drama", 0, 0},
        {"The Trial of the Chicago 7", "Drama", 0, 0}
    };

    cout << fixed << setprecision(2);

    cout << "========== MOVIE LIST ==========" << endl;

    for (int i = 0; i < MOVIE_COUNT; i++) {
        cout << i + 1 << ". " << movies[i].title
             << " (" << movies[i].genre << ")" << endl;
    }

    cout << "Choose movie number (1-" << MOVIE_COUNT << "): ";
    int movieNumber = getChoice(1, MOVIE_COUNT);

    cout << "Give a rating (1-5): ";
    int rating = getChoice(1, 5);

    movies[movieNumber - 1].ratingTotal += rating;
    movies[movieNumber - 1].ratingCount++;

    cout << "Rating saved for "
         << movies[movieNumber - 1].title << "." << endl;

    cout << "\n========== MOVIE RATINGS ==========" << endl;

    for (int i = 0; i < MOVIE_COUNT; i++) {
        cout << i + 1 << ". " << movies[i].title << " - ";

        if (movies[i].ratingCount == 0) {
            cout << "Not rated yet" << endl;
        } else {
            double average =
                static_cast<double>(movies[i].ratingTotal)
                / movies[i].ratingCount;

            cout << "Average: " << average << "/5 ("
                 << movies[i].ratingCount << " ratings)" << endl;
        }
    }

    return 0;
}
