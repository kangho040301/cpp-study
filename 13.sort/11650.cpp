#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<vector<int>> v(n,vector<int>(2,0));
    for(int i = 0; i < n; i++) {
        cin >> v[i][0] >> v[i][1];
    }
    sort(v.begin(),v.end());
    for(int i = 0; i < n; i++) {
        cout << v[i][0] << ' ' << v[i][1] << '\n';
    }
    return 0;
}