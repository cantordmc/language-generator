#include "Markov.h"
#include <iostream>

const bool PRINT_DEBUG = false;

int binarySearch(string &ab, vector<Markov::Node*> &nodes, unsigned int start, unsigned int end) {
    if (start == nodes.size()) {
        if (PRINT_DEBUG) cout << "Did not find node " << ab << endl;
        return -1;
    }
    if (start >= end) {
        Markov::Node* closeNode = nodes[start];
        string closeData = closeNode->data;
        if (ab.compare(closeData) == 0) {
            return start;
        }
        if (PRINT_DEBUG) cout << "Did not find node " << ab << endl;
        return -1;
    }
    unsigned int pivot = (start + end)/2;

    Markov::Node* pivotNode = nodes[pivot];
    string pivotData = pivotNode->data;
    if (ab.compare(pivotData) < 0) {
        return binarySearch(ab, nodes, start, pivot);
    }
        
    else if (ab.compare(pivotData) > 0) {
        return binarySearch(ab, nodes, pivot+1, end);
    }
    else {
        if (PRINT_DEBUG) cout << "Found node " << ab << " at pos " << pivot << endl;
        return pivot;
    }
}

int binaryInsert(Markov::Node* newNode, vector<Markov::Node*> &nodes, unsigned int start, unsigned int end) {
    string ab = newNode->data;
    if (start == nodes.size()) {
        nodes.push_back(newNode);
        if (PRINT_DEBUG) cout << "Inserted node " << ab << " at pos " << start << endl;
        return start;
    }
    if (start >= end) {
        Markov::Node* closeNode = nodes[start];
        string closeData = closeNode->data;
        if (ab.compare(closeData) == 0) {
            nodes.insert(nodes.begin() + start, newNode);
            if (PRINT_DEBUG) cout << "Inserted node " << ab << " at pos " << start << endl;
            return start;
        }
        if (ab.compare(closeData) < 0) {
            vector<Markov::Node*>::iterator newPos = nodes.begin() + start;
            nodes.insert(newPos, newNode);
            if (PRINT_DEBUG) cout << "Inserted node " << ab << " at pos " << start << endl;
            return start;
        }
        else{
            vector<Markov::Node*>::iterator newPos = nodes.begin() + (start+1);
            if (PRINT_DEBUG) cout << "Inserted node " << ab << " at pos " << (start+1) << endl;
            nodes.insert(newPos, newNode);
            return start + 1;
        }
    }
    unsigned int pivot = (start + end)/2;

    Markov::Node* pivotNode = nodes[pivot];
    string pivotData = pivotNode->data;
    if (ab.compare(pivotData) < 0) {
        return binaryInsert(newNode, nodes, start, pivot);
    }
        
    else if (ab.compare(pivotData) > 0) {
        return binaryInsert(newNode, nodes, pivot+1, end);
    }
    else {
        nodes.insert(nodes.begin() + pivot, newNode);
        if (PRINT_DEBUG) cout << "Inserted node " << ab << " at pos " << pivot << endl;
        return pivot;
    }
}

Markov::Node* Markov::getRoot() {
    return root;
}

Markov::Node* Markov::fetchNode(string &ab) {
    if (allNodes.size() != numNodes){
        cerr << "Sizes do not match" << endl;
        return 0;
    }
    int theNodeIndex = binarySearch(ab, allNodes, 0, numNodes);
    Node* theNode;
    if (theNodeIndex == -1){
        theNode = new Markov::Node(ab);
        theNodeIndex = binaryInsert(theNode, allNodes, 0, numNodes);
        numNodes += 1;
        if (PRINT_DEBUG) { 
            cout << "All nodes: ";
            for (unsigned int i = 0; i < allNodes.size(); i++) {
                cout << allNodes[i]->data << ", ";
            }
            cout << endl;
        }
    }
    theNode = allNodes[theNodeIndex];
    return theNode;
}

void Markov::Node::printChildren() {
    cout << data << "'s children:" << endl;
    Markov::Node* thisChild;
    for (unsigned int i = 0; i < numChildren; i ++){
        thisChild = childNodes[i];
        cout << thisChild->data << ", ";
    }
    cout << endl;
}

void Markov::Node::connectTo(Node* node) {
    binaryInsert(node, childNodes, 0, numChildren);
    numChildren += 1;
    if (numChildren != childNodes.size()) {
        cerr << "Error: child nodes do not match";
        throw 20;
    }
    if (PRINT_DEBUG) printChildren();
}

Markov::Node* Markov::Node::traverseOnce() {
    if (numChildren == 0) {
        cerr << "No children in node " << data << endl;
        return nullptr;
    }
    if (PRINT_DEBUG) printChildren();
    unsigned int randIndex = rand() % numChildren;
    if (PRINT_DEBUG) cout << randIndex << "th node of " << numChildren << endl;
    return childNodes[randIndex];
}

Markov::Markov(string inputText) {
    root = new Node(" ");
    numNodes = 0;
    numLinks = 0;
    string beginning = " ";
    inputText = beginning.append(inputText);
    unsigned int length = inputText.length();
    if (length < 2) {
        //ERROR
        return;
    }
    string ab;
    Node* nextNode;
    Node* thisNode = root;
    vector<Node*> thisNodeChildren;
    vector<unsigned int> thisNodeLinkCounts;
    for (unsigned int i = 0; i < length - 1; i++) {
        ab = inputText.substr(i, CHUNK_LENGTH);
        nextNode = fetchNode(ab);
        thisNode->connectTo(nextNode);
        thisNode=nextNode;
    }
}

Markov::~Markov() {
}
