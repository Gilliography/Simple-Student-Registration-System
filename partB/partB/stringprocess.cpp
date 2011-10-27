#include "StudentNode.h"

std::string randomString(int length, bool letters, bool numbers, bool symbols) {
    // the shortest way to do this is to create a string, containing
    // all possible values. Then, simply add a random value from that string
    // to our return value
    std::string allPossible; // this will contain all necessary characters
    std::string str; // the random string
    if (letters == true) { // if you passed true for letters, we'll add letters to the possibilities
        for (int i = 65; i <= 90; i++) {
            allPossible += static_cast<char>(i);
            // allPossible += static_cast<char>(i+32); // add a lower case letter // we do not use in this project!
        }
    } if (numbers == true) { // if you wanted numbers, we'll add numbers
        for (int i = 48; i <= 57; i++) {
            allPossible += static_cast<char>(i);
        }
    } if (symbols == true) { // if you want symbols, we'll add symbols (note, their ASCII values are scattered)
        for (int i = 33; i <= 47; i++) {
            allPossible += static_cast<char>(i);
        } for (int i = 58; i <= 64; i++) {
            allPossible += static_cast<char>(i);
        } for (int i = 91; i <= 96; i++) {
            allPossible += static_cast<char>(i);
        } for (int i = 123; i <= 126; i++) {
            allPossible += static_cast<char>(i);
        }
    }
    // get the number of characters to use (used for rand())
    int numberOfPossibilities = allPossible.length();
	
    for (int i = 0; i < length; i++) {
		
        str += allPossible[rand() % numberOfPossibilities];
    }
 
    return str;
}

