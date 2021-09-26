#include<cstdio>
/*Vick Ye
 *time
 *score
 *...
 */

int cows[100];
bool ordered(int begin, int end) {
	int previous = cows[begin];
	for(int i = begin + 1; i < end; i++) {
		if(cows[i] >= previous) {
			previous = cows[i];
		} else {
			return false;
		}
	}
	return true;
}

void shiftL(int position) {
	int temp = cows[0];
	for(int i = 0; i < position; i++) {
		cows[i] = cows[i + 1];
	}
	cows[position] = temp;
}

int main() {
	FILE * in = fopen("sleepy.in", "r");
	int n;
	fscanf(in, "%d", &n);
	for(int i = 0; i < n; i++) {
		fscanf(in, "%d", &cows[i]);
	}
	fclose(in);

	int steps = 0;
	while(!ordered(0, n)) {
		int c = cows[0];
		int position = n - 1;
		//loop from back to front
		for(int i = n - 1; i >= 0; i--) {
			//potential positions
			if(c < cows[i]) {
				//if everything above potential position is ordered
				if(ordered(i, n)) {
					position = i - 1;
				} else {
				//if anything above current potential is not ordered
				//any position under is not ordered
					break;
				}
			}
		}
		//if no potential position is chosen, send to end
		shiftL(position);
		steps += 1;
	}
	FILE * out = fopen("sleepy.out", "w");
	fprintf(out, "%d", steps);
	fclose(out);
	return 0;
}
