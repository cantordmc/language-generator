#ifndef MARKOV_H
#define MARKOV_H
#include <vector>
#include <string>
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
                int linkCount;

                /**
                 * Number of links to each child
                 */
                vector<Node*> childNodes;

                /**
                 * Pointer to the node's children
                 */
                vector<Node*> childNodes;

                /**
                 * Node constructor, which initializes everything
                 */
                Node(string ab) : data(ab), linkCount(0) {}

                
                void connectTo(Node*);

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

        Node* fetchNode(string ab);

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
