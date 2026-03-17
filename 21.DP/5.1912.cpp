#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> num(n);
    vector<int> memo(n);
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    memo[0] = num[0];
    int final_max = memo[0];
    for(int i = 1; i < n; i++) {
        memo[i] = max(num[i], memo[i-1] + num[i]);

        if(memo[i] > final_max) final_max = memo[i];
    }
    cout << final_max << '\n';
    return 0;
}