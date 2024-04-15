#include <queue>

using namespace std;


#define MAX_N 30
#define POSE pair<int, int>

int map_size_;
int map_[MAX_N][MAX_N];
int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

struct Queue {
    POSE rock_pose;
    POSE person_pose;
    int move_cnt;
};


bool is_possible(POSE next_rock_pose, POSE current_rock_pose, POSE required_person_pose, POSE current_person_pose) {
    bool person_visited[map_size_][map_size_];
    for (int i = 0; i < map_size_; i++) {
        for (int j = 0; j < map_size_; j++) {
            person_visited[i][j] = false;
        }
    }

    if (map_[next_rock_pose.first][next_rock_pose.second] != 1 &&
        map_[required_person_pose.first][required_person_pose.second] != 1) {
        
        queue<POSE> person_move_queue;
        person_move_queue.push(current_person_pose);

        while (!person_move_queue.empty()) {
            auto person_pose = person_move_queue.front();
            person_move_queue.pop();

            if (person_pose == required_person_pose) {
                return true;
            }

            for (int i = 0; i < 4; i++) {
                POSE next_person_pose = {person_pose.first + dir[i][0], person_pose.second + dir[i][1]};

                if (map_[next_person_pose.first][next_person_pose.second] != 1 &&
                    next_person_pose != current_rock_pose &&
                    !person_visited[next_person_pose.first][next_person_pose.second]) {
                    
                    person_move_queue.push(next_person_pose);
                    person_visited[next_person_pose.first][next_person_pose.second] = true;
                }

            }
        }
    }
    return false;
}

void init(int N, int mMap[MAX_N][MAX_N])
{
    map_size_ = N;

    for (int i = 0; i < map_size_; i++) {
        for (int j = 0; j < map_size_; j++) {
            map_[i][j] = mMap[i][j];
        }
    }
	return;
}

int push(int mRockR, int mRockC, int mDir, int mGoalR, int mGoalC)
{
    POSE rock_pose = {mRockR, mRockC};
    POSE person_pose = {mRockR + dir[mDir][0], mRockC + dir[mDir][1]};
    bool checked_case[map_size_][map_size_][4];

    for (int i = 0; i < map_size_; i++) {
        for (int j = 0; j < map_size_; j++) {
            for (int k = 0; k < 4; k++) {
                checked_case[i][j][k] = false;
            }
        }
    }

    queue<Queue> rock_move_queue;

    Queue rock_move;
    rock_move.rock_pose = rock_pose;
    rock_move.person_pose = person_pose;
    rock_move.move_cnt = 0;
    rock_move_queue.emplace(rock_move);
    checked_case[rock_pose.first][rock_pose.second][mDir] = true;

    while (!rock_move_queue.empty()) {
        auto rock_pose = rock_move_queue.front().rock_pose;
        auto person_pose = rock_move_queue.front().person_pose;
        auto move_cnt = rock_move_queue.front().move_cnt;
        rock_move_queue.pop();

        if (rock_pose.first == mGoalR && rock_pose.second == mGoalC) {
            return move_cnt;
        }

        for (int i = 0; i < 4; i++) {
            POSE next_rock_pose  = {rock_pose.first + dir[i][0], rock_pose.second + dir[i][1]};
            POSE required_person_pose = {rock_pose.first - dir[i][0], rock_pose.second - dir[i][1]};

            if (is_possible(next_rock_pose, rock_pose,  required_person_pose, person_pose) &&
                !checked_case[next_rock_pose.first][next_rock_pose.second][(i + 2) % 4 - 1]) {
                
                Queue rock_move;
                rock_move.rock_pose = next_rock_pose;
                rock_move.person_pose = rock_pose;
                rock_move.move_cnt = move_cnt + 1;
                rock_move_queue.emplace(rock_move);
                checked_case[next_rock_pose.first][next_rock_pose.second][(i + 2) % 4 - 1] = true;
            }
        }
    }

	return 0;
}


#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>

#define MAX_N 30

void init(int N, int mMap[MAX_N][MAX_N]);
int push(int mRockR, int mRockC, int mDir, int mGoalR, int mGoalC);

/////////////////////////////////////////////////////////////////////////

#define INIT		100
#define PUSH		200

static bool run()
{
	int cmd, ans, ret;
	int N, r, c, dir, r2, c2;
	int Q = 0;
	bool okay = false;
	int region[MAX_N][MAX_N];

	scanf("%d", &Q);

	for (int q = 0; q < Q; ++q)
	{
		scanf("%d", &cmd);

		switch (cmd)
		{
		case INIT:
			scanf("%d", &N);

			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					scanf("%d", &region[i][j]);

			init(N, region);
			okay = true;
			break;

		case PUSH:
			scanf("%d %d %d %d %d", &r, &c, &dir, &r2, &c2);
			ret = push(r, c, dir, r2, c2);
			scanf("%d", &ans);
			if (ret != ans)
				okay = false;
			break;

		default:
			okay = false;
		}
	}

	return okay;
}

int main()
{
	setbuf(stdout, NULL);
	freopen("sample_input.txt", "r", stdin);

	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}

	return 0;
}