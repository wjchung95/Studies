#include <iostream>

using namespace std;

int main() {
  int N, X;
  cin >> N >> X;

  int n[N], val;
  int cnt = 0;

  for (int i = 0; i < N; i++) {
    cin >> val;
    if (val < X) {
      n[cnt] = val;
      cnt ++;
    }
  }

  for (int i = 0; i < cnt; i++) {
    if (i == cnt - 1) {
      cout << n[i] << endl;
      break;
    }
    cout << n[i] << ' ';
  }

  return 0;
}