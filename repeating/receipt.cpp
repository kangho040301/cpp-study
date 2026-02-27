#include <iostream>
using namespace std;
int main() {
    int sum;
    int t;
    int n = 0;
    cin >> sum;
    cin >> t;
    for (int i=0;i<t;i++) {
        int a , b;
        cin >> a >> b;
        n = n + a*b;
    }
    if (sum == n) cout << "Yes" << endl;
    else cout << "No" << endl;
}