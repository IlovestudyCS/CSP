/*
 * 1080 Graduate Admission
 * 根据最终分数来排名，从高到低
 * final grade > Ge, Ge相同，排名相同
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class school{
public:
    vector<int> list;
    int quota;
    int number = 0;
} sch[100];

class stu {
public:
    int id;
    int Ge;
    int Gi;
    int choices[5];
    int total;
    int sid; //被录取的学校id
    bool flag = false; //是否被录取
};

int N, M, K;

int main()
{
    vector<stu> v;
    cin >> N >> M >> K;
    for(int i = 0; i < M; i++) {
        cin >> sch[i].quota;
    }
    for(int i = 0; i < N; i++) {
        stu s;
        s.id = i;
        cin >> s.Ge >> s.Gi;
        s.total = s.Ge + s.Gi;
        for(int j = 0; j < K; j++) {
            cin >> s.choices[j];
        }
        v.push_back(s);
    }

    sort(v.begin(), v.end(), [](stu s1, stu s2)->bool{
        if(s1.total != s2.total) return s1.total > s2.total;
        else return s1.Ge > s2.Ge;
    });

    for(int i = 0; i < K; i++) {
        if(sch[v[0].choices[i]].quota > 0) {
            v[0].flag = true;
            v[0].sid = v[0].choices[i];
            sch[v[0].choices[i]].number++;
            sch[v[0].choices[i]].list.push_back(v[0].id);
            break;
        }
    }
    for(int i = 1; i < v.size(); i++) {
        if(v[i].total != v[i - 1].total || v[i].Ge != v[i - 1].Ge) {
            for(int j = 0; j < K; j++) {
                if(sch[v[i].choices[j]].number < sch[v[i].choices[j]].quota) {
                    v[i].sid = v[i].choices[j];
                    v[i].flag = true;
                    sch[v[i].choices[j]].number++;
                    sch[v[i].choices[j]].list.push_back(v[i].id);
                    break;
                }
            }
        } else{
            for(int j = 0; j < K; j++) {
                if(v[i - 1].flag && v[i - 1].sid == v[i].choices[j]) {
                    v[i].sid = v[i].choices[j];
                    v[i].flag = true;
                    sch[v[i].choices[j]].number++;
                    sch[v[i].choices[j]].list.push_back(v[i].id);
                    break;
                }
                if(sch[v[i].choices[j]].number < sch[v[i].choices[j]].quota) {
                    v[i].sid = v[i].choices[j];
                    v[i].flag = true;
                    sch[v[i].choices[j]].number++;
                    sch[v[i].choices[j]].list.push_back(v[i].id);
                    break;
                }
            }
        }
    }
    for(int i = 0; i < M; i++) {
        if(sch[i].list.size() != 0) {
            sort(sch[i].list.begin(), sch[i].list.end(), [](int a, int b)->bool{
                return a < b;
            });
            for(int j = 0; j < sch[i].list.size(); j++) {
                cout << sch[i].list[j];
                if(j != sch[i].list.size() - 1) cout << " ";
            }
            cout << endl;
        } else{
            cout << endl;
        }
    }
    return 0;
}