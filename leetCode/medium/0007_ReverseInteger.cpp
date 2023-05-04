class Solution {
public:
    int reverse(int x) {
        long long int reverseVal = 0;
        while(x){
            int dig = x%10;
            if(reverseVal*10 > INT_MAX || reverseVal*10 < INT_MIN)
                return 0;
            reverseVal *= 10;
            reverseVal += dig;
            x/=10;
        }
        return reverseVal;
    }
};
