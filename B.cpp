#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct Crap{
    char symbol{};
    int number = 0;
};
stack<Crap> temp;
int inputSize;
vector<Crap> input;
string inputLine;
vector<int> answer;

void reduce(){
    temp.push(input[input.size()-1]);
    for (int i = 0; i < input.size(); i++){
        if (temp.empty()) temp.push(input[i]);
        else{
            if (abs(input[i].symbol - temp.top().symbol) == 32){
                Crap upper, lower;
                if (input[i].symbol < temp.top().symbol){
                    upper = input[i];
                    lower = temp.top();
                } else {
                    lower = input[i];
                    upper = temp.top();
                }
                answer[upper.number] = lower.number;
                temp.pop();
            } else temp.push(input[i]);
        }
    }
}

int main() {
    cin >> inputLine;
    inputSize = inputLine.size();
    answer.resize(inputSize / 2);
    int counter1 = 0, position1 = 0;
    for (int i = 0; i < inputSize; i++) {
        Crap crap;
        crap.symbol = inputLine[i];
        if (inputLine[i] >= 95) crap.number = ++counter1;
        else crap.number = position1++;
        input.push_back(crap);
    }
    reduce();
    if (answer[0] == 0) {
        cout << "Impossible";
    } else{
        cout << "Possible" << endl;
        for (int c : answer){
            cout << c << " ";
        }
    }
    return 0;
}