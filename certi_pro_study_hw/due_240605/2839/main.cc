// #include <iostream>

// using namespace std;

// int min_bag_cnt = 1000;

// void func(int remaining_weight, int bag_cnt) {
//   if (remaining_weight == 0) {
//     if (bag_cnt < min_bag_cnt) {
//       min_bag_cnt = bag_cnt;
//     }
//     return;
//   }
//   if (remaining_weight == 1 || remaining_weight == 2 || remaining_weight == 4) return;
//   if (bag_cnt > min_bag_cnt) return;

//   func(remaining_weight - 5, bag_cnt + 1);
//   func(remaining_weight - 3, bag_cnt + 1);
// }

// int main() {
//   int N;

//   cin >> N;

//   func(N, 0);

//   if (min_bag_cnt == 2000) {
//     cout << -1 << endl;
//   } else {
//     cout << min_bag_cnt << endl;
//   }

//   return 0;
// }

#include <iostream>

using namespace std;
int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for(int i=0; i<=n/3; i++) {
        for(int j=0; j<=n/5; j++) {
            if(3 * i + 5 * j == n) {
                cout << i + j << '\n';
                return 0;
            }
        }
    }
    cout << -1 << '\n';
}