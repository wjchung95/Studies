#include <iostream>
#include <string>

using namespace std;

int main() {
    int test_cnt;
    cin >> test_cnt;

    string answer[test_cnt];
    int score[test_cnt];

    for (int i = 0; i < test_cnt; i++) {
        cin >> answer[i];
        score[i] = 0;
    }

    for (int i = 0; i < test_cnt; i++) {
        int cumulative = 0;

        for (int j = 0; j < answer[i].length(); j++) {
            if (answer[i][j] == 'O') {
                score[i] += ++cumulative;
            } else {
                cumulative = 0;
            }
        }
        cout << score[i] << endl;
    }

    return 0;
}