#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Pass {
private:
	int size;//size of the amount of elements
	vector<string> elements;//vector of all elements
	string key;//the password
	string res;//the result
	vector <int> output;//the output at the end
public:
	void SetSize() { cout << "Set Size: "; int a; cin >> a; size = a; }//set size, key, res, and elements
	void SetKey() { cout << "Set Key "; string b; cin >> b; key = b; }
	void SetRes(const string c) { res = c; }
	void SetElements();
	int GetSize() { return size; }//accessor methods
	string GetKey() { return key; }
	string GetRes() { return res; }
	vector<string> GetElements() { return elements; }
	vector<int> GetOutput() { return output; }
	bool check(string res, const string key, const vector<string> &elements);//the recursion
};


void Pass::SetElements() {
	int x = size;
	cout << size << endl;
	for (int i = 0; i < x; i++) {

		cout << "Enter Set " << i << ": ";
		string temp;
		cin >> temp;
		elements.push_back(temp);

	}
}
bool Pass::check(string res, const string key, const vector<string> &elements) {
	int x;

	for (int i = 0; i < elements.size(); i++) {
		string tempres = res + elements[i];
		string tempkey = key.substr(0, tempres.length());
		if (tempres == key) {
			output.push_back(i);
			x = 1;
		}
		else if (tempres == tempkey) {
			output.push_back(i);
			check(tempres, key, elements);
		}
		if (x == 1) {
			return true;
		}
	}
}

int main() {

	Pass Password;
	Password.SetSize();
	Password.SetKey();
	Password.SetElements();


	if (!Password.check(Password.GetRes(), Password.GetKey(), Password.GetElements())) { //checks
		for (int i = 0; i < Password.GetOutput().size(); i++) {
			cout << Password.GetOutput()[i] << " ";
		}

	}
	else {
		cout << "Doesn't Work" << endl;


	}

}

