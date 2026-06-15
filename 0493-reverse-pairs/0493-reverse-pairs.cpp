class Solution {
    void merge(vector<int> & arr, int low,int high){
        vector<int> temp;
        int mid = low+(high-low)/2;
        int i = low, j=mid+1;
        while(i<=mid && j<=high){
            if(arr[i] < arr[j])
                temp.push_back(arr[i++]);
            else
                temp.push_back(arr[j++]);
        }
        while(i<=mid)
            temp.push_back(arr[i++]);
        while(j<=high)
            temp.push_back(arr[j++]);
        for(int i = low, j=0; i<=high; i++,j++){
                arr[i]= temp[j];
    }
    }
    
    int paircount(vector<int> &arr, int low,int high){
        int mid= low + (high-low)/2;
        int count = 0;
        int j=mid+1;
        for(int i=low;i<=mid;i++){
            while(j<= high && (long long)arr[i]>(long long)arr[j]*2LL){
                j++;
            }
            count += j-(mid+1);
        }
    
        return count;
    }
    int mergesort(vector<int> &arr, int low,int high){
        if(low==high)
            return 0;
        int mid = low+(high-low)/2;
        int count = 0;
        count += mergesort(arr,low,mid);
        count += mergesort(arr,mid+1,high);
        count += paircount(arr,low,high);
        merge(arr,low,high);
        return count;
    }
public:
    int reversePairs(vector<int>& nums) {
       return mergesort(nums,0,nums.size()-1);
    }
};