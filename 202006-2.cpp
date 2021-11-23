#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int n, a, b;

int main()
{
    map<long, pair<bool, long long>> v;
    cin >> n >> a >> b;
    for(int i = 0; i < a + b; i++) {
        long index, value;
        cin >> index >> value;
        pair<bool, long long> p;
        p.first = false;
        p.second = 0;
        if(v.find(index) == v.end()) {
            p.second = value;
            v[index] = p;
        } else{
            p.first = true;
            p.second = v[index].second * value;
            v[index] = p;
        }
    }
    long long sum = 0;
    for(auto i : v) {
        if(i.second.first == true)
        sum += (i.second.second);
    }
    cout << sum;
	return 0;	
}