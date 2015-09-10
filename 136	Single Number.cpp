class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            //It is a xor operator. We use it here because of following properties.
            //1) x^x = 0. 2) 0^x = x.
            ans ^= nums[i];
        }
        return ans;
    }
};
