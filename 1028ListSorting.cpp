#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;
int N, C;

class stu{
public:
    char id[10];
    char name[10];
    int grade;
};

int main()
{
    vector<stu> v;
    scanf("%d %d", &N, &C);
    for(int i = 0; i < N; i++) {
        stu s;
        scanf("%s %s %d", &s.id, &s.name, &s.grade);
        v.push_back(s);
    }
    sort(v.begin(), v.end(), [](stu s1, stu s2) -> bool{
        switch (C)
        {
        case 1:
            if(strcmp(s1.id, s2.id) != 0) return strcmp(s1.id, s2.id) < 0;
            break;
        case 2:
            if(strcmp(s1.name, s2.name) != 0) return strcmp(s1.name, s2.name) < 0;
            break;
        default:
            if(s1.grade != s2.grade) return s1.grade < s2.grade;
            else return strcmp(s1.id, s2.id) < 0;
            break;
        }
    });
    for(int i = 0; i < v.size(); i++) {
        printf("%s %s %d", v[i].id, v[i].name, v[i].grade);
        if(i != v.size() - 1) printf("\n");
    }
    return 0;
}