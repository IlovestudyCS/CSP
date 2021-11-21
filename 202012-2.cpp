#include<iostream>
using namespace std;

int m;
int result[100010] = {0};
int score[100010] = {0};
int maxV[100010] = {0};
int main()
{
	cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> score[i];
        cin >> result[i];
    }
    int max = 0, theta = 0, maxtheta = 0, pos = 0;
    for(int i = 0; i < m; i++) {
        int cnt = 0;
        for(int j = 0; j < m; j++) {
            if(score[i] > score[j] && result[j] == 0) {
                cnt++;
            }
            if(score[i] <= score[j] && result[j] == 1) {
                cnt++;
            }
        }
        // if(max <= cnt) {
        //     max = cnt;
        //     if(max == cnt) {
        //         if(theta < score[i])
        //         theta = score[i];
        //     }else{
        //         theta = score[i];
        //     }
        // }
        if(max <= cnt) {
            if(max == cnt) {
                maxV[pos++] = result[i];
            } else{
                max = cnt;
                pos = 0;
                maxV[pos++] = result[i];
            }
        }
    }
    max = 0;
    for(int i = 0; i <= pos; i++) {
        if(max < maxV[i]) max = maxV[i];
    }
    cout << max;
	return 0;	
}