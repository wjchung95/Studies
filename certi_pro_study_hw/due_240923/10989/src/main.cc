#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;

  cin >> N;

  int nums[10001] = {0};

  for (int i = 0; i < N; i++) {
    int temp;
    cin >> temp;
    nums[temp] += 1;
  }

  for (int i = 1; i <= 10000; i++) {
    for (int j = 0; j < nums[i]; j++) {
      cout << i << "\n";
    }
  }

  return 0;
}