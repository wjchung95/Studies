#include <iostream>
#include <string>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    int cnt[10];

    for (int i = 0; i < 10; i++) {
        cnt[i] = 0;
    }

    int result = A * B * C;
    string result_in_str = to_string(result);

    for (int i = 0; i < result_in_str.length(); i++) {
        cnt[result_in_str[i] - '0']++;
    }

    for (int i = 0; i < 10; i++) {
        cout << cnt[i] << endl;
    }

    return 0;
}