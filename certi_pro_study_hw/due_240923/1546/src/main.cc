#include <iostream>

using namespace std;

int main() {
  int n;

  cin >> n;

  float scores[n];
  float max_score = 0;
  int max_idx;

  for (int i = 0; i < n; i++) {
    cin >> scores[i];
    if (scores[i] > max_score) {
      max_score = scores[i];
      max_idx = i;
    }
  }

  float new_scores[n];
  float new_score_sum = 0;

  for (int i = 0; i < n; i++) {
    new_scores[i] = scores[i] / max_score * 100;
    new_score_sum += new_scores[i];
  }

  cout << new_score_sum / n << endl;

  return 0;
}