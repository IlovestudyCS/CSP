/*
 * 1095 Cars on Campus
 */
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include<iomanip>

using namespace std;

#define in 1;
#define out 0;

class record
{
public:
    string number;
    string time[3];
    int status;
    bool flag = false;
};
class car
{
public:
    string number;
    string sin;
    string sout;
    int interval;
    int flag = false;
};

int N, K;

int main()
{
    vector<record> vr;
    scanf("%d %d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        record r;
        string t;
        char buffer1[10];
        char buffer2[10];
        char buffer3[10];
        scanf("%s %s %s", buffer1, buffer2, buffer3);
        r.number = string(buffer1);
        t = string(buffer2);
        int rest = 0;
        for (int j = 0; j < 3; j++)
        {
            int pos = t.find(":", rest);
            string s = t.substr(rest, 2);
            r.time[j] = s;
            rest = pos + 1;
        }
        string s;
        s = string(buffer3);
        if (s == "in")
            r.status = in;
        if (s == "out")
            r.status = out;
        vr.push_back(r);
    }

    sort(vr.begin(), vr.end(), [](record r1, record r2) -> bool
         {
             for (int i = 0; i < 3; i++)
             {
                 if (r1.time[i] != r2.time[i])
                 {
                     return r1.time[i] < r2.time[i];
                 }
             }
             return false;
         });

    vector<car> vc;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            
            if (vr[i].number == vr[j].number && (!((vr[i].status == 1) && (vr[j].status == 0)) || vr[j].flag == true))
            {
                break;
            }
            if (vr[i].number == vr[j].number && (vr[i].status == 1) && (vr[j].status == 0) && vr[j].flag == false)
            {
                car s;
                s.number = vr[i].number;
                s.sin = vr[i].time[0] + ":" + vr[i].time[1] + ":" + vr[i].time[2];
                s.sout = vr[j].time[0] + ":" + vr[j].time[1] + ":" + vr[j].time[2];
                s.interval = (atoi(vr[j].time[0].c_str()) - atoi(vr[i].time[0].c_str())) * 60 * 60
                            + (atoi(vr[j].time[1].c_str()) - atoi(vr[i].time[1].c_str())) * 60 +
                            (atoi(vr[j].time[2].c_str()) - atoi(vr[i].time[2].c_str()));
                vc.push_back(s);
                vr[j].flag = true;
                break;
            }
        }
    }
    set<string> maxCar;
    int max = 0;
    for (int i = 0; i < K; i++)
    {
        string s;
        char buffer[10];
        scanf("%s", buffer);
        s = string(buffer);
        int cnt = 0;
        for (int j = 0; j < vc.size(); j++)
        {
            if (vc[j].sin <= s && vc[j].sout > s)
            {
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }

    for(int i = 0; i < vc.size(); i++) {
        for(int j = i + 1; j < vc.size(); j++) {
            if(vc[i].number == vc[j].number && vc[j].flag == false) {
                vc[i].interval += vc[j].interval;
                vc[j].flag = true;
            }
        }
    }

    for (int i = 0; i < vc.size(); i++)
    {
        if(vc[i].flag) {
            continue;
        }
        if (vc[i].interval > max)
        {
            max = vc[i].interval;
            maxCar.clear();
            maxCar.insert(vc[i].number);
        }
        if (vc[i].interval == max)
        {
            maxCar.insert(vc[i].number);
        }
    }
    for(auto i = maxCar.begin(); i != maxCar.end(); i++) {
        printf("%s ", (*i).c_str());
    }
    printf("%02d:%02d:%02d", max / 3600, max % 3600 / 60, max % 60);
    return 0;
}