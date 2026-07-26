class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int m1,m2,m3 ,min1 , min2;
        m1 = m2 = m3 = INT_MIN;
        min1= min2 = INT_MAX;
        for(int x : nums){
            if (x > m1) {
                m3 = m2;
                m2 = m1;
                m1 = x;
            } else if (x > m2) {
                m3 = m2;
                m2 = x;
            } else if (x > m3) {
                m3 = x;
            }

            if(x<min1){
                min2 = min1;
                min1 = x;
            }
            else if(x<min2){
                min2 = x;
            }

        }
        return max(m1*m2*m3 , min1*min2*m1);
    }
};