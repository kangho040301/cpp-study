#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    string w;
    cin >> w;
    //대문자로 변환
    for(char &c : w) { // &c에 w값을 참조하여 w를 변환 
        c = toupper(c);
    }
    vector<int> count(26);
    
    //카운팅
    int len = w.length();
    string nw = "";
    for(int i = 0; i<len; i++) {
        if(nw.find(w[i]) == string::npos) nw += w[i];
        ++count[nw.find(w[i])];
    }
   
    //최댓값 찾기
    auto it = max_element(count.begin(),count.end());
    int max_index = it - count.begin();
    
    //중복체크
    int nlen = nw.length();
    for(int i = max_index; i < nlen; i++) {
        if(count[max_index] == count[i+1]) {
            cout << "?" << '\n';
            return 0;
        }
    }
    
    cout << nw[max_index] << '\n';
    return 0;
}
/*
// 더 나은 코드
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string w;
    cin >> w;
    vector<int> count(26);

    //1.대문자로 변환 후 카운팅
    for(char c : w) {
        ++count[toupper(c) - 'A'];
    }

    //2.최댓값 찾기
    auto it = max_element(count.begin(),count.end());
    int max_val = *it;
    int max_idx = it - count.begin();

    //3.중복체크
    int dup_check = 0;
    for(int i = 0; i < 26; i++) {
        if(count[i] == max_val) dup_check++;
    }
    
    //4.출력
    if(dup_check > 1) cout << "?" << '\n';
    else cout << (char)(max_idx + 'A') << '\n'; //'A'의 아스키코드 + 가장 큰 값의 인덱스 = 가장 많은 알파벳
}
*/