#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> num;
vector<int> op(4);
int max_result = -1000000001;
int min_result = 1000000001;
void calculate(int cnt, int result) {
    if(cnt == n) {
        if(result > max_result) max_result = result;
        if(result < min_result) min_result = result;
        return;
    }
    for(int i = 0; i < 4; i++) {
        if(op[i]) {
            op[i]--;
            if(i == 0) calculate(cnt + 1, result + num[cnt]);
            else if(i == 1) calculate(cnt + 1, result - num[cnt]);
            else if(i == 2) calculate(cnt + 1, result * num[cnt]);
            else calculate(cnt + 1, result / num[cnt]);
            op[i]++;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        num.push_back(a);
    }
    for(int i = 0; i < 4; i++) {
        cin >> op[i];
    }
    int result = num[0];
    calculate(1, result);
    cout << max_result << '\n' << min_result << '\n';
    return 0;
}