#include <iostream>
using namespace std;

struct Question {
	int total, correct, score, wrongNums;
	char answer[5];
	friend istream& operator >> (istream& i, Question &q);
};
istream& operator >> (istream& is, Question &q) {
	is >> q.score >> q.total >> q.correct;
	for (size_t i = 0; i < q.correct; i++) {
		is >> q.answer[i];
	}
	return is;
}

int main(int argc, char const *argv[]) {
	int N, M, score[1000] = { 0 };
	Question question[100];

	cin >> N >> M;
	for (size_t i = 0; i < M; i++) {
		cin >> question[i];
		question[i].wrongNums = 0;
	}
	// for (size_t i = 0; i < M; i++) {
	//     cout << question[i].score << question[i].total << question[i].correct;
	//     for (size_t j = 0; j < question[i].correct; j++) {
	//         cout << question[i].answer[j];
	//     }
	//     cout << endl;
	// }
	for (size_t i = 0; i < N; i++) {
		char ch;
		int n;
		for (size_t j = 0; j < M; j++) {
			while ((ch = cin.get()) != '(');
			cin >> n;
			if (n != question[j].correct) {
				++question[j].wrongNums;
				while ((ch = cin.get()) != ')');
				continue;
			}

			size_t k = 0;
			for (; k < n; k++) {
				cin >> ch;
				if (ch != question[j].answer[k]) {
					++question[j].wrongNums;
					while ((ch = cin.get()) != ')');
					break;
				}
			}
			if (k == n) {
				score[i] += question[j].score;
			}
		}
	}

	for (size_t i = 0; i < N; i++) {
		cout << score[i] << endl;
	}

	int max = 0, tag = 0;
	for (size_t i = 0; i < M; i++) {
		if (question[i].wrongNums > max)
			max = question[i].wrongNums;
	}
	if (max == 0)
		cout << "Too simple";
	else {
		cout << max;
		for (size_t i = 0; i < M; i++) {
			if (question[i].wrongNums == max)
				cout << " " << i + 1;
		}
	}
	return 0;
}