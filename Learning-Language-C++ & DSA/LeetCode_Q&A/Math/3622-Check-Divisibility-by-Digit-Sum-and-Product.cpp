class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, pro = 1;
        int num = n;
        while(num>0){
            int digit = num%10;
            sum += digit;
            pro *= digit;
            num = num/10;
        }
        int sum_pro = sum + pro;

        if(n%sum_pro != 0) return false;

        return true;
    }
};