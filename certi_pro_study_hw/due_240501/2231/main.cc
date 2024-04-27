#include <iostream>

using namespace std;

int main() {
  int n;
  
  cin >> n;

  for (int i = 1; i < n; i++) {
    int tmp = i;
    int sum = i;

    while (tmp != 0) {
      sum += tmp % 10;
      tmp /= 10;
    }
    
    if (sum == n) {
      cout << i << endl;
      return 0;
    }
  }

  cout << 0 << endl;
  return 0;
}