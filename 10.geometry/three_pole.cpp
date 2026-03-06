#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    vector<int> v(3, 0);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(),v.end());
    int answer = 0;
    if(v[0] + v[1] <= v[2]) {
        cout << (v[0] + v[1]) + (v[0] + v[1]) - 1 << '\n';
    }
    else cout << v[0] + v[1] + v[2] << '\n';
    return 0;
}