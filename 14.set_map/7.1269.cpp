#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int a, b;
    cin >> a >> b;
    unordered_map<int,int> A;
    A.reserve(a+b);
    for(int i = 0; i < a; i++) {
        int n;
        cin >> n;
        A[n]++;
    }
    for(int i = 0; i < b; i++) {
        int n;
        cin >> n;
        if(A.find(n) != A.end()) A[n]--;
        else A[n]++;
    }
    int answer = 0;
    for(const auto& [key, val] : A) {
        answer += val;
    }
    cout << answer << '\n';
    return 0;
}
//집합은 중복을 포함하지않는다. (set으로 하는게 더 간결함)