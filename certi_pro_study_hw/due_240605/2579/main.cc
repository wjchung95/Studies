#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int N;
int stair_scores[303];
int mem[303][3];

int func(int stair_level, int consec_cnt) {
  if (stair_level == N) {
    return stair_scores[N];
  }

  if (stair_level == N + 1) return -9999;

  int& ret = mem[stair_level][consec_cnt];
  if (ret != -1) return ret;

  if (consec_cnt == 2) {
    return ret = stair_scores[stair_level] + func(stair_level + 2, 1);
  } else {
    return ret = stair_scores[stair_level] +
                 max(func(stair_level + 1, consec_cnt + 1),
                     func(stair_level + 2, 1));
  }
}

int main() {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> stair_scores[i];
  }
  memset(mem, -1, sizeof(mem));

  cout << func(0, 0) << endl;

  return 0;
}