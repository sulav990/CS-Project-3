//Name : Sulav Uprety
//Project 3 : to track grocery items's purchases
//Date : 6/22/2025



#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

// GroceryTracker class manages item frequency operations
class GroceryTracker {
private:
    map<string, int> itemFrequency; // Stores item frequencies

    // Loads items from input file and populates the map
    void LoadItemsFromFile(const string& filename) {
        ifstream inputFile(filename);
        if (!inputFile) {
            cout << "Error: Cannot open file " << filename << endl;
            exit(1);
        }

        string item;
        while (inputFile >> item) {
            ++itemFrequency[item];
        }
        inputFile.close();
    }

    // Creates a backup file with item frequencies
    void CreateBackupFile() {
        ofstream outFile("frequency.dat");
        for (const auto& pair : itemFrequency) {
            outFile << pair.first << " " << pair.second << endl;
        }
        outFile.close();
    }

public:
    // Constructor: Loads items and creates backup
    GroceryTracker(const string& filename) {
        LoadItemsFromFile(filename);
        CreateBackupFile();
    }

    // Displays frequency of a specific item
    void DisplayItemFrequency(const string& itemName) {
        if (itemFrequency.find(itemName) != itemFrequency.end()) {
            cout << itemName << " was purchased " << itemFrequency[itemName] << " times." << endl;
        } else {
            cout << itemName << " was not purchased today." << endl;
        }
    }

    // Displays all items with their frequencies
    void DisplayAllFrequencies() {
        for (const auto& pair : itemFrequency) {
            cout << pair.first << " " << pair.second << endl;
        }
    }

    // Displays a histogram of item frequencies
    void DisplayHistogram() {
        for (const auto& pair : itemFrequency) {
            cout << setw(12) << left << pair.first << " ";
            for (int i = 0; i < pair.second; ++i) {
                cout << "*";
            }
            cout << endl;
        }
    }
};

// Displays the user menu
void ShowMenu() {
    cout << "\n===== Corner Grocer Item Tracking Menu =====" << endl;
    cout << "1. Search for an item's purchase frequency" << endl;
    cout << "2. Display all item frequencies" << endl;
    cout << "3. Display a histogram of item frequencies" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    GroceryTracker tracker("CS210_Project_Three_Input_File.txt");

    int choice;
    string itemName;

    do {
        ShowMenu();
        cin >> choice;

        // Validate user input
        if (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number between 1 and 4." << endl;
            continue;
        }

        switch (choice) {
        case 1:
            cout << "Enter the item name: ";
            cin >> itemName;
            tracker.DisplayItemFrequency(itemName);
            break;
        case 2:
            tracker.DisplayAllFrequencies();
            break;
        case 3:
            tracker.DisplayHistogram();
            break;
        case 4:
            cout << "Thank you for using the Corner Grocer Item Tracker. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
