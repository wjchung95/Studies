#include <iostream>

using namespace std;

long long mem[101];

int main() {
  int T, N;

  cin >> T;

  mem[0] = 1;
  mem[1] = 1;
  mem[2] = 1;

  for (int i = 0; i < T; i++) {
    cin >> N;

    for (int j = 3; j < N; j++) {
      mem[j] = mem[j - 3] + mem[j - 2];
    }
    cout << mem[N - 1] << endl;
  }

  return 0;
}