/** CS515 10P
 File: HuffmanCoder.cpp
 Name: Theodore Belanger
 Section: 1
 Date: 11/21/2014
*/
#include "HuffTree.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <cstdlib>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]){
    char letters[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    // 81 means 8.1% etc.
    int f[26] = { 81, 15, 28, 43, 128, 23, 20, 61, 71, 2, 1, 40, 24, 69, 76, 20, 1, 61, 64, 91, 28, 10, 24, 1, 20, 1 };
    // fill in below
    //=-=-=- Testing for clean command line arg#'s =-=-=-=-=-=-
    /*
     * This is testing the command line for good user args
     */
    if( argc != 2 )
    {
        cout <<"Incorrect command line argument"<< endl;
        cout <<" ./HuffmanCoder <inputFile>"<< endl; 
        return 1;
    }
    //=-=-=-=-=- Checking input File for good file  =-=-=-=-=--
    /*
     * This is checking for a good file open( Error Check )
     */
    ifstream input( argv[1] );
    if( !input.good() )
    {
        cout<< "The file provided was invalid and could not be opened."<< endl; 
    }
    //=-=-=-=-=-=-=-=-=- Program Integers =-=-=-=-=-=-=-=-=-=-
    /*
     * These int values will be uses to keep track of file
     * size before and after compression  as well as the %
     *                      reduced.
     */ 
    float originalSize    = 0; 
    float compressedSize  = 0;
    float compressionRate = 0.0;
    //=-=-=-=-=--==-=-= Setting Up HuffmanTree =-=-=-=-=-=-=-=-
    /*
     * This will create the Huffman Tree with Aphas and freq's
     */
    HuffTree tree;
    tree.buildTree(letters,f,26);
    //=-=-=-=-=-=- Making the input =-=-=-=-=-=-=-=-=-=-=-=-=-=
    /*
     * This handles the users input file
     */
    string curLine; 
    while ( getline (input,curLine) )
    {
      //=-=-=-=- Logic of each line in the file  handling  =-=-=-=-
      //cout<< curLine<<endl;
      int i = 0;
      transform(curLine.begin(), curLine.end(), curLine.begin(), ::tolower);
      
      //=-=-=-=-= TESTS =-=-=-=-=-=-=-=-=-=-=
      //cout<<"Test input to lower: "<<endl;
      //cout<< curLine<<endl;
      //=-=-=-=-= End of TESTS =-=-=-=-=-=-=-=-=-=-=
      
      //=-=-=- This will handle  every char on current line =-=-=-=-
      while( i <=  curLine.length() )
      {
		  //=- Char handeling for clean input ( upper to lower =-=
		 
		  //=-=-=-- Goes in if you are handling a char or space =-=-=-
		  if( isalpha(curLine[i])  ) //|| curLine[i]== ' '
		  {			   
			   //=-=-=-= Updating original  size =-=-=-=-=-
			   originalSize += 8;	
			   		  
			   //Gets the HuffMan Code of alpha letter
			   string code;
			   char c = curLine[i];
		       code =  tree.getCode(c);
		       
		       //-=-=-=-Updating total compressed size =-=-=
		       compressedSize += code.length();
		       
		       //=-=-=-= Testing =-=-=-=-
			   //cout << c<<":";
			   //cout <<"Char Code: "<< code.length() <<endl;
			   //=-=-=--=-=-=-=-=-=-=-=-=-
		  }
		  //=-=-=-=-= Goes in for special chars and returns =-=--=-
		  else
		  {
			  //=-=-=-=-=-= Testing =-=-=-=-=-=-=-=-
			  //cout<<" >"<< curLine[i] <<"< ";
			  //=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
			  
			  //=-=-=-= Updating original  size =-=-=-=-=-
			  originalSize += 8;	
			   
			  //-=-=-=-Updating total compressed size =-=-=
		      compressedSize += 8;
		  }
		  i++;
	  }
	  //cout<< endl;
	  //cout<<"end of line chars "<<endl;
    }
    //cout<<"Program done scanning "<<endl;
    //cout<<"closing file"<<endl;
    input.close();
    //=-=-=-=- Calculating final % =-=-=-=-=-
    int totalBitsReducedByCompression = originalSize - compressedSize;
    
    compressionRate = 100*(totalBitsReducedByCompression / originalSize)  ; 
    
    //=-=-=-=-=-=-=-=-=-=-- TESTS =-=-=-=-=-=-=-=-=-
    //cout<<"compressionRate"<<compressionRate<<endl;
    //cout<< "totalBitsReducedByCompression"<<totalBitsReducedByCompression<<endl;
    //cout<< "=-=-=-= Final Values =-=-=-=-" <<endl;
    
    //=-=-=-=-=-=-=-=- PROGRAM OUTPUT =-=-=-=-=-=-=-=-
    cout<<"original bits: "           << originalSize    << endl;
    cout<< "bits after compression: " << compressedSize  <<endl;
    cout<<"compression rate: "        << setprecision(2)<<compressionRate <<"%"<<endl;
}
