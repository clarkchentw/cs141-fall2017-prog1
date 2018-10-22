/*
 Overall Score out of 100: 100

 Grading comments in the code below are marked with //-!-

 Program execution (55 points total)
 A.  5: Displays header information                            |
 B.  5: Displays table from 99 down to 0                       |
 C.  5: Columns are lined up                                   |
 D.  5: Table has random upper and lower-case values           |
 E.  5: Special character value in all multiple of 9 positions |
 F. 10: Table shown, prompt, then special character displayed  |
 G. 10: Special character is random                            |
 H. 10: Table changes each time program is run                 |
 
 Program Style (45 points total):
 A.  5: Followed program naming conventions     |
 B. 10: Meaningful identifier names             |
 C. 10: Comments                                |
 D.  5: Functional Decomposition                |
 E. 10: Appropriate data and control structures |
 F.  5: Code Layout                             |
 */


// Program #1: Guess It
// Author: Clark Chen
// Lab: Tues 9am
// TA: Moumita Samanta
// Date: Sep 10, 2017
// System:  C++ in Cloud 9


#include <iostream>
#include <time.h>
#include <string>
using namespace std; 

//--------------------------------------------
// Generating a random letter
char getRandomLetter(){
    bool isLowerCase = rand() % 2;
    char outputLetter = rand() % 26 + 65;
    if (isLowerCase){
        outputLetter += 32;
    }
    
    return outputLetter;
}

int main() {
    // Improve rand()
    srand(time(NULL));
    
    // All the variable use
    int sectionCounter = 99;
    char keyLetter = getRandomLetter();
    char randomLetter;
    char userInput;
    
    
    // Header (Program Info)
    cout << "Program #1: Guess It" << endl;
    cout << "Author: Clark Chen" << endl;
    cout << "Lab: Tues 9am" << endl;
    cout << "TA: Moumita Samanta" << endl;
    cout << "Date: Sep 10, 2017" << endl;
    cout << "System:  C++ in Cloud 9" << endl << endl;
    
    // Loop for creating 99 sections
    while (sectionCounter >= 0){
        // Prepare the random letter for this section
        if (sectionCounter % 9 != 0){
            randomLetter = getRandomLetter();
        }
        else{
            randomLetter = keyLetter;
        }
        
        // add a space for beginning of the line
        if (sectionCounter % 10 == 9){
            cout << " ";
        }
        
        // add space for single digit number
        if (sectionCounter < 10){
            cout << " ";
        }
        
        // compile and print out the text for this section
        cout << sectionCounter << ":" << randomLetter;
        
        // determine to make a new line or adding a space
        if (sectionCounter % 10 == 0){
            cout << endl;
        }
        else{
            cout << " ";
        }
        
        // -1 to go to the next section
        sectionCounter -= 1;
    }
    
    // Print out the instruction for this program
    cout << endl;
    cout << "1. Choose any two-digit number in the table above (e.g. 73)." << endl;
    cout << "2. Subtract its two digits from itself (e.g. 73 - 7 - 3 = 63)" << endl;
    cout << "3. Find this new number (e.g. 63) and remember the letter next to it." << endl;
    cout << "4. Now press 'r' and I'll read your mind..." << endl;
    
    // receive user input
    cin >> userInput;
    
    // Detect if user input a 'r', otherwise ask the user to input again
    while (userInput != 'r'){
        cout << "Please enter 'r'" << endl;
        cin >> userInput;
    }
    
    // Print out keyLetter
    cout << endl;
    cout << "You selected the character: " << keyLetter;
    
    
    return 0;
}
