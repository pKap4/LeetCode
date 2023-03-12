//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        if(x.size() == 0){
            return true;
        }
        
        stack<char> stack;
        
        if(x.size()%2 == 1){
            return false;
        }
        
        for(int i = 0; i<x.size(); i++){
            if(x[i] == '{' || x[i] == '(' || x[i] == '['){
                stack.push(x[i]);
            }
            else if(!stack.empty()){
                
                if(x[i] == '}'){
                    if(stack.top() == '{'){
                        stack.pop();
                    }
                    else
                        return false;
                }
                if(x[i] == ')'){
                    if(stack.top() == '('){
                        stack.pop();
                    }
                    else
                        return false;
                }
                if(x[i] == ']'){
                    if(stack.top() == '['){
                        stack.pop();
                    }
                    else
                        return false;
                }
            }
        }
        
        if(stack.empty())
            return true;
        
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends