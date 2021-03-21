#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> arr;
string input, answer;

bool comparator(string left, string right){
    string l = left + right, r = right + left;
    for (int i = 0; i < l.size(); i++){
        if (l[i] > r[i]) return true;
        if (l[i] < r[i]) return false;
    }
    return false;
}

int main(){
    while (cin >> input) {
        if (input.empty()) break;
       arr.push_back(input);
    }
    sort(arr.begin(), arr.end(), comparator);
    for (string str: arr) answer += str;
    cout << answer << endl;
    return 0;
}

//Вася написал на длинной полоске бумаги большое число и решил похвастаться своему старшему брату Пете этим достижением.
// Но только он вышел из комнаты, чтобы позвать брата, как его сестра Катя вбежала в комнату и разрезала полоску бумаги
// на несколько частей. В результате на каждой части оказалось одна или несколько идущих подряд цифр.
//
//Теперь Вася не может вспомнить, какое именно число он написал. Только помнит, что оно было очень большое.
// Чтобы утешить младшего брата, Петя решил выяснить, какое максимальное число могло быть написано
// на полоске бумаги перед разрезанием. Помогите ему!
//
//Формат ввода
//Входной файл содержит одну или более строк, каждая из которых содержит последовательность цифр.
// Количество строк во входном файле не превышает 100, каждая строка содержит от 1 до 100 цифр.
// Гарантируется, что хотя бы в одной строке первая цифра отлична от нуля.
//
//Формат вывода
//Выведите в выходной файл одну строку — максимальное число, которое могло быть написано на полоске перед разрезанием.