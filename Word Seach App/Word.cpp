//
//  Word.cpp
//  Word Seach App
//
//  Created by Macbook on 14/01/2024.
//

#include "Word.hpp"

Word::Word() {
    left = NULL;
    right = NULL;
}

void Word::setWord(string word) {
    this->word = word;
}
string Word::getWord() {
    return word;
}

void Word::setLeft(Word* left) {
    this->left = left;
}
Word* Word::getLeft() {
    return left;
}

void Word::setRight(Word* right) {
    this->right = right;
}
Word* Word::getRight() {
    return right;
}

