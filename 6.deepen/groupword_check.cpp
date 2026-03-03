#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    int answer = n;

    for(int i = 0; i < n; i++) {
        string word;
        cin >> word;
        //그룹 단어인지 체크
        int len = word.length();
        string new_word;
        new_word = word[0];
        for(int j = 1; j < len; j++) {
            if(word[j] == word[j-1]) continue;

            if(new_word.find(word[j]) == string::npos) new_word += word[j];
            else {
                answer--;
                break;
            }
        }
    }
    cout << answer << '\n';
    return 0;
}