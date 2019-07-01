#include<iostream>
 #include<vector>
 #include<bits/stdc++.h>
 using namespace std;
    unordered_map<char,int> m;
   void initialise(){
    for(int i = 0; i <= 9 ;i ++)
    {
        m[i + '0'] = i;
    }
    m['a']=10;
    m['b']=11;
    m['c']=12;
    m['d']=13;
    m['e']=14;
    m['f']=15;
   }
 string closest(string s1, string s2,string color)
 {
     int d1 = m[s1[0]] * 16 + m[s1[1]];
     int d2 = m[s2[0]] * 16 + m[s2[1]];
     int main = m[color[0]] * 16 + m[color[1]];
        cout<<"color code: "<<color << " " <<m[color[0]]<<" " <<m[color[1]]<<endl;
     cout<<"closert: "<<d1<<" " <<d2<< " "<<main<<endl;
     if(abs(main-d1) <= abs(main-d2))
     {
         return s1;
     }
     else
        return s2;

 }

 string retclosest(string color)
 {
    cout<<"hm value: "<<m[color[1]] << "  "<< m[color[0]]<<endl;
    if(m[color[0]] < m[color[1]])
    {
       string op1 ="";
       op1 = op1 + color[0] + color[0] + "";
       string op2= "";
       if(color[0] != 'f' && color[0] != '9')
        op2 = op2 + (char)( color[0] + 1 ) + (char)( color[0] + 1 );
        else if(color[0] == '9')
        {
            op2 = "aa";
        }
        else
            op2 = "00";

     cout<<"if1 "<<op1<<" " <<op2<<endl;
        return closest(op1,op2,color);
    }
    else
    {
       string op1 ="";
       op1 = op1 + color[0] + color[0] + "";
       string op2 = "";
       if(color[0] != '0' && color[0]!='a')
        op2 = op2 + (char)( color[0] - 1 ) + (char)( color[0] - 1 );
        else if(color[0] == 'a')
        {
             op2 = "99";
        }
        else
            op2 = "ff";
   //  cout<<"if2 "<<op1<<" " <<op2<<endl;
       return closest(op1,op2,color);
    }
 }
 string similarRGB(string &color) {
    color = color.substr(1,color.length()-1);
    initialise();
    unordered_map<char,int> :: iterator it;
    for(it = m.begin() ; it!= m.end() ; it++)
    {
        cout<<it->first<<" " <<it->second<<endl;
    }
    string ans;
    for(int i = 0 ; i < color.size() ; i+=2)
    {
        string t = color.substr(i,2);
     //   cout<<t<<" " ;
       ans += retclosest(t);
     //  cout<<ans <<endl;
    }
    return ans;
 }


 int main(int argc,char** argv){
//string m = "01bc12";
//string o ="";
//o = o + m[0] + m[1] ;
//cout<<o;
     string color;
     cin>>color;
    cout<<"#"<<similarRGB(color)<<endl;
}

