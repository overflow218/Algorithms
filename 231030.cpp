// leetcode 1356번
#include <algorithm>
using namespace std;

int countBit(int x)
{
    int cnt = 0;
    while(x)
    {
        cnt += x % 2;
        x /= 2;
    }
    return cnt;
}
bool cmp(int a, int b)
{
    int bitA = countBit(a);
    int bitB = countBit(b);
    if(bitA != bitB) return bitA < bitB;
    return a < b;
}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};

// leetcode 1357번
#include <unordered_map>
using namespace std;

class Cashier {
public:
    unordered_map<int, int> check;
    int discount;
    int n;
    int cnt;
    Cashier(int n, int discount, vector<int>& products, vector<int>& prices) {
        this -> n = n;
        this -> discount = discount;
        this -> cnt = 0;
        for(int i = 0; i < products.size(); i++)
        {
            check[products[i]] = prices[i];
        }
    }
    
    double getBill(vector<int> product, vector<int> amount) {
        cnt++;
        double total = 0;
        for(int i = 0; i < product.size(); i++)
        {
            total += check[product[i]] * amount[i];
        }

        if(cnt % (this -> n) == 0)
        {
            total = total * ((100 - (this -> discount)) / 100.0);
        }
        return total;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */
