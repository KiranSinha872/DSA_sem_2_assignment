#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 1};
    int n = arr.size();

    vector<int> answer(n, -1);
    stack<int> st;

    for(int i = 2 * n - 1; i >= 0; i--) {

        while(!st.empty() && st.top() <= arr[i % n]) {
            st.pop();
        }

        if(i < n && !st.empty()) {
            answer[i] = st.top();
        }

        st.push(arr[i % n]);
    }

    for(int x : answer) {
        cout << x << " ";
    }
}