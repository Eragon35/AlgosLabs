#include <iostream>
#include <string>
using namespace std;

string reduce(string line) {
    int i = 0;
    int size = line.length();
    while (i < size){
        if (abs(line[i] - line[i+1]) == 32) {
            line.erase(i, 2);
            size = line.length();
        }
        else i++;
    }
    return line;
}


int main() {
    string line, upper, lower;
    cin >> line;
    for (char i : line) {
        if (i < 90) upper += i;
        else lower += i;
    }
    short length = 0;
    while (length != line.length()){
        length = line.length();
        line = reduce(line);
    }

    if (line.length() != 0) {
        cout << "Impossible";
        return 0;
    } else{
        cout << "Possible" << endl;
        for (char i : upper){
            cout << lower.find(tolower(i))+1 << " ";
        }
    }
    return 0;
}

