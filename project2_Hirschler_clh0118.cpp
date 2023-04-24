//Calvin Hirschler
//clh0118
//project2_Hirschler_clh0118.cpp
//vi project2_Hirschler_clh0118.cpp -o a.out
//./a.out
//Compares and tests two strategies with 3 shooters each with a different shooting accuracy

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>
#include <cstddef>
using namespace std;

//declaring variables
bool A_alive = true; bool B_alive = true; bool C_alive = true;
float A_accuracy = (float)1/3; float B_accuracy = (float)1/2; //setting accuracy
bool * target; //pointer used in assert testing
int AWins1 = 0, AWins2 = 0, BWins = 0, CWins = 0;
int strategy = 0;

//if two people are alive
bool at_least_two_alive(bool a,bool b,bool c){
	int count = 0;
	if (a) count++; if (b) count++; if (c) count++;
	if (count >= 2)
		return true;
	else
		return false;
}

//Aaron fires at the target with the highest accuracy
void AFire1(bool &B_alive, bool &C_alive){
	//test if alive
	if (!A_alive)
		return;
	//declaring target
	if (C_alive)
		target = &C_alive;
	else
		target = &B_alive;
	//shoot at target
	double random = (float) rand() / RAND_MAX;
	if (random <= A_accuracy)
		*target = false;
}
//Aaron misses his first shot intentionally
void AFire2(bool &B_alive, bool &C_alive){
	//test if alive
	if (!A_alive)
		return;
	//declaring target	
	if (C_alive && !B_alive)
		target = &C_alive;
	else if (!C_alive && B_alive)
		target = &B_alive;
	else {
		target = NULL;
		return;
	}
	//shoot at target
	double random = (float) rand() / RAND_MAX;
	if (random <= A_accuracy)
		*target = false;
}

//Bob shoots at target with highest accuracy
void BFire(bool &A_alive, bool &C_alive) {
	//test if alive
	if (!B_alive)
		return;
	//declare target	
	if (C_alive)
		target = &C_alive;
	else
		target = &A_alive;
	//shoot at target
	double random = (float) rand() / RAND_MAX;
	if (random <= B_accuracy)
		*target = false;		
}

//Charlie shoots at target with highest accuracy
void CFire(bool &A_alive, bool &B_alive) {
	//test if alive
	if (!C_alive)
		return;
	//declare target	
	if (B_alive)
		target = &B_alive;
	else
		target = &A_alive;
	//shoot at target	
	*target = false;
}

//continuing method
void Cont() { 
	cout << "Presss Enter to continue..."; 
	cin.ignore().get(); //Pause Command for Linux Terminal
}

//testing at least two alive
void test_at_least_two_alive(void) { 
	cout << "Unit Testing 1: Function: at_least_two_alive()\n"; 

	cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n"; 
	assert(true == at_least_two_alive(true, true, true)); 
	cout << "\t\tCase passed ...\n"; 
 
	cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n"; 
	assert(true == at_least_two_alive(false, true, true)); 
	cout << "\t\tCase passed ...\n"; 
 
	cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n"; 
	assert(true == at_least_two_alive(true, false, true)); 
	cout << "\t\tCase passed ...\n"; 
  
	cout << "\tCase 4: Aaron dead, Bob dead, Charlie dead\n"; 
	assert(false == at_least_two_alive(false, false, false)); 
	cout << "\t\tCase passed ...\n"; 
  
	cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n"; 
	assert(false == at_least_two_alive(false, false, true)); 
	cout << "\t\tCase passed ...\n"; 
  
	cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n"; 
	assert(false == at_least_two_alive(false, true, false)); 
	cout << "\t\tCase passed ...\n"; 
  
	cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n"; 
	assert(false == at_least_two_alive(true, false, false)); 
	cout << "\t\tCase passed ...\n"; 
  
	cout << "\tCase 8: Aaron alive, Bob alive, Charlie dead\n"; 
	assert(true == at_least_two_alive(true, true, false)); 
	cout << "\t\tCase passed ...\n"; 
	Cont();
}

//testing Aaron strategy 1
void test_AFire1() {
	cout << "Unit Testing 2: Function: AFire1(B_alive, C_alive)\n";
	
	B_alive = true; C_alive = true;
	cout << "\tCase 1: Bob alive, Charlie alive\n";
	AFire1(B_alive, C_alive);
	assert(&C_alive == target);
	cout << "\t\tAaron is shooting at Charlie\n";

	B_alive = false; C_alive = true;
	cout << "\tCase 2: Bob dead, Charlie alive\n";
	AFire1(B_alive, C_alive);
	assert(&C_alive == target);
	cout << "\t\tAaron is shooting at Charlie\n";

	B_alive = true; C_alive = false;
	cout << "\tCase 3: Bob alive, Charlie dead\n";
	AFire1(B_alive, C_alive);
	assert(&B_alive == target);
	cout << "\t\tAaron is shooting at Bob\n";
	Cont();
}

//testing Bob firing
void test_BFire() {
	cout << "Unit Testing 3: Function: BFire(A_alive, C_alive)\n";
	
	A_alive = true; B_alive = true; C_alive = true;
	cout << "\tCase 1: Aaron alive, Charlie alive\n";
	BFire(A_alive, C_alive);
	assert(&C_alive == target);
	cout << "\t\tBob is shooting at Charlie\n";

	A_alive = false; C_alive = true;
	cout << "\tCase 2: Aaron dead, Charlie alive\n";
	BFire(A_alive, C_alive);
	assert(&C_alive == target);
	cout << "\t\tBob is shooting at Charlie\n";

	A_alive = true; C_alive = false;
	cout << "\tCase 3: Aaron alive, Charlie dead\n";
	BFire(A_alive, C_alive);
	assert(&A_alive == target);
	cout << "\t\tBob is shooting at Aaron\n";
	Cont();
}

//testing Charlie firing
void test_CFire() {
	cout << "Unit Testing 4: Function: CFire(A_alive, B_alive)\n";
	
	A_alive = true; B_alive = true; C_alive = true;
	cout << "\tCase 1: Aaron alive, Bob alive\n";
	CFire(A_alive, B_alive);
	assert(&B_alive == target);
	cout << "\t\tCharlie is shooting at Bob\n";

	A_alive = false; B_alive = true;
	cout << "\tCase 2: Aaron dead, Bob alive\n";
	CFire(A_alive, B_alive);
	assert(&B_alive == target);
	cout << "\t\tCharlie is shooting at Bob\n";

	A_alive = true; B_alive = false; 
	cout << "\tCase 3: Aaron alive, Bob dead\n";
	CFire(A_alive, B_alive);
	assert(&A_alive == target);
	cout << "\t\tCharlie is shooting at Aaron\n";
	Cont();
}

//testing Aaron strategy 2
void test_AFire2(){
	cout << "Unit Testing 5: Function: AFire2(B_alive, C_alive)\n";
	
	A_alive = true; B_alive = true; C_alive = true;
	cout << "\tCase 1: Bob alive, Charlie alive\n";
	AFire2(B_alive, C_alive);
	assert(target == NULL);
	cout << "\t\tAaron intentionally missed his target\n";

	B_alive = false; C_alive = true;
	cout << "\tCase 2: Bob dead, Charlie alive\n";
	AFire2(B_alive, C_alive);
	assert(&C_alive == target);
	cout << "\t\tAaron is shooting at Charlie\n";

	B_alive = true; C_alive = false;
	cout << "\tCase 3: Bob alive, Charlie dead\n";
	AFire2(B_alive, C_alive);
	assert(&B_alive == target);
	cout << "\t\tAaron is shooting at Bob\n";
	Cont();
}

//implimentation of Aaron strategy 1
void strategy1(){
	while (at_least_two_alive(A_alive, B_alive, C_alive)) {
		AFire1(B_alive, C_alive);
		BFire(A_alive, C_alive);
		CFire(A_alive, B_alive);
	}
	if (A_alive) AWins1++;
	else if (B_alive) BWins++;
	else CWins++;
	A_alive = true; B_alive = true; C_alive = true;
}

//testing of strategy 1 10,000 times
void test_strategy1(){
	for (int i = 0; i < 10000; i++)
		strategy1();
	cout << "Aaron won " << AWins1 << "/10000 duels or " << (float)AWins1/100 << "%" << endl;
	cout << "Bob won " << BWins << "/10000 duels or " << (float)BWins/100 << "%" << endl;
	cout << "Charlie won " << CWins << "/10000 duels or " << (float)CWins/100 << "%\n" << endl;
	BWins = 0; CWins = 0;
}

//implimentation of Aaron strategy 2
void strategy2(){
	while (at_least_two_alive(A_alive, B_alive, C_alive)) {
		AFire2(B_alive, C_alive);
		BFire(A_alive, C_alive);
		CFire(A_alive, B_alive);
	}
	if (A_alive) AWins2++;
	else if (B_alive) BWins++;
	else CWins++;
	A_alive = true; B_alive = true; C_alive = true;
}

//testing of strategy 2 10,000 times
void test_strategy2(){
	for (int i = 0; i < 10000; i++)
		strategy2();
	cout << "Aaron won " << AWins2 << "/10000 duels or " << (float)AWins2/100 << "%" << endl;
	cout << "Bob won " << BWins << "/10000 duels or " << (float)BWins/100 << "%" << endl;
	cout << "Charlie won " << CWins << "/10000 duels or " << (float)CWins/100 << "%\n" << endl;
}

//comparing the two strategies
void compare_strategies(int AWins1, int AWins2) {
	if (AWins1 > AWins2)
		cout << "Strategy 1 is better than strategy 2" << endl;
	else
		cout << "Strategy 2 is better than strategy 1" << endl;
}
//main method
int main() {
	srand(time(0));
	test_at_least_two_alive();
	test_AFire1();
	test_BFire();
	test_CFire();
	test_AFire2();
	cout << "Ready to test strategy 1 (run 10000 times):" << endl;
	Cont();	
	test_strategy1();
	cout << "Ready to test strategy 2 (run 10000 times):" << endl;
	Cont();
	test_strategy2();
	compare_strategies(AWins1, AWins2);
}
