/*
 * A trie (pronounced as "try") or prefix tree is a tree data structure used to
 * efficiently store and retrieve keys in a dataset of strings. There are
 * various applications of this data structure, such as autocomplete and
 * spellchecker. Implement the Trie class:
 * - Trie() Initializes the trie object.
 * - void insert(String word) Inserts the string word into the trie.
 * - boolean search(String word) Returns true if the string word is in the trie
 * (i.e., was inserted before), and false otherwise.
 * - boolean startsWith(String prefix) Returns true if there is a previously
 * inserted string word that has the prefix prefix, and false otherwise.
 */
/*
 * Constraints:
 * 1) 1 <= word.length, prefix.length <= 2000
 * 2) word and prefix consist only of lowercase English letters.
 * 3) At most 3 * 10^4 calls in total will be made to insert, search, and
 * startsWith.
 */

#include <cstddef>
#include <string>

class TrieNode {
public:
  // pointer array for child nodes of each node
  TrieNode *children[26];

  // Used for indicating ending of string
  bool isLeaf;

  TrieNode() {

    // initialize the wordEnd variable with false
    // initialize every index of childNode array with NULL
    isLeaf = false;
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
  }
};

class Trie {
  TrieNode *root;

public:
  Trie() : root(new TrieNode()) {}

  ~Trie() { releaseTrie(root); }

  void releaseTrie(TrieNode *node) {
    for (int i = 0; i < 26; i++) {
      if (node->children[i] != nullptr)
        releaseTrie(node->children[i]);
    }

    delete node;
  }

  void insert(const std::string &word) {
    TrieNode *curr = root;
    for (char c : word) {
      if (curr->children[c - 'a'] == nullptr) {
        TrieNode *newNode = new TrieNode();
        curr->children[c - 'a'] = newNode;
      }

      curr = curr->children[c - 'a'];
    }

    curr->isLeaf = true;
  }

  bool search(const std::string &word) {
    TrieNode *curr = root;
    for (char c : word) {
      if (curr->children[c - 'a'] == nullptr)
        return false;

      curr = curr->children[c - 'a'];
    }

    return curr->isLeaf;
  }

  bool startsWith(const std::string &prefix) {
    TrieNode *curr = root;
    for (char c : prefix) {
      if (curr->children[c - 'a'] == nullptr)
        return false;
      curr = curr->children[c - 'a'];
    }

    return true;
  }
};