class Solution {
public:
    bool zeroFree(long long x) {
        while (x) {
            if (x % 10 == 0) return false;
            x /= 10;
        }
        return true;
    }

    bool divisible(long long x, long long t) {
        long long prod = 1;
        while (x) {
            prod *= (x % 10);
            x /= 10;
        }
        return prod % t == 0;
    }

    string smallestNumber(string num, long long t) {
        long long n = stoll(num);

        while (true) {
            if (zeroFree(n) && divisible(n, t))
                return to_string(n);
            n++;
        }

        return "-1";
    }
};