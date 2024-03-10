#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Roulette Wheel (Random Number Generation)

    int balance; 
    int betAmount;
    int betNumber;
    char choice;

    cout << "Welcome to Roulette!" << endl;

    cout << "Enter the cash " << endl;
    cin >> balance;

    do {
        cout << "Your current balance is $" << balance << endl;
        cout << "Enter your bet amount: $";
        cin >> betAmount;

        // Check if the bet amount is valid
        if (betAmount > balance || betAmount <= 0) {
            cout << "Invalid bet amount! Please enter a valid bet." << endl;
            continue;
        }

        cout << "Enter the number you want to bet on (0-36): ";
        cin >> betNumber;

        // Check if the bet number is valid
        if (betNumber < 0 || betNumber > 36) {
            cout << "Invalid bet number! Please enter a number between 0 and 36." << endl;
            continue;
        }

        // Spin the wheel
        int randomNumber = rand() % 37; // Generates a random number between 0 and 36

        cout << "The wheel is spinned ... and the result is: " << randomNumber << endl;

        // Check if the player wins
        if (randomNumber == betNumber) {
            cout << "Congratulations! You win $" << betAmount * 36 << endl;
            balance += betAmount * 36; // Player wins 36 times the bet amount
        } else {
            cout << "Sorry, you lose $" << betAmount << endl;
            balance -= betAmount; // Player loses the bet amount
        }

        // Ask if the player wants to continue
        cout << "Do you want to play again? (Y/N): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    cout << "Thank you for playing. Your final balance is $" << balance << endl;

    return 0;
}
