#include "BST.h"

Markov::Node* binarySearch(string ab, vector<Markov::Node*> nodes, unsigned int start, unsigned int end) {
    if (start >= end) {
        return nullptr;
    }
    unsigned int pivot = (start + end)/2;

    Markov::Node* pivotNode = nodes[pivot]
    string pivotData = pivotNode->data;
    if (ab.compare(pivotData) < 0) {
        return binarySearch(ab, nodes, start, pivot)
    }
        
    else if (ab.compare(pivotData) > 0) {
        return binarySearch(ab, nodes, pivot+1, end)
    }
    else {
        return pivotNode;
    }
}

void binaryInsert(ab, allNodes, 0, numNodes)

Markov::fetchNode(string ab) {
    Node* theNode = binarySearch(ab, allNodes, 0, numNodes);
    if (theNode == null){
        theNode = new Node(ab);
        binaryInsert(ab, allNodes, 0, numNodes);
        numNodes += 1;
    }
    return theNode;
}

Markov::Markov(string inputText) {
    root = new Node(" ");
    numNodes = 0;
    numLinks = 0;
    unsigned int length = inputText.length();
    if (length < 2) {
        //ERROR
        return;
    }
    string ab;
    Node* nextNode;
    Node* thisNode = root;
    Node* thisNodeChildren;
    for (unsigned int = 0; i < length - 1; i++) {
        ab = str.substr(i, i+CHUNK_LENGTH);
        nextNode = fetchNode(ab);
    }
}
