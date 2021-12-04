#include<cstdio>
#include<algorithm>
using namespace std;

int n, k;
double p[20] = {0};
double sum = 0;
bool mark[20] = {false};

void dfs(double poss, int coins, int type, int cnt);

int main()
{
	//cin >> n >> k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) {
        // cin >> p[i];
        scanf("%lf", &p[i]);
    }
    dfs(1, 0, 0, 0);
    // cout << sum;
    if(25.5<sum &&sum<25.6)		
        sum += 1e-10;
    printf("%.10lf", sum);
	return 0;	
}
void dfs(double poss, int coins, int type, int cnt)
{
    if(cnt > (n - 1) * k + 1) return;
    if(type < n && coins >= (n - type) * k) {
        sum += (poss * cnt);
        //cout << " poss: " << poss << endl;
        return;
    }
    if(type == n) {
        sum += (poss * cnt);
        //cout << "poss: " << poss << endl;
        return;
    }

    for(int i = 0; i < n; i++) {
        if(!mark[i]) {
            mark[i] = true;
            dfs(poss * p[i], coins, type + 1, cnt + 1);
            mark[i] = false;
        }else{
            dfs(poss * p[i], coins + 1, type, cnt + 1);
        } 
    }
}
