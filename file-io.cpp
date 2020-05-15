#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    // Outputing to a file one character at a time
    string s = "Is this the Krusty Krab?\nNo, this is Patrick.";
    ofstream foutText;
    foutText.open("spongebob-per-char.txt", ios::binary);

    char c;
    for (int i = 0; i < s.size(); i++) {
        c = s[i];
        foutText.put(c);
    }

    foutText.close();


    // Reading from a file one character at a time
    ifstream finText;
    finText.open("spongebob-per-char.txt", ios::binary); 

    string recovered = "";
    while (finText.get(c)) {
        recovered += c;
    }
    cout << recovered << endl;

    finText.close();


    // Reading in using >> operator
    finText.open("spongebob-per-char.txt", ios::binary);

    recovered = "";
    while (finText >> c) {
        recovered +=c;
    }
    cout << recovered << endl;

    finText.close();

    // Reading in using getline
    finText.open("spongebob-per-char.txt", ios::binary);

    recovered = "";
    string temp;
    while (getline(finText, temp)) {
        recovered += temp;
    }
    cout << recovered << endl;

    finText.close();



    // Outputing a char per line
    foutText.open("spongebob-char-per-line.txt", ios::binary);

    for (int i = 0; i < s.size(); i++) {
        foutText << s[i] << endl;
    }

    foutText.close();

    // Reading from a file one character at a time
    finText.open("spongebob-char-per-line.txt", ios::binary); 

    recovered = "";
    while (finText.get(c)) {
        recovered += c;
    }
    cout << recovered << endl;

    finText.close();


    // Reading in using >> operator
    finText.open("spongebob-char-per-line.txt", ios::binary);

    recovered = "";
    while (finText >> c) {
        recovered +=c;
    }
    cout << recovered << endl;

    finText.close();

    // Reading in using getline
    finText.open("spongebob-char-per-line.txt", ios::binary);

    recovered = "";
    while (getline(finText, temp)) {
        recovered += temp;
    }
    cout << recovered << endl;

    finText.close();


    
    // Outputing an array of chars to a file
    char* arr = new char[s.size()];
    for (int i = 0; i < s.size(); i++) {
        arr[i] = s[i];
    }

    foutText.open("spongebob-with-array.txt", ios::binary);
    foutText.write(arr, s.size());
    foutText.close();


    // Reading the chars back into an array
    char* arrRecovered = new char[s.size() + 1];
    finText.open("spongebob-with-array.txt", ios::binary);
    finText.read(arrRecovered, s.size());
    finText.close();


    delete[] arr;
    delete[] arrRecovered;
}
