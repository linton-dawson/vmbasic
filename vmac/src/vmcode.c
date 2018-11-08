#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

bool run = true;

int sp=-1;
int ip=0;
int stack[256];

typedef enum {
	PSH,
	ADD,
	POP,
	SET,
	HLT
}instructions;


const int program[] = {
    PSH, 4,
    PSH, 3,
    ADD,
    POP,
    HLT
};



int fetch() {
	return program[ip];
}

void compute(int instr ) {
	switch(instr) {
	
	case PSH: {
		sp++;
		stack[sp]=program[++ip];
		break;
	}
	
	case ADD: {
		int n1 = stack[sp--];
		int n2 = stack[sp--];
		int res = n1 + n2;
		sp++;
		stack[sp] = res;
		break;
	}
	
	case POP: {
		printf("%d is popped\n",stack[sp]);
		sp--;
		break;
	}
	
	case HLT: {
		run=false;
		printf("DONE\n");
		break;
	}
    }
}

int main() {
	
	while(run) {

		compute(fetch());
		ip++;

		}
}
