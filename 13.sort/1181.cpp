#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool compare(const string &a,const string &b) {
    if(a.length() != b.length()) return a.length() < b.length();
    else return a < b;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<string> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(),v.end(),compare);
    auto it = unique(v.begin(), v.end());
    v.erase(it, v.end());
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }
    return 0;
}