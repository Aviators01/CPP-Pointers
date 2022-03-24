/*
Timothy Queva
CS2010 Lab6
Nov. 2, 2020
*/

/*
This program is for the purposes of a lab. A series of generic functions are written to allow
for the implementation of various algorithms via other specific functions.
*/

#include <iostream>
#include <vector>
#include <iomanip>
#define CONSTANT 7		//This is the constant to which all sequence elements are compared against

using namespace std;

typedef vector<int> int_vec;

//typedef'd pointers to functions
typedef int (*bin_op)(int,int);
typedef int (*un_op)(int);
typedef bool (*bool_op)(int);

//function prototypes
int reduce(int_vec,bin_op);
void transform(int_vec&,un_op);
int_vec test_all(int_vec,bool_op);
int_vec generate(int,un_op);
int fill(int);
int add(int,int);
int sub(int,int);
int mult(int,int);
int max(int,int);
int compareC(int);
bool greaterThanC(int);


//Takes a vector and calls a function (provided via parameter) to manipulate the data.
int reduce(int_vec v,bin_op op){
	int result=v.front();
	for(vector<int>::iterator it=v.begin()+1;it!=v.end();it++) result = op(result,*it);
	return result;
}

//Changes original vector elements according to a specified function (provided via parameter)
void transform(int_vec &v,un_op op){
	for(vector<int>::iterator it=v.begin();it!=v.end();it++) *it=op(*it);
}

//Creates new boolean 1-to-1 vector with results that depend on a boolean function (provided via parameter)
int_vec test_all(int_vec v,bool_op op){
	int_vec r;
	for(vector<int>::iterator it=v.begin();it!=v.end();it++){
		if(op(*it)==true)r.push_back(1);
		else r.push_back(0);
	}
	return r;
}

//Generates a sequence of integers by calling a function (provided via parameter) to create the sequence.
int_vec generate(int n,un_op op){
	int_vec v;
	for(int i=1;i<=n;i++) v.push_back(op(i));
	return v;
}


//Specific functions start here
int fill(int n){
	return n*n;
}
int add(int a,int b){
	return a+b;
}
int mult(int a,int b){
	return a*b;
}
int max(int a,int b){
	if(a>b) return a;
	return b;
}
//This function is affected by macro changes (the "#define CONSTANT" one)
int compareC(int a){
	if(a>CONSTANT) return 1;
	else if(a==CONSTANT) return 0;
	return -1;
}
//This function is affected by macro changes (the "#define CONSTANT" one)
bool greaterThanC(int a){
	if(a>CONSTANT) return true;
	return false;
}


int main(){
	const int VSIZE=5;		//This specifies the number of elements in sequence
	
	//a. Generate a sequence
	int_vec v = generate(VSIZE,fill);
	cout << "Elements of int_vec v are: ";
	for(int i=0;i<VSIZE;i++) cout << v[i] << " ";
	cout << "\n\n";
	
	//b. Use reduce to add all elements of v and print result
	cout << "Using reduce to add all elements of int_vec v      : " << reduce(v,add) << endl;
	
	//c. Use reduce to multiply all elements of v and print result
	cout << "Using reduce to multiply all elements of int_vec v : " << reduce(v,mult) << endl;
	
	//d. Use reduce to find the maximum element in v. Print result
	cout << "Using reduce to find largest element in int_vec v  : " << reduce(v,max) << endl;
	
	//e. Use test_all and reduce to count # of elements larger than some constant C (constant specified by macro: "#define CONSTANT 7"
	int_vec counts = test_all(v,greaterThanC);
	cout << "Number of elements greater than " << CONSTANT << ": " << reduce(counts,add) << endl;
	
	/*f. Use transform to change vector v according to rule:
		if vi > C, vi=1
		if vi = C, vi=0
		if vi < C, vi=-1
		
		Note: C is defined by a macro above: "#define CONSTANT 7". Used in functions compareC and greaterThanC. */
	transform(v,compareC);
	
	//g. Prints vector v
	for(int i=0;i<VSIZE;i++){
		cout << "Element " << VSIZE-i << ": " << v.back() << endl;
		v.pop_back();
	}
	
	return 0;
}