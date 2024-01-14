//
//  wordTree.cpp
//  Word Seach App
//
//  Created by Macbook on 14/01/2024.
//

#include "wordTree.hpp"

wordTree::wordTree() {
    root = NULL;
}

void wordTree::insertWord(string word) {
    Word* newWord = new Word();
    newWord->setWord(word);
    
    if (root == NULL) {
        root = newWord;
        return;
    }
    
    Word* current = root;
    Word* parent = nullptr;
    
    while (current != NULL) {
        parent = current;

        if (newWord->getWord() < current->getWord()) {
            current = current->getLeft();
        } else {
            current = current->getRight();
        }
    }

    if (newWord->getWord() < parent->getWord()) {
        parent->setLeft(newWord);
    } else {
        parent->setRight(newWord);
    }

}


void wordTree::search(string word) {
    if(root == NULL) {
        cout<<"\nThe word tree is empty.";
        return;
    }
    
    Word* current = root;
    
    while(current != NULL) {
        if(word < current->getWord()) {
            if(current->getWord() == word) {
                cout<<"\n"<<word<<" is found in tree.";
                return;
            }
            else {
                current = current->getLeft();
            }
        }
        else {
            if(current->getWord() == word) {
                cout<<"\n"<<word<<" is found in tree.";
                return;
            }
            else {
                current = current->getRight();
            }
        }
    }
    cout<<"\n"<<word<<" is not found in tree.";
}

void wordTree::displayPreOrder(Word* word) {
    if(root == NULL) {
        cout<<"\nThe tree is empty.";
        return;
    }
    
    if(word != NULL) {
        cout<<word->getWord()<<" ";
        displayPreOrder(word->getLeft());
        displayPreOrder(word->getRight());
    }
}

void wordTree::displayInOrder(Word* word) {
    if (root == NULL) {
        cout << "\nThe tree is empty.";
        return;
    }

    if (word != NULL) {
        displayInOrder(word->getLeft());
        cout << word->getWord() << " ";
        displayInOrder(word->getRight());
    }
}

void wordTree::displayPostOrder(Word* word) {
    if (root == NULL) {
        cout << "\nThe tree is empty.";
        return;
    }

    if (word != NULL) {
        displayPostOrder(word->getLeft());
        displayPostOrder(word->getRight());
        cout << word->getWord() << " ";
    }
}

void wordTree::deleteWord(string word) {
      root = deleteRecursive(root, word);
  }


Word* wordTree::deleteRecursive(Word* node,string word) {
      if (node == nullptr) {
          cout<<"\nThe word not found.";
          return nullptr;
      }

      if (word < node->getWord()) {
          node->setLeft(deleteRecursive(node->getLeft(), word));
      } else if (word > node->getWord()) {
          node->setRight(deleteRecursive(node->getRight(), word));
      } else {
          if (node->getLeft() == nullptr) {
              Word* temp = node->getRight();
              delete node;
              return temp;
          } else if (node->getRight() == nullptr) {
              Word* temp = node->getLeft();
              delete node;
              return temp;
          }

          Word* temp = findMin(node->getRight());

          node->setWord(temp->getWord());

          node->setRight(deleteRecursive(node->getRight(), temp->getWord()));
      }
    return node;
  }

Word* wordTree::findMin(Word* node) {
    while (node->getLeft() != nullptr) {
        node = node->getLeft();
    }
    return node;
}

int wordTree::calculateHeight(Word* node) {
    if (node == nullptr) {
        return 0;
    }

    int leftHeight = calculateHeight(node->getLeft());
    int rightHeight = calculateHeight(node->getRight());

    return 1 + std::max(leftHeight, rightHeight);
}

string wordTree::findShortestWord() {
    if (root == nullptr) {
        cout << "\nThe tree is empty.";
        return ""; 
    }

    Word* current = root;
    string shortest = "";

    while (current != nullptr) {
        if (current->getLeft() == nullptr) {
            string currentWord = current->getWord();
            if (shortest.empty() || currentWord.length() < shortest.length()) {
                shortest = currentWord;
            }
            current = current->getRight();
        } else {
            Word* predecessor = current->getLeft();
            while (predecessor->getRight() != nullptr && predecessor->getRight() != current) {
                predecessor = predecessor->getRight();
            }

            if (predecessor->getRight() == nullptr) {
                predecessor->setRight(current);
                current = current->getLeft();
            } else {
                predecessor->setRight(nullptr);
                string currentWord = current->getWord();
                if (shortest.empty() || currentWord.length() < shortest.length()) {
                    shortest = currentWord;
                }
                current = current->getRight();
            }
        }
    }

    return shortest;
}

string wordTree::findMaxLengthWord() {
    if (root == nullptr) {
        cout << "\nThe tree is empty.";
        return "";
    }

    Word* current = root;
    string maxLengthWord = "";

    while (current != nullptr) {
        if (current->getLeft() == nullptr) {
            string currentWord = current->getWord();
            if (currentWord.length() > maxLengthWord.length()) {
                maxLengthWord = currentWord;
            }
            current = current->getRight();
        } else {
            Word* predecessor = current->getLeft();
            while (predecessor->getRight() != nullptr && predecessor->getRight() != current) {
                predecessor = predecessor->getRight();
            }

            if (predecessor->getRight() == nullptr) {
                predecessor->setRight(current);
                current = current->getLeft();
            } else {
                predecessor->setRight(nullptr);
                string currentWord = current->getWord();
                if (currentWord.length() > maxLengthWord.length()) {
                    maxLengthWord = currentWord;
                }
                current = current->getRight();
            }
        }
    }

    return maxLengthWord;
}
