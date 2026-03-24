#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int k, n; cin >> k >> n;
    vector<int> lan(k);
    for(int i = 0; i < k; i++) {
        cin >> lan[i];
    }
    sort(lan.begin(),lan.end());
    long long low = 1, high = lan[k-1];
    long long ans = 0;
    while(low <= high) {
        long long lanN = 0;
        long long mid = low + (high - low) / 2;
        for(int i = 0; i < k; i++) {
            lanN += lan[i]/mid;
        }
        if(lanN >= n) {
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
/*
low = 1 high = 457;
mid = 229;
3, 3, 2, 2 = 10 < 11;
mid = 227 - 1 / 2 = 113;
.
.
.
*/