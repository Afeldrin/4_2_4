#include <iostream>
#include <stack>
#include <string>

using namespace std;

void brackets(string& s) {

    if (s == "") {
        cout << "There is no sequence!" << endl;
        return;
    }

    stack<char> st = {};

    for (auto i = s.begin(); i != s.end(); ++i) {
        if (*i == '(' or *i == '{' or *i == '[') {
            st.push(*i);
        }

        else if (*i == ')' or *i == '}' or *i == ']') {

            if (st.empty() == true) {
                cout << "Sequence is incorrect!" << endl;
                return;
            };

            if (*i == ')' and st.top() == '(') {
                st.pop();
            }
            else if (*i == ')' and st.top() != '(') {
                cout << "Sequence is incorrect!" << endl;
                return;
            }
            if (*i == ']' and st.top() == '[') {
                st.pop();
            }
            else if (*i == ']' and st.top() != '[') {
                cout << "Sequence is incorrect!" << endl;
                return;
            }
            if (*i == '}' and st.top() == '{') {
                st.pop();
            }
            else if (*i == '}' and st.top() != '{') {
                cout << "Sequence is incorrect!" << endl;
                return;
            }
        }
    }

    if (st.empty() == true) {
        cout << "Sequence is correct!" << endl;
    }
    else {
        cout << "Sequence is incorrect!" << endl;
    }

    return;
}

int main()
{
    string str = "[)]";

    brackets(str);

    return 0;
}