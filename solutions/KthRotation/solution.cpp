//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int ind = 0;
        queue<int> q;
        vector<int> st;
        int sz = arr.size();
        for(int i = 0; i<sz; i++){
            q.push(arr[i]);
        }
        for(int i = 0; i<sz; i++){
            st.push_back(arr[i]);
        }
    
        int countAntiClock = 0;
        while(!q.empty() && q.front()>q.back()){
            int rotVal = q.front();
            q.pop();
            q.push(rotVal);
            countAntiClock++;
        }
    
        return countAntiClock;

    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
}