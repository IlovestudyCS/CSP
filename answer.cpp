#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<cmath>
#include<string>

using namespace std;

void readfiles();
double getdistance(double fromlon, double fromlat, double tolon, double tolat);
void getPara(string buffer[], string line, int size, bool flag);

const int N = 20010, M = 70010;
const double PI = 3.1415926;

class vertex{
public:
    int id;
    string name;
    double lon;
    double lat;
} airports[M + 1];

class edge{
public:
    int v;
    double w;
};

vector<edge> routes[N];
int visit[M + 1];

int main()
{
    readfiles();
    return 0;
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
    fill(visit, visit + M + 1, -1);
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
        if(buffer1[3] == "\\N" || buffer1[5] == "\\N") continue;
        int from = stoi(buffer1[3]);
        int to = stoi(buffer1[5]);
        e.v = to;
        e.w = getdistance(airports[from].lon, airports[from].lon,
                            airports[to].lon, airports[to].lat);
        routes[from].push_back(e);    
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