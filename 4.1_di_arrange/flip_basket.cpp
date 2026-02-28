#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    iota(v.begin(),v.end(),1);
    for(int x = 0; x < m; x++) {
        int i, j;
        cin >> i >> j;
        reverse(v.begin() + i - 1,v.begin() + j);
    }
    for(int i = 0; i < n; i++) cout << v[i] << " ";
    return 0;
}