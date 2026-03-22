#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> coins(n);
    int idx = 0;
    for(int i = 0; i < n; i++) {
        cin >> coins[i];
        if(k >= coins[i]) idx = i;
    }
    int ans = 0;
    for(int i = idx; i >= 0; i--) {
        ans += k / coins[i];
        k %= coins[i];
    }
    cout << ans << '\n';
    return 0;
}