#include <iostream>

using namespace std;

int main() {
    int a, b, c, d, e;

    cin >> a >> b >> c >> d >> e;
    auto sum = a * a + b * b + c * c + d * d + e * e;
    auto remainder = sum % 10;

    cout << remainder << endl;
    
    return 0;
}