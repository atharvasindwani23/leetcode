class StockSpanner {
public:
    vector<int> prices;
    StockSpanner() {
    }
    
    int next(int price) {
        prices.push_back(price);
        int size = prices.size();
        for (int i = prices.size() - 1; i >= 0; i--) {
            if (prices[i] > price) {
                return size - i - 1;
            }
        }
        return prices.size();
    }

    //basically insert an element into the array and then find the last element within the array [first from behind  which has its value greater than the element you just popped => feels v stacky 

    //i want to keep track of two things => what is the largest element which ive seen so far; where did i see it last
    //brute force => o(n) everytime => pop an element into the array and then search 
    //im assuming o(n) is unoptimal??

};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
