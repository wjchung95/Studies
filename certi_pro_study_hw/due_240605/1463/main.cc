#include <iostream>

using namespace std;

int min_cnt = 1000005;

void func(int num, int cnt) {
  if (num == 1) {
    if (cnt < min_cnt) {
      min_cnt = cnt;
    }
    return;
  }
  
  func (num - 1, cnt + 1);

  if (num % 3 == 0) {
    func (num / 3, cnt + 1);
  }

  if (num % 2 == 0) {
    func (num / 2, cnt + 1);
  }
}

int main() {
  int N;
  cin >> N;

  func (N, 0);
  cout << min_cnt << endl;

  return 0;
}