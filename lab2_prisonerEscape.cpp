
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>

using namespace std;

const int totalBoxes = 10;
const int maxAttempts = 5;
const int maxRounds = 3;

bool searchNumber(int prisonerNum, const vector<int>& boxes);
void boxInitalization(vector<int> &boxes);

int main() {
    cout << "Lab 2 - Prisoner Escape\n@ AJ Arguello\n9/4/2024\n\n";

    for (int round = 0; round < maxRounds; ++round) { 
        cout << "\n============\n";
        vector<int> boxes(totalBoxes);  // initalization of boxes vector with size of 10 (totalBoxes)
        boxInitalization(boxes); // called function shuffles numbers 


        // Display the numbers inside each box 
        cout << "Box elements: ";
        for (int i = 0; i < totalBoxes; ++i) { // displays results of each box check 
            cout << boxes[i] << " ";
        }

        for (int prisoner = 1; prisoner <= totalBoxes; ++prisoner) { // for loop iterates over each prisoner #, each must find their number within 5 attempts
            cout << "\n";
            searchNumber(prisoner, boxes);
        }
        round++;

       // system("pause");

    }

    return 0;
}

// Function to initialize boxes with numbers and shuffle them
void boxInitalization(vector<int>& boxes) {
    vector<int> numbers(totalBoxes); // numbers vector is initalized containing totalBoxes elements
    for (int i = 0; i < totalBoxes; ++i) { // fils in the vector with integers from 1-10 (1 to the totalBoxes)
        numbers[i] = i + 1;
    }

    unsigned seed = static_cast<unsigned>(time(0)); // initialization of number generator
    mt19937 rng(seed); // Mersenne Twister random number generator
    shuffle(numbers.begin(), numbers.end(), rng); 

    boxes = numbers; //copies shuffled numbers into boxes vector
}

// Function to simulate a prisoner finding their own number
bool searchNumber(int prisonerNum, const vector<int>& boxes) {
    int currentBox = prisonerNum - 1; // Start at the box corresponding to the prisoner number
    int attempts = 0; // counts the attempts by prisoner(s)
    
    cout << "Prisoner " << prisonerNum << " starts with box " << (currentBox + 1) << "\n";

    while (attempts < maxAttempts) {
        cout << "Opening box " << (currentBox + 1) << ": found number " << boxes[currentBox] << "\n"; // starts at box 1
        
        if (boxes[currentBox] == prisonerNum) { // if the currentbox is equal to prisoner number
            cout << "Prisoner " << prisonerNum << " found their number " << prisonerNum << "!\n";
            return true; // Success
        }

        currentBox = boxes[currentBox] - 1; // Move to the box of the same number that was found in previous box
        ++attempts; // Increments attempt counter
    }

    // If the loop ends, the prisoner didn't find their number within the allowed attempts
    cout << "Prisoner " << prisonerNum << " could not find their number within " << maxAttempts << " attempts.\n";
    return false; // fail
}