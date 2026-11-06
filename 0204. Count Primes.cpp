class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        // isPrime[i] tracks whether i is prime
        // vector<bool> is space-optimized to 1 bit per boolean
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i < n; ++i) {
            if (isPrime[i]) {
                // Mark multiples starting from i * i
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                count++;
            }
        }

        return count;
    }
};
