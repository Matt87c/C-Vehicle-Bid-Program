//============================================================================
// Name        : Lab1-3.cpp
// Author      : Matthew Clockel
// Version     : 1.0
// Copyright   : Copyright Â© 2017 SNHU COCE
// Description : Lab 1-3 Up to Speed in C++
//============================================================================

#include <algorithm>
#include <iostream>

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

// FIXME (1): Define a data structure to hold bid information together as a single unit of storage.

//Defined a data structure to hold the bid information which consists of words and numbers.
struct bidInformation {
	string title;
	string fund;
	string vehicle;
	int bidAmount;
};



// FIXME (4): Display the bid values passed in data structure
/**
 * Display the bid information
 *
 * @param ?type? data structure containing the bid info
 */

//The input variables within the bidInformation data structure have been set.
void displayBid(bidInformation bid) {
    cout << "Title: " << bid.title << endl;
    cout << "Fund: " << bid.fund << endl;
    cout << "Vehicle: " << bid.vehicle << endl;
    cout << "Bid Amount: " << bid.bidAmount << endl;

    return;
}

// FIXME (3): Store input values in data structure
/**
 * Prompt user for bid information
 *
 * @return data structure containing the bid info
 */
//I had to move this above to clear errors to run properly
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}



// Calling the data structure containing bid info.
bidInformation getBid() {
    bidInformation bidInfo;

//Prints to enter title and user input stored in bidInformation data structure.
    cout << "Enter title: ";
    cin.ignore();
    getline(cin, bidInfo.title);

//Prints to enter fund and user input is stored in bidInformation data structure.
    cout << "Enter fund: ";
    cin >> bidInfo.fund;

//Prints to enter vehicle and user input is stored in bidInformation data structure.
    cout << "Enter vehicle: ";
    cin.ignore();
    getline(cin, bidInfo.vehicle);

//Prints to enter amount and user input enters a number to be stored in bidInformation data structure.
    cout << "Enter amount: ";
    cin.ignore();
    string strAmount;
    getline(cin, strAmount);
    bidInfo.bidAmount = strToDouble(strAmount, '$');

//Added to return bidInfo
    return bidInfo;
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */


/**
 * The one and only main() method
 */
int main() {

    // FIXME (2): Declare instance of data structure to hold bid information
//Instance bid declared to hold bid information.
	bidInformation bid;
	//Prints the display menu for user to input values
    // loop to display menu until exit chosen
    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Enter Bid" << endl;
        cout << "  2. Display Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        // FIXME (5): Complete the method calls then test the program
        //Completed the switch statement to call the bid information.
        switch (choice) {
        // case 1 will go through the menu that will obtain user information.
            case 1:
            	bid = getBid();
                break;
        //case 2 will display the user input bid amounts.
            case 2:
                displayBid(bid);
                break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
