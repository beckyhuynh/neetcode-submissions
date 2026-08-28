class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long max = *max_element(piles.begin(), piles.end());
        long min = 1;
        long ans = max;
        long k;
        while (min <= max){
            k = (max+min)/2;

            long hrs = 0;
            for (int pile : piles){
                hrs += (pile + k - 1)/k;
            }

            if (hrs <= h){
                ans = k;
                max = k - 1;
            }

            else{
                min = k + 1;
            }
        }
        return ans;
    }
};
