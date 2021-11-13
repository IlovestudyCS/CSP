/*
 * 1095 Cars on Campus
 */
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

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
};

int N, K;

int main()
{
    vector<record> vr;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        record r;
        string t;
        cin >> r.number;
        cin >> t;
        int rest = 0;
        for (int j = 0; j < 3; j++)
        {
            int pos = t.find(":", rest);
            string s = t.substr(rest, 2);
            r.time[j] = s;
            rest = pos + 1;
        }
        string s;
        cin >> s;
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
            
            if (vr[i].number == vr[j].number && !((vr[i].status == 1) && (vr[j].status == 0)) && vr[j].flag == true)
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
        cin >> s;
        int cnt = 0;
        for (int j = 0; j < vc.size(); j++)
        {
            if (vc[j].sin <= s && vc[j].sout > s)
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    for (int i = 0; i < vc.size(); i++)
    {
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
        cout << *i << " ";
    }
    cout << max / 3600 << ":" << max % 3600 / 60 << ":" << max % 60;
    return 0;
}
// JH007BD 18:00:01 in
// ZD00001 11:30:08 out
// DB8888A 13:00:00 out
// ZA3Q625 23:59:50 out
// ZA133CH 10:23:00 in
// ZD00001 04:09:59 in
// JH007BD 05:09:59 in
// ZA3Q625 11:42:01 out
// JH007BD 05:10:33 in
// ZA3Q625 06:30:50 in
// JH007BD 12:23:42 out
// ZA3Q625 23:55:00 in
// JH007BD 12:24:23 out
// ZA133CH 17:11:22 out
// JH007BD 18:07:01 out
// DB8888A 06:30:50 in