#include <vector>
#include <unordered_map>
using namespace std;

struct Cable {
	int con_dev;
	int latency;
};
unordered_map<int, vector<Cable>> dev_cable_map;

struct latency_to_dev {
	int pre_dev;
	int dest_dev;
	int latency_to_here;
};

void init(int mDevice)
{
	dev_cable_map.clear();
	return;
}

void connect(int mOldDevice, int mNewDevice, int mLatency)
{
	dev_cable_map[mOldDevice].push_back({ mNewDevice, mLatency });
	dev_cable_map[mNewDevice].push_back({ mOldDevice, mLatency });
	return;
}

int measure(int mDevice1, int mDevice2)
{
	// queue<latency_to_dev> dev_q;
	// dev_q.push({ 0, mDevice1, 0 });
    latency_to_dev dev_q[10005];
    int head = 0, tail = 0;
    dev_q[tail++] = { 0, mDevice1, 0 };

	//while (!dev_q.empty()) {
	while (head < tail) {
		//auto dev = dev_q.front();
		//dev_q.pop();
        auto dev = dev_q[head];
        head++;
		if (dev.dest_dev == mDevice2) return dev.latency_to_here;

		for (int i = 0; i < dev_cable_map[dev.dest_dev].size(); i++) {
			auto new_dest_dev = dev_cable_map[dev.dest_dev][i].con_dev;
			auto add_latency = dev_cable_map[dev.dest_dev][i].latency;
			if (new_dest_dev != dev.pre_dev) {
				// dev_q.push({ dev.dest_dev, new_dest_dev, dev.latency_to_here + add_latency });
                dev_q[tail++] = { dev.dest_dev, new_dest_dev, dev.latency_to_here + add_latency };
			}
		}

	}
	return -1;
}

int max_dist;
int visit[10010];
int vc;
//
// did 디바이스에서 연결되는 디바이스중 가장 먼 거리의 device 거리를 알아낸다. 
//
void dfs(int did, int dist) // 현재 device id , 현재 까지 거리 
{
    for (auto nx : edge[did])
    {
        if (visit[nx.first] == vc) continue;
        visit[nx.first] = vc;
        dfs(nx.first, dist + nx.second);
        visit[nx.first]--;
    }
    if (dist > max_dist) {
        max_dist = dist;
    }
}

int test(int mDevice)
{
    rint max1, max2;
    max1 = max2 = 0;
    vc++;
    rint did = Hash[mDevice];
    visit[did] = vc;
    // mDevice 에서 연결 되는 있는 subtree device 군들에 대한 각각 가장 먼 거리를 구한다. 
    for (auto nx : edge[did]) //
    {
        max_dist = 0;
        visit[nx.first] = vc;
        dfs(nx.first, nx.second);
        // 구해진 max_dist 의  가장 거리가 먼 첫번째와 두번째를 계속 update 한다. 
        if (max_dist > max1) {
            max2 = max1;
            max1 = max_dist;
        }
        else if (max_dist > max2) max2 = max_dist;
    }
    return max1+max2; // 첫번째와 두번째 먼 거리 합이 문제에서  원하는 답이다. 
}

// int test(int mDevice)
// {
//     auto top1 = 0;
//     auto top2 = 0;
//     // queue<latency_to_dev> dev_q;
//     latency_to_dev dev_q[10005];
//     int head = 0, tail = 0;

//     for (int path = 0; path < dev_cable_map[mDevice].size(); path++) {
//         int temp_max_latency = 0;
//         // dev_q.push({mDevice, dev_cable_map[mDevice][path].con_dev, dev_cable_map[mDevice][path].latency });
//         head = 0; tail = 0;
//         dev_q[tail++] = { mDevice, dev_cable_map[mDevice][path].con_dev, dev_cable_map[mDevice][path].latency };

//         // while (!dev_q.empty()) {
//         while (head < tail) {
//             // auto dev = dev_q.front();
//             // dev_q.pop();
//             auto dev = dev_q[head];
//         	head++;
//             temp_max_latency = max(temp_max_latency, dev.latency_to_here);

//             for (int i = 0; i < dev_cable_map[dev.dest_dev].size(); i++) {
//                 auto new_dest_dev = dev_cable_map[dev.dest_dev][i].con_dev;
//                 auto add_latency = dev_cable_map[dev.dest_dev][i].latency;
//                 if (new_dest_dev != dev.pre_dev) {
//                     // dev_q.push({ dev.dest_dev, new_dest_dev, dev.latency_to_here + add_latency });
//                     dev_q[tail++] = { dev.dest_dev, new_dest_dev, dev.latency_to_here + add_latency };
//                 }
//             }
//         }
//         if(top1 < temp_max_latency) {
//             top2 = top1;
//             top1 = temp_max_latency;
//         } else if(top2 < temp_max_latency) {
//             top2 = temp_max_latency;
//         }
//     }
// 	return top1 + top2;
// }