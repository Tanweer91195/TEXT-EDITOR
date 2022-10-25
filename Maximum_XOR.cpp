/*
To solve this problem let’s consider a subproblem and use the same approach to solve the above problem.

Q. Given an array of non-negative integer arr1 and a number x.find the maximum XOR value of (arr[i]^x).

Approach:

Step-I: Insert all the elements of arr1 into TRIE.

Step-II: Take x and find the maximum number from the arr1 where x^arr[i] is maximum.

Insertion into TRIE:

While inserting the number’s into the trie consider the binary format (Integer – 32bit) of the arr[i] and treat it as a string and insert the value. 

Let’s try to understand the insertion into trie by considering only 5bit’s but while coding we have to code it for 32bit.

arr[]:[9, 8, 7, 5, 4]

The binary format of the above array is as shown below.

    9             8             7              5             4

arr[ ]:[“01001”, “01000”, “00111”, “00101”, “00100”]

Insertion of 9 – “ 01001 ”
*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
struct Node {
  Node * links[2];
 
  bool containsKey(int ind) {
    return (links[ind] != NULL);
  }
  Node * get(int ind) {
    return links[ind];
  }
  void put(int ind, Node * node) {
    links[ind] = node;
  }
};
class Trie {
  private: Node * root;
  public:
    Trie() {
      root = new Node();
    }
 
  public:
    void insert(int num) {
      Node * node = root;
      // cout << num << endl; 
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (!node -> containsKey(bit)) {
          node -> put(bit, new Node());
        }
        node = node -> get(bit);
      }
    }
  public:
    int findMax(int num) {
      Node * node = root;
      int maxNum = 0;
      for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (node -> containsKey(!bit)) {
          maxNum = maxNum | (1 << i);
          node = node -> get(!bit);
        } else {
          node = node -> get(bit);
        }
      }
      return maxNum;
    }
};
int maxXOR(int n, int m, vector < int > & arr1, vector < int > & arr2) {
  Trie trie;
  for (int i = 0; i < n; i++) {
    trie.insert(arr1[i]);
  }
  int maxi = 0;
  for (int i = 0; i < m; i++) {
    maxi = max(maxi, trie.findMax(arr2[i]));
  }
  return maxi;
}
int main() {
  vector < int > arr1 = {6, 8};
  vector < int > arr2 = {7, 8, 2};
  int n = 2, m = 3;
  cout << maxXOR(n, m, arr1, arr2) << endl;
  return 0;
}
