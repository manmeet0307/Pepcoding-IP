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
         cout<<str<<" ";}
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
 void preorder(struct MinHeapNode* root)
 {
     if(root==NULL)
       return ;
      if(root->left == NULL && root->right ==NULL)
      {
          cout<<codes[root->data];
          return ;
      }
      preorder(root->left);
      preorder(root->right);
 }
 string decodeString(struct MinHeapNode* root, string s){
    //  string ans;
    //  for(int i = 0 ; i<s.length() ;i++ )
    //  {
    //      ans += codes[s[i]] + " ";
    //  }
    //  return ans;
    preorder(root);
 }



 int main()
 {
 	 minHeap=priority_queue <MinHeapNode*, vector<MinHeapNode*>, compare >();
     string str;
 	 cin>>str;
 	 for(int i = 0 ; i < str.length() ; i++)
 	 {
 	     int num;
 	     cin>>num;
 	     freq[str[i]] = num;
 	 }
        HuffmanCodes(str.length());
//    //  for (auto i: str)
//    //      encodedString+=codes[i];
//
//    //  //cout << "Encoded Huffman data:" << encodedString << endl;
//     decodedString = decodeString(minHeap.top(), str);
//     cout << decodedString << endl;
//     return 0;
// }  return 0;

//storeCodes(root,str);
}
