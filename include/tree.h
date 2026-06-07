// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>

struct Node {
    char val;
    std::vector<Node*> children;
    explicit Node(char v) : val(v) {}
};

class Tree {
 private:
    Node* root;
    void buildRecursive(Node* current, std::vector<char> remaining);
    void deleteTree(Node* node);

 public:
    explicit Tree(std::vector<char> in);
    ~Tree();
    Node* getRoot() const { return root; }
};

std::vector<std::vector<char>> getAllPerms(const Tree& tree);
std::vector<char> getPerm1(const Tree& tree, int num);
std::vector<char> getPerm2(const Tree& tree, int num);

#endif  // INCLUDE_TREE_H_
