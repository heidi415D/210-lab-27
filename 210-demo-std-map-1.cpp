#include <iostream>
#include <map>
#include <tuple>
#include <algorithm> // min, max
using namespace std;

int main() {
    
    map<string, tuple<int, string, string>> villagers; // friendship, species, catchphrase

    // preload villagers
    villagers["Drago"] = make_tuple(5, "Alligator", "Snap to It!");
    villagers["Kyle"] = make_tuple(10, "Wolf", "Hubba hubba!");
    villagers["Raymond"] = make_tuple(8, "Cat", "Nice fit");

    int choice; // user menu choice
    string name; // name entered by user

    while (true) { // keep showing menu until user exits
        cout << "\n==== Villager Menu ====\n";
        cout << "1. Add Villager\n";
        cout << "2. Delete Villager\n";
        cout << "3. Increase Friendship\n";
        cout << "4. Decrease Friendship\n";
        cout << "5. Search Villager\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Villager name: ";
            cin >> name;

            int level;
            string species, catchphrase;

            cout << "Friendship level: ";
            cin >> level;
            cout << "Species: ";
            cin >> species;
            cout << "Catchphrase: ";
            cin.ignore(); // clear newline from input buffer
            getline(cin, catchphrase);

            villagers[name] = make_tuple(level, species, catchphrase);
            cout << "Villager " << name << " added!\n"; //confirmation message
        }

        else if (choice == 2) {
            cout << "Enter Villager name to delete: ";
            cin >> name;

            if (villagers.find(name) != villagers.end()) { // check before erasing
                villagers.erase(name);
                cout << "Villager " << name << " deleted!\n"; //confirmation message
            } else {
                cout << "Villager " << name << " not found!\n";
            }
         }
            
        else if (choice == 3) {
            cout << "Enter Villager name: ";
            cin >> name;

            if (villagers.find(name) != villagers.end()) {
                int current = get<0>(villagers[name]);
                get<0>(villagers[name]) = min(10, current + 1); // max friendship is 10
                cout << "Friendship increased for " << name << "!\n";
            } else {
                cout << "Villager " << name << " not found!\n";
            }
    
        }
            
        else if (choice == 6) {
            cout << "Thanks for playing!\n";
            break; // exit the loop and program
        }
    }
    return 0;
}


