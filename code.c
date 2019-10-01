#include <stdio.h>
#include <string.h>

int inputState(int k) {
	if (k == 0)	return 0;
	int state = 0;
	for (int ii = 0; ii < k; ii++) {
		int val;	scanf("%d", &val);
		// state = state + (1 << val);
		state = state | (1 << val);
	}
	return state;
}

void inputTable(int arr[][2], int n) {
	for (int i = 0; i < n; i++) {
		printf("State: %d\n", i);

		int k = 0;
		printf("Number of States on move a: ");	scanf("%d", &k);
		arr[i][0] = inputState(k);
		k = 0;
		printf("Number of States on move b: ");	scanf("%d", &k);
		arr[i][1] = inputState(k);
	}
}

void printState(int x) {
	if (x == 0)	{printf("{}\t"); return;}
	printf("{");
	int value = x, cntr = 0;
	while (value) {
		if (value % 2 == 1) printf("%d,", cntr);
		cntr++;
		value /= 2;
	}

	printf("\b}\t");
}

void printTable(int arr[][2], int n) {
	printf("NFA obtained: \n");
	for (int i = 0; i < n; i++) {
		printf("State ");
		printState(i);
		putchar(':');
		printState(arr[i][0]);
		printState(arr[i][1]);
		printf("\n");
	}
}

int fillState(int in[][2], int out[][2], int curState, int type) {
	if (curState == 0)	return 0;
	if (out[curState][type] != 0) {
		return out[curState][type];
	}

	int value = curState, cntr = 0, val = 0, bVal = 0;
	while (value) {
		if (value % 2 == 1) {
			// | means, that the nodes present int curState, find their 'type' edges
			// and current state will be union of all those smaller states
			// in binary terms, OR
			val = val | in[cntr][type];
		}
		cntr++;
		value /= 2;
	}
	out[curState][type] = val;
}

void getDFA(int in[][2], int out[][2], int curState) {
	if (curState == 0) {
		// empty
		return;
	}

	// Builds the nodes recursively, and if already generated, no need to generate again
	if (out[curState][0] == 0) {
		fillState(in, out, curState, 0);
		getDFA(in, out, out[curState][0]);
	} else {
		return;
	}
	if (out[curState][1] == 0) {
		fillState(in, out, curState, 1);
		getDFA(in, out, out[curState][1]);
	} else {
		return;
	}
}

void printOutput(int arr[][2], int curState, int printed[]) {

	// If already printed, return
	if (printed[curState])	return;

	// Print currentState, and recursively print children
	// printState just gives the individual states from the binary representation
	printf("State ");
	printState(curState);
	putchar(':');
	printState(arr[curState][0]);
	printState(arr[curState][1]);
	printed[curState] = 1;
	printf("\n");
	printOutput(arr, arr[curState][0], printed);
	printOutput(arr, arr[curState][1], printed);
}

int main() {
	int arr[30000][2] = {{0}}, dfa[30000][2] = {{0}}, printed[30000] = {};
	int n;

	printf("Number of states in NFA: ");
	scanf("%d", &n);
	inputTable(arr, n);
	printTable(arr, n);

	// Example taken from: 
	// https://www.tutorialspoint.com/automata_theory/ndfa_to_dfa_conversion.htm
	int inputSt;
	printf("Initial State: ");	scanf("%d", &inputSt);
	printf("\nDFA obtained: \n\n");

	int startState = 1 << inputSt;
	getDFA(arr, dfa, startState);
	printOutput(dfa, startState, printed);
}
