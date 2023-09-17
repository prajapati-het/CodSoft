#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int NUM_ROWS = 5;
const int NUM_COLS = 10;
const double TICKET_PRICE = 10.0;

struct Movie {
    string name;
    vector<vector<char>> seats;
};

void printSeats(const vector<vector<char>>& seats) {
    cout << "   ";
    for (int col = 0; col < NUM_COLS; ++col) {
        cout << col << " ";
    }
    cout << "\n";

    for (int row = 0; row < NUM_ROWS; ++row) {
        cout << row << "  ";
        for (int col = 0; col < NUM_COLS; ++col) {
            cout << seats[row][col] << " ";
        }
        cout << "\n";
    }
}

bool isSeatAvailable(const vector<vector<char>>& seats, int row, int col) {
    return seats[row][col] == 'O';
}

double calculateTotalCost(int numTickets) {
    return numTickets * TICKET_PRICE;
}

int main() {
    Movie movie1{"Avengers: Endgame", vector<vector<char>>(NUM_ROWS, vector<char>(NUM_COLS, 'O'))};
    Movie movie2{"The Lion King", vector<vector<char>>(NUM_ROWS, vector<char>(NUM_COLS, 'O'))};

    unordered_map<int, Movie> movies = {{1, movie1}, {2, movie2}};

    while (true) {
        cout << "Movie Ticket Booking System\n";
        cout << "1. View Movie Listings\n";
        cout << "2. Book Tickets\n";
        cout << "3. Exit\n";
        cout << "Select an option: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            cout << "Movie Listings:\n";
            cout << "1. " << movie1.name << "\n";
            cout << "2. " << movie2.name << "\n";
        } else if (choice == 2) {
            cout << "Select a movie (1 or 2): ";
            int movieChoice;
            cin >> movieChoice;

            auto it = movies.find(movieChoice);
            if (it == movies.end()) {
                cout << "Invalid movie selection.\n";
                continue;
            }

            Movie& selectedMovie = it->second;

            cout << "Enter number of tickets: ";
            int numTickets;
            cin >> numTickets;

            cout << "Available seats for " << selectedMovie.name << ":\n";
            printSeats(selectedMovie.seats);

            for (int i = 0; i < numTickets; ++i) {
                cout << "Enter seat (row col) for ticket " << i + 1 << ": ";
                int row, col;
                cin >> row >> col;

                if (row < 0 || row >= NUM_ROWS || col < 0 || col >= NUM_COLS) {
                    cout << "Invalid seat selection.\n";
                    --i;
                    continue;
                }

                if (!isSeatAvailable(selectedMovie.seats, row, col)) {
                    cout << "Seat not available. Choose another seat.\n";
                    --i;
                    continue;
                }

                selectedMovie.seats[row][col] = 'X';
            }

            cout << "Tickets booked successfully for " << selectedMovie.name << "!\n";
            double totalCost = calculateTotalCost(numTickets);
            cout << "Total cost: $" << totalCost << "\n";

            cout << "Updated seat map for " << selectedMovie.name << ":\n";
            printSeats(selectedMovie.seats);

        } else if (choice == 3) {
            cout << "Exiting program.\n";
            break;
        } else {
            cout << "Invalid choice. Please select a valid option.\n";
        }
    }

    return 0;
}
