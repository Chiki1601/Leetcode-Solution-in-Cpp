class Solution {
    public boolean scoreBalance(String s) {
        int total = 0;
        for (char c : s.toCharArray()) total += c - 'a' + 1;
        int prefix = 0;
        for (char c : s.toCharArray()) {
            prefix += c - 'a' + 1;
            if (2 * prefix == total) return true;
        }
        return false;
    }
}
