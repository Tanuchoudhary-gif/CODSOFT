#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Random number generator

    int secretNumber = rand() % 100 + 1; // Number between 1 and 100
    int guess;
    int attempts = 0;

    cout << "===== Guess the Number Game =====" << endl;
    cout << "I have chosen a number between 1 and 100." << endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > secretNumber) {
            cout << "Too high! Try again." << endl;
        }
        else if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        }
        else {
            cout << "Congratulations! You guessed the number in "
                    << attempts << " attempts." << endl;
        }

    } while (guess != secretNumber);

    return 0;
}