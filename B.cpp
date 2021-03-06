#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Crap{
    char symbol{};
    int counter = 0;
    int position {};
};
int inputSize;
string input;

void printCrap(vector<Crap> vtc){
    for (int i = 0; i < vtc.size(); i++){
        cout << vtc[i].symbol << " " << vtc[i].counter << " " << vtc[i].position << endl;
    }
}

vector<Crap> reduce(vector<Crap> line) {
    int i = 1;
    int size = line.size();
    while (i < size){
        if (abs(line[i].symbol - line[i-1].symbol) == 32) {
            Crap upper, lower;
            if (line[i].symbol > line[i-1].symbol) {
                upper = line[i-1];
                lower = line[i];
            } else {
                upper = line[i];
                lower = line[i-1];
            }
            input[upper.position] = lower.counter + 48;
//            cout << lower.counter << endl;
            line.erase(line.begin() + i- 1, line.begin() + i + 1);
            size = line.size();
        }
        else i++;
    }
    return line;
}


int main() {
    vector<Crap> temp;
    cin >> input;
    inputSize = input.size();
    int counter = 0;
    for (int i = 0; i < inputSize; i++) {
        Crap crap;
        crap.symbol = input[i];
        if (input[i] >= 95) crap.counter = ++counter;
        crap.position = i;
        temp.push_back(crap);
    }
    int sizeBefore = 0, sizeAfter = inputSize;
    while (sizeBefore != sizeAfter){
        sizeBefore = temp.size();
        temp = reduce(temp);
        sizeAfter = temp.size();
//        printCrap(temp);
//        cout << endl;
//        cout << sizeBefore << " " << sizeAfter << endl;
    }

    if (temp.size() != 0) {
//        cout << input << endl;
        cout << "Impossible" << endl;
        return 0;
    } else{
        cout << "Possible" << endl;
//        cout << input.size() << endl;
//        cout << input;
        for (char i : input){
            if (i < 60) cout << i << " ";
        }
    }
    return 0;
}