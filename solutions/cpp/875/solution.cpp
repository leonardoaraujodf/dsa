int minEatingSpeed(vector<int> &piles, int h) {
    int left = 1, right = 0;
    for (int bananas : piles) {
        right = max(right, bananas)
    }

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(piles, mid, h)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

bool check(vector<int> &piles, int k, int limit) {
    long h = 0;
    for (double bananas : piles) {
        h += ceil(bananas / k);
    }
    return h <= limit;
}