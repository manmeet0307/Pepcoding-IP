#include<iostream>
 #include<vector>
 using namespace std;


 int Jump(vector<int> &nums) {

    int n = nums.size();
    vector<int> gap(n);
    gap[0] = nums[0];
    int i = 1;
    int maxgap = 0;
    int jumplace = gap[0];
    int c = 1;
    int r = 1;
    int steps = 0;
    while(c<n)
    {
      maxgap = 0;
      int tojump;
      while(r<=jumplace)
      {
            if(r>n) break;
            gap[r++] = i + nums[i];
            if(gap[i] >= maxgap)
            {
                tojump = i;
                maxgap = gap[i];
            }
            i++;
      }
      c = tojump;
      jumplace = maxgap;
      steps++;
      if(c == n-1 )
        break;
      if(jumplace == n-1)
      {
          steps++; break;
      }
    }
return steps;
 }


 int main(int argc,char**argv){

     int n;
     cin>>n;
     vector<int> v(n);
     for(int i=0;i<n;i++){
         cin>>v[i];
     }

     int res=Jump(v);
     cout<<res<<endl;
 }
