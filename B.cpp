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
//Недавно Глеб открыл зоопарк. Он решил построить его в форме круга и, естественно, обнёс забором.
// Глеб взял вас туда начальником охраны. Казалось бы все началось так хорошо, но именно в вашу первую смену
// все животные разбежались. В зоопарке n животных различных видов, также под каждый из видов есть свои ловушки.
// К сожалению некоторые животные враждуют с друг другом в природе (они обозначены разными буквами),
// а зоопарк обнесён забором и имеет форму круга. С помощью камер, удалось выяснить, где находятся все животные.
// Умная система поддержки жизнедеятельности зоопарка уже просканировала зоопарк и вывела id всех животных и ловушек
// в том порядке, в котором они видны из центра зоопарка. Получилось так, что все животные и все ловушки находятся
// на краю зоопарка. Вы хотите понять, могут ли животные прийти в свою ловушку так, чтобы их путь не пересекался с другими.
// Если да, также предъявите какую-нибудь из схем поимки животных.
//
//Формат ввода
//На вход подается строчка из 2 ⋅ n символов латинского алфавита, где маленькая буква - животное, а большая - ловушка.
// Размер строки не более 100000.
//
//Формат вывода
//Требуется вывести "Impossible", если решения не существует или "Possible", если можно вернуть всех животных в клетки.
// В случае если можно, то для каждой ловушки в порядке обхода требуется вывести индекс животного в ней.