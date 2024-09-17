#include <bits/stdc++.h>
using namespace std;

const string spl ="--------------------------------------------------------------------------------------------";

struct person {
	string name;
	string number;
}; 

struct menu {
	vector<person> p;
	int len = 0;
	void get_all() {
		if (p.empty()) {
			cout << "\nĿǰû���κ���Ϣ" << "\n\n";
			return ; 
		}
		cout << "\n�û���Ϣ���£�" << endl; 
		for (int i = 0; i < len; ++i) {
			cout << endl << i + 1 << "\t" << p[i].name << "\t" << p[i].number << endl;
		}
		cout << "\n��" << len << "��\n" ; 
		cout << "\n";
		return ;
	};
	void add() {
		string name;
		string number;
		cout << "���������� ";
		cin >> name;
		cout << "������룺 ";
		cin >> number;
		person tem = {name, number};
		p.push_back(tem);
		len += 1;
	};
	void del() {
		int index;
		cout << "��������Ҫɾ���ļ����� " ;
		cin >> index;
		if (index < 1 || index > len) {
			cout << "\n���볬����Χ" << endl; 
			return ;
		}
		p.erase(p.begin() + index - 1);
		cout << "\nĿǰ��ɾ����" << index << "��\n\n" ; 
		len -= 1;
		return ;
	};
	void mod() {
		int index, i;
		cout << "��������Ҫ�޸ĵļ����� " ;
		cin >> index;
		if (index < 1 || index > len) {
			cout << "���볬����Χ" << endl; 
			return ;
		}
		cout << "�޸�����������1�� �޸ĺ�������2 ,�����������˳��� " ;
		cin >> i;
		if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n�������������" << endl;
        }
		if (i < 1 || i > 2) {
			cout << "\n�˳��޸�ģʽ" << endl; 
		} else if (i == 1) {
			cout << "������ " << index << ", ������ " << p[index - 1].name << endl;
			cout << "��������Ҫ�޸ĵ������� " ;
			cin >> p[index - 1].name;
			cout << "�޸ĳɹ���" << endl;
			cout << "������ " << index << ", ������ " << p[index - 1].name << endl;
		} else if (i == 2) {
			cout << "������ " << index << ", ���룺 " << p[index - 1].number << endl;
			cout << "��������Ҫ�޸ĵĺ��룺 " ;
			cin >> p[index - 1].number;
			cout << "�޸ĳɹ���" << endl;
			cout << "������ " << index << ", ���룺 " << p[index - 1].number << endl;
		}
		return ;
	}
	void file();
};

void menus(menu m) {
	int key;
	while (1) {
		cout << spl << "\n��ӭʹ��ͨѶ¼ϵͳ" << endl;
		cout << "����-1���˳�����" << endl;
		cout << "����1����ʾ������Ϣ" << endl;
		cout << "����2������û���Ϣ" << endl;
		cout << "����3��ɾ���û���Ϣ" << endl;
		cout << "����4���޸��û���Ϣ" << endl;
		cout << "�������룺 " ;
		
		cin >> key;
		cout << spl << endl;
		if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n�������������" << endl;
            continue;
        }
		
		if (key == -1) {
			break;
		} else if (key == 1) {
			m.get_all();
		} else if (key == 2) {
			m.add();
		} else if (key == 3) {
			m.del();
		} else if (key == 4) {
			m.mod();
		} else {
			cout << "\n�������������" << endl;
			continue;
		}
	}
	cout << "\n\n�����˳��ó���" << endl; 
}

int main() {
	menu m;
	menus(m); 
	return 0;
}

