#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int a1, a0, c, n0;
    cin >> a1 >> a0 >> c >> n0;
    if(c >= a1 && a1*n0 + a0 <= c * n0) cout << 1 << '\n';
    else cout << 0 << '\n';
    return 0;
}