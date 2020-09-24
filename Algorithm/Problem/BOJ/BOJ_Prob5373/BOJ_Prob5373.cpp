#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> Up;
vector<string> Down;
vector<string> Front;
vector<string> Back;
vector<string> Left;
vector<string> Right;

void init();
void Plane_rotate(vector<string>& Plane, bool dir);
void rotate(char plane, bool dir);

int main() {
	freopen("input.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		init();
		int N;
		bool dir;
		char plane, dir_c;
		scanf("%d\n", &N);
		for (int i = 0; i < N; i++) {
			scanf("%c %c ", &plane, &dir_c);
			if (dir_c == '+')
				dir = true;
			else
				dir = false;
			rotate(plane, dir);
		}

		for (int i = 0; i < 3; i++)
			printf("%s\n", Up[i].c_str());
	}
	return 0;
}

void init() {
	Up.clear();
	Up.resize(3, "www");
	Down.clear();
	Down.resize(3, "yyy");
	Front.clear();
	Front.resize(3, "rrr");
	Back.clear();
	Back.resize(3, "ooo");
	Left.clear();
	Left.resize(3, "ggg");
	Right.clear();
	Right.resize(3, "bbb");
}

void Plane_rotate(vector<string>& Plane, bool dir) {
	char temp = Plane[0][0];
	if (dir) {
		Plane[0][0] = Plane[2][0];
		Plane[2][0] = Plane[2][2];
		Plane[2][2] = Plane[0][2];
		Plane[0][2] = temp;

		temp = Plane[0][1];
		Plane[0][1] = Plane[1][0];
		Plane[1][0] = Plane[2][1];
		Plane[2][1] = Plane[1][2];
		Plane[1][2] = temp;
	}
	else {
		Plane[0][0] = Plane[0][2];
		Plane[0][2] = Plane[2][2];
		Plane[2][2] = Plane[2][0];
		Plane[2][0] = temp;

		temp = Plane[0][1];
		Plane[0][1] = Plane[1][2];
		Plane[1][2] = Plane[2][1];
		Plane[2][1] = Plane[1][0];
		Plane[1][0] = temp;
	}
}

void rotate(char plane, bool dir) {
	vector<string>* Plane = &Up;
	if (plane == 'U')
		Plane = &Up;
	else if (plane == 'D')
		Plane = &Down;
	else if (plane == 'F')
		Plane = &Front;
	else if (plane == 'B')
		Plane = &Back;
	else if (plane == 'L')
		Plane = &Left;
	else if (plane == 'R')
		Plane = &Right;

	Plane_rotate(*Plane, dir);

	if (plane == 'U' || plane == 'D') {
		int idx = (plane == 'U') ? 0 : 2;
		if (plane == 'D')
			dir = !dir;

		string temp = Front[idx];
		if (dir) {
			Front[idx] = Right[idx];
			Right[idx] = Back[idx];
			Back[idx] = Left[idx];
			Left[idx] = temp;
		}
		else {
			Front[idx] = Left[idx];
			Left[idx] = Back[idx];
			Back[idx] = Right[idx];
			Right[idx] = temp;
		}
	}
	else if (plane == 'F' || plane == 'B') {
		int idx1 = 2, idx2 = 0;
		if (plane == 'B') {
			swap(idx1, idx2);
			dir = !dir;
		}
		string temp = Up[idx1];
		if (dir) {
			Up[idx1][0] = Left[2][idx1];
			Up[idx1][1] = Left[1][idx1];
			Up[idx1][2] = Left[0][idx1];
			
			Left[2][idx1] = Down[idx2][2];
			Left[1][idx1] = Down[idx2][1];
			Left[0][idx1] = Down[idx2][0];

			Down[idx2][2] = Right[0][idx2];
			Down[idx2][1] = Right[1][idx2];
			Down[idx2][0] = Right[2][idx2];

			Right[0][idx2] = temp[0];
			Right[1][idx2] = temp[1];
			Right[2][idx2] = temp[2];
		}
		else {
			Up[idx1][0] = Right[0][idx2];
			Up[idx1][1] = Right[1][idx2];
			Up[idx1][2] = Right[2][idx2];

			Right[0][idx2] = Down[idx2][2];
			Right[1][idx2] = Down[idx2][1];
			Right[2][idx2] = Down[idx2][0];

			Down[idx2][2] = Left[2][idx1];
			Down[idx2][1] = Left[1][idx1];
			Down[idx2][0] = Left[0][idx1];

			Left[2][idx1] = temp[0];
			Left[1][idx1] = temp[1];
			Left[0][idx1] = temp[2];
		}
	}
	else {
		int idx1 = 0, idx2 = 2;
		if (plane == 'R') {
			swap(idx1, idx2);
			dir = !dir;
		}
		char temp1 = Up[0][idx1];
		char temp2 = Up[1][idx1];
		char temp3 = Up[2][idx1];

		if (dir) {
			Up[0][idx1] = Back[2][idx2];
			Up[1][idx1] = Back[1][idx2];
			Up[2][idx1] = Back[0][idx2];

			Back[2][idx2] = Down[0][idx1];
			Back[1][idx2] = Down[1][idx1];
			Back[0][idx2] = Down[2][idx1];

			Down[0][idx1] = Front[0][idx1];
			Down[1][idx1] = Front[1][idx1];
			Down[2][idx1] = Front[2][idx1];

			Front[0][idx1] = temp1;
			Front[1][idx1] = temp2;
			Front[2][idx1] = temp3;
		}
		else {
			Up[0][idx1] = Front[0][idx1];
			Up[1][idx1] = Front[1][idx1];
			Up[2][idx1] = Front[2][idx1];

			Front[0][idx1] = Down[0][idx1];
			Front[1][idx1] = Down[1][idx1];
			Front[2][idx1] = Down[2][idx1];

			Down[0][idx1] = Back[2][idx2];
			Down[1][idx1] = Back[1][idx2];
			Down[2][idx1] = Back[0][idx2];

			Back[2][idx2] = temp1;
			Back[1][idx2] = temp2;
			Back[0][idx2] = temp3;
		}
	}
}