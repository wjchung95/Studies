#include <iostream>

using namespace std;

int main() {
  int tc, a, b;
  
  cin >> tc;

  for (int i = 0; i < tc; i++) {
    cin >> a >> b;
    cout << a + b << endl;
  }

  return 0;
}