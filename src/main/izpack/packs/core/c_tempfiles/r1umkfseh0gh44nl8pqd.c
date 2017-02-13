#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

int nondet_uint();
int nondet_int();

#define assert2(x, y) __CPROVER_assert(x, y)
#define assume(x) __CPROVER_assume(x)

//Code of the user
//Single-choice: Wähler stimmt jeweils für einen Kandidaten
//Single-choice: Ein gewählter Kandidat oder unentschieden
unsigned int voting(unsigned int votes[V]) { 
        int i = 1;
        return 1;
} 
int main(int argc, char *argv[]) {
	//Symbolic Variables initialisation
	
	//voting-array and elect variable initialisation
	unsigned int votes1[V];
	for(unsigned int counter_0 = 0; counter_0 < V; ++counter_0){
		votes1[counter_0] = nondet_uint();
		assume((0 <= votes1[counter_0]) && (votes1[counter_0] < C));
	}
	unsigned int elect1;
	elect1 = voting(votes1);
	unsigned int votes2[V];
	for(unsigned int counter_0 = 0; counter_0 < V; ++counter_0){
		votes2[counter_0] = nondet_uint();
		assume((0 <= votes2[counter_0]) && (votes2[counter_0] < C));
	}
	unsigned int elect2;
	elect2 = voting(votes2);
	
	//preproperties 
	
	unsigned int forAll_0 = 1;
	for(unsigned int v = 0; v < V && forAll_0; v++) {
		unsigned int comparison_0 = 1;
		comparison_0 = votes1[v] == votes2[v];
		forAll_0 = comparison_0;
	}
	assume(forAll_0);
	
	//postproperties 
	
	unsigned int comparison_1 = 1;
	comparison_1 = elect1 == elect2;
	assert(comparison_1);
}
