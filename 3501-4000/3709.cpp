class ExamTracker {
private:
    vector<pair<int,long long>>arr;
    long long fn(vector<pair<int,long long>>&arr,int time)
    {
        long long totalscore=0;

        int l=0,r=arr.size()-1;
        int ind=-1;

        while(l<=r)
            {
                int mid=(l+r)/2;

                if(arr[mid].first<=time)
                {
                    ind=mid;
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
        if(ind!=-1) totalscore=arr[ind].second;

        return totalscore;
        
    }
public:
    
    
    
    ExamTracker() 
    {
        
    }
    
    void record(int time, int score) 
    {
        long long ans=score;

        if(!arr.empty()) 
        {
            ans+=arr.back().second;
        }
        arr.push_back({time,ans});
        
    }
    
    long long totalScore(int startTime, int endTime) 
    {
        long long scoreuptostarttime=fn(arr,startTime-1);
        long long scoreuptoendtime=fn(arr,endTime);

        return scoreuptoendtime-scoreuptostarttime;
        
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */
