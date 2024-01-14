//
//  wordTree.hpp
//  Word Seach App
//
//  Created by Macbook on 14/01/2024.
//

#ifndef wordTree_hpp
#define wordTree_hpp
#include "Word.hpp"

class wordTree {
public:
    Word* root;
    
    wordTree();
    
    void insertWord(string);
    void search(string);
    void displayPreOrder(Word* word);
    void displayInOrder(Word* word);
    void displayPostOrder(Word* word);
    void deleteWord(string);
    Word* deleteRecursive(Word* node,string word);
    Word* findMin(Word* node);
    int calculateHeight(Word* node);
    string findShortestWord();
    string findMaxLengthWord();
};

#endif /* wordTree_hpp */
