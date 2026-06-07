// Copyright 2022 NNTU-CS
#include <iostream>
#include <fstream>
#include <locale>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include "tree.h"

Tree::Tree(std::vector<char> in) {
    std::sort(in.begin(), in.end());
    root = new Node('*');
    buildRecursive(root, in);
}

void Tree::buildRecursive(Node* current, std::vector<char> remaining) {
    if (remaining.empty()) return;
    for (size_t i = 0; i < remaining.size(); ++i) {
        Node* child = new Node(remaining[i]);
        current->children.push_back(child);
        std::vector<char> next_remaining = remaining;
        next_remaining.erase(next_remaining.begin() + i);
        buildRecursive(child, next_remaining);
    }
}

Tree::~Tree() {
    deleteTree(root);
}

void Tree::deleteTree(Node* node) {
    if (!node) return;
    for (auto child : node->children) {
        deleteTree(child);
    }
    delete node;
}

static void dfs(Node* node, std::vector<char>& current,
                std::vector<std::vector<char>>& result) {
    if (node->val != '*') current.push_back(node->val);
    if (node->children.empty()) {
        if (!current.empty()) result.push_back(current);
    } else {
        for (auto child : node->children) {
            dfs(child, current, result);
        }
    }
    if (node->val != '*') current.pop_back();
}

std::vector<std::vector<char>> getAllPerms(const Tree& tree) {
    std::vector<std::vector<char>> result;
    std::vector<char> current;
    dfs(tree.getRoot(), current, result);
    return result;
}

std::vector<char> getPerm1(const Tree& tree, int num) {
    std::vector<std::vector<char>> all = getAllPerms(tree);
    if (num <= 0 || num > static_cast<int>(all.size())) {
        return std::vector<char>();
    }
    return all[num - 1];
}

static long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; ++i) res *= i;
    return res;
}

std::vector<char> getPerm2(const Tree& tree, int num) {
    std::vector<char> result;
    Node* current = tree.getRoot();
    if (!current) return result;

    int n = static_cast<int>(current->children.size());
    if (num <= 0 || num > factorial(n)) return result;

    int current_num = num - 1;
    while (!current->children.empty()) {
        int fact = static_cast<int>(factorial(n - 1));
        int index = current_num / fact;
        current_num %= fact;
        current = current->children[index];
        result.push_back(current->val);
        n--;
    }
    return result;
}
