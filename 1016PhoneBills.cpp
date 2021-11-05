#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

/*
CYJJ 01:01:05:59 on-line
CYJJ 01:01:07:00 off-line
CYLL 01:01:06:01 on-line
CYLL 01:01:08:03 off-line
CYLL 01:28:15:41 on-line
CYLL 01:28:16:05 off-line

aaa 01:01:01:03 on-line
aaa 01:02:00:01 on-line
aaa 01:04:23:59 off-line
aaa 01:05:02:24 on-line
*/

#define MAXSIZE 24
#define on_line 1
#define off_line 0
int price[MAXSIZE];
int N;

class customer{
    public:
    string name;
    // int month;
    // int day;
    // int minute;
    int type;
    string time[4];
};

int main()
{
    for(int i = 0; i < MAXSIZE; i++) {
        cin >> price[i];
    }
    cin >> N;
    vector<customer> v;
    for(int i = 0; i < N; i++) {
        customer c;
        string call_type;
        string time;
        cin >> c.name;
        cin >> time;
        cin >> call_type;
        int remain = 0;
        for(int j = 0; j < 4; j++) {
            int  pos = time.find(':', remain);
            string s = time.substr(remain, 2);
            c.time[j] = s;
            remain = (pos + 1);
        }
        if(call_type == "on-line") c.type = on_line;
        if(call_type == "off-line") c.type = off_line;
        v.push_back(c);
    }
    
    sort(v.begin(), v.end(), [](customer c1, customer c2)->bool {
        if(c1.name != c2.name) return c1.name < c2.name;
        else if(c1.time[0] != c2.time[0]) return c1.time[0] < c2.time[0];
        else if(c1.time[1] != c2.time[1]) return c1.time[1] < c2.time[1];
        else if(c1.time[2] != c2.time[2]) return c1.time[2] < c2.time[2];
        else return c1.time[3] < c1.time[3];
    });
    for(int i = 0; i < N - 1; i++){
        if(v[i].name == v[i = 1].name && v[i].type == on_line && v[i + 1].type == off_line) {
            int total_time = 0, cost = 0;
            int day = atoi(v[i + 1].time[1].c_str()) - atoi(v[i].time[1].c_str());
            int hour = atoi(v[i + 1].time[2].c_str()) - atoi(v[i].time[2].c_str());
            int minute = atoi(v[i + 1].time[3].c_str()) - atoi(v[i].time[3].c_str());

            total_time = day * 24 * 60 + hour * 60 + minute;
            
            cout << v[i].name << " " << v[i].time[0] << endl;
            cout << v[i].time[1] <<":" << v[i].time[2] << ":" << v[i].time[3] <<
            " " << v[i + 1].time[1] <<":" << v[i + 1].time[2] << ":" << v[i + 1].time[3] <<
            " " << total_time;
        }
    }
    return 0;
}