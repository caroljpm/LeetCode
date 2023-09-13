//https://leetcode.com/problems/koko-eating-bananas/description/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int high = *max_element(piles.begin(), piles.end());
        int low = 1;

        int result = high;
        while(low <= high) {
            int mid = (low + high)/2;

            uint64_t hours = 0;
            for(int i=0; i<piles.size(); i++) {
                hours += ceil(piles[i]/(double)mid);
            }
            
            if(hours <= h){
                high = mid-1;
                result = min(result, mid);
            } else {
                low = mid+1;
            }
        }
        
        return result;
    }
};
