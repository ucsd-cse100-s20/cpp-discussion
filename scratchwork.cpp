#include <iostream>
#include <string>
#include <vector>

using namespace std;

// miscellaneous demoing based on Q&A:
//     below we compare a range-based for loop that uses
//     a copy of the element, and one that uses a reference
int main() {

    vector<int> v = {1, 2, 3, 4};

    // i is just a copy of an element
    for(int i : v) {
        // can't mutate elements of v through upating i
        i = 0;
    }


    for (int i = 0; i < 4; i++) {
        cout << v[i] << endl;
    }

    // i is a reference of an element
    for (int& i : v)  {
        // can mutate elements of v through updating i
        i = 0;
    }

    for (int i = 0; i < 4; i++) {
        cout << v[i] << endl;
    }

}
