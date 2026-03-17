#include <iostream>
#include <vector>
using namespace std;
struct RGB {
    int r, g, b;
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<RGB> house(n);
    vector<RGB> memo(n);
    for(int i = 0; i < n; i++) {
        cin >> house[i].r >> house[i].g >> house[i].b;
    }
    memo[0].r = house[0].r;
    memo[0].b = house[0].b;
    memo[0].g = house[0].g;
    for(int i = 1; i < n; i++) {
        memo[i].r = house[i].r + min(memo[i-1].g,memo[i-1].b);
        memo[i].g = house[i].g + min(memo[i-1].r,memo[i-1].b);
        memo[i].b = house[i].b + min(memo[i-1].r,memo[i-1].g);
    }
    int final_min = min(memo[n-1].r,min(memo[n-1].g,memo[n-1].b));
    cout << final_min << '\n';
    return 0;
}