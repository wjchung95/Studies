#include <iostream>

using namespace std;

int main() {
    int star_cnt;
    cin >> star_cnt;

    for (int i = 0; i < star_cnt; i++) {
        for (int j = 0; j < i + 1; j++) {
            cout << '*';
        }
        cout << endl;
    }
    return 0;
}