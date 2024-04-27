#include <iostream>

using namespace std;

int main() {
  int tc, h, w, n;

  cin >> tc;

  for (int i = 0; i < tc; i++) {
    cin >> h >> w >> n;
    int h_n = 0;
    int w_n = 1;
    for (int j = 0; j < n; j++) {
      if (h_n == h) {
        h_n = 1;
        w_n++;
      } else {
        h_n++;
      }
    }
    if (w_n < 10) {
      cout << h_n << '0' << w_n << endl;
    } else {
      cout << h_n << w_n << endl;
    }
  }
}