#include<iostream>
#include<algorithm>
using namespace std;
/*
    (xr, yd)            (xr, yu)

    
    (xl,yd)             (xl, yu)
*/
int n, k, t;
int xl, yd, xr, yu;          

bool isIn(int x, int y)
{
    if(x < xl || x > xr) return false;
    if(y < yd || y > yu) return false;
    return true;
}

int main()
{
	cin >> n >> k >> t;
    cin >> xl >> yd >> xr >> yu;
    int pass = 0, stop = 0;
    for(int i = 0; i < n; i++) {
        int incnt = 0, concnt = 0;
        bool flag = false;
        bool inflag = false;
        for(int j = 0; j < t; j++) {
            int x, y;
            cin >> x >> y;
            if(isIn(x, y)) {
                incnt++;
                concnt++;
            }else{
                if(concnt >= k && flag == false){
                    stop++;
                    flag = true;
                }
                if(concnt < k && concnt > 0 && inflag == false) {
                    inflag = true;
                }
                concnt = 0;
            }
        }
        if(concnt >= k && flag == false){
            stop++;
            flag = true;
        }
        if(incnt > 0 && inflag == false) {
            inflag = true;
        }
        if(inflag) pass++;
    }
    cout << pass << endl;
    cout << stop;
	return 0;	
}