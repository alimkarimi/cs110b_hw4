#include <iostream>
using namespace std;

//Have an array of 21 integers. 
//Display the elements and ask the user to think of a number from the 21 numbers. 
//Now ask the user to proceed to play the game by pressing 0. 
//Distribute the 21 cards into 3 piles of 7 in the breadthwise order. Remember how we dealt the cards into piles in class?
//Ask the user to enter which pile their card resides in. Give the user a choice of Pile 1 /2 /3
//The pile they pick must always be in the middle of the 21 array numbers.
//Do the pile separation for a total of 3 times

int assignOriginal(int[]); 
bool displayStart();
void distribute_pile_one(int[], int[]); 
void distribute_pile_two(int[], int[]);
void distribute_pile_three(int[], int[]);
void printArray(int[]);
void distributing(int[], int[], int[], int[]);
void fetchPileAndOrder(int[], int[], int[], int[], int);

int main()
{
	
	//declare 
	const int TOTAL_CARDS = 21;
	const int PILE_CARDS = 7;
	int pile_num;
	int cards[TOTAL_CARDS];
	int cards_pile_one[PILE_CARDS];
	int cards_pile_two[PILE_CARDS];
	int cards_pile_three[PILE_CARDS];


	//original assignment of cards
	assignOriginal(cards);

	//print original array to show user
	printArray(cards);
	
	//ask user if they want to continue
	if (displayStart() == true)
	{

		//if user decides to continue, the following functions should take place 3 times...

		for (int i = 0; i < 3; i++)			
		{
			//distribute cards for the amount of times specified in code		
			distributing(cards, cards_pile_one, cards_pile_two, cards_pile_three);

			//ask user which pile their card is in
			cout << "Which pile is the card in?" << endl;
			cin >> pile_num;
			while (pile_num <1 || pile_num > 3)
			{
				cout << "You didn't enter a valid pile. Enter again" << endl;
				cin >> pile_num;
			}

			//reorder cards with pile they chose in the middle
			fetchPileAndOrder(cards, cards_pile_one, cards_pile_two, cards_pile_three, pile_num);
		
			//print re-ordered array - pile they chose in the middle
			printArray(cards);
		}

	
	}

	cout << "Is the card that you had in mind " << cards[10] << "?" << endl; 


	
}

int assignOriginal(int  original[])
//This function gives the original array assignment
{
	const int TOTAL_CARDS = 21;
	for (int i = 0; i < 21; i++)
	{
		original[i] = i + 1;		
	}
	
	return original[TOTAL_CARDS];
}

bool displayStart()
//this function asks users if they want to start the game
{
	bool start = false;
	int start_num;

	cout << "The deck of cards is displayed above. Do you want to proceed? Press 0 to proceed" << endl;
	cin >> start_num;
	if (start_num == 0)
	{
		start = true;
	}
	else if (start_num != 0)
	{
		cout << "You choose to not proceed" << endl;
	}

	return start;


}

void distribute_pile_one(int original[], int first[])
//this function distributes element n=0 from origina[] into element n=0 of the first pile
//after that, element 3n of the orginal[] gets distributed into element n of the first pile (first[]), where n > 0
{
	cout << "Pile 1: ";
	for (int i = 0; i < 7; i++)
	{
		if (i == 0)
		{
			first[i] = original[i];
		}
		else if (i > 0)
		{
			first[i] = original[(i*3)];
		}
		cout << first[i] << ", ";
	}
	cout << endl;
}

void distribute_pile_two(int original[], int second[])
//this function distributes element n = 1 from the original[] into the first element of the second pile array
//furthermore, it takes element 3n + 1 of the original array and distributes it into the n+1 element of the second pile array
//n > 0
//e.g element 1 of second[] = 3*1 + 1 = 4, when element 1 of original is 1. 
{
	cout << "Pile 2: ";
	for (int i = 0; i < 7; i++)
	{
		if (i == 0)
		{
			second[i] = original[i+1];
		}
		else if (i > 0)
		{
			second[i] = original[(i*3)+1];
		}
		cout << second[i] << ", ";
	}
	cout << endl;
	
}


void distribute_pile_three(int original[], int third[])
//same logic as function "distribute_pile_three", except it takes the third element of original[] and distributes that to the first element 
//of pile 3
{
	cout << "Pile 3: ";
	for (int i = 0; i < 7; i++)
	{
		if (i == 0)
		{
			third[i] = original[i+2];
		}
		else if (i > 0)
		{
			third[i] = original[(i*3)+2];
		}
		cout << third[i] << ", ";
	}
	cout << endl;
}

void printArray(int original[])
{
	for (int i = 0; i < 21; i++)
	{
		cout << original[i] << ", ";
	}
	cout << endl;
	cout << endl;
}

void distributing(int cards[], int cards_pile_one[], int cards_pile_two[], int cards_pile_three[])
//all piles need to be distributed whenever distributing, so created a function to hold all distributions...
{
	cout << "Shuffling and distributing" << endl;
	//shuffle cards into 3 arrays of 7
	//pile one
	distribute_pile_one(cards, cards_pile_one);
	
	//pile two
	distribute_pile_two(cards, cards_pile_two);

	//pile three
	distribute_pile_three(cards, cards_pile_three);
}

void fetchPileAndOrder(int cards[], int cards_pile_one[], int cards_pile_two[], int cards_pile_three[], int pile_num)
//logic that puts pile the user chose into the middle of the updated array
{
	if (pile_num == 1)
	{
		//assign pile one to elements
		int j = 0; 
		for (int i = 0; i < 7; i++,j++)
		{
			cards[i+7] = cards_pile_one[j];
			cards[i] = cards_pile_two[j];
			cards[i+14] = cards_pile_three[j];
		}
	}

	else if (pile_num == 2)
	{
		//assign pile one to elements
		int j = 0; 
		for (int i = 0; i < 7; i++,j++)
		{
			cards[i+7] = cards_pile_two[j];
			cards[i] = cards_pile_one[j];
			cards[i+14] = cards_pile_three[j];
		}
	}

	else if (pile_num == 3)
	{
		int j = 0;
		for (int i = 0; i < 7; i++, j++)
		{
			cards[i+7] = cards_pile_three[j];
			cards[i] = cards_pile_two[j];
			cards[i+14] = cards_pile_one[j];
		}
	}
}


