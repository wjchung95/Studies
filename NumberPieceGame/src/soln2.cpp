#include <memory.h>
#include <unordered_map>
#include <queue>
#include <set>
using namespace std;
#define rint register int
#define MAX_ROW 40
#define MAX_COL 30
using pii = pair<int, int>;
   
struct Result {
    int row;
    int col;
};
   
// 
struct puzzle
{
    int cnt;
    int dr[6], dc[6];
};
// 조각 5 개 puzzle 의 정보를  좌표로 표현 
puzzle P[5] = { {2,{0,0},{0,1}},
              {3,{0,0,0 },{0,1,2}},
              {3,{0,1,2 },{0,0,0}},
              {4,{0,0,1,1},{0,1,1,2}},
              {5,{0,1,1,1,2},{0,0,1,2,2}}
};
int map[MAX_ROW][MAX_COL];
int R, C;
unordered_map< int, vector<pii>> Hash[5];// block type 별 해시 : r,c (행,열 순)
struct Info
{
    int r, c, t, key;
};
int visit[MAX_ROW][MAX_COL];
int vc;
bool safe(int r, int c)
{
    if (r < 0 || c < 0 || r >= R || c >= C) return false;
    return true;
}
int get_key(int r, int c, int t)
{
    int key = 0;
    int base = map[r + P[t].dr[0]][c + P[t].dc[0]];
    for (rint i = 1; i < P[t].cnt; ++i)
    {
        key *= 10;
        int nr = r + P[t].dr[i], nc = c + P[t].dc[i];
        if (!safe(nr, nc))return -1;
        key += (map[nr][nc] - base) + 5; // 항상 1 이상 되게 만든다. 
    }
    return key;
}
void init(int mRows, int mCols, int mCells[MAX_ROW][MAX_COL])
{
    R = mRows, C = mCols;
    vc++;
   
    memcpy(map, mCells, sizeof(map));
    for (rint i = 0; i < 5; i++)Hash[i].clear();
    //make hash
    for (rint r = 0; r < MAX_ROW; ++r)
    {
        for (rint c = 0; c < MAX_COL; ++c)
        {
            for (int i = 0; i < 5; ++i)
            {
                int key = get_key(r, c, i);
                if (key < 0) continue;
                Hash[i][key].push_back({ r,c });
            }
        }
    }
}
int get_type(int(*pz)[3])
{
    rint i, j;
    for (i = 4; i >= 0; --i) {
   
        for (j = 0; j < P[i].cnt; ++j)
        {
            if (pz[P[i].dr[j]][P[i].dc[j]] == 0) break;
        }
        if (j == P[i].cnt) return i;
    }
    return -1;
}
int get_match_key(int t, int(*pz)[3])
{
    int key = 0;
    int base = pz[P[t].dr[0]][P[t].dc[0]];
    for (rint i = 1; i < P[t].cnt; ++i)
    {
        key *= 10;
        int nr = P[t].dr[i], nc = P[t].dc[i];
        key += (pz[nr][nc] - base) + 5; // 항상 1 이상 되게 만든다. 
    }
    return key;
   
}
bool is_possible_set(int r, int c, int t)
{
    for (rint i = 0; i < P[t].cnt; ++i)
    {
        if (visit[r + P[t].dr[i]][c + P[t].dc[i]] == vc) return false;
    }
    return true;
}
void set_visit(int r, int c, int t)
{
    for (rint i = 0; i < P[t].cnt; ++i)
    {
        visit[r + P[t].dr[i]][c + P[t].dc[i]] = vc;
    }
}
//100,000
Result putPuzzle(int mPuzzle[3][3])
{
    Result ret = { -1, -1 };
    //type 을 알아 내다. 
    int t = get_type(mPuzzle);
    int key = get_match_key(t, mPuzzle);
    auto &vt = Hash[t][key];
    for (auto it : vt)
    {
        if (is_possible_set(it.first, it.second, t))
        {
            set_visit(it.first, it.second ,t);
            ret = { it.first,it.second };
            break;
        }
    }
    return ret;
}
//1,000
void clearPuzzles()
{
    vc++;
}