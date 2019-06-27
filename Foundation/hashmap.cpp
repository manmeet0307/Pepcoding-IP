#include<bits/stdc++.h>
using namespace std;
template <typename k , typename v>
class hm{
private :
    int n , N;
    class hmnode
    {
     private:

        public:
        k key;
        v value;
        hmnode(k key , v value)
        {
            this->key = key;
            this->value = value;
        }
    };

    list<hmnode> * buckets = NULL;
     public:
        hm()
        {
            n = 0;
            N = 4;
            buckets = new list<hmnode>[N];
        }
        int getbucketindex(k key)
        {
            int hc = hash<k>()(key);
            hc = abs(hc);
            hc = hc % N;
            return hc;
        }
        int count(k key)
        {
          int bi = getbucketindex(key);
          auto distr = getdataindex(bi , key);

          if(distr == buckets[bi].end())
          {
              return 0;
          }
          else
          {
              return 1;
          }
        }

        typename list<hmnode> :: iterator getdataindex(int bi , k key)
        {
            for(auto itr = buckets[bi].begin();itr != buckets[bi].end() ;itr++)
            {
                if(itr->key == key)
                {
                    return itr;
                }
            }
            return buckets[bi].end();
        }

        v& operator[](const k& key)
        {
           int bi = getbucketindex(key);
            auto distr = getdataindex(bi , key);

            if(distr == buckets[bi].end())
            {

                hmnode node(key,v());
                buckets[bi].push_back(node);
                n++;

                return buckets[bi].back().value;
            }
            else{

                return distr->value;
            }
        }
};
int main()
{
    hm<string,int> h;
    h["india"] = 1;
    cout<<h["india"];
}
