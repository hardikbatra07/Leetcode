class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorr = 0;
        for (int num : nums) xorr ^= num;
        int diff = xorr & (-(unsigned int)xorr);
        int bucket1 = 0, bucket2 = 0;
        for (int num : nums) {
            if (num & diff)
                bucket1 ^= num;
            else
                bucket2 ^= num;
        }

        if (bucket1 < bucket2) return {bucket1, bucket2};
        return {bucket2, bucket1};
    }
};
