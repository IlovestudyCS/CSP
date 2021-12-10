#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<cmath>
#include<string>

using namespace std;

void readfiles();
double getdistance(double fromlon, double fromlan, double tolon, double tolan);

const int N = 20010, M = 70010;
const double PI = 3.1415926;

class vertex{
public:
    int id;
    string name;
    double lon;
    double lan;
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

double getdistance(double fromlon, double fromlan, double tolon, double tolan) //计算两点间的距离
{
  fromlon = (PI/180)*fromlon;
  double fromlan = (PI/180)*fromlan;
  double tolon = (PI/180)*tolon;
  double tolan = (PI/180)*tolan;

  double earthR = 6378;

  double distance = acos(sin(fromlan)*sin(tolan)+cos(fromlan)*cos(tolan)*cos(tolon-fromlon))*earthR;
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
        int cnt = 0;
        int end = 0;
        int begin = 0;
        int i = 0;
        // cout << line[2] << endl;
        // cout << line[3] << endl;
        while (cnt < 8)
        {
            end = line.find(',', begin);
            if(line[end - 1] != '\"' && (line[end - 1] < '0' || line[end - 1] > '9')) {
                end = line.find(',', end + 1);
            }
            buffer[i++] = line.substr(begin, end - begin);
            //cout << buffer[i - 1] << endl;
            begin = end + 1;
            cnt++;
        }
        int id = stoi(buffer[0]);
        string name = buffer[1].substr(1, buffer[1].size() - 2);
        double lon = stof(buffer[6]);
        double lan = stof(buffer[7]);
        airports[id].id = id;
        airports[id].name = name;
        airports[id].lon = lon;
        airports[id].lan = lan;
        visit[id] = 0;           
    }
    
    
}