#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    vector<int> v(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    vector<vector<bool>> ispalin(n+1,vector<bool>(n+1));
    for(int i = 1; i <= n; i++) {
        ispalin[i][i] = true;
    }
    int t; cin >> t;
    while(t--) {
        int start, end; cin >> start >> end;
        int left = start, right = end;
        while(!ispalin[left][right] && left < right) {
            if(v[left] != v[right]) {
                cout << 0 << '\n';
                break;
            }
            else {
                left++;
                right--;
            }
        }
        if(ispalin[left][right] || left >= right) {
            cout << 1 << '\n';
            while(!ispalin[start][end] && start < end) {
                ispalin[start][end] = true;
                start++;
                end--;
            }
            }
    }
    return 0;
}