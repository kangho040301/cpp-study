#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, s; cin >> n >> s;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int left = 0, right = 0;
    int cnt = v[0];
    int ans = 2e9;
    while(left <= right) {
        if(cnt < s) {
            right++;
            if(right >= n) {
                break;
            }
            cnt += v[right];
            if(cnt >= s) ans = min(ans, right - left + 1);
        }
        else {
            ans = min(ans, right - left + 1);
            cnt -= v[left++];
        }
    }
    if(ans == 2e9) cout << 0 << '\n';
    else cout << ans << '\n';
    return 0;
}