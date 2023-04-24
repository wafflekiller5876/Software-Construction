/*
 * 4/8/2022
 * Calvin Hirschler
 * clh0118
 * project4_Hirschler_clh0118
 * g++ project4_Hirschler_clh0118 -o a.out --std=c++11
 * comment out line 32 to change the version
 * Trivia game using a linked list
 */

//imports
#include <iostream>
#include <string>
using namespace std;

//structure holding information
struct trivia_node{
	string question;
	string answer;
	int point;
	trivia_node *next;
};

//creates pointer to trivia_node
typedef trivia_node* ptr_node;

//initializing variables
int num_of_questions = 0;
int totalPoints = 0;

//creates two versions. remove or add "//" to test or not to test
#define UNIT_TESTING

//given an empty node, initializes 3 nodes to the list
void init_questions_list(ptr_node& q_list) {
	ptr_node cur_ptr = new trivia_node; //initializes a pointer node

	q_list->question = "How long was the shortest war on record? (Hint: How many minutes)";
	q_list->answer = "38";
	q_list->point = 100;
	q_list->next = new trivia_node; //sets next to a node

	cur_ptr = q_list; //sets the pointer node to the start of q_list

	q_list = q_list->next; //sets the q_list to the next node
	q_list->question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
	q_list->answer = "Bank of Italy";
	q_list->point = 50;
	q_list->next = new trivia_node; //sests next to a node

	q_list = q_list->next; //sets the q_list to the next node
	q_list->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)";
	q_list->answer = "Wii Sports";
	q_list->point = 20;

	q_list = cur_ptr; //sets the q_list back to the beginning
	num_of_questions = 3;
}

//Gives the user the option to add a question to the linked list
//Question is added to end of list
void add_question(ptr_node& q_list) {
	num_of_questions += 1; //increases number of questions
	string userPoints = ""; //initialize a string for later use
	ptr_node start_ptr = new trivia_node; //create a new node
	start_ptr = q_list; //sets start_ptr to start of q_list
	string userAnswer = ""; //initializes string answer for later use

	//search for end of node list
	while (q_list->next != NULL){
		q_list = q_list->next;
	}
	q_list->next = new trivia_node;
	q_list = q_list->next;

	//add values to node
	cout << "Enter a question: ";
	getline(cin, q_list->question);
	cout << "Enter an answer: ";
	getline(cin, q_list->answer);
	cout << "Enter award points: ";
	getline(cin, userPoints);
	q_list->point = stoi(userPoints);
	
	q_list = start_ptr; //sets q_list to start of list

	//continue???	
	cout << "Add a question? (Yes/No): "; 
	getline(cin, userAnswer);
	while (userAnswer != "Yes" && userAnswer != "No") {//checks for a valid answer
		cout << "Add a question? (Yes/No): ";
		getline(cin, userAnswer);
	}

	if (userAnswer == "Yes") //if yes, add another question to the list
		add_question(q_list);
}

//Asks the user trivia questions and stats the game
void ask_question(ptr_node& q_list, int num_ask){
	string userAnswer = ""; //initializing string answer
	if (q_list == NULL)
		return;
	if (num_ask < 1)
		cout << "Warning - the number of questions must be equal or greater than 1\n";
	else if (num_of_questions < num_ask)
		cout << "Warning - there is only " << num_of_questions << " questions in the list\n";
	else {
		ptr_node start_ptr = new trivia_node;
		start_ptr = q_list; //getting a reference to the start

		for (int x = 0; x < num_ask; x++){
			cout << "Question: " << q_list->question << endl; //asks question
			cout << "Answer: "; //waits for answer
			getline(cin, userAnswer);
			if (userAnswer.compare(q_list->answer) == 0) { //correct answer
				cout << "Your answer is correct! You receive " << q_list->point << " points\n";
				totalPoints += q_list->point;
				cout << "Your total points: " << totalPoints << "\n";
			}
			else { //incorrect answer
				cout << "Your answer is wrong. The correct answer is " << q_list->answer << endl;
				cout << "Your total points: " << totalPoints << "\n";
			}
			q_list = q_list->next;
		}
		q_list = start_ptr;
	}
}

//Test cases to check whether the methods work
void Unit_Test() {
	cout << " *** This is a debugging version ***\n\n";
	//initialize node_list
	ptr_node node_list = new trivia_node;
	init_questions_list(node_list);
	//case 1
	cout << "Unit test case 1: Ask no question. The program should give a warning message.\n";
	ask_question(node_list, 0);
	cout << "\nCase 1 Passed\n\n";
	//case 2
	cout << "Unit test case 2: Ask 1 question in the linked list. The tester enters an incorrect answer\n";
	ask_question(node_list, 1);
	cout << "\nCase 2 passed\n\n";
	//case 3
	cout << "Unit test case 3: Ask all the questions in the linked list\n";
	ask_question(node_list, 3);
	cout << "\nCase 3 passed\n\n";
	//case 4
	cout << "Unit test case 4: Ask 5 questions in the linked list.\n";
	ask_question(node_list, 5);
	cout << "\ncase 4 passed\n\n";
	
	cout << " *** End of the Debugging Version ***\n";
}

int main() {
	ptr_node node_list = new trivia_node;
#ifdef UNIT_TESTING
	Unit_Test();

#else
	init_questions_list(node_list);
	cout << "*** Welcome to Calvin Hirschler's trivia quiz game ***\n";

	add_question(node_list); //adds questions until satisfied
	//This is start of Trivia quiz game. 
	ask_question(node_list, num_of_questions); 
	cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***\n";
#endif 
}	 
