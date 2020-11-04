//see geeks for geeks for better concept 
class Solution {
public:
    int largestRectangleArea(vector<int>& input) {
        if(input.size()==0)
            return 0;
        stack<int>s;
        int max=0,max_val=INT_MIN;
        int tp;
        int i;
        for(i=0;i<input.size();){
            if(s.empty() || input[i]>=input[s.top()])
                s.push(i++);
            else{
                tp=s.top();
                s.pop();
                if(s.empty())
                    max=input[tp]*i;
                else
                    max=input[tp]*(i-s.top()-1);
                if(max>max_val)
                    max_val=max;
               // cout<<max<<endl;
                
            }
            //cout<<i<<endl;
        }
        while(!s.empty()){
                tp=s.top();
                s.pop();
                if(s.empty())
                    max=input[tp]*i;
                else
                    max=input[tp]*(i-s.top()-1);
                if(max>max_val)
                    max_val=max;
                //cout<<max<<endl;
        }
        return max_val;
    }
};
