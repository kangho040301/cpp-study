#include <iostream>
#include <vector>
using namespace std;
const long long p = 1000000007;
vector<vector<long long>> m_multiple(vector<vector<long long>> &m1, vector<vector<long long>> &m2) {
    vector<vector<long long>> temp(2, vector<long long>(2));
    for(long long i = 0; i < 2; i++) {
        for(long long j = 0; j < 2; j++) {
            for(long long k = 0; k < 2; k++) {
                temp[i][j] += (m1[i][k] * m2[k][j])%p;
            }
            temp[i][j] %= p;
        }
    }
    return temp;
}
vector<vector<long long>> dc_power(vector<vector<long long>> &m, long long b) {
    if(b == 1) {
        return m;
    }
    vector<vector<long long>> temp(2,vector<long long>(2));
    temp = dc_power(m, b/2);
    temp = m_multiple(temp, temp);
    if(b%2 == 0) {
        return temp;
    }
    else return m_multiple(temp, m);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    long long n;
    cin >> n;
    vector<vector<long long>> m(2,vector<long long>(2));
    m = {{1,1},{1,0}};
    vector<vector<long long>> ans = dc_power(m, n);
    cout << ans[0][1] << '\n';
    return 0;
}
