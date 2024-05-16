#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

bool isPalindrome(string str) {
    stack<char> s;
    string filteredStr = "";
    
    // Filter non-alphanumeric characters and convert to lowercase
    for (char c : str) {
        if (isalnum(c)) {
            filteredStr += tolower(c);
        }
    }
    
    // Push all characters of the filtered string onto the stack
    for (char c : filteredStr) {
        s.push(c);
    }
    
    // Compare characters from the beginning with those popped from the stack
    for (char c : filteredStr) {
        if (c != s.top()) {
            return false;
        }
        s.pop();
    }
    
    return true;
}

int main() {
    string input;
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, input);
    
    if (isPalindrome(input)) {
        cout << "Kalimat tersebut adalah palindrom." << endl;
    } else {
        cout << "Kalimat tersebut bukan palindrom." << endl;
    }
    
    return 0;
}