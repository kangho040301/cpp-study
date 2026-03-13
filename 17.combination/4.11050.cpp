#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    if(k == 0) {
        cout << 1 << '\n';
        return 0;
    }
    int a = n;
    for(int i = 1; i < k; i++) {
        a *= (n - i);
    }
    int fac = 1;
    for(int i = 1; i <= k; i++) {
        fac *= i;
    }
    cout << a/fac << '\n';
    return 0;
}