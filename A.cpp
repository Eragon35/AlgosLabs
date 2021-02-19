#include <iostream>
using namespace std;

int main() {
    int n = 10;
    int max = 0, left = 0, right = 0, currnetMax = 0, currentLeft = 1;
    cin >> n;
    int array[200000];
    for (int i = 0; i < n; i++)  cin >> array[i];
    for (int i = 2; i < n; i++)  {
        if ((array[i] != array[i - 1]) && (array[i - 1] != array[i - 2])) currnetMax++;
        else {
            if (currnetMax > max){
                max = currnetMax;
                left = currentLeft+1;
                right = i;
            }
            currentLeft = i;
            currnetMax = 0;
        }
    }
    if (currnetMax > max){
        left = currentLeft-1;
        right = n;
    }
    cout << left << " " << right;
    return 0;
}
