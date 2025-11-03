#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

int main() {
    // milestone 3
    map<string, tuple<int, string, string>> villager; // friendship, species, catchphrase

    // preload villagers
    villagers["Drago"] = make_tuple(5, "Alligator", "Snap to It!");
    villagers["Kyle"] = make_tuple(10, "Wolf", "Hubba hubba!");
    villagers["Raymond"] = make_tuple(8, "Cat", "Nice fit");

    int choice; // user menu choice
    string name; // name entered by user

    while (true) {
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
            get<0>(villager[name])++; // increase friendship
            cout << "Friendship incresed for " << name  << "!\n"; //confirmation message
        }

        else if (choice == 2)
    }

    
    
  
}

