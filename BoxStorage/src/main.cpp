
#include <queue>

using namespace std;

struct Storage {
    int loc;
    int box_cnt;
    bool operator<(Storage s) {
        if (box_cnt < s.box_cnt) true;
        else if (box_cnt == s.box_cnt)
            return loc > s.loc;
    }
};

priority_queue<Storage> storage_queue_;

void calculate_cover_size();

void init(int N)
{
	return;
}

int stock(int mLoc, int mBox)
{
	return -1;
}

int ship(int mLoc, int mBox)
{
	return -1;
}

int getHeight(int mLoc)
{
	return -1;
}

void calculate_cover_size() {
    while (!storage_queue_.empty()) {
        auto most = storage_queue_.top();
        storage_queue_.pop();
        auto next_most = storage_queue_.top();
        q.pop();
    }
}