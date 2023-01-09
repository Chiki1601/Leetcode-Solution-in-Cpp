class DataStream {
public:
    int val = 0, kmax = 0;
    int valCount = 0;
    DataStream(int value, int k) {
        val = value;
        kmax = k;
    }
    
    bool consec(int num) {
        if(num == val)
            valCount++;
        else
            valCount = 0;
        return valCount >= kmax;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
