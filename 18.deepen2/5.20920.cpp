#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(pair<int,string> const& a,pair<int,string> const& b) {
    // 빈도수가 다르면? 많은 순
    if(a.first != b.first) return a.first > b.first;
    // 빈도수 같은데 길이가 다르면? 긴 순
    else if(a.second.size() != b.second.size()) return a.second.size() > b.second.size();
    // 빈도수 같고 길이도 같다면? 사전 순(오름차순)
    else return a.second < b.second;
} 
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    unordered_map<string,int> words;
    //words에 단어와 빈도수 저장
    for(int i = 0; i < n; i++) {
        string word;
        cin >> word;
        if(word.size() >= m) {
            words[word]++;
        }
    }
    
    //저장된 map을 pair의 vector로 변환(기준에 따라 sort하기 위함)
    int num = words.size();
    vector<pair<int,string>> dict(num);
    int i = 0;
    for(auto const&[key, val] : words) {
        dict[i].first = val;
        dict[i].second = key;
        i++;
    }
    sort(dict.begin(),dict.end(),compare);
    
    for(int a = 0; a < num; a++) {
        cout << dict[a].second << '\n';
    }
    return 0;
}