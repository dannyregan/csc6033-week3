#include <iostream>
#include <string>

using namespace std;

class FSA {
private:
    enum State { Start, a1, a2, b1, b2, T, F };
public:
    State currentState = Start;

    // Input is at least 3 letters long
    bool WordLength(string input) {
        if (input.length() < 3) currentState = F;
        else currentState = T;
    }

    bool ProcessChar(char ch) {
        // Input is of the alphabet {a, b, c}
        if (ch != 'a' && ch != 'b' && ch != 'c') {
            currentState = F;
        }

        switch (currentState) {
            case Start:
                if      (ch == 'a') currentState = a1;
                else if (ch == 'b') currentState = b1;
                else if (ch == 'c') currentState = Start;
                else                currentState = F;
                break;
            case a1:
                if      (ch == 'a') currentState = a2;
                else if (ch == 'b') currentState = b1;
                else if (ch == 'c') currentState = Start;
                else                currentState = F;
                break;
            case a2:
                if      (ch == 'a') currentState = T;
                else if (ch == 'b') currentState = b1;
                else if (ch == 'c') currentState = Start;
                else                currentState = F;
                break;
            case b1:
                if      (ch == 'a') currentState = a1;
                else if (ch == 'b') currentState = b2;
                else if (ch == 'c') currentState = Start;
                else                currentState = F;
                break;
            case b2:
                if      (ch == 'a') currentState = a1;
                else if (ch == 'b') currentState = T;
                else if (ch == 'c') currentState = Start;
                else                currentState = F;
                break;
        }
        return (currentState == T) || (currentState == F);
    }

    bool IsAccepted() const {
        return currentState == T;
    }
};

int main() {
    FSA fsa;
    string input;
    
    cout << "Enter a string (alphabet {a, b, c}): ";
    cin >> input;

    fsa.WordLength(input);

    for (char c: input) {
        fsa.ProcessChar(c);
    }

    fsa.IsAccepted() ? cout << "String is accepted." << endl : cout << "String is rejected." << endl;

    return 0;
}