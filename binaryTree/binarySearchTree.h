#ifndef BINARYTREE_BINARYSEARCHTREE_H
#define BINARYTREE_BINARYSEARCHTREE_H

#include <iostream>
#include <queue>
#include <stack>
#include <vector>

namespace algo {

template <typename Key, typename Value> struct BSTNode {
  Key key;
  Value val;
  BSTNode *left, *right;

  BSTNode(Key key, Value val)
      : key(key), val(val), left(nullptr), right(nullptr) {}

  BSTNode(BSTNode *node)
      : key(node->key), val(node->val), left(node->left), right(node->right) {}
};

template <typename Key, typename Value> class BST {
public:
  BST() : root(nullptr), _size(0) {}
  ~BST() { destroy(root); }

  /* write */
  void insert(Key key, Value val) { root = insert(root, key, val); }
  void remove_minimum() { root = remove_minimum(root); }
  void remove_maximum() { root = remove_maximum(root); }
  void remove(Key key) { root = remove(root, key); }

  /* read */
  bool contain(Key key) const { return contain(root, key); }
  Value *search(Key key) const { return search(root, key); }
  Key minimum() const { return minimum(root)->key; }
  Key maximum() const { return maximum(root)->key; }

  /* 应用程序调用以上操作需要先调用以下成员函数判空 */
  int size() const { return _size; }
  bool empty() const { return _size == 0; }

  /* tarvesal */
  std::vector<Key> preOrder() const { return preOrder(root); }
  std::vector<Key> inOrder() const { return inOrder(root); }
  std::vector<Key> postOrder() const { return postOrder(root); }
  std::vector<Key> levelOrder() const { return evelOrder(root); }
  std::vector<Key> print() const { return inOrder(); } // 保持有序性

private:
  BSTNode<Key, Value> *insert(BSTNode<Key, Value> *node, Key key, Value val) {
    if (node == nullptr) {
      _size++;
      return new BSTNode<Key, Value>(key, val);
    }

    if (key == node->key)
      node->val = val;
    else if (key < node->key)
      node->left = insert(node->left, key, val);
    else
      node->right = insert(node->right, key, val);

    return node;
  }

  bool contain(BSTNode<Key, Value> *node, Key key) const {
    if (node == nullptr)
      return false;

    if (key == node->key)
      return true;
    else if (key < node->key)
      return contain(node->left, key);
    else
      return contain(node->right, key);
  }

  Value *search(BSTNode<Key, Value> *node, Key key) const {
    if (node == nullptr)
      return nullptr;

    if (key == node->key)
      return &(node->val);
    else if (key < node->key)
      return search(node->left, key);
    else
      return search(node->right, key);
  }

  BSTNode<Key, Value> *minimum(BSTNode<Key, Value> *node) const {
    while (node->left)
      node = node->left;

    return node;
  }

  BSTNode<Key, Value> *maximum(BSTNode<Key, Value> *node) const {
    while (node->right)
      node = node->right;

    return node;
  }

  BSTNode<Key, Value> *remove_minimum(BSTNode<Key, Value> *node) {
    if (node->left == nullptr) {
      auto rightNode = node->right;
      delete node;
      _size--;
      return rightNode;
    }

    node->left = remove_minimum(node->left);
    return node;
  }

  BSTNode<Key, Value> *remove_maximum(BSTNode<Key, Value> *node) {
    if (node->right == nullptr) {
      auto leftNode = node->left;
      delete node;
      _size--;
      return leftNode;
    }

    node->right = remove_maximum(node->right);
    return node;
  }

  BSTNode<Key, Value> *remove(BSTNode<Key, Value> *node, Key key) {
    if (node == nullptr)
      return nullptr;

    if (key < node->key) {
      node->left = remove(node->left, key);
      return node;
    }

    if (node->key < key) {
      node->right = remove(node->right, key);
      return node;
    }

    /* key == node->key */
    if (node->left == nullptr) {
      auto rightNode = node->right;
      delete node;
      _size--;
      return rightNode;
    }

    if (node->right == nullptr) {
      auto leftNode = node->left;
      delete node;
      _size--;
      return leftNode;
    }

    /* node->left && node->right */
    auto successor = new BSTNode<Key, Value>(minimum(node->right));
    successor->right = remove_minimum(node->right);
    successor->left = node->left;
    delete node;

    return successor;
  }

  std::vector<Key> preOrder(BSTNode<Key, Value> *node) const {
    if (node == nullptr)
      return {};

    std::vector<Key> res;
    std::stack<BSTNode<Key, Value> *> lookup;
    while (node || !lookup.empty()) {
      while (node) {
        res.push_back(node->key);
        lookup.push(node);
        node = node->left;
      }
      if (!lookup.empty()) {
        node = lookup.top()->right;
        lookup.pop();
      }
    }
    return res;
  }

  std::vector<Key> inOrder(BSTNode<Key, Value> *node) const {
    if (node == nullptr)
      return {};

    std::vector<Key> res;
    std::stack<BSTNode<Key, Value> *> lookup;
    while (node || !lookup.empty()) {
      while (node) {
        lookup.push(node);
        node = node->left;
      }
      if (!lookup.empty()) {
        node = lookup.top()->right;
        res.push_back(lookup.top()->key);
        lookup.pop();
      }
    }
    return res;
  }

  std::vector<Key> postOrder(BSTNode<Key, Value> *node) const {
    if (node == nullptr)
      return {};

    std::vector<Key> res;
    std::stack<BSTNode<Key, Value> *> lookup;
    while (node || !lookup.empty()) {
      while (node) {
        res.push_back(node->key);
        lookup.push(node);
        node = node->right;
      }
      if (!lookup.empty()) {
        node = lookup.top()->left;
        lookup.pop();
      }
    }

    reverse(res.begin(), res.end());

    return res;
  }

  std::vector<Key> levelOrder(BSTNode<Key, Value> *node) const {
    if (node == nullptr)
      return {};

    std::vector<Key> res;
    std::queue<BSTNode<Key, Value> *> lookup;
    lookup.push(node);
    while (!lookup.empty()) {
      BSTNode<Key, Value> *cur = lookup.front();
      lookup.pop();
      res.push_back(cur->key);
      if (cur->left)
        lookup.push(cur->left);
      if (cur->right)
        lookup.push(cur->right);
    }

    return res;
  }

  void destroy(BSTNode<Key, Value> *node) {
    if (node) {
      destroy(node->left);
      destroy(node->right);
      delete node;
      _size--;
    }
  }

private:
  BSTNode<Key, Value> *root;
  int _size;
};
} // namespace algo

#endif