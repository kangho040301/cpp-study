/*
1 3 7 13 -> 2 4 6 gcd = 2; 7 - 3 = 4, 4/2 = 2, 2 - 1 = 1
2 6 12 18 -> 4 6 6 gcd = 2;
1 5 11 18 -> 4 6 7 gcd = 1;
a b c/ gcd = g; ((b - a / g) - 1) + ((c - b / g) - 1)
*/
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> tree(n);
    vector<int> interval(n-1);
    cin >> tree[0];
    for(int i = 1; i < n; i++) {
        cin >> tree[i];
        interval[i-1] = tree[i] - tree[i-1];
    }
    int gcd_whole = interval[0];
    for(int i = 1; i < n-1; i++) {
        gcd_whole = gcd(gcd_whole,interval[i]);
    }
    int sum = 0;
    for(int i = 0; i < n-1; i++) {
        sum += interval[i]/gcd_whole - 1;
    }
    cout << sum << '\n';
    return 0;
}