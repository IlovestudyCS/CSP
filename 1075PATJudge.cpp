#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

//一个没有赋初值的字符串，会被初始化为 "",atoi("") = 0
//If the first sequence of non-whitespace characters in str is not a valid integral number, 
//or if no such sequence exists because either str is empty or it contains only whitespace 
//characters, no conversion is performed and zero is returned.
using namespace std;

class user{
public:
    string id = "10000";
    bool flag = false;
    int problem[10] = {-2};
    int total_score = 0;
    int solve = 0;
} users[10010];


int N, K, M;
int P[10] = {0};

int main()
{
    cin >> N >> K >> M;
    for(int i = 1; i <= K; i++) {
        cin >> P[i];
    }
    for(int i = 1; i <= N; i++) {
        fill(users[i].problem, users[i].problem + K + 1, -2);
    }
    for(int i = 0; i < M; i++) {
        string sid;
        int id, pid, score;
        cin >> sid;
        cin >> pid;
        cin >> score;
        id = atoi(sid.c_str());
        if(score != -2) {
            users[id].id = sid;
            if(score > users[id].problem[pid]) {
                if(score == P[pid]) {users[id].solve ++;}
//                 if(score == -1) users[id].problem[pid] = 0;
//                 else 
                    users[id].problem[pid] = score;
            }
            if(score != -1)
            users[id].flag = true;
        }
    }
    for(int i = 1; i <= N; i++){
        if(users[i].flag) {
            for(int j = 1; j <= K; j++) {
                if(users[i].problem[j] != -1 && users[i].problem[j] != -2) {
                    users[i].total_score += users[i].problem[j];
                }
            }
        }
    }
    sort(users + 1, users + N + 1, [](user u1, user u2)->bool{
        if(u1.total_score != u2.total_score) return u1.total_score > u2.total_score;
        else if(u1.solve != u2.solve) return u1.solve > u2.solve;
        else return atoi(u1.id.c_str()) < atoi(u2.id.c_str());
    });
    users[0].total_score = -1;
    int cnt = 1;
    for(int i = 1; i <= N && users[i].flag; i++) {
        if(users[i].total_score != users[i - 1].total_score) {
            cnt = i;
            cout << cnt;
        } else{
            cout << cnt;
        }
        cout << " " << users[i].id << " " << users[i].total_score;
        for(int j = 1; j <= K; j++) {
            if(users[i].problem[j] == -1) cout << " " << 0;
            if(users[i].problem[j] != -2 && users[i].problem[j] != -1) cout << " " << users[i].problem[j];
            if(users[i].problem[j] == -2) cout << " " << "-";
        }
        cout << endl;
    }
    return 0;
}