 #include<iostream>
 #include<unordered_map>
 #include<vector>
 #include<queue>
 #define MAX_TREE_HT 256
 using namespace std;
 struct MinHeapNode
 {
     char data;
     int freq;
     MinHeapNode *left, *right;

     MinHeapNode(char data, int freq)
     {
         left = right = NULL;
         this->data = data;
         this->freq = freq;
     }
 };
 struct compare
 {
     bool operator()(MinHeapNode* l, MinHeapNode* r)
     {
         return (l->freq > r->freq);
     }
 };


 unordered_map<char, string> codes;
 unordered_map<char, int> freq;   //parse feeder to make fmap
 priority_queue< MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

 void storeCodes(struct MinHeapNode* root, string str)
 {
     if (root==NULL)
         return;
     if (root->data != '$'){
         codes[root->data]=str;
        // cout<<str<<" ";
        }
     storeCodes(root->left, str + "0");
     storeCodes(root->right, str + "1");
 }

 void HuffmanCodes(int size)
 {
     struct MinHeapNode *left, *right, *top;
     for (unordered_map<char, int>::iterator v=freq.begin(); v!=freq.end(); v++)
         minHeap.push(new MinHeapNode(v->first, v->second));
     while (minHeap.size() != 1)
     {
         left = minHeap.top();
         minHeap.pop();
         right = minHeap.top();
         minHeap.pop();
         top = new MinHeapNode('$', left->freq + right->freq);
         top->left = left;
         top->right = right;
         minHeap.push(top);
     }
     storeCodes(minHeap.top(), "");
 }
 string decodeString(struct MinHeapNode* root, string s){
    string ans;
    struct MinHeapNode* curr = root;
    for(int i = 0 ;i < s.length();i++)
    {
        if(s[i]=='0')
        {
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
        if(curr->left == NULL && curr->right == NULL)
        {
            ans += curr->data;
            curr = root;
        }
    }
    return ans;
 }

 void calcFreq(string str, int n)
 {
     for (int i=0; i<str.size(); i++)
         freq[str[i]]++;
 }


 int main()
 {
 	 minHeap=priority_queue <MinHeapNode*, vector<MinHeapNode*>, compare >();
     string str;
 	 cin>>str;
     string encodedString, decodedString;
     calcFreq(str, str.length());
     HuffmanCodes(str.length());
     for (auto i: str)
         encodedString+=codes[i];

     //cout << "Encoded Huffman data:" << encodedString << endl;
     decodedString = decodeString(minHeap.top(), encodedString);
     cout << decodedString << endl;
     return 0;
 }
