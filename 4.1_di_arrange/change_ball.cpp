#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for(int i = 0; i<n; i++) v[i] = i+1;
    for(int x = 0; x<m; x++) {
        int i, j;
        cin >> i >> j;
        swap(v[i-1],v[j-1]);
    }
    for(int i = 0; i<n; i++) cout << v[i] << " ";
    return 0;
}