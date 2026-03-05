// 1 , 6, 12, 18, 24 ... / 1, 7, 19, 37, 61 ... / 1, 1+6*1, 1+6*1+6*2, 1+6*1+6*2+6*3...
#include <iostream>
#include <cmath>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    n--;
    int i = 1;
    while(n>0) {
        n = n - 6*i;
        i++;
    }
    cout << i << '\n';
    return 0;
}