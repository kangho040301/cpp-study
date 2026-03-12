#include <iostream>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    if(n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    queue<int> card;
    int i = 1;
    while(n--) {
        card.push(i);
        i++;
    }
    while(true) {
        card.pop();
        if(card.size() == 1) {
            cout << card.front() << '\n';
            return 0;
        }
        card.push(card.front());
        card.pop();
    }
}