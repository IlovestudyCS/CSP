#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int n;
struct node{
    int x;
    int y;
    node(){
        x = 0;
        y = 0;
    }
    node(int xx, int yy) {
        x = xx;
        y = yy;
    }
};
int score[5] = {0};
struct Compare{
    bool operator()(const node n1, const node n2) {
        if(n1.x != n2.x) return n1.x < n2.x;
        else return n1.y < n2.y;
    }
};
int main()
{
    cin >> n;
    
    map<node, bool, Compare> v;
    for(int i = 0; i < n; i++) {
        node s;
        cin >> s.x >> s.y;
        v[s] = false;
    }
    for(pair<node, bool> p : v) {
        int cnt = 0;
        if(v.find(node(p.first.x - 1, p.first.y)) != v.end()
        && v.find(node(p.first.x + 1, p.first.y)) != v.end()
        && v.find(node(p.first.x, p.first.y + 1)) != v.end()
        && v.find(node(p.first.x, p.first.y - 1)) != v.end()) 
        {
            if(v.find(node(p.first.x - 1, p.first.y - 1)) != v.end()) cnt++;
            if(v.find(node(p.first.x - 1, p.first.y + 1)) != v.end()) cnt++;
            if(v.find(node(p.first.x + 1, p.first.y - 1)) != v.end()) cnt++;
            if(v.find(node(p.first.x + 1, p.first.y + 1)) != v.end()) cnt++;
            score[cnt]++;
        }
    }
    for(int i = 0; i < 5; i++) {
        cout << score[i] << endl;
    }
	return 0;	
}