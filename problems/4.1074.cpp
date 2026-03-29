#include <iostream>
using namespace std;
int solve(int n, int r, int c) {
    if(n == 0) return 0;

    int half = 1 << (n-1); // 2^(n-1)
    int size = half * half;
    if(r < half && c < half) { // 왼쪽 위
        return solve(n-1,r,c);
    }
    else if(r < half && c < 2*half) { // 오른쪽 위
        return size + solve(n-1,r,c-half);
    }
    else if(r < 2*half && c < half) { // 왼쪽 아래
        return 2*size + solve(n-1,r-half,c);
    }
    else { // 오른쪽 아래
        return 3*size + solve(n-1,r-half,c-half);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, r, c; cin >> n >> r >> c;
    int ans = solve(n, r, c);
    cout << ans << '\n';
    return 0;
}
/*
2 3 1
half = 2;
size = 4;
2*4 + solve(1,1,1);
*/