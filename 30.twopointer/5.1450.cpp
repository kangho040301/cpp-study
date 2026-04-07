#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
ll v[31];
void getSums(vector<ll>& sums, int idx, ll cnt, int end) {
    if(idx == end) {
        sums.push_back(cnt);
        return;
    }

    getSums(sums, idx + 1, cnt, end);
    getSums(sums, idx + 1, cnt + v[idx], end);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, c; cin >> n >> c;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<ll> sumA;
    vector<ll> sumB;
    getSums(sumA, 0, 0, n/2);
    getSums(sumB, n/2, 0,n);
    sort(sumA.begin(),sumA.end());
    sort(sumB.begin(),sumB.end());
    
    int right = sumB.size() - 1;
    int ans = 0;
    for(int left = 0; left < sumA.size(); left++) {
        while(right >= 0 && sumA[left] + sumB[right] > c) {
            right--;
        }
        ans += right + 1;
    }
    cout << ans << '\n';
    return 0;
}