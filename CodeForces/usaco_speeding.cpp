#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("speeding.in");
    ofstream fout("speeding.out");

    int N, M;
    fin >> N >> M;

    vector<int> road_length(N);
    vector<int> road_speed_limit(N);
    vector<int> bessie_length(M);
    vector<int> bessie_speed(M);

    for (int i = 0; i < N; ++i) {
        fin >> road_length[i] >> road_speed_limit[i];
    }

    for (int i = 0; i < M; ++i) {
        fin >> bessie_length[i] >> bessie_speed[i];
    }

    int max_over_limit = 0;
    int road_index = 0, bessie_index = 0;

    while (road_index < N && bessie_index < M) {
        int road_end = road_length[road_index];
        int bessie_end = bessie_length[bessie_index];

        int road_speed = road_speed_limit[road_index];
        int bess_speed = bessie_speed[bessie_index];

        int over_limit = max(0, bess_speed - road_speed);

        max_over_limit = max(max_over_limit, over_limit);

        if (road_end < bessie_end) {
            bessie_length[bessie_index] -= road_end;
            road_index++;
        } else if (road_end > bessie_end) {
            road_length[road_index] -= bessie_end;
            bessie_index++;
        } else {
            road_index++;
            bessie_index++;
        }
    }

    fout << max_over_limit << endl;

    fin.close();
    fout.close();

    return 0;
}
