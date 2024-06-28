#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

using namespace std;

// Function to play the number guessing game
void numberGuessingGame(int maxNumber, int maxAttempts, int& score) {
    srand(time(0));
    int numberToGuess = rand() % maxNumber + 1;
    int playerGuess = 0;
    int attempts = 0;

    cout << "\nI have selected a number between 1 and " << maxNumber << "." << endl;
    cout << "You have " << maxAttempts << " attempts to guess it correctly." << endl;

    while (attempts < maxAttempts && playerGuess != numberToGuess) {
        cout << "Enter your guess: ";
        cin >> playerGuess;
        attempts++;

        if (playerGuess > numberToGuess) {
            cout << "Too high! ";
        } else if (playerGuess < numberToGuess) {
            cout << "Too low! ";
        } else {
            cout << "Congratulations! You've guessed the number in " << attempts << " attempts." << endl;
            score += (maxAttempts - attempts + 1) * 10; // Calculate score based on remaining attempts
            return;
        }

        // Provide additional hints
        if (abs(playerGuess - numberToGuess) <= 5) {
            cout << "You're very close! ";
        } else if (abs(playerGuess - numberToGuess) <= 10) {
            cout << "You're close! ";
        }
        cout << "Try again." << endl;

        if (attempts == maxAttempts - 1) {
            cout << "Hint: The number is " << (numberToGuess % 2 == 0 ? "even." : "odd.") << endl;
        } else if (attempts == maxAttempts) {
            cout << "Sorry, you've used all your attempts. The number was " << numberToGuess << "." << endl;
        }
    }
}

// Function to select difficulty level
void selectDifficultyLevel(int& maxNumber, int& maxAttempts) {
    int choice;
    cout << "\nSelect difficulty level:" << endl;
    cout << "1. Easy (Number between 1 and 50, 10 attempts)" << endl;
    cout << "2. Medium (Number between 1 and 100, 7 attempts)" << endl;
    cout << "3. Hard (Number between 1 and 200, 5 attempts)" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            maxNumber = 50;
            maxAttempts = 10;
            break;
        case 2:
            maxNumber = 100;
            maxAttempts = 7;
            break;
        case 3:
            maxNumber = 200;
            maxAttempts = 5;
            break;
        default:
            cout << "Invalid choice. Starting game with Medium difficulty." << endl;
            maxNumber = 100;
            maxAttempts = 7;
            break;
    }
}

// Function to display the leaderboard
void displayLeaderboard(const vector<int>& leaderboard) {
    cout << "\nLeaderboard:" << endl;
    for (size_t i = 0; i < leaderboard.size(); ++i) {
        cout << i + 1 << ". " << leaderboard[i] << " points" << endl;
    }
}

// Main function
int main() {
    int score = 0;
    vector<int> leaderboard;
    char playAgain = 'y';
    
    cout << "Welcome to the Enhanced Number Guessing Game!" << endl;

    while (playAgain == 'y' || playAgain == 'Y') {
        int maxNumber, maxAttempts;
        selectDifficultyLevel(maxNumber, maxAttempts);
        numberGuessingGame(maxNumber, maxAttempts, score);

        cout << "Your current score: " << score << " points" << endl;
        leaderboard.push_back(score);

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }

    // Sort leaderboard in descending order
    sort(leaderboard.begin(), leaderboard.end(), greater<int>());
    displayLeaderboard(leaderboard);

    cout << "Thank you for playing! Your final score: " << score << " points" << endl;

    return 0;
}
