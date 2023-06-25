#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class ItemTracker {
private:
    map<string, int> itemFrequency;
    string dataFilePath;

public:
    ItemTracker() {
        dataFilePath = "C:\\Users\\azari\\source\\repos\\shoppingcart\\shoppingcart\\frequency.dat";
    }
    //set to open, read and close my input file
    void processInputFile(const string& filePath) {
        ifstream inputFile(filePath);
        string item;

        if (inputFile.is_open()) {
            while (getline(inputFile, item)) {
                itemFrequency[item]++;
            }
            inputFile.close();
        }
        else {
            cout << "Error: Unable to open file " << filePath << endl;
        }
    }
    //opens the output file sends info and closes
    void saveDataToFile() {
        ofstream outputFile(dataFilePath);

        if (outputFile.is_open()) {
            for (const auto& pair : itemFrequency) {
                outputFile << pair.first << " " << pair.second << endl;
            }
            outputFile.close();
            cout << "Data saved to " << dataFilePath << endl;
        }
        else {
            cout << "Error: Unable to create output file " << dataFilePath << endl;
        }
    }
    //Loop to print item freq to prevent redundancy
    void printItemFrequency() {
        for (const auto& pair : itemFrequency) {
            cout << pair.first << " " << pair.second << endl;
        }
    }
    // loop for printing the histogram to prevent redundancy
    void printHistogram() {
        for (const auto& pair : itemFrequency) {
            cout << pair.first << " ";
            for (int i = 0; i < pair.second; i++) {
                cout << "*";
            }
            cout << endl;
        }
    }

    void run() {
        string userInput;
        int choice;

        do {
            cout << "Menu Options:" << endl;
            cout << "1. Look up item frequency" << endl;
            cout << "2. Print item frequency list" << endl;
            cout << "3. Print item frequency histogram" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                // allows the user to input the option for the menu
                cout << "Enter the item to look up: ";
                cin.ignore();
                getline(cin, userInput);
                //tells the user the frequency for the item
                cout << "Frequency of " << userInput << ": " << itemFrequency[userInput] << endl;
                break;
            case 2:
                //prints the frequency for the items 
                printItemFrequency();
                break;
            case 3:
                //prints the freq with the *****
                printHistogram();
                break;
            case 4:
                //Saves the data to the output file
                saveDataToFile();
                break;
            default:
                //Can only insert 1-4
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
            
        } while (choice != 4);
    }
};

int main() {
    //now gotta access the input file but only works with the full path
    string inputFile = "C:\\Users\\azari\\source\\repos\\shoppingcart\\shoppingcart\\CS210_Project_Three_Input_File.txt";
    ItemTracker tracker;
    tracker.processInputFile(inputFile);
    tracker.run();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
