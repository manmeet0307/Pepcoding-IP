#include<bits/stdc++.h>
using namespace std;
string got(int n)
{
    vector<string> v{ "" , "Thousand " , "Million " , "Billion " , "Trillion "};
    return v[n];
}
string teens(int n)
{
    vector<string> v{ "" , "One " , "Two " , "Three " , "Four " , "Five " , "Six " , "Seven " ,
     "Eight " , "Nine " , "Ten ", "Eleven ", "Twelve ",
     "Thirteen ", "Fourteen " ,"Fifteen ","Sixteen ", "Seventeen ", "Eighteen ", "Nineteen " };
    return v[n];
}
string tens(int n)
{
    vector<string> v{ "" , "" , "Twenty " , "Thirty " , "Forty " , "Fifty " , "Sixty " , "Seventy " ,
    "Eighty " , "Ninety "
     };

    return v[n];
}
string f2(int num)
{
    string a;

    string n = to_string(num);
    if(n.length() == 1 )
    {
        return teens(num);
    }
    else if( n.length() == 2)
    {
        if(num<20)
        {
            return teens(num);
        }
        else return tens(num/10) + teens(num%10);
    }
    a += teens(n[0]-48) +"Hundred ";
    if(stoi(n.substr(1,2)) >=20)
    {
        a += tens(n[1] - 48);
        a += teens(n[2] - 48);
    }
    else if(stoi(n.substr(1,2)) >=10)
    {
        a += teens(stoi(n.substr(1,2)));
    }
    else{
          a += teens(n[2] - 48) ;

    }
    return a;
}
string f1(int num , int gotl)
{
    if(num == 0 )
    {
        return "";
    }
    return f1(num/1000 , gotl+1)  + f2(num%1000)  + got(gotl);
}
int main()
{
    int num ;
    cin>>num;
    cout<<f1(num,0);
}
