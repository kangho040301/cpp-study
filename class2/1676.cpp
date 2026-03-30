#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    int ans[501]{};
    for(int i = 1; i <= n; i++) {
        if(i%5 == 0) {
            int a = 0;
            int x = i;
            while(x > 0 && x%5 == 0) {
                x /= 5;
                a++;
            }
            ans[i] = ans[i-1] + a;
        }
        else {
            ans[i] = ans[i-1];
        }
    }
    cout << ans[n] << '\n';
    return 0;
}
/*
0! = 1
1! = 1
2! = 2
3! = 6
4!= 24
5! = 120
6! = 720
7! = 
*/