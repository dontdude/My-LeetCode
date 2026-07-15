class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // sum of first n even numbers = 2 * (n * (n + 1)/2) => n * (n + 1)
        // sum of first n odd numbers = (2n * (2n + 1)) / 2 - n * (n + 1) => n * n/

        // gcd(n*n, n*(n + 1)) => n
        return n;
    }
};