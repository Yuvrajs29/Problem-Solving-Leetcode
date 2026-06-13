class Solution {
public:
    vector<int> leftMin(vector<int> arr){
        int n = arr.size();
        vector<int> leftMinIdx(n, -1);
        stack<int> st;
        for(int i = 0; i<n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            leftMinIdx[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return leftMinIdx;
    }
    vector<int> rightMin(vector<int> arr){
        int n = arr.size();
        vector<int> rightMinIdx(n, -1);
        stack<int> st;
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            rightMinIdx[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return rightMinIdx;
    }
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> leftMinIdx = leftMin(h);
        vector<int> rightMinIdx = rightMin(h);
        int maxArea = INT_MIN;
        for(int i = 0 ; i < n; i++){
            int width = rightMinIdx[i] - leftMinIdx[i] - 1;
            int area = width * h[i];
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};