class ProductOfNumbers {
public:
    vector<int> prefixProduct;
    int lastZeroIdx;
    ProductOfNumbers() {
        prefixProduct.push_back(1);
        lastZeroIdx = -1;
    }
    void add(int num) {
        if (num == 0) {
            prefixProduct.clear();
            prefixProduct.push_back(1);
            lastZeroIdx = prefixProduct.size() - 1;
        } else {
            prefixProduct.push_back(num * prefixProduct.back());
        }
    }
    int getProduct(int k) {
        int size = prefixProduct.size();
        if (size - k - 1 < lastZeroIdx) return 0;
        return prefixProduct.back() / prefixProduct[size - k - 1];
    }
};
