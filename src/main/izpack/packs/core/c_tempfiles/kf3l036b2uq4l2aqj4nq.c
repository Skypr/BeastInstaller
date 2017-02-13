#include <stdlib.h>
#include <stdint.h>
#include <assert.h>

int nondet_uint();
int nondet_int();

#define assert2(x, y) __CPROVER_assert(x, y)
#define assume(x) __CPROVER_assume(x)

//Code of the user
//Zustimmungswahl: Wähler bewertet jeden Kandidaten mit Ja/Nein
//Zustimmungswahl: Ein gewählter Kandidat oder unentschieden
unsigned int  voting(unsigned int votes[V][C]) { 
    unsigned int res[C];
    unsigned int i = 0;
    unsigned int j = 0;
 
    for (i = 0; i < C; i++) {
        res[i] = 0;
    }
    for (i = 0; i < V; i++) {
        for (j = 0; j < C; j++) {
            res[j] = res[j] + votes[i][j];
        }
    }
    unsigned int max = 0;
    unsigned int elect = 0;
    for (i = 0; i < C; i++) {
        if (max < res[i]) {
            max = res[i];
            elect = i+1;
        } else {
            if (max == res[i]) {
                elect = C;
            }
        }
    }
    return elect;
} 
int main(int argc, char *argv[]) {
	//Symbolic Variables initialisation
	
	//voting-array and elect variable initialisation
	unsigned int votes1[V][C];
	for(unsigned int counter_0 = 0; counter_0 < V; ++counter_0){
		for(unsigned int counter_1 = 0; counter_1 < C; ++counter_1){
			votes1[counter_0][counter_1] = nondet_uint();
			assume((0 <= votes1[counter_0][counter_1]) && (votes1[counter_0][counter_1] < 2));
		}
	}
	unsigned int elect1;
	elect1 = voting(votes1);
	unsigned int votes2[V][C];
	for(unsigned int counter_0 = 0; counter_0 < V; ++counter_0){
		for(unsigned int counter_1 = 0; counter_1 < C; ++counter_1){
			votes2[counter_0][counter_1] = nondet_uint();
			assume((0 <= votes2[counter_0][counter_1]) && (votes2[counter_0][counter_1] < 2));
		}
	}
	unsigned int elect2;
	elect2 = voting(votes2);
	
	//preproperties 
	
	unsigned int forAll_0 = 1;
	for(unsigned int v = 0; v < V && forAll_0; v++) {
		unsigned int comparison_0 = 1;
		for(unsigned int count_0 = 0; count_0 < V && comparison_0; ++count_0) {
			comparison_0 = votes1[v][count_0] == votes2[v][count_0];
		}
		forAll_0 = comparison_0;
	}
	assume(forAll_0);
	
	//postproperties 
	
	unsigned int comparison_1 = 1;
	comparison_1 = elect1 != elect2;
	assert(comparison_1);
}
