#include <iostream>
#include <string>

int BoyerMoor(string t, string w) {
	int i = w.size() - 1;
	int j = i;
	int lastOccurence = 0;
	do {
		if (t[i] == w[j]) {
			if (j == 0)
				return i;
			else {
				i--;
				j--;
			}
		}
		else {
			lastOccurence = -1;
			for (int ii = 0; ii < w.size(); ii++) {
				if (w[ii] == t[i])
					lastOccurence = ii;
			}
			i += w.size() - min(j, 1 + lastOccurence);
			j = w.size() - 1;
		}
	} while (i < t.size() - 1);
	return -1;
}

void bm(string& tablica, string& wzorzec) {
	int index = 0;
	int s;
	bool indexChanged;
	while (index < tablica.size()) {
		indexChanged = false;
		for (int i = wzorzec.size() - 1; i >= 0; i--) {
			if ((index + i) >= tablica.size())
				return;
			if (tablica[index + i] != wzorzec[i]) {
				for (s = 0; s < wzorzec.size(); s++) {
					if (wzorzec[s] == tablica[index + i]) {
						index += wzorzec.size() - s - 1;
						indexChanged = true;
						break;
					}
				}
				if (!indexChanged) {
					index += wzorzec.size();
					indexChanged = true;
				}
			}
		}
		if (!indexChanged) {
			cout << "TUTEJ JEST: " << index << endl;
			index++;
		}
	}

}

int main() {
	string tablica = "67212316723871236128123";
	string wzorzec = "123";

	cout << tablica << endl;

	bm(tablica, wzorzec);

	return 0;
}