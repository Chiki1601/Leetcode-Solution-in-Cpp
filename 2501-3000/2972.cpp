class Solution {
public:
    long long countSortedArrays(const vector<int>& arr1, const vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();

        long long result = 0;
        int i = 0, j = 0;

        while (i < n1 && j < n2) {
            if (arr1[i] < arr2[j]) {
                // If arr1[i] is less than arr2[j], you can form sorted arrays with arr1[0..i] and arr2[j..n2-1]
                result += (n2 - j);
                i++;
            } else {
                // If arr1[i] is greater than arr2[j], move to the next element in arr2
                j++;
            }
        }

    return result;
}
    long long incremovableSubarrayCount(vector<int>& a) {
        long long n = a.size();
		
        if(n==1)
            return 1;
        
		int i=0;
        int j=n-1;
		
        vector<int>arr1,arr2;

        while((i+1)<n and a[i]<a[i+1])
        {
            arr1.push_back(a[i]);
            i++;
        }
        arr1.push_back(a[i]);
  
        while((j-1)>=0 and a[j]>a[j-1]){
            arr2.push_back(a[j--]);
        }
        arr2.push_back(a[j]);
		
        reverse(arr2.begin(),arr2.end());
        if(j<i)
        {
            long long ans = (1ll*n*(n+1)*1LL)/2;
            return ans;
        }
		
        long long ans = 0;
		ans += arr1.size();   //1
        ans += arr2.size();  //2
        ans += countSortedArrays(arr1,arr2); //3
		ans++; //4
        
		return ans;
        
    }
};
