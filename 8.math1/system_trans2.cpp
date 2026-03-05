#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, b;
    cin >> n >> b;
    string answer = "";
    while(n>0) {
        int num = n%b;
        if(num <= 9 && num >= 0) {
            answer += (num + '0');
        }
        else {
            answer += (num + 'A' - 10);
        }
        n = n/b;
    }
    reverse(answer.begin(),answer.end());
    cout << answer << '\n';
    return 0;
}