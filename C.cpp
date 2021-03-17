#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

int main() {
    stack <unordered_map<string, int>> stack;
    unordered_map<string, int> map;
    stack.push(map);
    string str;
    getline(cin, str);
    while (!str.empty()) {
        if (str == "{") {
            if (stack.empty()) stack.push(map); // insert map
            else {
                unordered_map<string, int> temp = stack.top();
                stack.push(temp);
            }
        }
        else if (str == "}") stack.pop(); // delete temp map
        else {
            int delimeter = str.find('=');
            string left = str.substr(0, delimeter);
            string right = str.substr(delimeter + 1, str.length());
            if ((right[0] >= 48 && right[0] <= 57) || (right[0] == '-')) {
                // it means right is a number => <variable>=<number>
                if (stack.top().find(left) != stack.top().end()) stack.top()[left] = stoi(right); // it means stack.top() has left
                else stack.top().insert({left, stoi(right)}); // added new var to stack.top() with it value
            } else { // it means right is a another var => <variable1>=<variable2> & here we should cout
                int number;
                if (stack.top().find(right) != stack.top().end()) {
                    number = stack.top()[right];
                    if (stack.top().find(left) != stack.top().end()) stack.top()[left] = stack.top()[right]; // check if left exists
                    else stack.top().insert({left, number});
                }
                else {
                    number = 0;
                    stack.top().insert({right, 0});
                    stack.top().insert({left, 0});
                }
//                cout << left << " = " << right << " => " << number << endl;
                cout << number << endl;
            }
        }
        getline(cin, str);
    }
    return 0;
}