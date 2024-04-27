#include <iostream>

using namespace std;

int main() {
  int n, sum, cnt;

  cin >> n;
  sum = 0;
  cnt = 0;

  while (sum < n) {
    sum += 6 * cnt;
    cnt++;
  }
  cout << cnt;
  
  return 0;
}