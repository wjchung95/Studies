#include <iostream>
#include <string>

using namespace std;

int main() {
    int test_cnt;
    cin >> test_cnt;

    int cnt[test_cnt];
    string str[test_cnt];

    for (int i = 0; i < test_cnt; i++) {
        cin >> cnt[i] >> str[i];
    }

    for (int i = 0; i < test_cnt; i++) {
        cout << "testcase " << i << ": " << cnt[i] << ", " << str[i] << endl;
    }

    for (int i = 0; i < test_cnt; i++) {
        for (int j = 0; j < str[i].length(); j++) {
            for (int k = 0; k < cnt[i]; k++) {
                cout << str[i][j];
            }
        }
        cout << endl;
    }


    return 0;
}