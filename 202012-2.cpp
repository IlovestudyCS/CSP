#include<iostream>
#include<algorithm>
using namespace std;

int m;

struct stu
{
    int score;
    int result;
} stus[100010];
int sum[100010] = {0};

int totalpass = 0;

int main()
{
	cin >> m;
    stu s;
    s.score = 0;
    s.result = -1;
    fill(stus, stus + m, s);
    for(int i = 0; i < m; i++) {
        cin >> stus[i].score>> stus[i].result;
        if(stus[i].result == 1) totalpass++;
    }
    sort(stus, stus + m, [](stu s1, stu s2)->bool{
        return s1.score < s2.score;
    });
    sum[0] = 0;
    int Max = 0, id = 0, pre = 0;
    for(int i = 1; i < m; i++) {
        sum[i] = sum[i - 1] + 1 - stus[i - 1].result;
        int prepass = i - sum[i];
        int ans = 0;
        if(stus[i].score != stus[i - 1].score) {
            pre = sum[i];
        }
        ans = pre + totalpass - prepass;
        if(Max <= ans) {
            Max = ans;
            id = stus[i].score;
        }
    }

    cout << id;
	return 0;	
}