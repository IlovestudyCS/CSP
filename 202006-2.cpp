#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int n, a, b;

int main()
{
    map<int, pair<bool, int>> v;
    cin >> n >> a >> b;
    for(int i = 0; i < a + b; i++) {
        int index, value;
        cin >> index >> value;
        pair<bool, int> p;
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
    int sum = 0;
    for(auto i : v) {
        if(i.second.first == true)
        sum += (i.second.second);
    }
    cout << sum;
	return 0;	
}