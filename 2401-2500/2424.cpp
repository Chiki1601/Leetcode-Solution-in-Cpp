class LUPrefix {
public:
    vector<int> v;
    
    LUPrefix(int n) {
        v.resize(n + 1, -1);
    }
    int i = 1;
    void upload(int video) {
         v[video] = video;
    }
    
    int longest() {
        while(i < v.size() && v[i] != -1) i++;
        if(i == 1) return 0;
        return i - 1;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
