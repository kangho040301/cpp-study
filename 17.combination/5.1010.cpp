#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;  

        if (n > m/2) n = m - n;
        long long ans = 1;
        for(int i = 1; i <= n; i++) {
            ans *= m - i + 1;
            ans /= i;
        }
        cout << ans << '\n';
    }
    return 0;
}