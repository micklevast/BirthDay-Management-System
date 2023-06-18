#include "a4_birthdayBST.hpp"
#include "a4_birthdaylib.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
using namespace std;

// //internal recursive insert function
        BirthdayBSTreeNode* BirthdayBST::insertNode_rec(BirthdayBSTreeNode* node,
                                        Birthday* value){
            if(node == NULL){
                return newNode(value);
            }
            if(value->year < node->value->year){
                node->left = insertNode_rec(node->left, value);
                node->left->parent = node;
            }
            else if(value->year > node->value->year){
                node->right = insertNode_rec(node->right, value);
                node->right->parent = node;
            }
            else if(value->month < node->value->month){
                node->left = insertNode_rec(node->left, value);
                node->left->parent = node;
            }
            else if(value->month > node->value->month){
                node->right = insertNode_rec(node->right, value);
                node->right->parent = node;
            }
            else if(value->day < node->value->day){
                node->left = insertNode_rec(node->left, value);
                node->left->parent = node;
            }
            else if(value->day > node->value->day){
                node->right = insertNode_rec(node->right, value);
                node->right->parent = node;
            }
            else if(value->name < node->value->name){
                node->left = insertNode_rec(node->left, value);
                node->left->parent = node;
            }
            else if(value->name > node->value->name){
                node->right = insertNode_rec(node->right, value);
                node->right->parent = node;
            }
            else{
                cout << "Duplicate entry found: " << value->name << " " << value->month << "/" << value->day << "/" << value->year << endl;
            }
            return node;
            }
        
//         //internal recursuve remove function
        BirthdayBSTreeNode* BirthdayBST::removeNode_rec(BirthdayBSTreeNode* node,
                                        Birthday* value){
            if(node == NULL){
                return node;
            }
            if(value->year < node->value->year){
                node->left = removeNode_rec(node->left, value);
            }
            else if(value->year > node->value->year){
                node->right = removeNode_rec(node->right, value);
            }
            else if(value->month < node->value->month){
                node->left = removeNode_rec(node->left, value);
            }
            else if(value->month > node->value->month){
                node->right = removeNode_rec(node->right, value);
            }
            else if(value->day < node->value->day){
                node->left = removeNode_rec(node->left, value);
            }
            else if(value->day > node->value->day){
                node->right = removeNode_rec(node->right, value);
            }
            else if(value->name < node->value->name){
                node->left = removeNode_rec(node->left, value);
            }
            else if(value->name > node->value->name){
                node->right = removeNode_rec(node->right, value);
            }
            else{
                if(node->left == NULL){
                    BirthdayBSTreeNode* temp = node->right;
                    delete node;
                    return temp;
                }
                else if(node->right == NULL){
                    BirthdayBSTreeNode* temp = node->left;
                    delete node;
                    return temp;
                }
                BirthdayBSTreeNode* temp = minSuccessor(node->right);
                node->value = temp->value;
                node->right = removeNode_rec(node->right, temp->value);

                }
                return node;
            }
        
//         //internal recursive find function for duplicates, useful for insert
        BirthdayBSTreeNode* BirthdayBST::findNodeByYMDN_rec(BirthdayBSTreeNode* node,
                                        short year, short month, short day,
                                        string name){

            if(node == NULL){
                return NULL;
            }
            if(year < node->value->year){
                return findNodeByYMDN_rec(node->left, year, month, day, name);
            }
            else if(year > node->value->year){
                return findNodeByYMDN_rec(node->right, year, month, day, name);
            }
            else if(month < node->value->month){
                return findNodeByYMDN_rec(node->left, year, month, day, name);
            }
            else if(month > node->value->month){
                return findNodeByYMDN_rec(node->right, year, month, day, name);
            }
            else if(day < node->value->day){
                return findNodeByYMDN_rec(node->left, year, month, day, name);
            }
            else if(day > node->value->day){
                return findNodeByYMDN_rec(node->right, year, month, day, name);
            }
            else if(name < node->value->name){
                return findNodeByYMDN_rec(node->left, year, month, day, name);
            }
            else if(name > node->value->name){
                return findNodeByYMDN_rec(node->right, year, month, day, name);
            }
            else{
                return node;
            }
                                        }
        
//         //internal recursive find function for same month and day, useful for remove
        BirthdayBSTreeNode* BirthdayBST::findNodeByMD_rec(BirthdayBSTreeNode* node,
                                        short month, short day){
            if(node == NULL){
                return NULL;
            }
            if(month < node->value->month){
                return findNodeByMD_rec(node->left, month, day);
            }
            else if(month > node->value->month){
                return findNodeByMD_rec(node->right, month, day);
            }
            else if(day < node->value->day){
                return findNodeByMD_rec(node->left, month, day);
            }

            else if(day > node->value->day){
                return findNodeByMD_rec(node->right, month, day);
            }
            else{
                return node;
            }

                                        }   
                                                

//         //internal recursive print function with matching month and day
        void BirthdayBST::printAllNodeWithMatchingMD_rec(BirthdayBSTreeNode* node, ostream& os,
                                        short month, short day){
            if(node == NULL){
                return;
            }
            BirthdayBST::printAllNodeWithMatchingMD_rec(node->left, os, month, day);
            if(node->value->month == month && node->value->day == day){
                os << node->value->name << " " << node->value->month << "/" << node->value->day << "/" << node->value->year << endl;
            }
            BirthdayBST::printAllNodeWithMatchingMD_rec(node->right, os, month, day);
                                        }
                
//         //internal recursive print function performing an in-order traversal
        void BirthdayBST::inOrderPrint_rec(BirthdayBSTreeNode* node, ostream& os){
            if(node == NULL){
                return;
            }
            BirthdayBST::inOrderPrint_rec(node->left, os);
            os << node->value->year << "-" << node->value->month << "-" << node->value->day << "\n" << node->value->name << endl << node->value->knownFor<< endl<<"====================================================\n";
            BirthdayBST::inOrderPrint_rec(node->right, os);

        }
                
//         //internal recursive delete function releasing memory use by the tree
//         //also releases the Birthday structs along the way
        
        void BirthdayBST::deleteTree_rec(BirthdayBSTreeNode* node){
            if(node == NULL){
                return;
            }
            BirthdayBST::deleteTree_rec(node->left);
            BirthdayBST::deleteTree_rec(node->right);
            delete node->value;
            delete node;
        }
        
//         //internal helper function for creating a new tree node
        BirthdayBSTreeNode* BirthdayBST::newNode(Birthday* value){
            BirthdayBSTreeNode* node = new BirthdayBSTreeNode;
            node->value = value;
            node->left = NULL;
            node->right = NULL;
            return node;
        }
        
//         //internal helper function for finding the minimal successor, used by remove
        BirthdayBSTreeNode* BirthdayBST::minSuccessor(BirthdayBSTreeNode* node){
            BirthdayBSTreeNode* current = node;
            while(current->left != NULL){
                current = current->left;
            }
            return current;
        }

        
        BirthdayBST::BirthdayBST(){
            root = NULL;
            size = 0;
        }

        //return the size of the tree
        int BirthdayBST::getSize(){
            return size;
        }

        //insert the Birthday entry to the tree
        void BirthdayBST::insertNode(Birthday* value){
            root = insertNode_rec(root, value);
            size++;
        }

        //remove a node with matching content from the tree, return the data
        Birthday* BirthdayBST::removeNode(Birthday* value){
            Birthday* temp = findNodeByYMDN(value->year, value->month, value->day, value->name);
            if(temp != NULL){
                root = removeNode_rec(root, value);
                size--;
            }
            return temp;
        }
        //find a node with matching year, month, day, and name, return the data
        Birthday* BirthdayBST::findNodeByYMDN(short year, short month, short day,
                                string name){
            BirthdayBSTreeNode* temp = findNodeByYMDN_rec(root, year, month, day, name);
            if(temp != NULL){
                return temp->value;
            }
            return NULL;
        }
        
        //find a matching node with month and date, return the data
        Birthday* BirthdayBST::findNodeByMD(short month, short day){
            BirthdayBSTreeNode* temp = findNodeByMD_rec(root, month, day);
            if(temp != NULL){
                return temp->value;
            }
            return NULL;
        }
        
        //print all content with matching node with month and day
        
        void BirthdayBST::printAllNodeWithMatchingMD(short month, short day, ostream& os){
            printAllNodeWithMatchingMD_rec(root, os, month, day);
        }
        
        
        //performs an in-order traversal and print the content to the output stream
        void BirthdayBST::inOrderPrint(ostream& os){
            inOrderPrint_rec(root, os);
        }

        //delete all nodes in the tree
        //destructor
        BirthdayBST::~BirthdayBST(){
            deleteTree_rec(root);
        }
