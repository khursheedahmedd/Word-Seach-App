//
//  Word.hpp
//  Word Seach App
//
//  Created by Macbook on 14/01/2024.
//

#ifndef Word_hpp
#define Word_hpp
#include <iostream>
#include<string>
using namespace std;

class Word {
private:
    string word;
    Word* left;
    Word* right;
    
public:
    Word();
    
    void setWord(string);
    string getWord();
    Word* getLeft();
    void setLeft(Word* left);
    Word* getRight();
    void setRight(Word* right);
};

#endif /* Word_hpp */
