#include <iostream>

using namespace std;

int main() {
  int n;
  string s;
  int sum = 0;

  cin >> n >> s;

  for (int i = 0; i < s.length(); i++) {
    sum += static_cast<int>(s.at(i) - '0');
  }
  cout << sum << endl;

  return 0;
}