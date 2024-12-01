#include<iostream>
#include<vector>
#include<unordered_map>

class DetectSquares {
public:
    std::unordered_map<int, std::unordered_map<int, int>> pointCount;

    DetectSquares() {}

    void add(std::vector<int> point) {
        int x = point[0], y = point[1];
        pointCount[x][y]++;
    }

    int count(std::vector<int> point) {
        int x = point[0];
        int y = point[1];
        int counts = 0;

        if (pointCount.find(x) == pointCount.end()) return 0;

        for (const auto& [py, count] : pointCount[x]) {
            if (py == y) continue;
            
            int sideLength = abs(py - y);

            if (pointCount[x + sideLength][y] > 0 && pointCount[x + sideLength][py] > 0) {
                counts += count * pointCount[x + sideLength][y] * pointCount[x + sideLength][py];
            }

            if (pointCount[x - sideLength][y] > 0 && pointCount[x - sideLength][py] > 0) {
                counts += count * pointCount[x - sideLength][y] * pointCount[x - sideLength][py];
            }
        }
        return counts;
    }
};
