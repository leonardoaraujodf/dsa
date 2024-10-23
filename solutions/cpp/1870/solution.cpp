class Solution {
public:
    double limit;
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if (dist.size() > ceil(hour)) {
            return -1;
        }

        this->limit = hour;
        int left = 1;
        int right = pow(10, 7);
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid, dist)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    bool check(double speed, vector<int> &dist) {
        double h = 0;
        for (double d : dist) {
            h = ceil(h);
            h += d / speed;
        }

        return h <= limit;
    }
};
