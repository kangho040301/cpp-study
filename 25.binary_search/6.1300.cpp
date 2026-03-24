#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, k; cin >> n >> k;
   
    int low = 1, high = k;
    int ans = 0;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        int num = 0;
        for(int i = 1; i <= n; i++) {
            num += min(mid/i, n);
        }
        if(num < k) {
            low = mid + 1;
        }
        else {
            ans = mid;
            high = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}