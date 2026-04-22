#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int left = 0, right = n - 1;
    int small = INT_MAX;
    int ans1, ans2;
    while(left < right) {
        if(abs(v[left] + v[right]) < small) {
            small = abs(v[left] + v[right]);
            ans1 = v[left];
            ans2 = v[right];
        }
        if(v[left] + v[right] < 0) left++;
        else right--;
    }
    cout << ans1 << ' ' << ans2 << '\n';
    return 0;
}