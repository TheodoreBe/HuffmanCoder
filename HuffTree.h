/** CS515 10P
 File: Hufftree.h
 Name: Theodore Belanger
 Section: 1
 Date: 11/21/2014
*/

#ifndef HUFFTREE_H
#define HUFFTREE_H
#include "PQueue.h"
#include <string>
using namespace std;

struct HuffNode{
    // default constructor
    HuffNode(HuffNode* l = 0, HuffNode* r = 0, int f = 0, char d = '\0')
        : left(l), right(r), freq(f), data(d){}
    HuffNode * left, * right;  // two child node
    unsigned int freq; // freqency of the node
    char data;  // char value for leaf nodes; '\0' for internal nodes
    string code;  // Huffman code for leaf nodes; not assigned for internal nodes
    
    // do not change above code
    // you may add below here
    bool operator<(HuffNode &);//comp
    bool operator>(HuffNode &);//comp 
};

class HuffTree{
public:
    // get Huffman code and return it as a string
    string getCode(char);
    
    // build Huffman tree from an array of characters
    // and an array of their corresponding frequencies;
    // the size of both arrays is given
    void buildTree(char * chs, int * freqs, int size);
    
private:
    HuffNode * _root; // root of the Huffman tree
    
    // do not change above code
    // you may add below here
    string helper( HuffNode *  , const char , string, bool&  );//bool HuffTree::helper( HuffNode* cur, const char find, string code, bool& found )

    PQueue<HuffNode, 100> _test;// = new PQueue<HuffNode, 100>;
};
//#include "HuffTree.cpp"
#endif
