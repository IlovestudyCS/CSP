#include<iostream>
#include<algorithm>
using namespace std;

int n;
int X,Y;
struct node
{
    int id = 0;;
    int d = 0;
} dis[210];


int main()
{
	cin >> n;
    cin >> X >> Y;
    for(int i = 1; i <= n; i++) {
        int x,y;
        cin >> x >> y;
        dis[i].id = i;
        dis[i].d = (x-X)*(x-X) + (y-Y)*(y-Y);
    }
    sort(dis + 1, dis + n + 1, [](node n1, node n2)->bool{
        if(n1.d != n2.d) return n1.d < n2.d;
        else return n1.id < n2.id;
    });
    for(int i = 1; i <= 3; i++) {
        cout << dis[i].id <<endl;
    }
	return 0;	
}