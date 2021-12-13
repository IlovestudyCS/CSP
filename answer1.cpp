#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<cmath>
#include<string>
#include<set>

using namespace std;

typedef priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double,int>>> PQ;

void readfiles();
double getdistance(double fromlon, double fromlat, double tolon, double tolat);
void getPara(string buffer[], string line, int size, bool flag);
void init();
void Dijkstra(int s);
void DFS(int s, int v);
void test();

const int N = 20010, M = 70010;
const double PI = 3.1415926;
const double INF = 1e20;

class vertex{
public:
    int id;
    string name;
    double lon;
    double lat;
} airports[N];

class edge{
public:
    int v;
    double w;
};

vector<edge> routes[N];
set<int> quchong[N];
int visit[N];
double dis[N];
int pre[N];

template<typename T>
void writeAns(string file, T obj[])
{
    ofstream answer(file);
    for(int i = 0; i < N; i++) {
        answer << obj[i] << endl;
    }
    answer.close();
}

int main()
{
    init();
    Dijkstra(1);
    cout << "-------" << endl;
    cout << dis[8] << endl;
    cout << "-------" << endl;
    DFS(1, 8);
    test();
    // writeAns(string("pq_dis.txt"), dis);
    // writeAns(string("pq_pre.txt"), pre);
    return 0;
}

void test()
{
    cout << getdistance(airports[5].lon, airports[5].lat, 
                airports[3316].lon, airports[3316].lat) << endl;
    cout << getdistance(airports[5].lon, airports[5].lat, 
                airports[3077].lon, airports[3077].lat) << endl;
}

double getdistance(double fromlon, double fromlat, double tolon, double tolat) //计算两点间的距离
{
  fromlon = (PI/180)*fromlon;
  fromlat = (PI/180)*fromlat;
  tolon = (PI/180)*tolon;
  tolat = (PI/180)*tolat;

  double earthR = 6378;

  double distance = acos(sin(fromlat)*sin(tolat)+cos(fromlat)*cos(tolat)*cos(tolon-fromlon))*earthR;
  return round(distance);
}

void init()
{
    fill(visit, visit + N, -1);
    readfiles();
}

void readfiles()
{
    ifstream file ("./airports.dat");
    string line;
    vertex v;
    string buffer[8];
    while(getline(file, line)) {
        // int id = atoi(line.substr(0, line.find(',')).c_str());
        getPara(buffer, line, 8, true);
        int id = stoi(buffer[0]);
        string name = buffer[1].substr(1, buffer[1].size() - 2);
        double lat = stod(buffer[6]);
        double lon = stod(buffer[7]);
        airports[id].id = id;
        airports[id].name = name;
        airports[id].lon = lon;
        airports[id].lat = lat;
        visit[id] = 0;           
    }

    ifstream file1 ("./routes.dat");
    edge e;
    string buffer1[8];
    int cnt = 0;
    while(getline(file1, line)) {
        cnt++;
        // int id = atoi(line.substr(0, line.find(',')).c_str());
        getPara(buffer1, line, 8, false);
        cout << cnt << endl;
        if(buffer1[1] == "\\N" || buffer1[3] == "\\N" || buffer1[5] == "\\N") continue;
        int from = stoi(buffer1[3]);
        int to = stoi(buffer1[5]);
        if(quchong[from].find(to) == quchong[from].end()) {
            e.v = to;
            e.w = getdistance(airports[from].lon, airports[from].lat,
                            airports[to].lon, airports[to].lat);
            routes[from].push_back(e);
            quchong[from].insert(to);    
        }
           
    }
    
}

void getPara(string buffer[], string line, int size, bool flag)
{
    int cnt = 0;
    int end = 0;
    int begin = 0;
    int i = 0;
    
    while (cnt < size)
    {
        end = line.find(',', begin);
        if(flag && line[end - 1] != '\"' && (line[end - 1] < '0' || line[end - 1] > '9')) {
            end = line.find(',', end + 1);
        }
        buffer[i++] = line.substr(begin, end - begin);
        //cout << buffer[i - 1] << endl;
        begin = end + 1;
        cnt++;
    }
}

void Dijkstra(int s)
{
    fill(dis, dis + N, INF);
    for(int i = 0; i < N; i++) {
        pre[i] = i;
    }
    dis[s] = 0;
    PQ minQueue;
    minQueue.push(make_pair(0, s));
    while (!minQueue.empty()) {
        pair<double, int> node;
        node = minQueue.top();
        int u = node.second;
        minQueue.pop(); 
      //  if(visit[u] == 1) continue;
        visit[u] = 1;
        for(int i = 0; i < routes[u].size(); i++) {
            int v = routes[u][i].v;
            int d = routes[u][i].w;
            if(/*visit[v] == 0 &&*/ dis[u] + d < dis[v]) {
                dis[v] = dis[u] + d;
                pre[v] = u;
                if(visit[v] == 0)
                    minQueue.push(make_pair(dis[v], v));
            }
        }
    }
}

void DFS(int s, int v)
{
    if(v == s) {
        cout << s << endl;
        return;
    }
    DFS(s, pre[v]);
    cout << v << endl;
}