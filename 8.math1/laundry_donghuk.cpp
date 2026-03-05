#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int t, c;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> c;
        int q, d, n, p;
        q = c/25;
        d = (c%25)/10;
        n = ((c%25)%10)/5;
        p = ((c%25)%10)%5;
        cout << q << ' ' << d << ' ' << n << ' ' << p << '\n';
    }
    return 0;
}