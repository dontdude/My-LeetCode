class Solution {
    vector<int> numbers;
    vector<long long> factorial;

    void generatePermutation(int n, int k, string& result) {
        if(n == 0)  return;
        
        int ind = k / factorial[n - 1];

        result.append(to_string(numbers[ind]));
        numbers.erase(numbers.begin() + ind);

        int restK = k % factorial[n - 1];
        generatePermutation(n - 1, restK, result);
    }
public:
    string getPermutation(int n, int k) {
        string result = "";

        factorial.resize(n);
        factorial[0] = 1;

        for(int i = 1; i <= n; i++) {
            numbers.push_back(i);
            if(i < n) factorial[i] = (long long)i * factorial[i - 1];
        }
        generatePermutation(n, k - 1, result);

        return result;
    }
};