#include<iostream>
 #include<vector>
 using namespace std;
 vector<pair<string , int> > v{{"I" , 1} ,{"IV" , 4} ,{"V" , 5} ,{"IX" , 9} ,{"X" , 10} ,{"XL" , 40} ,{"L" , 50} ,{"XC" , 90}
 ,{"C" , 100} ,{"CD" , 400} ,{"D" , 500} ,{"CM" , 900} ,{"M" , 1000} };
 string intToRoman(int num) {
        int ptr = v.size()-1;
        string ans ; int n = num;
        while(n>0)
        {
            if(v[ptr].second <= n)
            {
                n = n - v[ptr].second;
                ans += v[ptr].first;
            }
            else
            {
                ptr--;
            }
        }
        return ans;
 }

 int main(int argc,char** argv ){

     int num ;
     cin>>num;
     cout<<intToRoman(num)<<endl;

 }
