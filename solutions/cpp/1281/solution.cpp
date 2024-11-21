class Solution {
public:
    int numberofPeople;
    int maximizeSweetness(vector<int>& sweetness, int k) {
        numberofPeople = k + 1;
        int left = *min_element(sweetness.begin(), sweetness.end());
        int right = accumulate(sweetness.begin(), sweetness.end(), 0) / numberofPeople;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(mid, sweetness)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
    }

    bool check(int minSweetness, vector<int> &sweetness) {
        int peopleWithChocolate = 0;
        int currSweetness = 0;
        for (int s : sweetness) {
            currSweetness += s;
            if (currSweetness >= minSweetness) {
                peopleWithChocolate++;
                currSweetness = 0;
            }
        }

        return peopleWithChocolate >= numberofPeople;
    }
};
