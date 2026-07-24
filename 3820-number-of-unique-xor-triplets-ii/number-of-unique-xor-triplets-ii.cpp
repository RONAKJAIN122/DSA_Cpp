class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        vector<bool> p(2048, false), v(2048, false);

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                p[nums[i] ^ nums[j]] = true;
            }
        }

        for (int i = 0; i < 2048; i++) {
            if (!p[i]) continue;
            for (int x : nums) {
                v[i ^ x] = true;
            }
        }

        int ans = 0;
        for (int i = 0; i < 2048; i++) {
            ans += v[i];
        }

        return ans;
    }
};