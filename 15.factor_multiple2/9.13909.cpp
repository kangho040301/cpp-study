#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    
    int i = 1;
    for(;i * i <= n; i++) {
    }
    cout << i - 1 << '\n';
}
/*
(1)
(1,0)
(1,0,0)
(1,0,0,1)
(1,0,0,1,0)
(1,0,0,1,0,0)
(1,0,0,1,0,0,0)
(1,0,0,1,0,0,0,0) 약수 개수 % 2 == 0 --> 제곱수면 1, 아니면 0
*/