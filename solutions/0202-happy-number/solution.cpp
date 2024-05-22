class Solution {
public:
 bool isHappy(int n) {
    // Use Floyd's Cycle-Finding Algorithm (Tortoise and Hare)
    int slow = n;
    int fast = squareReplacer(squareReplacer(n));

    while (fast != 1 && slow != fast) {
        slow = squareReplacer(slow); // Move slow pointer one step
        fast = squareReplacer(squareReplacer(fast)); // Move fast pointer two steps
    }

    return fast == 1; // If fast reaches 1, it's a happy number; otherwise, it's not
}
    int squareReplacer(int n) {
         int sum = 0;
         while (n > 0) {
         int digit = n % 10;  // Extract the last digit
         sum += digit * digit;  // Square the digit and add to sum
          n /= 10;             // Remove the last digit
    }
    return sum;
    }
};
