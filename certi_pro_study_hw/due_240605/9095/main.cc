#include <iostream>

using namespace std;

int cnt;

void func(int remain) {
  if (remain == 0) {
    cnt++;
    return;
  }

  if (remain < 0) return;

  func(remain - 1);
  func(remain - 2);
  func(remain - 3);
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    int n;
    cin >> n;
    cnt = 0;
    func(n);
    cout << cnt << endl;
  }

  return 0;
}