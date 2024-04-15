#include <unordered_map>
#include <queue>
#include <cstring>
#include <cmath>

using namespace std;

struct location {
  int x, y;
//   location(int X , int Y) : x(X), y(Y) {}
};

struct ordered_data {
    int category;
    int dist, dist_x, dist_y;
    bool operator<(const ordered_data Data) const{
        if (Data.dist < this->dist) {
            return true;
        } else if (Data.dist == this->dist) {
            if (Data.dist_x < this->dist_x) {
                return true;
            } else if (Data.dist_x == dist_x) {
                if (Data.dist_y < this->dist_y)  {
                    return true;
                }
            }
        }
        return false;
    }
};

int K;
int L;
int data[4000][4000];
int near[1010][1010];

unordered_map<int, location> data_loc;

void init(int K, int L)
{
    ::K = K;
    ::L = L;
    memset(::data, 0, sizeof(::data));
    data_loc.clear();
	return;
}

void addSample(int mID, int mX, int mY, int mC)
{
    location data_location;
    data_location.x = mX;
    data_location.y = mY;
    data_loc[mID] = data_location;//location(mX, mY);
    ::data[mX][mY] = mC;
	return;
}

void deleteSample(int mID)
{
    auto loc = data_loc.at(mID);
    ::data[loc.x][loc.y] = 0;
    data_loc.erase(mID);
	return;
}

int predict(int mX, int mY)
{
    priority_queue<ordered_data> ordered_data_pqueue;
    for (auto data: data_loc) {
        auto id = data.first;
        auto loc = data.second;
        auto cat = ::data[loc.x][loc.y];
        auto dist_x = abs(loc.x - mX);
        auto dist_y = abs(loc.y - mY);
        auto dist = dist_x + dist_y;

        if (dist < ::L) {
            ordered_data data2 = {cat, dist, dist_x, dist_y};
            ordered_data_pqueue.push(data2);
        }
    }

    int category_cnt[10] = {0, };
    for (int i = 0; i < ::K; i++) {
        if (ordered_data_pqueue.empty()) {
            return -1;
        }
        auto next_closest_data = ordered_data_pqueue.top();
        ordered_data_pqueue.pop();
        category_cnt[next_closest_data.category - 1]++;
    }
    
    int most_category;
    int max_cnt = 0;
    for (int i = 0; i < 10; i++) {
        auto cnt = category_cnt[i];
        if (cnt > max_cnt) {
            most_category = i + 1;
            max_cnt = cnt;
        }
    }
    return most_category;
}

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define CMD_INIT			(100)
#define CMD_ADD_SAMPLE		(200)
#define CMD_DELETE_SAMPLE	(300)
#define CMD_PREDICT			(400)

extern void init(int K, int L);
extern void addSample(int mID, int mX, int mY, int mC);
extern void deleteSample(int mID);
extern int predict(int mX, int mY);

static bool run()
{
	int Q;
	int K, L;
	int mID, mX, mY, mC;
	
	int ret = -1, ans;

	scanf("%d", &Q);

	bool okay = false;

	for (int q = 0; q < Q; ++q)
	{
		int cmd;
		scanf("%d", &cmd);
		switch(cmd)
		{
		case CMD_INIT:
			scanf("%d %d", &K, &L);
			init(K, L);
			okay = true;
			break;
		case CMD_ADD_SAMPLE:
			scanf("%d %d %d %d", &mID, &mX, &mY, &mC);
			addSample(mID, mX, mY, mC);
			break;
		case CMD_DELETE_SAMPLE:
			scanf("%d", &mID);
			deleteSample(mID);
			break;
		case CMD_PREDICT:
			scanf("%d %d", &mX, &mY);
			ret = predict(mX, mY);
			scanf("%d", &ans);
			if (ret != ans)
				okay = false;
			break;
		default:
			okay = false;
			break;
		}
	}

	return okay;
}

int main()
{
	setbuf(stdout, NULL);
	freopen("sample_input.txt", "r", stdin);

	int TC, MARK;

	scanf("%d %d", &TC, &MARK);
	for (int tc = 1; tc <= TC; ++tc)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}