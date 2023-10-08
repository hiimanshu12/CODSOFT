#include <iostream>
#include <vector>

using namespace std;

const int NUM_ROWS = 5;
const int NUM_COLS = 10;

void displaySeating(vector<vector<char>>& seats) {
    cout << "  Seats: A B C D E F G H I J\n";
    for (int i = 0; i < NUM_ROWS; i++) {
        cout << "Row " << (i + 1) << " ";
        for (int j = 0; j < NUM_COLS; j++) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSeatAvailable(vector<vector<char>>& seats, int row, char col) {
    int colIndex = col - 'A';
    return seats[row - 1][colIndex] == 'O';
}

void bookSeat(vector<vector<char>>& seats, int row, char col) {
    int colIndex = col - 'A';
    seats[row - 1][colIndex] = 'X';
}

double calculateTotalCost(int numSeats) {
    const double TICKET_PRICE = 10.0; 
    return numSeats * TICKET_PRICE;
}

int main() {
    vector<vector<char>> seating(NUM_ROWS, vector<char>(NUM_COLS, 'O'));

    int choice;
    int numSeats;
    char col;
    int row;

    while (true) {
        cout << "Movie Ticket Booking System" << endl;
        cout << "1. Display Movie Listings and Seating" << endl;
        cout << "2. Book a Seat" << endl;
        cout << "3. Calculate Total Cost" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displaySeating(seating);
                break;
            case 2:
                cout << "Enter the row (1-5) and seat (A-J) you want to book: ";
                cin >> row >> col;

                if (row < 1 || row > NUM_ROWS || col < 'A' || col > 'J') {
                    cout << "Invalid row or seat. Please try again." << endl;
                    continue;
                }

                if (isSeatAvailable(seating, row, col)) {
                    bookSeat(seating, row, col);
                    cout << "Seat " << col << row << " has been booked." << endl;
                } else {
                    cout << "Seat " << col << row << " is already booked. Please choose another seat." << endl;
                }
                break;
            case 3:
                cout << "Enter the number of seats you want to calculate the total cost for: ";
                cin >> numSeats;
                cout << "Total cost: $" << calculateTotalCost(numSeats) << endl;
                break;
            case 4:
                cout << "Thank you for using the Movie Ticket Booking System. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}
