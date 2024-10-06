#include <iostream>

using namespace std;

int main() {
  int N, K;

  cin >> N >> K;
  int coin[N];

  for (int i = 0; i < N; i++) {
    cin >> coin[i];
  }

  int min_coin_cnt = 0;

  for (int i = N - 1; i >= 0; i--) {
    if (K == 0) break;
    min_coin_cnt += K / coin[i];
    K = K % coin[i];
  }

  cout << min_coin_cnt << endl;
}