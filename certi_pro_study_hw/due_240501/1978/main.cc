#include <iostream>

using namespace std;

bool IsPrime(int n) {
  if (n == 1) return false;
  for (int i = 2; i < n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int N;
  int n;
  int cnt = 0;

  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> n;

    if (IsPrime(n)) {
      cnt++;
    }
  }
  cout << cnt << endl;

  return 0;
}