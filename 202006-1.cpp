#include<iostream>
#include<algorithm>
using namespace std;

struct node
{
    int x = 0;
    int y = 0;
    int type = 0;
    char t;
} input[1010];

int n, m;

int main()
{
    cin >> n >>m;
    for(int i = 0; i < n; i++) {
        cin >> input[i].x >> input[i].y;
        cin >> input[i].t;
    }
    for(int i = 0; i < m; i++) {
        int theta0, theta1, theta2;
        bool flag = true;
        cin >> theta0 >>theta1 >> theta2;
        if(theta0 + theta1 * input[0].x + theta2 * input[0].y > 0){
            input[0].type = 1;
        } else{
            input[0].type = -1;
        }
        for(int j = 1; j < n; j++) {
            if(input[j].t == input[0].t) {
                input[j].type = input[0].type;
            }else{
                input[j].type = - input[0].type;
            }
            if((theta0 + theta1 * input[j].x + theta2 * input[j].y) * input[j].type < 0) {
                flag = false;
                break;
            }
        }
        if(flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
	return 0;	
}