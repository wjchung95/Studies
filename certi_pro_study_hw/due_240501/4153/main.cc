#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int a, b, c;

  while (cin >> a >> b >> c) {
    if (a == 0 && b == 0 && c == 0) {
      break;
    }
    if (a > b) {
      if (a > c) {
        if (a * a == b * b + c * c) {
          cout << "right" << endl;
        } else {
          cout << "wrong" << endl;
        }
      } else {
        if (c * c == a * a + b * b) {
          cout << "right" << endl;
        } else {
          cout << "wrong" << endl;
        }
      }
    } else {
      if (b > c) {
        if (b * b == a * a + c * c) {
          cout << "right" << endl;
        } else {
          cout << "wrong" << endl;
        }
      } else {
        if (c * c == a * a + b * b) {
          cout << "right" << endl;
        } else {
          cout << "wrong" << endl;
        }
      }
    }
  }

  return 0;
}