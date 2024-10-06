#include <algorithm>
#include <iostream>

using namespace std;

int main() {
  int N;
  int total_time = 0;

  cin >> N;
  int withdraw_time[N];

  for (int i = 0; i < N; i++) {
    cin >> withdraw_time[i];
  }

  sort(withdraw_time, withdraw_time + N);

  for (int i = 0; i < N; i++) total_time += withdraw_time[i] * (N - i);

  cout << total_time << endl;

  return 0;
}