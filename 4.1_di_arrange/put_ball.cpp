#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> v(n, 0);
    for(int x = 0; x < m; x++) {
        int i, j, k;
        cin >> i >> j >> k;
        for(int index = i-1; index <= j-1; index++) v[index] = k;
    }
    for(int i = 0; i < n; i++) cout << v[i] << " ";
    return 0;
}