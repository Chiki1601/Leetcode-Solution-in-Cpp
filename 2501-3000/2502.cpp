class Allocator {
public:
    vector<int> vt;
    int allocated=0;
    int nn;
    map<int,int> mp;
    Allocator(int n) {
        vt.resize(n,-1);
        nn=n;
    }
    
    int allocate(int size, int mID) {
        if(size>nn) {
            return -1;
            
        }
        int cf=0;
        int si=0;
        for(int i=0;i<nn;++i){
           
            if(vt[i]==-1){
                 cf++;
            }
            else {
                 
                cf=0;
            }
             if(cf==size){
                si=i-size+1;
                break;
            }
            
        }
         
        if(cf!=size) return -1;
        
        for(int i=0;i<size;++i){
            vt[i+si]=mID;
            // mp[i]=mID;
        }
        // for(auto it:vt) cout<<it<<" ";
        // cout<<endl;
        // cout<<si<<endl;
        
        
        return si;
                
        
    }
    
    int free(int mID) {
        int cnt=0;
        for(auto& it:vt){
            if(it==mID) {
                it=-1;
                cnt++;
            }
        }
        return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */


// [null, 0, 1, 2, 1, 3, 1, 6, 3, -1, 0]
