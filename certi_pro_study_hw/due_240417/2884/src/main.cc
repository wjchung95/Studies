#include <iostream>

using namespace std;

int main() {
    int H, M;
    cin >> H >> M;

    if (M >= 45) {
        cout << H << ' ' << M - 45 << endl;
    } else {
        if (H > 0) {
            cout << H - 1 << ' ' << 60 - (45 - M) << endl;
        } else {
            cout << 23 << ' ' << 60 - (45 - M) << endl;
        }
    }
    return 0;
}