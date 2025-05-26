#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <sstream>
#include <queue>
#include <vector>

void read_matrix(const std::string& filename, std::vector<int>& matrix) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file: " + filename);
    }

    matrix.clear();
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string cell;
        while (std::getline(ss, cell, ',')) {
            matrix.push_back(std::stoi(cell));
        }
    }
}

int dynamic_programming(const std::vector<int>& matrix, int N) {
    std::vector<int> dp(N, 0);
    for (int r = 0; r < N; r++) {
        // 0. each row starts with first column weight M[r][0]
        dp[r] = matrix[r * N];
    }

    for (int c = 1; c < N; c++) {
        // 1. compute the weight to move to the current column from the left
        for (int r = 0; r < N; r++) {
            dp[r] += matrix[r * N + c];
        }
        // 2. compare with the weight to move downward to the current row
        for (int r = 1; r < N; r++) {
            dp[r] = std::min(dp[r], dp[r - 1] + matrix[r * N + c]);
        }
        // 3. compare with the weight to move upward to the current row
        for (int r = N - 2; r >= 0; r--) {
            dp[r] = std::min(dp[r], dp[r + 1] + matrix[r * N + c]);
        }
    }

    // 4. lookup for the row with the minimum weight
    return *std::min_element(dp.begin(), dp.end());
}

int dijkstra(const std::vector<int>& matrix, int N) {
    const int NxN = N * N;
    std::vector<int> dist(NxN, INT_MAX);
    using pos_and_weight = std::pair<int, int>;
    std::priority_queue<pos_and_weight, std::vector<pos_and_weight>> pq;

    for (int r = 0; r < N; r++) {
        dist[r * N] = matrix[r * N];
        pq.push({r * N, dist[r * N]});
    }

    while (!pq.empty()) {
        int u = pq.top().first;
        int d = pq.top().second;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        int r = u / N;
        int c = u % N;

        int within_bounds[3] = {
            c < N - 1,
            r < N - 1,
            r > 0,
        };
        int neighbors[3] = {
            u + 1, // right
            u + N, // down
            u - N, // up
        };

        for (int i = 0; i < 3; i++) {
            if (within_bounds[i]) {
                int v = d + matrix[neighbors[i]];
                if (v < dist[neighbors[i]]) {
                    dist[neighbors[i]] = v;
                    pq.push({neighbors[i], v});
                }
            }
        }
    }

    int min_dist = INT_MAX;
    for (int r = 0; r < N; r++) {
        min_dist = std::min(min_dist, dist[r * N + N - 1]);
    }
    return min_dist;
}

int bellman_ford(const std::vector<int>& matrix, int N) {
    std::vector<int> dist(N * N, INT_MAX);
    for (int r = 0; r < N; r++) {
        dist[r * N] = matrix[r * N];
    }

    for (int i = 0; i < N * N; i++) {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                int u = r * N + c;

                // right
                if (c < N - 1) {
                    dist[u + 1] = std::min(dist[u + 1], dist[u] + matrix[u + 1]);
                }
                // down
                if (r < N - 1) {
                    dist[u + N] = std::min(dist[u + N], dist[u] + matrix[u + N]);
                }
                // up
                if (r > 0) {
                    dist[u - N] = std::min(dist[u - N], dist[u] + matrix[u - N]);
                }
            }
        }
    }

    int min_dist = INT_MAX;
    for (int r = 0; r < N; r++) {
        min_dist = std::min(min_dist, dist[r * N + N - 1]);
    }
    return min_dist;
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        std::cerr << "Usage: " << argv[0] << " <filename> <rows>" << std::endl;
        return 1;
    }

    int N = std::stoi(argv[2]);

    std::vector<int> matrix;
    matrix.reserve(N * N);
    read_matrix(argv[1], matrix);

    std::cout << dynamic_programming(matrix, N) << std::endl;
    std::cout << dijkstra(matrix, N) << std::endl;
    std::cout << bellman_ford(matrix, N) << std::endl;
}
