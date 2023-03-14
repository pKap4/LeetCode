//{ Driver Code Starts
// C++ program to evaluate value of a postfix expression

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        // Your code here
        if(S.size() == 0){
            return 0;
        }
        
        stack<int> st;
        int eval = 0;
        
        for(auto ch: S){
            if(ch - '0' >= 0 && ch - '0' < 10){
                st.push(ch-'0');
                //cout<<"pushed "<<ch-'0'<<'\n';
            }
            
            else{
                
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                
                //cout<<ch<<" operation with "<<a<<" and "<<b<<endl;
                
                if(ch == '+'){
                    st.push(a+b);
                }
                else if(ch == '-'){
                    st.push(b-a);
                }
                else if(ch == '*'){
                    st.push(a*b);
                }
                else{
                    st.push(b/a);
                }
            }
        }
        
        return st.top();
    }
};

//{ Driver Code Starts.

// Driver program to test above functions
int main()
{
    int t;
    cin>>t;
    cin.ignore(INT_MAX, '\n');
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
    
    cout<<obj.evaluatePostfix(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends