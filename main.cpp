#include<iostream>
#include <string>
#include<vector>

using namespace std;

struct NumTypes {
	int positive;
	int zero;
	int negative;
};

class MyMath {
	public:
		vector<int> _vec1;

		void printArrayAverage() {
			if (this->_vec1.empty()) {
				cout << "Array is empty" << endl;
			}
			else {
				int sum = 0;
				for (auto num : this->_vec1) sum += num;
				cout << "Array average: ";
				cout << sum / this->_vec1.size();
				cout << endl;
			}
		}

		void printArrayTypesCount() {
			NumTypes types = { 0, 0, 0 };

			for (auto num : this->_vec1) {
				if (num > 0) types.positive++;
				else if (num == 0) types.zero++;
				else types.negative++;
			}

			cout << "Positive: " << types.positive << endl;
			cout << "Zero: " << types.zero << endl;
			cout << "Negative: " << types.negative << endl;
		}

		void printArraySum(vector<int> secondVector) {
			int minSize = this->_vec1.size() > secondVector.size()
				? secondVector.size()
				: this->_vec1.size();

			for (int i = 0; i < minSize; i++) {
				cout << this->_vec1[i] + secondVector[i] << " ";
			}

			vector<int> maxVect = this->_vec1.size() > secondVector.size()
				? this->_vec1
				: secondVector;

			for (int i = minSize; i < maxVect.size(); i++) {
				cout << maxVect[i] << " ";
			}
		}
};

int main() {
	vector<int> vc2 = { 1,2,4,0 };

	MyMath math = { { 1,2,4, 0, -12, 11 } };
	math.printArrayAverage();
	math.printArrayTypesCount();
	math.printArraySum(vc2);
	return 0;
}