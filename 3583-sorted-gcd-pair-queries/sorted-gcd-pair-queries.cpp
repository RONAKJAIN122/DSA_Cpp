class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());

        vector<int> freq(mx + 1, 0);
        for (auto x : nums) {
            freq[x]++;
        }

        vector<long long> cnt(mx + 1, 0);

        for (int i = 1; i <= mx; i++) {
            for (int j = i; j <= mx; j += i) {
                cnt[i] += freq[j];
            }
        }

        vector<long long> exact(mx + 1, 0);

        for (int i = 1; i <= mx; i++) {
            exact[i] = cnt[i] * (cnt[i] - 1) / 2;
        }

        for (int i = mx; i >= 1; i--) {
            for (int j = 2 * i; j <= mx; j += i) {
                exact[i] -= exact[j];
            }
        }

        vector<long long> prefix(mx + 1, 0);

        for (int i = 1; i <= mx; i++) {
            prefix[i] = prefix[i - 1] + exact[i];
        }

        vector<int> ans;

        for (auto x : queries) {
            int l = 1, r = mx;

            while (l < r) {
                int mid = l + (r - l) / 2;

                if (prefix[mid] > x) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }

            ans.push_back(l);
        }

        return ans;
    }
};