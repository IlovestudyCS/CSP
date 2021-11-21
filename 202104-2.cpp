#include<iostream>
using namespace std;

int n, L, r, t;
int pix[610][610] = {0};
int sum[610][610] = {0};
int main()
{
	cin >> n >> L >> r >> t;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> pix[i][j];
			if(i == 0 && j == 0) sum[i][j] = pix[i][j];
			else if(i == 0) sum[i][j] = sum[0][j - 1] + pix[i][j];
			else if(j == 0) sum[i][j] = sum[i - 1][0] + pix[i][j];
			else sum[i][j] = sum[i - 1][j] + sum[i][j - 1] + pix[i][j] - sum[i - 1][j - 1];
		}
	}
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			int x1 = 0, y1 = 0;
			int x2 = 0, y2 = 0;
			x1 = (i - r) >= 0 ? (i - r) : 0;
			y1 = (j - r) >= 0 ? (j - r) : 0;
			x2 = (i + r) < n ? (i + r) : n - 1;
			y2 = (j + r) < n ? (j + r) : n - 1;
			int size = (x2 - x1 + 1) * (y2 - y1 + 1);
			int a = 0, b = 0, c = 0, x = 0;
			if(x1 != 0 && y1 != 0) c = sum[x1 - 1][y1 - 1];
			if(x1 != 0) a = sum[x1 - 1][y2];
			if(y1 != 0) b = sum[x2][y1 - 1];
			x = sum[x2][y2] - b - a + c;
			if((double)x / size <= t) cnt++;
		}
	}
	cout << cnt;
	return 0;	
} 
