using LL = long long;

class Solution {
public:
    vector<int> findProductsOfElements(vector<vector<LL>>& queries) {
        vector<int> result;
        result.reserve(queries.size());
        for (const auto& query : queries) {
            LL prefix_sum_1 = prefixSumTillIndex(query[0]);
            LL prefix_sum_2 = prefixSumTillIndex(query[1] + 1);

            result.push_back(pow(2, prefix_sum_2 - prefix_sum_1, query[2]));
        }

        return result;
    }

private:
    // Count the bits for all numbers from 1 to `value - 1`.
    // Return the bit value sum and total count.
    pair<LL, LL> sumAndCountBitsBeforeValue(LL value) {
        LL bit_sum = 0;
        LL bit_count = 0;
        for (LL bit = 0, power = 1; power < value; bit++, power <<= 1) {
            LL cur = (value >> (bit + 1)) << bit;
            cur += max(0LL, (value % (power << 1)) - power);
            bit_count += cur;
            bit_sum += bit * cur;
        }
        return {bit_sum, bit_count};
    }

    LL getValueFromIndex(LL index) {
        index++;
        LL low = 1, high = 1LL << 50;

        while (low < high) {
            LL mid = low + (high - low) / 2;
            if (sumAndCountBitsBeforeValue(mid + 1).second < index) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }

    LL prefixSumTillIndex(LL index) {
        LL value = getValueFromIndex(index);
        auto [bit_sum, bit_count] = sumAndCountBitsBeforeValue(value);
        // Also include the last value's partial bits.
        if (bit_count < index) {
            for (int bit = 0; bit_count < index; bit++, value >>= 1) {
                bit_sum += bit * (value % 2);
                bit_count += value % 2;
            }
        }
        return bit_sum;
    }

    // Calculate `(x ^ y) % mod` by converting the y into binary bits.
    int pow(LL x, LL y, int mod) {
        if (y <= 0) {
            return 1 % mod;
        }
        x %= mod;
        LL result = 1;
        while (y) {
            if (y & 1) {
                result = multiply(result, x, mod);
            }
            x = multiply(x, x, mod);
            y >>= 1;
        }
        return result;
    }

    int multiply(LL x, LL y, int mod) {
        return ((x % mod) * (y % mod)) % mod;
    }
};
