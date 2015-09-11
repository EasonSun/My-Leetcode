class Solution {
public:
    int hIndex(vector<int>& citations) {
        int cit_size = citations.size();
        if(cit_size==0) return 0;
        vector<int> cit_cnt(cit_size+1);
        for(int idx=0; idx<cit_size; idx++)
        {
            if(citations[idx]>=cit_size)
                cit_cnt[cit_size]++;
            else
                cit_cnt[citations[idx]]++;
        }
        
        int sum = 0;
        for(int idx=cit_size; idx>-1; idx--)
        {
            sum += cit_cnt[idx];
            if(sum>=idx)
                return idx;
        }
    }
};
