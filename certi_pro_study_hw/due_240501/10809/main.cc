#include <iostream>

using namespace std;

int main() {
  string s;
  int alphabet[26];

  for (int i = 0; i < 26; i++) {
    alphabet[i] = -1;
  }
  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    if (alphabet[s.at(i) - 'a'] == -1) {
      alphabet[static_cast<int>(s.at(i) - 'a')] = i;
    }
  }

  for (int i = 0; i < 26; i++) {
    cout << alphabet[i];
    if (i < 25) {
      cout << ' ';
    }
  }

  cout << endl;

  return 0;
}