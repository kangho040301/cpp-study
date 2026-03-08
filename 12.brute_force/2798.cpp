#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<int> v(n,0);
    for(int i = 0; i < n; i++) {
         cin >> v[i];
    }
    int max_sum = 0;
    for(int i = 0; i < n - 2; i++) {
        for(int j = i + 1; j < n - 1; j++) {
            for(int k = j + 1; k < n; k++) {
                int current_sum = v[i] + v[j] + v[k];
                if(current_sum <= m && current_sum > max_sum)
                    max_sum = current_sum;
            }
        }
    }
    cout << max_sum << '\n';
    return 0;
}