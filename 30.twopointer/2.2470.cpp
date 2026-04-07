#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    int left = 0, right = n - 1;
    unsigned int small = 2e9;
    int ans1 = 0, ans2 = 0;
    while(left != right) {
        int cnt = v[left] + v[right];
        if(abs(cnt) < small) {
            small = abs(cnt);
            ans1 = v[left];
            ans2 = v[right];
        }
        
        if(cnt == 0) {
            break;
        }
        else if(cnt < 0) {
            left++;
        }
        else {
            right--;
        }
    }
    cout << ans1 << ' ' << ans2 << '\n';
    return 0;
}