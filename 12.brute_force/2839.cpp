#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    if(n == 4 || n == 7) {
        cout << -1 << '\n';
        return 0;
    }
    
    int min_num = 5000;
    for(int i = 1;;i++) {
        int x = i;
        int weight_min = 5000;
        for(int y = 0; y <= i; y++) {
            int weight = x*5 + y*3;
            if(weight < weight_min) {
                weight_min = weight;
            }
            int num = x + y;
            if(weight == n && num < min_num) {
                min_num = num;
            }
            x--;
        }
        if(weight_min >= n) {
            cout << min_num << '\n';
            return 0;
        }
    }
}