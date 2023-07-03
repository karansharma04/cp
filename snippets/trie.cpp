#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
  unordered_map<char, TrieNode*> children;
  bool isEndOfWord = false;
};

class Trie {
  private:
  void destroy(TrieNode* t) {
    for(auto x: t->children) {
      destroy(x.second);
    }
    delete t;
  }
  void addMatches(vector<string>& ans, TrieNode* t, string& curr_str) {
    if(t->isEndOfWord) {
      ans.push_back(curr_str);
      return;
    }
    for(auto x: t->children) {
      curr_str+=x.first;
      addMatches(ans, x.second, curr_str);
      curr_str.pop_back();
    }
  }
  public:
  TrieNode* root;
  Trie() {
    root = new TrieNode();
  }
  void insert(string word) {
    TrieNode* current = root;
    for(auto ch: word) {
      if(current->children.find(ch)==current->children.end()) {
        current->children[ch] = new TrieNode;
      }
      current = current->children[ch];
    }
    current->isEndOfWord = true;
  }
  bool hasWord(string word) {
    TrieNode* current = root;
    for(auto ch: word) {
      if(current->children.find(ch)==current->children.end()) {
        return false;
      }
      current = current->children[ch];
    }
    return current->isEndOfWord;
  }

  bool hasPrefix(string word) {
    TrieNode* current = root;
    for(auto ch: word) {
      if(current->children.find(ch)==current->children.end()) {
        return false;
      }
      current = current->children[ch];
    }
    return true;
  }
  vector<string> matches(string word) {
    vector<string> ans;
    string curr_string = "";
    TrieNode* current = root;
    for(auto ch: word) {
      if(current->children.find(ch)==current->children.end()) {
        return ans;
      }
      current = current->children[ch];
    }
    curr_string+=word;
    addMatches(ans, current, curr_string);
    return ans;
  }
  ~Trie() {
    destroy(root);
  }
};

int main() {
    Trie t;
    t.insert("Karan");
    t.insert("Karalala");
    t.insert("Sharma");
    t.insert("Shama");
    t.insert("Sharra");
    vector<string> ans = t.matches("Shar");
    for(auto x: ans) cout<<x<<endl;
}