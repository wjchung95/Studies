#include <iostream>

using namespace std;

int main() {
    int num[9];

    for (int i = 0; i < 9; i++) {
        cin >> num[i];
    }
    
    int cnt = 0;
    int value = 0;

    for (int i = 0; i < 9; i++) {
        if (value < num[i]) {
            value = num[i];
            cnt = i;
        }
    }

    cout << value << endl << cnt + 1 << endl;

    return 0;
}