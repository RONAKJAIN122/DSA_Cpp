class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        //consturct 
        vector<int> prefixGcd;
        int max = INT_MIN;
        for(int i = 0; i<nums.size() ; i++){
            // int mxi = max_arr(nums,i); //o(n^2)
            if(nums[i] > max) max = nums[i];
            int temp = gcd(nums[i] , max);
            prefixGcd.push_back(temp);
        }
        //after
        sort(prefixGcd.begin() , prefixGcd.end());
        vector<pair<int,int>> p;
        int s = 0;
        int e = prefixGcd.size() - 1;
        long long sum = 0;
        while(s<e){
            // p.push_back({prefixGcd[s++] , prefixGcd[e--]});
            sum += (long long)gcd(prefixGcd[s++] , prefixGcd[e--]);
        }
        return sum;
    }
private:
    // int max_arr(vector<int> &v , int n){
    //     int max = INT_MIN;
    //     for(int i=0 ; i<=n ;i++){
    //         if(v[i] > max) max = v[i];
    //     }
    //     return max;
    // }
    int gcd(int a , int b){
        if(b == 0) return a;
        return gcd(b,a%b);
    }
};