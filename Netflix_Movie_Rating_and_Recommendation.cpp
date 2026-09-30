#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <cstdlib>
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

void showMovies(Movie movies[]) {
    cout << "\n========== MOVIE LIST ==========" << endl;
    for (int i = 0; i < MOVIE_COUNT; i++) {
        cout << i + 1 << ". " << movies[i].title
             << " (" << movies[i].genre << ")" << endl;
    }
}

void pauseAndClear() {
    cout << "\n";
    system("pause");
    system("cls");
}

int main() {
    // Sample titles for a classroom demonstration.
    Movie movies[MOVIE_COUNT] = {
        {"Extraction", "Action", 0, 0},
        {"The Gray Man", "Action", 0, 0},
        {"Murder Mystery", "Comedy", 0, 0},
        {"The Mitchells vs. the Machines", "Comedy", 0, 0},
        {"Marriage Story", "Drama", 0, 0},
        {"The Trial of the Chicago 7", "Drama", 0, 0}
    };

    int menuChoice;
    cout << fixed << setprecision(2);
    do {
        cout << "\n====== MOVIE RATING & RECOMMENDATION ======" << endl;
        cout << "1. View movies\n2. Rate a movie\n3. View ratings" << endl;
        cout << "4. Get recommendation\n5. Exit" << endl;
        cout << "Enter choice (1-5): ";
        menuChoice = getChoice(1, 5);

        switch (menuChoice) {
            case 1:
                showMovies(movies);
                pauseAndClear();
                break;
            case 2:{
                showMovies(movies);
                cout << "Choose movie number (1-" << MOVIE_COUNT << "): ";
                int movieNumber = getChoice(1, MOVIE_COUNT);
                cout << "Give a rating (1-5): ";
                int rating = getChoice(1, 5);
                movies[movieNumber - 1].ratingTotal += rating;
                movies[movieNumber - 1].ratingCount++;
                cout << "Rating saved for " << movies[movieNumber - 1].title << "." << endl;
                pauseAndClear();
                break;
            }
            case 3:
                cout << "\n========== MOVIE RATINGS ==========" << endl;
                for (int i = 0; i < MOVIE_COUNT; i++) {
                    cout << i + 1 << ". " << movies[i].title << " - ";
                    if (movies[i].ratingCount == 0) {
                        cout << "Not rated yet" << endl;
                    } else {
                        double average = static_cast<double>(movies[i].ratingTotal)
                                         / movies[i].ratingCount;
                        cout << "Average: " << average << "/5 ("
                             << movies[i].ratingCount << " ratings)" << endl;
                    }
                }
                pauseAndClear();
                break;
            case 4:{
                cout << "\nChoose a genre:\n1. Action\n2. Comedy\n3. Drama" << endl;
                cout << "Enter genre (1-3): ";
                int genreChoice = getChoice(1, 3);
                string chosenGenre;
                if (genreChoice == 1) chosenGenre = "Action";
                else if (genreChoice == 2) chosenGenre = "Comedy";
                else chosenGenre = "Drama";

                int bestIndex = -1;
                double bestAverage = -1.0;
                for (int i = 0; i < MOVIE_COUNT; i++) {
                    if (movies[i].genre == chosenGenre && movies[i].ratingCount > 0) {
                        double average = static_cast<double>(movies[i].ratingTotal)
                                         / movies[i].ratingCount;
                        if (average > bestAverage) {
                            bestAverage = average;
                            bestIndex = i;
                        }
                    }
                }

                if (bestIndex == -1) {
                    cout << "No ratings for " << chosenGenre << " yet." << endl;
                    cout << "Try this sample title: ";
                    for (int i = 0; i < MOVIE_COUNT; i++) {
                        if (movies[i].genre == chosenGenre) {
                            cout << movies[i].title << endl;
                            break;
                        }
                    }
                } else {
                    cout << "Recommended: " << movies[bestIndex].title << endl;
                    cout << "Genre: " << chosenGenre
                         << " | Average rating: " << bestAverage << "/5" << endl;
                }
                pauseAndClear();
                break;
            }
            case 5:
                cout << "Goodbye!" << endl;
                break;
        }
    } while (menuChoice != 5);
    return 0;
}
