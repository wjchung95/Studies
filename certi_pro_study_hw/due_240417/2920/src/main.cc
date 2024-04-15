#include <iostream>

using namespace std;

int main() {
    int note[8];
    
    for (int i = 0; i < 8; i++) {
        cin >> note[i];
    }

    int prev_note = -1;
    int process = 0; // 1 ascending, -1 descending, 0 mixed
    for (int i = 0; i < 8; i++) {
        if (i == 0) {
            prev_note = note[i];
        } else {
            if (note[i] > prev_note) {
                if (process == -1) {
                    process = 0;
                    break;
                }
                process = 1;
                prev_note = note[i];
            } else {
                if (process == 1) {
                    process = 0;
                    break;
                }
                process = -1;
                prev_note = note[i];
            }
        }
    }
    if (process == 1) {
        cout << "ascending" << endl;
    } else if (process == -1) {
        cout << "descending" << endl;
    } else if (process == 0) {
        cout << "mixed" << endl;
    }
    return 0;
}