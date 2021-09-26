#include<iostream>
#include<fstream>
/*Vick Ye
 *1h 51m 41s
 *10/10
 *strings and organizing animals and characteristics
 */
//array representing potential guesses, with inner array representing characteristics
std::string A[100][100];
int characteristics[100];

int commonTrait(int a, int b) {
	//if they are the same then dont count
	if(a == b) {
		return 0;
	}
	int count = 0;
	//loop through characteristics of index a
	for(int i = 0; i < characteristics[a]; i++) {
		//loop through characteristics of index b
		for(int j = 0; j < characteristics[b]; j++) {
			if(A[a][i] == A[b][j]) {
				count += 1;
			}
		}
	}
	return count;
}

int main() {
	std::ifstream in("guess.in");
	int n;
	in >> n;
	for(int i = 0; i < n; i++) {
		std::string name;
		in >> name >> characteristics[i];
		for(int j = 0; j < characteristics[i]; j++) {
			in >> A[i][j];
		}
	}
	in.close();
	
	int most = 0;
	//first set of traits
	for(int i = 0; i < n; i++) {
		//second set of traits
		for(int j = 0; j < n; j++) {
			int count = commonTrait(i, j);
			//max yes = amt of same traits + 1
			//1 represents unique trait narrowing down the potential to 1
			//amt of same traits represents questions that dont narrow down that much
			count += 1;
			if(most < count) {
				most = count;
			}
		}
	}

	std::ofstream out ("guess.out");
	out << most;
	out.close();
	return 0;
}
