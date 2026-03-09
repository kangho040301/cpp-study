#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.second != b.second) return a.second < b.second;
    else return a.first < b.first;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(),v.end(),compare);
    for(int i = 0; i < n; i++) {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
    cout << '\n';
    return 0;
}