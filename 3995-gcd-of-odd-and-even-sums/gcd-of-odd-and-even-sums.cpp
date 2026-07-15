class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int e = 0 , o = 0;
        for(int i=1 ; i <= 2*n ; i++){
            if(i%2) o += i;
            else e += i;
        }
        return gcd(e,o);
    }
private:

    int gcd(int a , int b){
        if(b == 0) return a;
        return gcd(b,a%b);
    }
};