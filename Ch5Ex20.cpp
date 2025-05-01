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

void displayMenu();
void randomGenerator(int& randomNumber);

int main() {
    int input;

  randomGenerator(randomNumber);
  cout << "Guess a number between 0 and 100: " << endl;
  cin >> guess;

  while (guess != randomNumber) {
    if (guess < randomNumber && !cin.fail()) {
        cout << "Too low, try again: " << endl;
        guessCount++;
        cin >> guess;
   }
    else if (guess > randomNumber && !cin.fail()) {
         cout << "Too high, try again: " << endl;
         guessCount++;
         cin >> guess;
   }
   else {
         while (cin.fail()) {
            cin.clear(); // Clear error flags
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "The input provided is invalid, please enter a valid input: " << endl;
            cin >> guess;
         }
   }
  }
    cout << endl << "Correct Answer!" << endl;
    cout << "Score: " << guessCount << endl;
    scoreHistory.push_back(guessCount);         
}

void displayMenu(){
    cout << endl;
    cout << "Enter 1-4 for the following options listed below: " << endl;
    cout << "1. Check Session History " << endl;
    cout << "2. Create New Session " << endl;
    cout << "3. Clear All Previous Session Memory " << endl;
    cout << "4. Exit Program " << endl << endl;
}

void randomGenerator(int& randomNumber) {
    srand(time(0));
    randomNumber = (rand() % 100);
}