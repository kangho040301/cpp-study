#include <iostream>
#include <deque>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    deque<pair<int,int>> balloon;
    for(int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        balloon.push_back({i, num});
    }
    cout << balloon.front().first << ' ';
    int k = balloon.front().second;
    balloon.pop_front();
    while(n-- > 1) {
        if(k > 0) {
            for(int i = 1; i < k; i++) {
                balloon.push_back(balloon.front());
                balloon.pop_front(); 
            }
            cout << balloon.front().first << ' ';
            k = balloon.front().second;
            balloon.pop_front();
        }
        else if(k < 0) {
            for(int i = 1; i < -1*k; i++) {
                balloon.push_front(balloon.back()); 
                balloon.pop_back();
            }
            cout << balloon.back().first << ' ';
            k = balloon.back().second;
            balloon.pop_back();
        }
    }
    return 0;
}