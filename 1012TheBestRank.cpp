#include <iostream>
#include <algorithm>
#include <string>
#include<vector>

using namespace std;

int N, M;

class stu
{
public:
    string id;
    int c_grade;
    int m_grade;
    int e_grade;
    int a_grade;
    int c_rank;
    int m_rank;
    int e_rank;
    int a_rank;
};

enum type{a = 1, c = 2, m = 3, e = 4};

class srank{
public:
    type t;
    int rank;
    srank(type t, int r) {
        this->t = t;
        this->rank = r;
    }
};

int main()
{
    cin >> N >> M;
    vector<stu> v;
    for(int i = 0; i < N; i++) {
        stu s;
        cin >> s.id >> s.c_grade >> s.m_grade >> s.e_grade;
        s.a_grade = (s.c_grade + s.m_grade + s.e_grade) / 3;
        v.push_back(s);
    }

    sort(v.begin(), v.end(), [](stu s1, stu s2) ->bool{
        return s1.c_grade > s2.c_grade;
    });
    v[0].c_rank = 1;
    for(int i = 1; i < v.size(); i++) {
        if(v[i].c_grade != v[i - 1].c_grade) {
            v[i].c_rank = i + 1;
        } else{
            v[i].c_rank = v[i - 1].c_rank;
        }
    }

    sort(v.begin(), v.end(), [](stu s1, stu s2) ->bool{
        return s1.m_grade > s2.m_grade;
    });
    v[0].m_rank = 1;
    for(int i = 1; i < v.size(); i++) {
        if(v[i].m_grade != v[i - 1].m_grade) {
            v[i].m_rank = i + 1;
        } else{
            v[i].m_rank = v[i - 1].m_rank;
        }
    }
    
    sort(v.begin(), v.end(), [](stu s1, stu s2) ->bool{
        return s1.e_grade > s2.e_grade;
    });
    v[0].e_rank = 1;
    for(int i = 1; i < v.size(); i++) {
        if(v[i].e_grade != v[i - 1].e_grade) {
            v[i].e_rank = i + 1;
        } else{
            v[i].e_rank = v[i - 1].e_rank;
        }
    }


    sort(v.begin(), v.end(), [](stu s1, stu s2) ->bool{
        return s1.a_grade > s2.a_grade;
    });
    v[0].a_rank = 1;
    for(int i = 1; i < v.size(); i++) {
        if(v[i].a_grade != v[i - 1].a_grade) {
            v[i].a_rank = i + 1;
        } else{
            v[i].a_rank = v[i - 1].a_rank;
        }
    }

    for(int i = 0; i < M; i++){
        string input;
        cin >> input;
        vector<srank> vv;
        bool flag = false;
        for(stu s : v) {
            if(input == s.id) {
                vv.push_back(srank(a, s.a_rank));
                vv.push_back(srank(c, s.c_rank));
                vv.push_back(srank(m, s.m_rank));
                vv.push_back(srank(e, s.e_rank));
                
                sort(vv.begin(), vv.end(), [](srank r1, srank r2)->bool{
                    if(r1.rank != r2.rank) return r1.rank < r2.rank;
                    else return r1.t < r2.t;
                });
                switch(vv[0].t){
                    case a: cout << vv[0].rank << " " << "A";break;
                    case c: cout << vv[0].rank << " " << "C";break;
                    case m: cout << vv[0].rank << " " << "M";break;
                    case e: cout << vv[0].rank << " " << "E";break;
                }
                flag = true;
            }
        }
        if(!flag) cout << "N/A";
        if(i != M - 1) cout << endl;
    }
}