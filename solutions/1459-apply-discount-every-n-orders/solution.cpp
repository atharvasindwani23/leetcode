class Cashier {
public:

    //1.figuring out how much someone has to pay for their groceries => amount[i] * price[i] where i is groceries they're buying
    //2. which current customer am i serving
    //3. how do i apply discount


    //some sort of a mapping between product and price => agreed?
    unordered_map<int,int> prodToPrice;
    int count = 0;
    int n = 0;
    double disc = 0;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        for (int i = 0; i < products.size(); i++) {
            prodToPrice[products[i]] = prices[i];
        }
        this->n = n;
        disc = discount;
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        double totAmount = 0;
        count++;
        for (int i = 0; i < product.size(); i++) {
            totAmount += prodToPrice[product[i]] * amount[i];
        }
        if (count % n == 0) {
            return (totAmount * (100 - disc)) / 100;
        }
        return totAmount;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
