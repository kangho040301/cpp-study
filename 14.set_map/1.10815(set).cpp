#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    unordered_set<int> my_card;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        my_card.insert(num);
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;
        if(my_card.find(num) != my_card.end()) cout << 1 << ' ';
        else cout << 0 << ' ';
    }
    cout << '\n';
    return 0;
}

//set : 중복x 오름차순으로 정리된 집합 O(log N)
//unordered_set : 중복x 집합 (해시 테이블) O(1)