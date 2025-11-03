#include <iostream>
#include <map>
#include <vector>
#include <tuple>
using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string>> villagerData; // friendship, species, catchphrase

    // insert villagers using make_tuple
    villagerData["Drago"] = {5, "Alligator", "Snap to It!"};
    villagerData["Kyle"] = {10, "Wolf", "Hubba hubba!"};
    villagerData.insert({"Raymond", make_tuple(8, "Cat", "Nice fit")});

    // print map contents using a range based for loop
    cout << "Villager details (range-based for loop):" << endl;
    for (auto pair : villagerData) {
        cout << pair.first << " ["
             << get<0>(pair.secon) << ", " // friendship
             << get<1>(pair.second) << ", " // species
             << get<2>(pair.second) << "]" endl; // catchphrase
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

    // delete an element
    villagerColors.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villagerColors.find(searchKey);
    if (it != villagerColors.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villagerColors.size() << endl;
    villagerColors.clear();
    cout << "Size after clear: " << villagerColors.size() << endl;

    return 0;
}
