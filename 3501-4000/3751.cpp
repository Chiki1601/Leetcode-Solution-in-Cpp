class Solution {
public:
    int totalWaviness(int num1, int num2) {
        // arr[i] will store *prefix sums* of waviness:
        //   - Before prefixing: arr[i] = waviness of number i
        //   - After prefixing:  arr[i] = total waviness from 0 to i
        //
        // Using a static initialization ensures
        // that all expensive computation happens only once
        // across multiple function calls.
        static array<long, 100001> arr = [] {
            array<long, 100001> arr;
            // Numbers below 100 cannot form 3-digit waves → waviness = 0
            for (int i = 0; i < 100; i++) {
                arr[i] = 0;
            }

            // Compute waviness for all numbers 100–100000
            for (int i = 100; i < 100001; i++) {
                int wave = 0;
                int n = i;

                // Scan the first 3 digits from right to left
                int prev = n % 10;          // right digit
                n /= 10;                    // remove the right/first digit
                int curr = n % 10;          // middle digit
                int next = (n % 100) / 10;  // left digit

                // A peak or valley adds 1 to waviness
                if ((prev < curr && next < curr) ||
                    (prev > curr && next > curr)) {
                    wave++;
                }

                // Optimization:
                // We've already computed waviness for the remaining prefix,
                // reuse it instead of continuing digit-by-digit.
                wave += arr[n];
                arr[i] = wave;
            }

            // Convert arr[] into a prefix sum array:
            // arr[i] = waviness(0) + waviness(1) + ... + waviness(i)
            for (int i = 1; i < 100001; i++) {
                arr[i] += arr[i - 1];
            }

            return arr;
        } ();

        // With prefix sums:
        // waviness(num1..num2) = arr[num2] - arr[num1 - 1]
        return arr[num2] - arr[num1 - 1];
    }
};
