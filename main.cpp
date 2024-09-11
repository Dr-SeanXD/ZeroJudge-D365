#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string>str;
vector<vector<int>>walk;
int H, W;

void DFS(int y, int x)
{
    if (walk[y][x] == 1) return;
    else
    {
        walk[y][x] = 1;
        if (y-1 >= 0 && walk[y-1][x] == 0 && str[y-1][x] == str[y][x])
        {
            DFS(y-1, x);
        }
        if (y+1 < H && walk[y+1][x] == 0 && str[y+1][x] == str[y][x])
        {
            DFS(y+1, x);
        }
        if (x-1 >= 0 && walk[y][x-1] == 0 && str[y][x-1] == str[y][x])
        {
            DFS(y, x-1);
        }
        if (x+1 < W && walk[y][x+1] == 0 && str[y][x+1] == str[y][x])
        {
            DFS(y, x+1);
        }
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i<N; i++)
    {
        cin >> H >> W;
        str.clear();
        walk.clear();
        map<char, int>MAP;
        for (int j = 0; j<H; j++)
        {
            string tmp;
            cin >> tmp;
            str.push_back(tmp);
            vector<int>it;
            for (int k = 0; k<W; k++)
            {
                it.push_back(0);
            }
            walk.push_back(it);
        }
        vector<char>ch;
        for (int j = 0; j<H; j++)
        {
            for (int k = 0; k<W; k++)
            {
                if (walk[j][k] == 0)
                {
                    char tmp = str[j][k];
                    DFS(j, k);
                    if (MAP[tmp] == 0) ch.push_back(tmp);
                    MAP[tmp]++;
                }
            }
        }
        cout << "World #" << i+1 << endl;
        vector<pair<int, char>>ans;
        for (int j = 0; j<ch.size(); j++)
        {
            pair<int, char>tmp;
            tmp.second = ch[j];
            tmp.first = MAP[ch[j]] * -1;
            ans.push_back(tmp);
        }
        sort(ans.begin(), ans.end());
        for (int j = 0; j<ans.size(); j++)
        {
            cout << ans[j].second << ": " << ans[j].first*-1 << endl;
        }
    }
}
