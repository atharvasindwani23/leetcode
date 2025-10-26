class Bank {
public:
    unordered_map<long,long> bankBalance;
    Bank(vector<long long>& balance) {
        for (int i = 0; i < balance.size(); i++) {
            bankBalance[i + 1] = balance[i];
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if (bankBalance.count(account1) && bankBalance.count(account2) && bankBalance[account1] >= money) {
            bankBalance[account1] -= money;
            bankBalance[account2] += money;
            return true;
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if (bankBalance.count(account)) {
        bankBalance[account] += money;
        return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if (bankBalance.count(account) && bankBalance[account] >= money) {
        bankBalance[account] -= money;
        return true;
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */
