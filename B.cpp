#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Crap{
    char symbol{};
    int number = 0;
};
int inputSize;
string input;
vector<Crap> temp;
vector<int> answer;

void reduce() {
    int i = 0;
    int size = temp.size();

    while (i < size){
        if (i == 0){
            if (abs(temp[i].symbol - temp[temp.size() - 1].symbol) == 32) {
                Crap upper, lower;
                if (temp[i].symbol > temp[temp.size() - 1].symbol) {
                    upper = temp[temp.size() - 1];
                    lower = temp[i];
                } else {
                    upper = temp[i];
                    lower = temp[temp.size() - 1];
                }
                answer[upper.number] = lower.number;
                temp.erase(temp.begin());
                temp.pop_back();
                size = temp.size();
            } else i++;
        } else {
            if (abs(temp[i].symbol - temp[i - 1].symbol) == 32) {
                Crap upper, lower;
                if (temp[i].symbol > temp[i - 1].symbol) {
                    upper = temp[i - 1];
                    lower = temp[i];
                } else {
                    upper = temp[i];
                    lower = temp[i - 1];
                }
                answer[upper.number] = lower.number;
                temp.erase(temp.begin() + i - 1, temp.begin() + i + 1);
                size = temp.size();
            } else i++;
        }
    }
}

int main() {
    cin >> input;
    inputSize = input.size();
    answer.resize(inputSize / 2);
    int counter = 0, position = 0;
    for (int i = 0; i < inputSize; i++) {
        Crap crap;
        crap.symbol = input[i];
        if (input[i] >= 95) crap.number = ++counter;
        else crap.number = position++;
        temp.push_back(crap);
    }
    int sizeBefore = 0;
    while (sizeBefore != temp.size()){
        sizeBefore = temp.size();
        reduce();
    }
    if (!temp.empty()) {
        cout << "Impossible";
    } else{
        cout << "Possible" << endl;
        for (int c : answer){
            cout << c << " ";
        }
    }
    return 0;
}