#include <iostream>
#include <stack>
#include <string>

using namespace std;

void reverseString(string str) {
    stack<char> s;

    // 1. Poori string ko stack mein "Push" kar do
    for (int i = 0; i < str.length(); i++) {
        s.push(str[i]);
    }

    cout << "Reversed String: ";

    // 2. Stack se aik aik kar ke "Pop" karo aur print karo
    // Kyunke Stack ulta nikalta hai, string reverse ho jayegi
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }
    cout << endl;
}

int main() {
    string myName = "Muskan Khalil";
    
    cout << "Original String: " << myName << endl;
    
    reverseString(myName);

    return 0;
}