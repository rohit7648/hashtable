class Solution {
public:
    int find(vector<int>v,int n){
        stack<int>s;
        int i=0;
        int temp=0;
        int ans=INT_MIN;
        while(i<n){
            if(s.empty() || v[s.top()]<=v[i])
                s.push(i++);
            else{
                int tp=s.top();
                s.pop();
                if(s.empty())
                    temp=v[tp]*i;
                else{
                    temp=v[tp]*(i-s.top()-1);
                }
                if(temp>ans)
                    ans=temp;
            }
        }
        while(!s.empty()){
            int tp=s.top();
                s.pop();
                if(s.empty())
                    temp=v[tp]*i;
                else{
                    temp=v[tp]*(i-s.top()-1);
                }
                if(temp>ans)
                    ans=temp;
            }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int>v(n);                        //first copy first row in v
        for(int i=0;i<n;i++)                    //after that if matrix[i]==1 then v[j]=v[j+1
            v[i]=matrix[0][i]-'0';              //then for each v[j] find the maximum area using maximum rectangle histogram logic
        int final_result=0;                     //because each v[j] is eight of a bar and j=0 to matrix.size()-1
        for(int i=0;i<m;i++){
            if(i>0){
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='0')
                    v[j]=0;
                else
                    v[j]+=1;
            }
            }
            int result=find(v,n);
            if(result>final_result)
                final_result=result;
        }
        
        return final_result;
        
    }
};
