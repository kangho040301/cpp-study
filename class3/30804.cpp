#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    vector<int> stick(n);
    for(int i = 0; i < n; i++) {
        cin >> stick[i];
    }
    int left = 0, right = 0;
    int count[10]{};
    int kind = 0;
    int ans = 0;
    for(int right = 0; right < n; right++) {
        int x = stick[right];
        if(count[x] == 0) kind++;
        count[x]++;
        while(kind > 2) {
            int leftFruit = stick[left];
            count[leftFruit]--;
            if(count[leftFruit] == 0) {
                kind--;
            }
            left++;
        }
        ans = max(ans,right - left + 1);
    }
    cout << ans << '\n';
    return 0;
} 