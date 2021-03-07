#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Crap{
    char symbol{};
    int counter = 0;
    int position {};
};
struct Answer{
    int position {};
    int counter {};
};
int inputSize;
string input;
vector<Answer> answer;

void printCrap(vector<Crap> vtc){
    for (int i = 0; i < vtc.size(); i++){
        cout << vtc[i].symbol << " " << vtc[i].counter << " " << vtc[i].position << endl;
    }
}

bool comp(Answer ans, Answer awr){
    return ans.position < awr.position;
}

vector<Crap> reduce(vector<Crap> line) {
    int i = 0;
    int size = line.size();

    while (i < size){
        if (i == 0){
            if (abs(line[i].symbol - line[line.size()-1].symbol) == 32) {
                Crap upper, lower;
                if (line[i].symbol > line[line.size()-1].symbol) {
                    upper = line[line.size()-1];
                    lower = line[i];
                } else {
                    upper = line[i];
                    lower = line[line.size()-1];
                }
                Answer awr;
                awr.position = upper.position;
                awr.counter = lower.counter;
                answer.push_back(awr);
//                answer[upper.position].counter -= lower.counter;
                line.erase(line.begin());
                line.pop_back();
                size = line.size();
            } else i++;
        } else {
            if (abs(line[i].symbol - line[i - 1].symbol) == 32) {
                Crap upper, lower;
                if (line[i].symbol > line[i - 1].symbol) {
                    upper = line[i - 1];
                    lower = line[i];
                } else {
                    upper = line[i];
                    lower = line[i - 1];
                }
                Answer awr;
                awr.position = upper.position;
                awr.counter = lower.counter;
                answer.push_back(awr);
//                answer[upper.position].counter -= lower.counter;
                line.erase(line.begin() + i - 1, line.begin() + i + 1);
                size = line.size();
            } else i++;
        }
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
    }
    if (temp.empty()) {
        cout << "Possible" << endl;
        sort(answer.begin(), answer.end(), comp);
        for (Answer c : answer){
            cout << c.counter << " ";
            }
        return 0;
    } else{
        cout << "Impossible";
        return 0;
    }
}