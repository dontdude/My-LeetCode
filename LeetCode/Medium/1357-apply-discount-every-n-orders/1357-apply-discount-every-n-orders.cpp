class Cashier {
    int customer;
    int customerDiscountCycle;
    double discountFactor;
    unordered_map<int, int> priceMap;
public:
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        customerDiscountCycle = n;
        customer = 0;
        discountFactor = (100.0 - discount) / 100.0;

        for(int i = 0; i < products.size(); i++) {
            priceMap[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        customer++;

        double bill = 0;
        for(int i = 0; i < product.size(); i++) {
            bill += (amount[i] * priceMap[product[i]]);
        }

        if(customer == customerDiscountCycle) {
            customer = 0;
            
            double discountedBill = bill * discountFactor;
            return discountedBill;
        }

        return bill;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */