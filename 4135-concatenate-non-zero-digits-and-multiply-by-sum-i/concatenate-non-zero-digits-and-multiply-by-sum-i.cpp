class Solution {
public:
    long long sumAndMultiply(int n) {
        long long temp = n;
        long long x = 0;
        long long sum = 0;
        while(temp>0){
            long long ld = temp%10;
            temp /= 10;
            if(ld){
                x = x*10 + ld;
                sum += ld;
            }
        }
        long long rev = 0;
        while(x > 0){
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        
        return rev * sum;
    }
};