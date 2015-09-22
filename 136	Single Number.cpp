class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            //bitwise xor
            //actually not a running result, but rather xor everything so order does not matter
            ans ^= nums[i];
        }
        return ans;
    }
};
