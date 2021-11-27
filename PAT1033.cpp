/*
 * PAT(Basic Level) Practice (中文)
 * 1033 旧键盘打字
 * 坑：第一个字符串为空时，cin会忽略换行，要用getline(cin, line)
 */

#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool key[128] = {false};

int main()
{
    string broken_key, actual;
    //cin >> broken_key >> actual;
    getline(cin, broken_key);
    getline(cin, actual);
    for(int i = 0; i < broken_key.size(); i++) {
        if(broken_key[i] >= 'A' && broken_key[i] <= 'Z') {
            key[broken_key[i] + ('a' - 'A')] = true;
            key[broken_key[i]] = true;
        } else if(broken_key[i] == '+') {
            fill(key + 'A', key + 'Z' + 1, true);
        } else{
            key[broken_key[i]] = true;
        }
        
    }
    int cnt = 0;
    for(int i = 0; i < actual.size(); i++) {
        if(key[actual[i]]) continue;
        cout << actual[i];
        cnt++;
    }
    if(cnt == 0) cout << endl;
    return 0;
}