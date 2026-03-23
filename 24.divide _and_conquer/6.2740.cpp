#include <iostream>
#include <vector>
using namespace std;
void fillMatrix(vector<vector<int>> &m, int a, int b) {
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < b; j++) {
            cin >> m[i][j];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m, k;
    cin >> n >> m;
    vector<vector<int>> m1(n,vector<int>(m));
    fillMatrix(m1, n , m);
    cin >> m >> k;
    vector<vector<int>> m2(m,vector<int>(k));
    fillMatrix(m2, m, k);

    vector<vector<int>> ans(n,vector<int>(k));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            for(int a = 0; a < m; a++) {
                ans[i][j] += m1[i][a] * m2[a][j];
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < k; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}