class Solution {
public:
    void merge(vector<int>& arr,int low, int high){
        vector<int> ans;
        int mid = low +(high-low)/2;
        int i=low;
        int j=mid+1;
        while(i<=mid && j<=high){
            if(arr[i]<=arr[j]){
                ans.push_back(arr[i++]);
                
            }
            else{
                ans.push_back(arr[j++]);
                
            }
        }
        while(i<=mid){
            ans.push_back(arr[i++]);
        }
        while(j<=high){
            ans.push_back(arr[j++]);
        }
        for(int i=low,j=0;i<=high ; i++,j++){
            arr[i]=ans[j];        
        }
    }
    void mergesort(vector<int> &arr,int low,int high){
        if(low>=high)
            return;
        int mid= low+(high-low)/2;
        mergesort(arr,low,mid);
        mergesort(arr,mid+1,high);
        merge(arr,low,high);
    }
    vector<int> sortArray(vector<int>& nums){
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
    };