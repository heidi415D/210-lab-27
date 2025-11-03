#include <iostream>
#include <map>
#include <tuple>
#include <algorithm> // min, max
using namespace std;

int main() {
    // milestone 3
    map<string, tuple<int, string, string>> villagers; // friendship, species, catchphrase

    // preload villagers
    villagers["Drago"] = make_tuple(5, "Alligator", "Snap to It!");
    villagers["Kyle"] = make_tuple(10, "Wolf", "Hubba hubba!");
    villagers["Raymond"] = make_tuple(8, "Cat", "Nice fit");

    int choice; // user menu choice
    string name; // name entered by user

    while (true) { // keep showing menu until user exits
        cout << "\n==== Villager Menu ====\n";
        cout << "1. Increase Friendship\n";
        cout << "2. Decrease Friendship\n";
        cout << "3. Search Villager\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Villager name: ";
            cin >> name;

            if (villagers.find(name) != villagers.end()) {
                int current = get<0>(villagers[name]);
                get<0>(villagers[name]) = min(10, current + 1); // increase friendship but cap at 10
                cout << "Friendship increaised for " << name  << "!\n"; //confirmation message
            } 
            else {
                cout << "Villager not found.\n";
            }
        }

        else if (choice == 2) {
            cout << "Enter Villager name: ";
            cin >> name;

            if (villagers.find(name) != villagers.end()) {
                int current = get<0>(villagers[name]);
                get<0>(villagers[name]) = max(0, current - 1); // decrease friendship but floor at 0
                cout << "Friendship decreased for " << name  << "!\n"; //confirmation message
        } 
        else {
                cout << "Villager not found.\n";
        }
    }
            

        else if (choice == 3) {
            cout << "Enter Villager name: ";
            cin >> name;

            // search logic with check
            if (villagers.find(name) != villagers.end()) {
                auto data = villagers[name];
                cout << name << " ["
                     << get<0>(data) << ", "
                     << get<1>(data) << ", "
                     << get<2>(data) << "]\n";
            } 
            else {
                cout << "Villager not found.\n";
            }
        }
            
        else if (choice == 4) {
            cout << "Thanks for playing!\n";
            break;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }

    }

    return 0;
}


