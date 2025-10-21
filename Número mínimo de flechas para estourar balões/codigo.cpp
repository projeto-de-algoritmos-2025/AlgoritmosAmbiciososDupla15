#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int arrows = 1;
        long long arrow_pos = points[0][1]; 

        for (auto& balloon : points) {
            if (balloon[0] > arrow_pos) {
                arrows++;
                arrow_pos = balloon[1];
            }
        }

        return arrows;
    }
};
