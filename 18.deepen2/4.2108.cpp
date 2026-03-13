#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> v(n);
    unordered_map<int, int> m;
    double sum = 0;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v[i] = a;
        sum += a;
        m[a]++;
    }

    int ave = round(sum / n);

    sort(v.begin(),v.end());
    int mid = v[n/2];
    
    int wide = v[n-1] - v[0];

    int max_val = 0;
    int max_key = -4001;
    for(auto const& [key, val] : m) {
        if(max_val < val) {
            max_val = val;
            max_key = key;
        }
    }
    vector<int> max_keys;
    for(auto const& [key, val] : m) {
        if(max_val == val) {
            max_keys.push_back(key);
        }
    }
    int most = 0;
    if(max_keys.size() > 1) {
        sort(max_keys.begin(),max_keys.end());
        most = max_keys[1];
    }
    else most = max_keys[0];
    
    cout << ave << '\n' << mid << '\n' << most << '\n' << wide << '\n';
    return 0;
}