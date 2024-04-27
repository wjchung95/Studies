#include <iostream>

using namespace std;

int main() {
  int n, m;

  cin >> n >> m;
  int card[n];

  for (int i = 0; i < n; i++) {
    cin >> card[i];
  }

  int max_sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        int sum = card[i] + card[j] + card[k];
        if (max_sum < sum && sum <= m) {
          max_sum = sum;
        }
      }
    }
  }

  cout << max_sum;

  return 0;
}