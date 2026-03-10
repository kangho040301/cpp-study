#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    unordered_map<int, int> card;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if(card.find(num) != card.end()) {
            card[num]++;
        }
        else card[num] = 1;
        // if-else 부분을 그냥 card[num]++; 로 써도 똑같음
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++) {
        int num;
        cin >> num;
        if(card.find(num) != card.end()) {
            cout << card[num] << ' ';
        }
        else cout << 0 << ' ';
        //if-else 부분을 그냥 cout << card[num] << ' ' 로 써도 똑같음 (num이 없으면 0 출력)
    } 
    cout << '\n';
    return 0;
}