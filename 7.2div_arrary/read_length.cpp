#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    vector<string> word(5);
    vector<int> w_length(5);
    for(int i = 0; i < 5; i++) {
        cin >> word[i];
        w_length[i] = word[i].length();
    }
    auto it = max_element(w_length.begin(),w_length.end());
    int longest = *it;
    
    for(int i = 0; i < longest; i++) {
        for(int j = 0; j < 5; j++) {
            if(i < (int)word[j].length())
                cout << word[j][i];
        }
    }
    return 0;
}