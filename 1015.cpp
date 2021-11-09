#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
    德分 >= H && 才分 >= H "才德全尽" 按德才总分从高到低
    才分 < H && 德分 >= H "德胜才" 按总分排序，在 "才德全尽"之后排序
    才分 < H && 德分 < H && 德分 >= 才分 "才德兼亡" 按总分排序，在"德胜才"之后
    德分 >= L && 才分 >= L 总分，最后排序
*/

class stu
{
public:
    int moral_score;
    int talent_score;
    string id;
    int sclass;
};

int N, L, H;

int main()
{
    vector<stu> v;
    cin >> N >> L >> H;
    for (int i = 0; i < N; i++)
    {
        stu s;
        cin >> s.id;
        cin >> s.moral_score;
        cin >> s.talent_score;
        if (s.moral_score >= L && s.talent_score >= L)
        {
            if (s.moral_score >= H && s.talent_score >= H)
            {
                s.sclass = 1;
            }
            else if (s.talent_score < H && s.moral_score >= H)
            {
                s.sclass = 2;
            }
            else if (s.talent_score < H && s.moral_score < H && s.moral_score >= s.talent_score)
            {
                s.sclass = 3;
            }
            else
            {
                s.sclass = 4;
            }
            v.push_back(s);
        }
    }
    sort(v.begin(), v.end(), [](stu s1, stu s2) -> bool
         {
             if (s1.sclass != s2.sclass)
                 return s1.sclass < s2.sclass;
             else if (s1.moral_score + s1.talent_score != s2.moral_score + s2.talent_score)
             {
                 return s1.moral_score + s1.talent_score > s2.moral_score + s2.talent_score;
             }
             else if (s1.moral_score != s2.moral_score)
             {
                 return s1.moral_score > s2.moral_score;
             }
             else
             {
                 return s1.id < s2.id;
             }
         });
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++) {
        cout << v[i].id << " " << v[i].moral_score << " " << v[i].talent_score;
        if(i != v.size() - 1) {
            cout << endl;
        }
    }

}