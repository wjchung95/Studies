#include <unordered_map>

using namespace std;

struct Path {
    int s_city, e_city, cost, time;
};

struct City {
    int city;
    vector<Path> paths;
};

int n, k;
unordered_map<int, City> city_map;


void init(int N, int K, int sCity[], int eCity[], int mCost[], int mTime[]) {
    n = N;
    k = K;

    for (int i = 0; i < k; i++) {
        Path path = {sCity[i], eCity[i], mCost[i], mTime[i]};
        city_map[sCity[i]] = {sCity[i], path};
    }
	return;
}

void add(int sCity, int eCity, int mCost, int mTime) {
	return;
}

int cost(int M, int sCity, int eCity) {
	return 0;
}