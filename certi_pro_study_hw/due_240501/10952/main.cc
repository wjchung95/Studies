#include <iostream>

using namespace std;

using ll = long long;

ll a, b;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  while (cin >> a >> b) {
    if (a == 0 && b == 0) {
      break;
    }
    cout << a + b << '\n';
  }

  return 0;
}