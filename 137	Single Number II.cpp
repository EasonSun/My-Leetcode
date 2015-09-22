//credit to https://leetcode.com/discuss/54970/an-general-way-to-handle-all-this-sort-of-questions
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        //Here a generic way is to count, and actually count the bits
        //Input a int, which is 32 bits, count the time these bits appear
        //We need to implement a tree-time counter(base 3) that if a bit appears three time ,it will be zero.
        //The counter runs on all bits of an integer at once, by bit operation 
        //#curent  income  ouput
        //# ab      c/c       ab/ab
        //# 00      1/0       01/00
        //# 01      1/0       10/01
        //# 10      1/0       00/10
        // a = ~abc + a~b~c; intepret the only cases when a is 1
        // b = ~a~bc + ~ab~c; intepret the only cases when b is 1
        int a=0;
        int b=0;
        for(int c:nums){
            int nexta=(~a&b&c)|(a&~b&~c);
            int nextb=(~a&~b&c)|(~a&b&~c);
            a = nexta;
            b = nextb;
        }
        //Here we can should output b, because the target number appers only once, rendering the state stops at ab=01
        //So we can output any single number, given the time it appers
        return b;
    }
};
