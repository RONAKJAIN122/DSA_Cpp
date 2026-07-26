class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> s;
        for(int x : nums){
            s.insert(x);
        }
        for(int i=0 ; i <= nums.size() ;i++){
            if(!(s.contains(i))) return i;
        }
        return -1;
    }
};