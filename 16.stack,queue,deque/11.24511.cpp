#include <iostream>
#include <vector>
#include <deque>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> QorS(n);
    deque<int> d;
    for(int i = 0; i < n; i++) {
        cin >> QorS[i];
    }
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(QorS[i] == 0) {
            d.push_back(x);
        } 
    }
    int m;
    cin >> m;
    while(m--) {
        int x;
        cin >> x;
        d.push_front(x);
        cout << d.back() << ' ';
        d.pop_back();
    }
    cout << '\n';
    return 0;
}