/* ----------------------------------------------
C++ recursive function to
solve tower of hanoi puzzle
Enter the number of disks and get the output in TOH.txt
To run code 

------------------------------------------------*/
#include <iostream>
#include <fstream>
using namespace std; 
ofstream fout; // ofstream --- output file stream

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod,int* count)
{
	if (n == 0) // Recursive termination case
		return;

	//Shifts N-1 rods from source to auxiliary
	towerOfHanoi(n - 1, from_rod, aux_rod, to_rod,count); 
	
	fout << "Move disk " << n << " from rod " << from_rod<< " to rod " << to_rod << endl;//writes to file
	(*count)++; 

	 //Shifts N-1 rods from auxiliary to destination
	towerOfHanoi(n - 1, aux_rod, to_rod, from_rod,count);
} //end

// Main
int main()
{	
	fout.open("TOH.txt",ios::out|ios::trunc); //Opens file TOH.txt out:only write; trunc:delete existing content
	int N;
	cout<<"Enter N"<<endl;
	cin>>N;
	int count=0;
	// A, B and C are names of rods 
	// A-- source B-- auxiliary C-- destination
	towerOfHanoi(N, 'A', 'C', 'B',&count);
	fout<<endl<<count<<" moves needed"<<endl; 
	fout.close(); // Output gets stored in TOH.txt
	return 0;
} //end

