#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    int cnt = 0;
    getline(cin,str);

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ' && i != 0 && i != str.length() - 1) cnt++;
    }
    cout << cnt + 1 << endl;

    return 0;
}