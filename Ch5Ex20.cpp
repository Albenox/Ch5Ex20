/*
    Program File Name: Ch5Ex20.cpp
    Programmer: Gabriel Inocentes
    Date: April 30, 2025
    Requirements: Make a program that generates a random number guessing game for users to interact with
    
*/

#include <iostream>
#include <random>
#include <time.h>
#include <vector>

using namespace std;

int randomNumber;
int guess;
int guessCount;
vector <int> scoreHistory;

void inputCheck(int& guess, int& randomNumber, int& guessCount);
void randomGenerator(int& randomNumber);

int main() {
    int input;

  randomGenerator(randomNumber);
  cout << "Guess a number between 0 and 100: " << endl;
  cin >> guess;

  inputCheck(guess, randomNumber, guessCount);

    //Runs the code once the correct answer is given, outside the while loop
    cout << endl << "Correct Answer!" << endl;
    cout << "Score: " << guessCount << endl;
    scoreHistory.push_back(guessCount);         
}


void inputCheck(int& guess, int& randomNumber, int& guessCount) {
    //Makes a while loop happen if the guess does not equal the random generated number
    while (guess != randomNumber) {
        // Checks to see if the guess is lower than the number
        if (guess < randomNumber && !cin.fail()) {
            cout << "Too low, try again: " << endl;
            guessCount++;
            cin >> guess;
        }
        // Checks to see if the guess is higher than the number
        else if (guess > randomNumber && !cin.fail()) {
            cout << "Too high, try again: " << endl;
            guessCount++;
            cin >> guess;
        }
        else {
            // Checks to see if the guess input is invalid
            while (cin.fail()) {
                cin.clear(); // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "The input provided is invalid, please enter a valid input: " << endl;
                cin >> guess;
            }
        }
    }
}

void randomGenerator(int& randomNumber) {
    srand(time(0));
    randomNumber = (rand() % 100);
}