#include <iostream>

using namespace std;

int main() {
  int T, N;
  int fib[41] = {0, 1, 1};

  for (int i = 3; i < 41; i++) {
    fib[i] = fib[i - 2] + fib[i - 1];
  }

  cin >> T;
  for (int i = 0; i < T; i++) {
    cin >> N;

    if (N == 0) {
      cout << 1 << " " << 0 << endl;
    } else {
      cout << fib[N - 1] << " " << fib[N] << endl;
    }
  }

  return 0;
}