#include<cmath>
#include<cstring>
#include<unordered_map>
 
#define M 4005
 
using namespace std;
 
int category[M][M], k, l;
int cnt[11];
unordered_map<int, pair<int, int>> pos;
 
void init(int K, int L)
{
    memset(category, 0, sizeof(category));
    pos.clear();
    k = K; l = L;
    return;
}
 
void addSample(int mID, int mX, int mY, int mC)
{
    pos[mID] = make_pair(mX, mY);
    category[mX][mY] = mC;
    return;
}
 
void deleteSample(int mID)
{
    category[pos[mID].first][pos[mID].second] = 0;
    return;
}
 
int predict(int mX, int mY)
{
    int find = 0, ans = -1;
    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= l; i++)
    {
        for (int j = mX - i; j <= mX + i; j++)
        {
            if (j < 1 || j > 4000) continue;
            if (mY - (i - abs(mX - j)) >= 1 && category[j][mY - (i - abs(mX - j))])
            {
                cnt[category[j][mY - (i - abs(mX - j))]]++;
                find++;
            }
            if (find == k) break;
            if (abs(mX - j) == i) continue;
            if (mY + (i - abs(mX - j)) <= 4000 && category[j][mY + (i - abs(mX - j))])
            {
                cnt[category[j][mY + (i - abs(mX - j))]]++;
                find++;
            }
            if (find == k) break;
        }
        if (find == k) break;
    }
    if (find == k)
    {
        int maxv = -1;
        for (int i = 1; i <= 10; i++)
            if (cnt[i] > maxv)
            {
                maxv = cnt[i];
                ans = i;
            }
    }
    return ans;
}