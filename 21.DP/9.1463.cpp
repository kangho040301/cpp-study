#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> memo(n+1); // memo[i]는 숫자 i의 최소 카운트
    memo[0] = memo[1] = 0;
    for(int i = 2; i <= n; i++) { 
        if(i%6 == 0) {
            memo[i] = min(memo[i/3] + 1,min(memo[i/2] + 1,memo[i-1] + 1));
        }
        else if(i%3 == 0) {
            memo[i] = min(memo[i/3] + 1,memo[i-1] + 1);
        }
        else if(i%2 == 0) { 
            memo[i] = min(memo[i-1] + 1,memo[i/2] + 1);
        }
        else {
            memo[i] = memo[i-1] + 1;
        }
    }
    cout << memo[n] << '\n';
    return 0;
}
/*
1. 2의 배수 -> -1 or 2로 나누기
2. 3의 배수 -> 무조건 3으로 나누기
3. 아무것도 아님 -> -1
4. 6의 배수 -> 2 or 3으로 나누기
<<<< 이거 필요없고 DP할 때는 겸손하게 다 하기 (큰 수는 예측 불가)
ex)
memo[5] = 3
1 -> 2 -> 4 -> 5
memo[9] = 2
1 -> 3 -> 9
*/