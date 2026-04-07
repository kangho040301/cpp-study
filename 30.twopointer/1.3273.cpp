#include <iostream>
#include <vector>
#include <deque>
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
    deque<int> d;
    for(int i = 0; i < n; i++) {
        d.push_back(v[i]);
    }
    int x; cin >> x;
    int ans = 0;
    while(d.size() > 1) {
        if(d.front() + d.back() == x) {
            d.pop_front();
            d.pop_back();
            ans++;
        }
        else if(d.front() + d.back() > x) {
            d.pop_back();
        }
        else {
            d.pop_front();
        }
    }
    cout << ans << '\n';
    return 0;
}