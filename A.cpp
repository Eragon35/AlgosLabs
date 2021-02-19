#include <iostream>
using namespace std;

int main() {
    int n = 10;
    int max = 0, left = 0, right = 0, same = 1, fleft = 0;
    cin >> n;
    int array[200000];
    for (int i = 0; i < n; i++)  cin >> array[i];
    for (int i = 1; i < n; i++)  {
        if (array[i] == array[i-1]) same++;
        else same = 1;
        if (same >= 3) {
            // фотография закончилась
            left = i - 1;
        }
        else if (i - left > max){
            right = i;
            max = i - left;
            fleft = left;
        }
    }
    cout << fleft+1 << " " << right+1;
    return 0;
}
