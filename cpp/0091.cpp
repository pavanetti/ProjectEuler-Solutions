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

            int dp1 = x1 * x2 + y1 * y2;
            int dp2 = x1 * dx + y1 * dy;
            int dp3 = x2 * dx + y2 * dy;
            // if some of the dot products between some of the sides is 0,
            // then the sides are perpendicular to each other and the triangle
            // is a right triangle.
            if (dp1 == 0 || dp2 == 0 || dp3 == 0) {
                count++;
            }
        }
    }

    std::cout << count << std::endl;
}
