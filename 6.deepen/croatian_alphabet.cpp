#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    string word;
    cin >> word;
    
    //1.c,d,l,n,s,z가 나올 시 필터링
    int len = word.length();
    int word_length = word.length();
    for(int i = 0; i <len; i++) {
        switch (word[i]) {
            case 'c':
                if(word[i+1] == '=' || word[i+1] == '-') word_length--;
                break;
            case 's': case 'z':
                if(word[i+1] == '=') word_length--;
                break;
            case 'd':
                switch (word[i+1]) {
                    case 'z':
                        if(word[i+2] == '=') word_length--;
                        break;
                    case '-':
                        word_length--;
                        break;
                }
                break;
            case 'l':
                if(word[i+1] == 'j') word_length--;
                break;
            case 'n':
                if(word[i+1] == 'j') word_length--;
                break;
        }
    }
    cout << word_length << '\n';
    return 0;
}