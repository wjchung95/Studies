#include <iostream>

using namespace std;

int main() {
  int n1, n2;

  cin >> n1 >> n2;

  int bigger, smaller;

  if (n1 > n2) {
    bigger = n1;
    smaller = n2;
  } else {
    bigger = n2;
    smaller = n1;
  }

  int gcd = 1;

  for (int i = 1; i <= bigger; i++) {
    if (bigger % i == 0 && smaller % i == 0) {
      gcd = i;
    }
  }

  int lcm = smaller;

  while (lcm % bigger != 0) {
    lcm += smaller;
  }

  cout << gcd << endl;
  cout << lcm << endl;

  return 0;
}