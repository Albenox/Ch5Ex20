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

//Declares global variables
int randomNumber;
int guess;
int guessCount;
vector <int> scoreHistory;
string name;

void displayMenu();
void randomGenerator(int& randomNumber);

int main() {
    cout << "What is your name? " << endl;
    cin >> name;

    int input;
    int i = 0;
    while (true) {
        //Resets the variables between attempts
        guess = 0;
        guessCount = 0;

        //Sets up the user to use the menu again
        displayMenu();
        cin >> input;

        //Switch case to allow inputs from 1-4
        switch (input) {
            //Case to check existing sessions
        case 1:
            cout << endl << "Session History Selected " << endl << endl;
            //Checks to see if the list is empty, providing a relevant response if it is
            if (scoreHistory.empty() == 1) {
                cout << "No session history found!" << endl << "Sessions played will be displayed here with their scores, playing sessions should fill this with all previous games played. " << endl << endl;
                break;
            }
            else {
                while (i < scoreHistory.size()) {
                    cout << name << " scored for session " << i + 1 << " a " << guessCount << scoreHistory[i] << endl;
                    i++;
                }
                cout << endl;
                break;
            }

            //Case to start new session
        case 2:
            cout << endl << "New Session Selected " << endl << endl;
            randomGenerator(randomNumber);
            cout << "Guess a number between 0 and 100: " << endl;
            cin >> guess;

            //Checks to see if the guess does not equal the random number generated
            while (guess != randomNumber) {
                //Checks to see if the guess is lower than the random number
                if (guess < randomNumber && !cin.fail()) {
                    cout << "Too low, try again: " << endl;
                    guessCount++;
                    cin >> guess;
                }
                //Checks to see if the guess is higher than the random number
                else if (guess > randomNumber && !cin.fail()) {
                    cout << "Too high, try again: " << endl;
                    guessCount++;
                    cin >> guess;
                }
                else {
                    //Checks to see if the input is not a valid input
                    while (cin.fail()) {
                        cin.clear(); // Clear error flags
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                        cout << "The input provided is invalid, please enter a valid input: " << endl;
                        cin >> guess;
                    }
                }
            }
            //Runs this after the while loop finishes, meaning the number guessed was correct
            cout << endl << "Correct Answer!" << endl;
            cout << name << " scored: " << guessCount << endl;
            scoreHistory.push_back(guessCount);
            break;

            //Case to clear all previous sessions from memory
        case 3:
            cout << endl << "Clear Previous Sessions Selected" << endl << endl;
            //Checks to see if the list is empty, providing a relevant response if it is
            if (scoreHistory.empty() == 1) {
                cout << "No history found to be cleared!" << endl;
            }
            else {
                while (i < scoreHistory.size()) {
                    scoreHistory.pop_back();
                    i++;
                }
                cout << "Succesfully removed " << scoreHistory.size() << " saved sessions!" << endl;
            }
            break;

            //Case to exit program
        case 4:
            cout << endl << "Exit Program Selected" << endl << endl;
            cout << "Closing program! " << endl;
            exit(0);
            break;

        default:
            //Checks to see if the input is not a valid input
            if (cin.fail() || input < 1 || input > 4) {
                cin.clear(); // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "The input provided is invalid, please enter a valid input: " << endl;
            }
        }
    }  
}

//A repeatable function for displaying the menu options
void displayMenu(){
    cout << endl;
    cout << "Enter 1-4 for the following options listed below: " << endl;
    cout << "1. Check Session History " << endl;
    cout << "2. Create New Session " << endl;
    cout << "3. Clear All Previous Session Memory " << endl;
    cout << "4. Exit Program " << endl << endl;
}

//Generates the random number for a game session
void randomGenerator(int& randomNumber) {
    srand(time(0));
    randomNumber = (rand() % 100);
}