#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<int> num(n);
    vector<int> sum(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        sum[i+1] = sum[i] + num[i];
    }
    while(m--) {
        int start, end;
        cin >> start >> end;
        cout << sum[end] - sum[start - 1] << '\n';
    }
    return 0;
}