#include <iostream>
#include <vector>
using namespace std;
int n;
vector<vector<int>> m_multiple(vector<vector<int>> &m1, vector<vector<int>> &m2) {
    vector<vector<int>> temp(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < n; k++) {
                temp[i][j] += (m1[i][k] * m2[k][j])%1000;
            }
            temp[i][j] %= 1000;
        }
    }
    return temp;
}
vector<vector<int>> dc_power(vector<vector<int>> &m, long long b) {
    if(b == 1) {
        return m;
    }
    vector<vector<int>> temp(n,vector<int>(n));
    temp = dc_power(m, b/2);
    temp = m_multiple(temp, temp);
    if(b%2 == 0) {
        return temp;
    }
    else return m_multiple(temp, m);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    long long b;
    cin >> n >> b;
    vector<vector<int>> m(n,vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> m[i][j];
            m[i][j] %= 1000;
        }
    }
    vector<vector<int>> ans(n, vector<int>(n));
    ans = dc_power(m, b);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}