class Bank {
public:
    vector<long long> bal;

    Bank(vector<long long>& balance) {
        bal = balance;
    }
    
    bool transfer(int a1, int a2, long long m) {
        a1--; 
        a2--;
        if (a1 < 0 || a1 >= bal.size() || a2 < 0 || a2 >= bal.size()) 
            return false;
        if (bal[a1] < m) 
            return false;
        bal[a1] -= m;
        bal[a2] += m;
        return true;
    }
    
    bool deposit(int a, long long m) {
        a--;
        if (a < 0 || a >= bal.size()) 
            return false;
        bal[a] += m;
        return true;
    }
    
    bool withdraw(int a, long long m) {
        a--;
        if (a < 0 || a >= bal.size()) 
            return false;
        if (bal[a] < m) 
            return false;
        bal[a] -= m;
        return true;
    }
};
