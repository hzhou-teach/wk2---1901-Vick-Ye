#include<cstdio>
/*Vick Ye
 *38m 06s
 *10/10
 *shell numbers into indices
 */
int position[3] = {1, 2, 3};
int A[100], B[100], G[100];

void swap(int i, int j) {
	int temp = position[i];
	position[i] = position[j];
	position[j] = temp;
}

int main() {
	FILE * in = fopen("shell.in", "r");
	int n;
	fscanf(in, "%d", &n);
	for(int i = 0; i < n; i++) {
		fscanf(in, "%d %d %d", &A[i], &B[i], &G[i]);
	}
	fclose(in);
	
	int shellCount[3] = {0, 0, 0};

	for(int i = 0; i < n; i++) {
		swap(A[i] - 1, B[i] - 1);
		int chosen = position[G[i] - 1] - 1;
		shellCount[chosen] += 1;
	}

	//highest score is highest shell count
	int highestScore;
	if(shellCount[0] > shellCount[1]) {
		highestScore = shellCount[0];
	} else {
		highestScore = shellCount[1];
	}
	if(highestScore < shellCount[2]) {
		highestScore = shellCount[2];
	}

	FILE * out = fopen("shell.out", "w");
	fprintf(out, "%d", highestScore);
	fclose(out);
	return 0;
}
