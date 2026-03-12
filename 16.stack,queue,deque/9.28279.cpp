#include <iostream>
#include <deque>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    deque<int> d;
    while(n--) {
        int a;
        cin >> a;
        switch (a) {
            case 1: {
                int x;
                cin >> x;
                d.push_front(x);
                break;
            }
            case 2: {
                int x;
                cin >> x;
                d.push_back(x);
                break;
            }
            case 3:
                if(!(d.empty())) {
                    cout << d.front() << '\n';
                    d.pop_front();
                }
                else cout << -1 << '\n';
                break;
            case 4:
                if(!(d.empty())) {
                    cout << d.back() << '\n';
                    d.pop_back();
                }
                else cout << -1 << '\n';
                break;
            case 5:
                cout << d.size() << '\n';
                break;
            case 6:
                cout << (d.empty() ? 1 : 0) << '\n';
                break;
            case 7:
                cout << (d.empty() ? -1 : d.front()) << '\n';
                break;
            case 8:
                cout << (d.empty() ? -1 : d.back()) << '\n';
                break;
        }
    }
    return 0;
}