/*
 * PAT (Advanced Level) Practice
 * 1084 Broken Keyboard
 * 字符串大小写转换：
 * 大写：transform(expected.begin(), expected.end(), expected.begin(), ::toupper);
 * 小写：transform(expected.begin(), expected.end(), expected.begin(), ::tolower);
 */
#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
    string expected, actual;
    cin >> expected >> actual;
    transform(expected.begin(), expected.end(), expected.begin(), ::toupper);
    transform(actual.begin(), actual.end(), actual.begin(), ::toupper);

    set<char> sc;
    vector<char> v;
    for(int i = 0; i < actual.size(); i++) {
        sc.insert(actual[i]);
    }
    for(int i = 0; i < expected.size(); i++) {
        if(sc.find(expected[i]) == sc.end()) {
            v.push_back(expected[i]);
            sc.insert(expected[i]);
        }
    }
    for(char c : v){
        cout << c;
    }
    return 0;
}