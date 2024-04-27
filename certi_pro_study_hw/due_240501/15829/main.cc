#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int l;
  string s;
  int r = 31;
  int m = 1234567891;

  cin >> l >> s;

  int sum = 0;
  for (int i = 0; i < s.length(); i++) {
    int a_i = static_cast<int>(s.at(i) - 'a') + 1;
    r = 31;
    
    r = pow(r, i);
    sum += a_i * r;
  }

  cout << sum % m << endl;

  return 0;
}