#include <iostream>

using namespace std;

int main() {
    int num[10];
    int remainder[42];

    for (int i = 0; i < 42; i++) {
        remainder[i] = 0;
    }

    for (int i = 0; i < 10; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < 10; i++) {
        remainder[num[i] % 42]++;
    }

    int total_cnt = 42;
    for (int i = 0; i < 42; i++) {
        if (remainder[i] == 0) {
            total_cnt--;
        }
    }

    cout << total_cnt << endl;

    return 0;
}