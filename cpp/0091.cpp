#include <iostream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <size>" << std::endl;
        return 1;
    }

    int size = std::stoi(argv[1]) + 1;
    int size_sq = size * size;

    int count = 0;
    for (int i = 1; i < size_sq; i++) {
        for (int j = i + 1; j < size_sq; j++) {
            int x1 = i / size, y1 = i % size;
            int x2 = j / size, y2 = j % size;
            int dx = x2 - x1, dy = y2 - y1;

            int sq1 = x1 * x1 + y1 * y1;
            int sq2 = x2 * x2 + y2 * y2;
            int sq3 = dx * dx + dy * dy;
            int hyp = std::max(sq1, std::max(sq2, sq3));
            if (sq1 + sq2 + sq3 == 2 * hyp) {
                count++;
            }
        }
    }

    std::cout << count << std::endl;
}
