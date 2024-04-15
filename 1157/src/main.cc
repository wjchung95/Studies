#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    int cnt[26];
    for (int i = 0; i < 26; i++) {
        cnt[i] = 0;
    }

    getline(cin, str);
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'z') {
            if (str[i] <= 'Z') {
                cnt[str[i] - 'A']++;
            } else if (str[i] >= 'a') {
                cnt[str[i] - 'a']++;
            }
        }
    }

    int max_char = 0;
    int max_cnt = 0;
    bool more_than_two = false;
    for (int i = 0; i < 26; i++) {
        if (max_cnt < cnt[i]) {
            max_char = i;
            max_cnt = cnt[i];
            more_than_two = false;
        } else if (max_cnt == cnt[i]) {
            more_than_two = true;
        }
    }

    if (more_than_two) {
        cout << '?' << endl;
    } else {
        cout << static_cast<char>(max_char + 'A') << endl;
    }

    return 0;
}