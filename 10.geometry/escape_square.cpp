#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    vector<int> v(4,0);
    cin >> v[0] >> v[1] >> v[2] >> v[3];
    v[2] = v[2] - v[0];
    v[3] = v[3] - v[1];
    auto it = min_element(v.begin(),v.end());
    cout << *it << '\n';
    return 0;
}
     