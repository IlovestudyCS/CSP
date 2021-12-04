/*
 * PAT (Advanced Level) Ptactice
 * 1103 Integer Factorization(30分)
 * cmath：pow(基底，幂次):乘方 sqrt(): 开方
 */

#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>

using namespace std;

int N, K, P;
int integ[401] = {0};
vector<int> ansV, tempV;
int cnt = 0;
int maxIndexSum = 0;

void dfs(int index, int sum, int number, int max);
int stop = 0;


int main()
{
    // cin >> N >> K >> P;
    scanf("%d %d %d", &N, &K, &P);
    for(int i = 0; i <= N; i++) {
        integ[i] = i;
        integ[i] = pow(i, P);
    }
//     for(int i = 0; i <= N; i++) {
//         integ[i] = pow(i, P);
//     }
    if(P == 3) {
        stop = cbrt(N);
    }else{
        stop = sqrt(N);
    }
    dfs(stop, 0, 0, 0);
    if(ansV.size() != 0) {
        // cout << N << " = ";
        printf("%d = ", N);
        // cout << ansV[ansV.size() - 1] << "^" << P;
        printf("%d^%d", ansV[0], P);
        for(int i = 1; i < ansV.size(); i++){
            // cout << " + " << ansV[i] << "^" << P;
            printf(" + %d^%d", ansV[i], P);
        }
        // cout << endl;
        printf("\n");
    } else{
        // cout  << "Impossible";
        printf("Impossible");
    }
    
    return 0;
}

void dfs(int index, int sum, int number, int max)
{
    // if(index > stop) return;
    // if(index > N || sum > N || number > K) return;
    if(index < 1 || sum > N || number > K) return;
    if(sum == N && number == K) {
        cnt++;
        // sort(tempV.begin(), tempV.end(), [](int a, int b)->bool{
        //     return a > b;
        // });
        if(max >= maxIndexSum) {
//             if(max == maxIndexSum) {
//                 ansV = (ansV < tempV) ? ansV : tempV;
//             } else{
//                 ansV = tempV;
//             }
            ansV = tempV;
            maxIndexSum = max;
        }
        return ;
    }

    tempV.push_back(index);
    dfs(index, sum + integ[index], number + 1, max + index);
    tempV.pop_back();
    dfs(index - 1, sum, number, max);
}