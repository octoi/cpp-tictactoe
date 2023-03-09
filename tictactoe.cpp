#include <iostream>

using namespace std;

void printBoard(int (&board)[9]) {
	for(int i = 0; i < 9; i++) {
		cout << "| ";

		switch(board[i]) {
			case 10:
				cout << "X";
				break;
			case 11:
				cout << "O";
				break;
			default:
			cout << board[i];
		}

		cout << " ";

		if ((i + 1) % 3 == 0) {
			cout << "|\n";
		}
	}
	cout << "\n";
}

int getInputAndValidate(int (&board)[9]) {
	int n;

	cout << "Enter number: ";
	cin >> n;

	while(board[n - 1] == 10 || board[n - 1] == 11) {
		cout << "Enter number: ";
		cin >> n;
	}

	return n;
}

bool checkWinner(int (&arr)[9]) {
	int winner = 0;

	//  First line parrallel case
	if (arr[0] == arr[1] && arr[0] == arr[2]) {
		winner = arr[0];
	}

	// Second line parrallel case
	if (arr[3] == arr[4] && arr[3] == arr[5]) {
		winner = arr[3];
	}

	// Third line parrallel case
	if (arr[6] == arr[7] && arr[6] == arr[8]) {
		winner = arr[6];
	}

	// First vertical case
	if (arr[0] == arr[3] && arr[0] == arr[6]) {
		winner = arr[0];
	}

	// Second vertical case
    if (arr[1] == arr[4] && arr[1] == arr[7]) {
		winner = arr[1];
    }

    // Third vertical case
    if (arr[2] == arr[5] && arr[2] == arr[8]) {
		winner = arr[2];
    }

    // Top left to bottom right diagnoal
    if (arr[0] == arr[4] && arr[0] == arr[8]) {
		winner = arr[0];
    }

    // Top right to bottom left diagnoal
    if (arr[2] == arr[4] && arr[2] == arr[8]) {
		winner = arr[2];
    }

	if (winner == 10) {
		cout << "X is the winner" << endl;
		return true;
	}

	if (winner == 11) {
		cout << "O is the winner" << endl;
		return true;
	}

	return false;
}

int main() {
	int board[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	bool isLastX = false;

	printBoard(board);

	while(!checkWinner(board)) {
		int val = getInputAndValidate(board);
		board[val - 1] = isLastX ? 11 : 10;
		isLastX = !isLastX;
		printBoard(board);
	}

	return 0;
}

