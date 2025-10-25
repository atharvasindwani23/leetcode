class Solution {
public:
    int totalMoney(int n) {
       int weeks = n / 7;
       int remaining_days = n % 7; 
       return weekMoney(weeks) + daysMoney(remaining_days, weeks);
    }

    int weekMoney(int weeks) {
        int initial_sum  = 28;
        return (weeks * 28) + (7) * (weeks) * (weeks - 1) / 2;
    } 

    int daysMoney(int remaining_days, int weeks) {
        int sum = 0;
        for (int i = weeks + 1; i <= remaining_days + weeks; i++) {
            sum += i;
        }
        return sum;
    }




    //1 + 2 + 3 + 4 + 5 + 6 + 7

};
