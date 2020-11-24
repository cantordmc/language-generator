#ifndef MARKOV_H
#define MARKOV_H
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const unsigned int CHUNK_LENGTH = 2;

/**
 * Class to implement a Binary Search Tree (BST)
 */
class Markov {
    public:
        /**
         * Nested helper Node class
         */
        class Node {
            public:
                /**
                 * The data stored within a node
                 */
                string data;

                /**
                 * Total number of links
                 */
                unsigned int linkCount;

                /**
                 * Pointer to the node's children
                 */
                vector<Node*> childNodes;

                unsigned int numChildren;

                void printChildren();

                unsigned int getChildIndex(string ab);

                /**
                 * Node constructor, which initializes everything
                 */
                Node(string ab) : data(ab), linkCount(0), numChildren(0) {}

                
                void connectTo(Node* node);

                /**
                 * Find the successor of this Node
                 *
                 * @return Node* Pointer to the successor of this Node, or nullptr if none exists
                 */
                Node* traverseOnce();
        };

        /**
         * BST Constructor, which should initialize an empty BST
         */
        Markov(string inputText);

        /**
         * BST Destructor, which should deallocate anything dynamic
         */
        ~Markov();

        Node* getRoot();

        Node* fetchNode(string &ab);

        /**
         * Remove all elements from the Markov network
         */
        void clear();

    private:
        /**
         * Pointer to the root node of this BST
         */
        Node* root;

        vector<Node *> allNodes;

        unsigned int numNodes;

        /**
         * Total number of elements currently in the BST
         */
        unsigned int numLinks;
};
#endif
