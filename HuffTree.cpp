/** CS515 10P
 File: HuffTree.cpp
 Name: Theodore Belanger
 Section: 1
 Date: 11/21/2014
*/ 
#include "HuffTree.h"

/**
 * This operator  is used to compare two HuffNodes <
 */
bool HuffNode::operator<(HuffNode & comp)
{
	return freq < comp.freq;
}
/**
 * This operator  is used to compare two HuffNodes >
 */
bool HuffNode::operator>(HuffNode & comp)
{
	//cout<<"TEST: here"<<endl;
	return freq > comp.freq;
}

/**
 * This Function is the driver for the recursive  getCode function
 */
string HuffTree::getCode(char c)
{
	//cout<<"_root(getCode) = "<<_root->freq<<endl;
	bool found = false;
	string answer = "";
	HuffNode* send = _root;
	answer = helper( send , c, "", found );
	//=-=-=-=-=- Error Checking =-=-=-=-=-<- didn't use because should 
	//return empty string( BASH ), Would use for user though.
	//if( answer == "" )
	//	return "The char requested could not be found";	
	return answer;
}

/**
 * This function is the driving search for get code. It will return 
 * the Huffman Code that corresponds  with the key char sent in. 
 */
string HuffTree::helper( HuffNode* node, const char find, string print, bool& found )
{
	string temp;
	//cout<<"Test: CHECK HELPER CALL:  "<<cur->freq <<endl;
	if( find == node->data )
	{
		found = true; 
		return print;
	}
	if( found == false  && node->right != 0 )
	{
		temp = helper( node->right, find,  print +"1", found); 
	}	
	if( found == false && node->left != 0  )
	{
		temp = helper( node->left, find,  print +"0", found); 
	}
	return temp;
}  
   
// build Huffman tree from an array of characters
// and and an array of their corresponding frequencies;
// the size of both arrays is given
/**
 * This function creates the Huffman Tree from a min first priority 
 * Queue. The trees structure is saved in the only node in the array.  
 */
void HuffTree::buildTree(char * chs, int * freqs, int size)
{
	//_test = new PQueue<HuffNode, 100>;
	for( int i = 0; i< size; i++)
	{
		HuffNode temp = new HuffNode();
		temp.left  = 0;
		temp.right = 0;
		temp.freq  = freqs[i];
		temp.data  = chs[i];
		_test.insert( temp );
		//	cout<< "temp.freq: "<<temp.freq<< "  temp.data:  "<< temp.data<<endl;
	}
	//=-=-=-=-=-=-=-=-=-=- Testing: Good To Point -=-=-=-=-=-=-=-=-=-=-=-=-=
	HuffNode* one; 
	HuffNode* two;
	//cout<<"=-=-=-=-=-=--=-=-  Done With Array setup =-=-=-=-=-=-=-=-"<<endl;
	while( _test.size() > 1 )
	{
		//=-=-=--= LEFT =-=-=-=-=-
		HuffNode temp = _test.findMin();   //  = new HuffNode();
		//cout<<"Temp Val:  "<< temp.freq<<endl;
		one = new HuffNode();
		one-> right = temp.right;
		one-> left  = temp.left;
		one-> freq  = temp.freq;
		one-> data  = temp.data;
		_test.deleteMin();
		//cout<<" One's freq: "<<  one->freq  << endl; //<< "One's LeftChild-> "
		//<< one->left->freq<<" Ones RightChild: " << one->right->freq
		//=-=-=-=-=- RIGHT  =-=-=-=-
		temp = _test.findMin();
		two = new     HuffNode();
		two-> right = temp.right;
		two-> left  = temp.left;
		two-> freq  = temp.freq;
		two-> data  = temp.data;
		_test.deleteMin();
		//cout<<" Two's freq: "<<  two->freq  << endl;//<< "Two's LeftChild-> "
		//<< one->left->freq<<" Two RightChild: " << one->right->freq
		//=-=-=-=-=- New Parent =-=-=-=-=-
		HuffNode parent;
		parent.data  = '\0';
		parent.freq  = two->freq + one->freq;
		parent.left  = one; 
		parent.right = two; 
		//cout<< parent.freq << " parent.freq" <<endl;
		_test.insert( parent ); 
		//cout<<" parent's freq: "<<  parent.freq  << endl;
	}
	//=-=-=-=-- Root UPDATE =-=-=-=-=-=-
	_root = new HuffNode; 
	*_root = _test.findMin();
}
