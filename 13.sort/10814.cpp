#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool compare(const pair<int, string> &a,const pair<int, string> &b) {
    return a.first < b.first;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<pair<int, string>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    stable_sort(v.begin(),v.end(),compare);
    for(int i = 0; i < n; i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
    return 0;
}