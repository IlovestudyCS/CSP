/*
 * 1083 List Grades
 * 按照分数递减排序
 */

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class stu{
public:
    string name;
    string id;
    int grade;
};

int N;
int lmin, lmax;

int main()
{
    vector<stu> v;
    cin >> N;
    for(int i = 0; i < N; i++) {
        stu s;
        cin >> s.name;
        cin >> s.id;
        cin >> s.grade;
        v.push_back(s);
    }
    cin >> lmin >> lmax;

    sort(v.begin(), v.end(), [](stu s1, stu s2)->bool{
        return s1.grade > s2.grade;
    });
    int cnt = 0;
    for(int i = 0; i < v.size(); i++) {
        if(v[i].grade >= lmin && v[i].grade <= lmax) {
            cout << v[i].name << " " << v[i].id << " " << v[i].grade << endl;
            cnt++;
        }
    }
    if(cnt == 0) cout << "NONE";
    return 0;
}