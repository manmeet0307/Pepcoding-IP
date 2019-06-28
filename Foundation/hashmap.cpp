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

                double lambda = (n*1.0)/N;
                if(lambda > 2.0)
                {
                    rehash();

                     bi = getbucketindex(key);
                     distr = getdataindex(bi , key);
                }

                return buckets[bi].back().value;
            }
            else{
                return distr->value;
            }
        }

        void rehash()
        {

            list<hmnode> * oba = buckets;
            int oldn = N;
            N = 2*N;

            buckets = new list<hmnode> [N];
            int n = 0;
            for(int bi = 0; bi < oldn ; bi++)
            {
                for(auto ditr = oba[bi].begin() ; ditr != oba[bi].end() ; ditr++)
                {
                    (*this)[ditr->key] = ditr->value;
                }
            }
        }
        void display()
        {
            for(int bi = 0; bi < N ; bi++)
            {
                for(auto ditr = buckets[bi].begin() ; ditr != buckets[bi].end() ; ditr++)
                {
                    cout<<bi<<" "<<ditr->key<<" " <<ditr->value<<endl;
                }
            }
        }
};
int main()
{
    hm<string,int> h;
    h["i"] = 1;
    h["h"] = 1;h["g"] = 1;h["f"] = 1;h["e"] = 1;h["d"] = 1;h["c"] = 1;h["b"] = 1;h["a"] = 1;
    h.display();
}
