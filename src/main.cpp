// Copyright 2022 NNTU-CS
#include <chrono>
#include <iostream>
#include <vector>
#include "tree.h"

int main() {
    std::vector<char> in = {'1', '2', '3'};
    Tree tree(in);

    auto p1 = getPerm1(tree, 2);
    auto p2 = getPerm2(tree, 2);

    for (char c : p1) std::cout << c;
    std::cout << std::endl;
    for (char c : p2) std::cout << c;
    std::cout << std::endl;

    return 0;
}
