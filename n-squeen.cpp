#include<iostream>
#include<cmath>

using namespace std;
#define MaxSize 100

void generateP(int index);
int P[MaxSize];
int hashtable[MaxSize] = {false};
int n = 8;
int count = 0;
int main()
{
    // cin >> n;
    generateP(1);
    cout << count << endl;
    return 0;
}

void generateP(int index)
{
    if(index == n + 1) {
        count++;
        return;
    }
    for(int i = 1; i <= n; i++) {
        if(!hashtable[i]) {
            hashtable[i] = true;
            P[index] = i; 
            bool flag = true;
            for(int k = 1; k < index; k++) {
                if(abs(k - index) == abs(i - P[k])) {
                    flag = false;
                    break;
                }
            }
            if(flag) {
                generateP(index + 1);
            }
            hashtable[i] = false;
        }
    }
}