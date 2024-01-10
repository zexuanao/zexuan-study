#include <iostream>
#include <cstdlib>
#include <ctime>
#include "string.h"

const int ArSize = 10;
const int MaxLen = 81;

int main() {
    using namespace std;
    String name;
    cout << "Hi, what's your name? \n>> ";
    cin >> name;
    //注意：这里的cin不是普通的cin，是String重载的，对最后的回车已经处理过了。
    cout << name << ", please enter up to " << ArSize << " short sayings (empty line to quit): \n";
    
    String sayings[ArSize];
    char temp[MaxLen]; // temporary string storage
    int i;
    for (i = 0; i < ArSize; i++) {
        cout << i + 1 << ": ";
        cin.get(temp, MaxLen);
        while (cin && cin.get() != '\n')
            continue;
        if (!cin || temp[0] == '\0') { // empty line?
            // i not incremented
            break;
        } else {
            sayings[i] = temp; // overloaded assignment
        }
    }
    int total = i; // total # of lines read
    if (total > 0) {
        cout << "Here are your sayings: \n";
        for (i = 0; i < total; i++)
            cout << sayings[i] << endl;
        
        // Use pointers to keep track of shortest and first strings
        String *shortest = &sayings[0]; // initialize to first object
        String *first = &sayings[0];
        for (i = 1; i < total; i++) {
            if (sayings[i].length() < shortest->length())
                shortest = &sayings[i];
            if (sayings[i] < *first)
                first = &sayings[i]; // compare values and assign address
        }

        cout << "Shortest saying: \n" << *shortest << endl;
        cout << "First alphabetically: \n" << *first << endl;

        srand(static_cast<unsigned int>(time(0)));
        int choice = rand() % total; // pick index at random
        
        // Use new to create and initialize a new String object
        String *favorite = new String(sayings[choice]);
        cout << "My favorite saying: \n" << *favorite << endl;
        delete favorite;
    } else {
        cout << "Not much to say, eh?\n";
    }
    cout << "Bye.\n";
    return 0;
}
