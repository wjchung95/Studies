#include <iostream>

using namespace std;

long long mem[1001];

int main() {
  int N;

  cin >> N;

  mem[0] = 1;
  mem[1] = 2;

  for (int i = 2; i < N; i++) {
    mem[i] = (mem[i - 2] + mem[i -1]) % 10007;
  }
  cout << mem [N - 1] << endl;

  return 0;
}