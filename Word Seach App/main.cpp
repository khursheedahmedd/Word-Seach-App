//
//  main.cpp
//  Word Seach App
//
//  Created by Macbook on 13/01/2024.
//

#include <iostream>
#include "wordTree.hpp"

int main() {
    wordTree* tree = new wordTree();
    
    int choice;

    do {
        cout<<"\n******** Word Tree *********";
        cout<<"\n* 1. Insert a paragraph    *";
        cout<<"\n* 2. Insert a word         *";
        cout<<"\n* 3. Search a word         *";
        cout<<"\n* 4. Display pre-order     *";
        cout<<"\n* 5. Display in-order      *";
        cout<<"\n* 6. Display post order    *";
        cout<<"\n* 7. Delete a word         *";
        cout<<"\n* 8. Find Height           *";
        cout<<"\n* 9. Max lengtth word      *";
        cout<<"\n* 10. Minimum length word  *";
        cout<<"\n* 11. Exit                 *";
        cout<<"\n****************************";
        cout<<"\nEnter your choice: ";
        cin>>choice;
        
        switch(choice) {
            case 1: {
                cin.ignore();
                string paragraph;
                cout<<"\nEnter a paragraph to insert: ";
                getline(cin,paragraph);
                char* cParagraph = new char[paragraph.size() + 1];
                strcpy(cParagraph, paragraph.c_str());
                
                char* token = strtok(cParagraph, " .");
                
                while (token != nullptr) {
                    string word(token);
                    tree->insertWord(word);
                    token = strtok(nullptr, " .");
                }
                break;
                }
            case 2: {
                string str;
                cout<<"\nEnter a word to insert: ";
                cin>>str;
                
                tree->insertWord(str);
                break;
            }
            case 3: {
                string str;
                cout<<"\nEnter a word to search: ";
                cin>>str;
                
                tree->search(str);
                break;
            }
            case 4: {
                cout<<"\nDisplaying pre-order: ";
                tree->displayPreOrder(tree->root);
                break;
            }
            case 5: {
                cout<<"\nDisplaying in-order: ";
                tree->displayInOrder(tree->root);
                break;
            }
            case 6: {
                cout<<"\nDisplaying post order: ";
                tree->displayPostOrder(tree->root);
                break;
            }
            case 7: {
                string word;
                cout<<"\nEnter a word to delete : ";
                cin>>word;
                
                tree->deleteWord(word);
                break;
            }
            case 8: {
                int height = tree->calculateHeight(tree->root) - 1;
                if(height > -1)
                    cout<<"\nThe height of the tree is : "<<height;
                else
                    cout<<"\nThe tree is empty.";
                break;
            }
            case 9: {
                cout<<"\nThe maximum length word is: "<<tree->findMaxLengthWord();
                break;
            }
            case 10: {
                cout<<"\nThe minimum length word is: "<<tree->findShortestWord();
                break;
            }
            case 11: {
                cout<<"\nExiting.....\n";
                delete tree;
                return 0;
            }
            default:
                cout<<"\nInvalid choice.";
        }
    
    }while(true);
    
    return 0;
}

