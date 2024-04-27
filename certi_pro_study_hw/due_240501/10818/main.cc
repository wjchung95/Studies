#include <iostream>

using namespace std;

int main() {
  int N;
  
  cin >> N;
  int n[N];

  for (int i = 0; i < N; i++) {
    cin >> n[i];
  }

  int min, max;
  for (int i = 0; i < N; i++) {
    if (i == 0) {
      min = n[i];
      max = n[i];
    } else {
      if (min > n[i]) min = n[i];
      if (max < n[i]) max = n[i];
    }
  }
  cout << min << ' ' << max << endl;

  return 0;
}