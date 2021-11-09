/* 
 * 1055 The World's Richest 
 */
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int N, K;
int M, Amin, Amax;

class people{
public:
    char name[10];
    int age;
    int worth;
};

int main()
{
    vector<people> v;
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++) {
        people p;
        scanf("%s %d %d", &p.name, &p.age, &p.worth);
        v.push_back(p);
    }
    sort(v.begin(), v.end(), [](people p1, people p2)->bool{
            return p1.age < p2.age;
    });
    for(int i = 0; i < K; i++) {
        scanf("%d %d %d", &M, &Amin, &Amax);
        printf("Case #%d:\n", i + 1);
        int cnt = 0;
        int begin = 0, end = 0;
        bool bflag = false, eflag = false;
        int j = 0;
        for(; j < v.size(); j++) {
            if(v[j].age >= Amin && bflag == false) {
                begin = j;
                bflag = true;
            }
            if(v[j].age <= Amax) {
                eflag = true;
                end = j;
            }
        }
        if(bflag && eflag && begin <= end) {
            sort(v.begin() + begin, v.begin() + end + 1, [](people p1, people p2)->bool{
                if(p1.worth != p2.worth) return p1.worth > p2.worth;
                else if(p1.age != p2.age) return p1.age  < p2.age;
                else return strcmp(p1.name, p2.name) < 0; 
            });
            for(int k = begin; k <= end && cnt < M; k++){
                cnt++;
                printf("%s %d %d\n", v[k].name, v[k].age, v[k].worth);
            }
        }else{
            printf("None\n");
        }

        sort(v.begin() + begin, v.begin() + end + 1, [](people p1, people p2)->bool{
            return p1.age < p2.age;
        });
    }

    return 0;
}