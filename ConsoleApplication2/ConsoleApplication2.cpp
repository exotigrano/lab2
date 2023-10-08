#include <iostream> 
using namespace std;
int main() {
	locale::global(locale(""));
	int N;
	cout << "Введите размерность матрицы: "; cin >> N;
	int summa = 0;
	int** a = new int* [N];
	for (int n = 0; n < N; n++) {
		a[n] = new int[N];
		for (int m = 0; m < N; m++) {
			cout << "a[" << n << "][" << m << "] -> ";
			cin >> a[n][m];
			if (n == 0) summa += a[n][m];
		}
	} system("cls");
	for (int n = 0; n < N; n++, cout << endl)
		for (int m = 0; m < N; m++)
			cout << a[n][m] << ' ';
	int temp;
	bool flag = true;
	for (int n = 1; n < N; n++) {
		temp = 0;
		for (int m = 0; m < N; m++) temp += a[n][m];
		if (temp != summa) {
			flag = false;
			break;
		}
	}
	int main_diagonal = 0, collateral_diagonal = 0;
	for (int n = 0; n < N; n++)
		for (int m = 0; m < N; m++) {
			if (n == m) main_diagonal += a[n][m];
			if (n + m == N - 1) collateral_diagonal += a[n][m];
		}
	if (main_diagonal != summa || collateral_diagonal != summa) flag = false;
	if (flag) cout << endl << " Квадрат магический";
	else cout << endl << " Квадрат обыкновенный";
	for (int n = 0; n < N; n++) delete[] a[n];
	delete[] a;
	cin.get(); cin.get();
	return 0;
}