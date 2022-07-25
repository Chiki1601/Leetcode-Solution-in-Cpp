class NumberContainers {
public:


  map<int,int> m;
    NumberContainers() {
      
        
    }
    
    void change(int index, int number) {
      m[index]=number;
        
    }
    
    int find(int number) {
         int ans=-1;
        for(auto it:m){
            if(it.second==number){
                ans=it.first;
                break;
            }
        }
         
        return ans;
        
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
