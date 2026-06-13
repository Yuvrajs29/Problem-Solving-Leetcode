class Solution {
public:
    bool find132pattern(vector<int>& arr) {
        stack<int> stk;
        int small=INT_MIN;
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i]<small)
                return true;
            while(!stk.empty() && stk.top()<arr[i]){
                small=stk.top();
                stk.pop();
            }
            stk.push(arr[i]);
        }
        return false;
        
    }
};