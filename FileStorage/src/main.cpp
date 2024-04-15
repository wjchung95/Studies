#include <unordered_map>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

unordered_map<int, int> hash_;
priority_queue<pii, vector<pii>, greater<pii>> free_queue_;
pii file_[12000][30];
int chunk_cnt_[12000];
int free_size_, file_idx_;

void init(int N) {
    hash_.clear();
    free_queue_ = {};
    free_size_ = N;
    file_idx_ = 0;
    free_queue_.emplace(1, N);

	return;
}

int add(int mId, int mSize) {
    if (mSize > free_size_) return -1;
    else free_size_ -= mSize;

    hash_[mId] = file_idx_;
    auto& file = file_[file_idx_];
    auto& chunk_cnt = chunk_cnt_[file_idx_++] = 0;

    while (!free_queue_.empty()) {
        auto current = free_queue_.top();
        free_queue_.pop();

        while (!free_queue_.empty() && free_queue_.top().first == current.first + current.second) {
            auto next  = free_queue_.top();
            free_queue_.pop();
            current.second += next.second;
        }

        if (current.second < mSize) {
            mSize -= current.second;
            file[chunk_cnt++] = current;
            continue;
        } else if (current.second > mSize) {
            free_queue_.emplace(current.first + mSize, current.second - mSize);
            current.second = mSize;
        }
        file[chunk_cnt++] = current;
        break;
    }
	return file[0].first;
}

int remove(int mId) {
    auto file_idx = hash_[mId];
    auto chunk_cnt = chunk_cnt_[file_idx];
    auto& file = file_[file_idx];

    for (int i = 0; i < chunk_cnt; i++) {
        auto chunk = file[i];
        free_queue_.push(chunk);
        free_size_ += chunk.second;
    }
    chunk_cnt_[file_idx] = 0;
	return chunk_cnt;
}

int count(int mStart, int mEnd) {
    int cnt = 0;
    for (int i = 0; i < file_idx_; i++) {
        auto chunk_cnt = chunk_cnt_[i];
        auto& file = file_[i];
        for (int j = 0; j < chunk_cnt; j++) {
            if (file[j].first <= mEnd && file[j].first + file[j].second > mStart) {
                cnt++;
                break;
            }
        }
    }
	return cnt;
}