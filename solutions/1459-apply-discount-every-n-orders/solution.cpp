class Cashier {
public:
    unordered_map<int, int> productToPrice;
    int n = 0;
    int discount = 0;
    int count = 0;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        for (int i = 0; i < products.size(); i++) {
            productToPrice[products[i]] = prices[i];
            this->n = n;
            this->discount = discount;
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        count++;
        double totalCost = 0;

        for (int i = 0; i < product.size(); i++) {
            totalCost += amount[i] * productToPrice[product[i]];
        }

        if (count % n == 0) {
            cout << discount << endl;
            totalCost = totalCost * ((double)(100 - discount) / (double)100);
        }
        return totalCost;
    }

    //product price amount
    //total bill will be price[i] * amount[i] where i represents the ith product.
    //we need some sort of a mapping between product and price right?
    //logic should be that against this product this is the price.
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
