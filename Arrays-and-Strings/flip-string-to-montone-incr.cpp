class Solution {
public:
    int minFlipsMonoIncr(string S) {
        vector<int> a (S.length() - 1), b(S.length() - 1);// a = 01 , b = 11
      // 00 11 10 01
      if(S[0] == '0' && S[1] == '0')
      {
         a[0] = 1;
         b[0] = 0;
      }
      else if(S[0] == '0' && S[1] == '1')
      {
         a[0] = 0;
         b[0] = 1;
      }
      else if(S[0] == '1' && S[1] == '0')
      {
         a[0] = 2;
         b[0] = 1;
      }
      else if(S[0] == '1' && S[1] == '1')
      {
         a[0] = 1;
         b[0] = 2;
      }
      for(int i = 2 ; i  < S.length() ; i++)
      {
          if(S[i] == '1')
          {
              a[i-1] = min(a[i-2] , b[i-2]);
              b[i-1] = b[i-2] + 1;
          }
          else
          {
              a[i-1] = min(a[i-2] , b[i-2]) + 1;
              b[i-1] = b[i-2];
          }
      }
      int op1 = a[S.length() - 2];
      int op2 = b[S.length() - 2];
      int op3 = S.length() - op2;
      return min(op1,min(op2,op3));
    }
};
