#include <iostream>
#include <conio.h>
#include <stdlib.h> // For new :)
using namespace std;

//DOUBLY-LINKED LIST ------------------------------------
struct Node {
	string Character;
	struct Node* Next;
	struct Node* prev;
};

Node* List;

void AddNodeAtBeggining(int data) {
	
	//Definition of the new element
	Node* new_elem = new Node();
	new_elem->Character = data;

	//--------------------
	new_elem->Next = List; // The next position of the new element connects to the list
	List->prev = new_elem; // The prev position of the list connects to the new element
	List = new_elem; //The list is now replace by the new element
	//Getting a list with the new element inserted
}

void AddNodeAtMiddle(int position, int data) {

	Node* new_elem = new Node();
	Node* Aux1 = new Node();
	Node* Aux2 = new Node();
	new_elem->Character = data;
	Aux2 = List;
	int a = 1; 
	while (a < position) { // "Position" value of the position of the element after
		Aux2 = Aux2->Next;
		a++;
	}//when Aux2 is in the correct position of the element after: 
	Aux2 = Aux1->Next; 
	Aux1->Next = new_elem; 
	new_elem->prev = Aux1; 
	Aux2->prev = new_elem; 
	new_elem->Next = Aux2;
	// after the respective pointer connections, the new node would be in the middle
	/*
		 :::::::::     :::::::::      :::::::::
	prev :::::::::---->:::::::::----->:::::::::---> next
	<----:::::::::<----:::::::::<-----:::::::::
		 :::::::::     :::::::::      :::::::::
		  Aux1          new_elem        Aux2
	*/
}
//_______________________________________________________________________________________


//BINARY TREE
struct NodeTree {
	string Char;
	struct NodeTree* left;
	struct NodeTree* Right;
};

NodeTree* Tree;

void LocateElement(NodeTree* Tree, string Char) { //Pre-order search
	if (Tree == NULL) {
		return;
	}
	else {
		//Compare the value that we are looking for with the value in active node
		if (Tree->Char == Char) {
			cout << "Founf the Node!!" << endl;
		}
		//Use recursion to search first for the left branchesand then for the right branches
		LocateElement(Tree->left, Char);
		LocateElement(Tree->Right, Char);
	}
}

//_______________________________________________________________
//CHAR TO INTEGER
int main() {
	char text[] = "8246415";
	int length = 0;
	length = strlen(text);

	CharToInt(text, length);

	system("pause>null");
}

void CharToInt(char txt[], int length) {
	int newInt = 0;
	int cont = 1;
	int num = 0;
	for (int i = 0; i < length; i++) { //This FOR loops through the character string
		num = txt[i] - '0'; //// convet ASCII '0'..'9' to digit 0..9 and add it to number
		for (int j = 0; j < 10; j++)
		{
			if (num == j) { //Check when the numbers are the same
				newInt = newInt + j; //add the next number to the int number
				if (cont < length) {
					newInt = newInt * 10; //add an extra 0, only if there are missing numbers to add
					cont++;
				}
			}
		}
	}
	cout << "The result is = " << newInt << endl;
}
//________________________________________________________________________
