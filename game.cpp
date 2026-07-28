#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    char playAgain = 'Y';

    while (playAgain == 'Y' || playAgain == 'y') {

        int maxNumber, lives;

        cout << "\n==================================================";
        cout << "\n            GUESS THE NUMBER GAME";
        cout << "\n==================================================\n";

        cout << "\nChoose Difficulty Level\n";
        cout << "1. Easy   (1 - 50)   | 10 Lives\n";
        cout << "2. Medium (1 - 100)  | 7 Lives\n";
        cout << "3. Hard   (1 - 500)  | 10 Lives\n";

        int choice;
        cout << "\nEnter your choice (1-3): ";
        cin >> choice;

        while (cin.fail() || choice < 1 || choice > 3) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid choice. Enter 1, 2 or 3: ";
            cin >> choice;
        }

        switch (choice) {
        case 1:
            maxNumber = 50;
            lives = 10;
            break;

        case 2:
            maxNumber = 100;
            lives = 7;
            break;

        case 3:
            maxNumber = 500;
            lives = 10;
            break;
        }

        int secretNumber = rand() % maxNumber + 1;
        int guess;
        int guessCount = 0;
        bool guessedCorrectly = false;

        cout << "\n--------------------------------------------\n";
        cout << "Guess a number between 1 and " << maxNumber << endl;
        cout << "You have " << lives << " lives.\n";
        cout << "--------------------------------------------\n";

        while (lives > 0) {

            cout << "\nEnter your guess: ";
            cin >> guess;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Please enter a valid number.\n";
                continue;
            }

            guessCount++;

            if (guess == secretNumber) {
                guessedCorrectly = true;
                break;
            }

            lives--;

            if (guess > secretNumber)
                cout << "Too High!";
            else
                cout << "Too Low!";

            if (lives > 0)
                cout << " Lives Remaining: " << lives << endl;
        }

        cout << "\n============================================\n";

        if (guessedCorrectly) {
            cout << " Congratulations!\n";
            cout << "You guessed the number in "
                 << guessCount << " attempts.\n";
        }
        else {
            cout << " Game Over!\n";
            cout << "The correct number was "
                 << secretNumber << ".\n";
        }

        cout << "============================================\n";

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> playAgain;

        cin.ignore(10000, '\n');
    }

    cout << "\n============================================\n";
    cout << "Thanks for playing!\n";
    cout << "See you next time!\n";
    cout << "============================================\n";

    return 0;
}