#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int n;
int cnt[4] = {0};
int main()
{
    cin >> n;
    int total = 0;
    char buffer[10];
    int j = 0;
    for(int i = 1; ; i++) {
        string s = string(itoa(i, buffer, 10));
        if(i % 7 == 0 || s.find('7') != string::npos) {
            cnt[j] ++;
            j = (j + 1) % 4;
        }else{
            j = (j + 1) % 4;
            total++;
        }
        if(total >= n) break;
    }
    for(int i = 0; i< 4; i++)
    cout << cnt[i] <<endl;
	return 0;	
}