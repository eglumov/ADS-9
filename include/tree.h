// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

#include <vector>

struct Node {
    char val;
    std::vector<Node*> children;
    explicit Node(char v) : val(v) {}
};

class PMTree {
 private:
    Node* root;
    void buildRecursive(Node* current, std::vector<char> remaining);
    void deleteTree(Node* node);

 public:
    explicit PMTree(std::vector<char> in);
    ~PMTree();
    Node* getRoot() const { return root; }
};

std::vector<std::vector<char>> getAllPerms(const PMTree& tree);
std::vector<char> getPerm1(const PMTree& tree, int num);
std::vector<char> getPerm2(const PMTree& tree, int num);

#endif  // INCLUDE_TREE_H_
