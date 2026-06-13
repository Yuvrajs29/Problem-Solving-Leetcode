class Solution {
  public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n= arr.size();
        stack<int> stk;
        vector<int> ans(n,-1);
        for(int i=n*2-1;i>=0;i--){
            while(!stk.empty() && stk.top()<=arr[i%n]){
                stk.pop();
           }               
            ans[i%n]=stk.empty()?-1 : stk.top();
            stk.push(arr[i%n]);
        }
        return ans;
        
    }
};