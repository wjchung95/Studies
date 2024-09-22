#include <iostream>

using namespace std;

int main() {
  int N, T, P;

  cin >> N;
  int size[6];

  for (int i = 0; i < 6; i++) {
    cin >> size[i];
  }
  cin >> T >> P;

  int T_cnt = 0;
  int P_cnt = 0;
  int P_add = 0;

  for (int i = 0; i < 6; i++) {
    if (size[i] == 0) {
      continue;
    } else if (size[i] < T) {
      T_cnt++;
    } else if (size[i] % T == 0) {
      T_cnt += size[i] / T;
    } else {
      T_cnt += size[i] / T + 1;
    }
  }

  if (N < P) {
    P_cnt = 0;
    P_add = N;
  } else if (N % P == 0) {
    P_cnt = N / P;
    P_add = 0;
  } else {
    P_cnt = N / P;
    P_add = N % P;
  }

  cout << T_cnt << endl;
  cout << P_cnt << " " << P_add << endl;

  return 0;
}