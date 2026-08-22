class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int product=1;
        int num =n;

        for(int i=num;num>0;i++)
        {
            sum += num % 10;
            product *= num % 10;
            num /= 10;
        }
        return n % (sum + product) == 0;
    }
};