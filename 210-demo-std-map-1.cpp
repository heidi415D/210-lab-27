#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerData; // friendship, species, catchphrase

    // insert villagers using make_tuple
    villagerData["Drago"] = make_tuple(5, "Alligator", "Snap to It!");
    villagerData["Kyle"] = make_tuple(10, "Wolf", "Hubba hubba!");
    villagerData.insert({"Raymond", make_tuple(8, "Cat", "Nice fit")});

    // print map contents using a range based for loop
    cout << "Villager details (range-based for loop):" << endl;
    for (auto pair : villagerData) {
        cout << pair.first << " ["
             << get<0>(pair.second) << ", " // friendship
             << get<1>(pair.second) << ", " // species
             << get<2>(pair.second) << "]" << endl; // catchphrase
    }

    //  print again using an iterator loop
    cout << "\nVillager details (iterator loop):" << endl;
    for (map<string, tuple<int, string, string>>::iterator it = villagerData.begin();
         it != villagerData.end(); ++it) {
        cout << it->first << " ["
             << get<0>(it->second) << ", "
             << get<1>(it->second) << ", "
             << get<2>(it->second) << "]" << endl;
    }

    // delete element by key
    villagerData.erase("Raymond");

    //search for villager using find()
    string searchKey = "Drago";
    auto it = villagerData.find(searchKey);
    if (it != villagerData.end()) {
        cout << "\nFound " << searchKey << ": ["
             << get<0>(it->second) << ", "
             << get<1>(it->second) << ", "
             << get<2>(it->second) << "]" << endl;
    } else 
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerData.size() << endl;
    villagerData.clear();
    cout << "Size after clear: " << villagerData.size() << endl;

    return 0;
}
