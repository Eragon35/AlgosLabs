#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
using namespace std;

struct Crap{
    char symbol{};
    int number = 0;
};
int inputSize;
string input;
//vector<Crap> temp;
list<Crap> temp = {};
vector<int> answer;

void printCrap(list<Crap> vtc){
    for (auto & iter : vtc){
        cout << iter.symbol << " " << iter.number << endl;
    }
    cout << "---------------------------" << endl;
}

void reduce() {
    int i = 0;
    int size = temp.size();
    auto it = temp.begin();

    while (i < size){
        cout << "pidor";

        if (it == temp.begin()){
            if (abs(temp.front().symbol - temp.back().symbol) == 32) {
                Crap upper, lower;
                if (temp.front().symbol > temp.back().symbol) {
                    upper = temp.back();
                    lower = temp.front();
                } else {
                    upper = temp.front();
                    lower = temp.back();
                }
                answer[upper.number] = lower.number;
//                temp.erase(temp.begin());
//                temp.pop_back();
                    temp.pop_front();
                    temp.pop_back();
                size = temp.size();
                it = temp.begin();
                cout << "deleted first & last" << endl;
                printCrap(temp);
            }
            advance(it, 1);
            i++;
        } else {
            auto pv = prev(it, 1);
            auto nt = it;
            if (abs((*it).symbol - (*pv).symbol) == 32) {
                Crap upper, lower;
                if ((*it).symbol > (*pv).symbol) {
                    upper = *pv;
                    lower = *it;
                } else {
                    upper = *it;
                    lower = *pv;
                }
                answer[upper.number] = lower.number;
//                temp.erase(temp.begin() + i - 1, temp.begin() + i + 1);
//                temp.remove(upper);
//                temp.remove(lower);
                temp.erase(pv);
                temp.erase(it);
                cout << "delete inside" << endl;
                printCrap(temp);
                size = temp.size();
                it = temp.begin();
                advance(it, i);
            }
            it = temp.begin();
            advance(it, i++);
        }
    }
    cout << "end of reduce" << endl;
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
    printCrap(temp);
    int sizeBefore = 0;
    while (sizeBefore != temp.size()){
        sizeBefore = temp.size();
        reduce();
//        printCrap(temp);
    }
    if (!temp.empty()) {
        cout << "Impossible";
//        cout << endl;
//        printCrap(temp);
    } else{
        cout << "Possible" << endl;
        for (int c : answer){
            cout << c << " ";
        }
    }
    return 0;
}