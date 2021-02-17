#include <iostream>
using namespace std;

int main() {
    long long a0, a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    a0 = a;
    for (int i = 0; i < k; i++) {
        a *= b; // count of bacterias after reproduction
        a -= c; // count of bacterias after taking some for experimental
        if (a <= 0) { // if a <= 0 end of experiment
            cout << 0;
            return 0;
        }
        if (a >= d) {
            cout << d;
            return 0; // if we have d at the end we will have them every day
        }
        if (a == a0){
            cout << a0; // if nothing change after 1 day, it wouldn't change after k days
            return 0;
        }
    }
    cout << a;
    return 0;
}