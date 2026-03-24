#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    ll n, m; cin >> n >> m;
    vector<ll> h(n);
    for(int i = 0; i < n; i++) {
        cin >> h[i];
    }
    sort(h.begin(),h.end());
    ll low = 0, high = h[n-1];
    ll ans = 0;
    while(low <= high) {
        ll mid = low + (high - low) / 2;
        ll take = 0;
        for(int i = 0; i < n; i++) {
            if(h[i] > mid) take += h[i] - mid;
        }
        if(take >= m) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}