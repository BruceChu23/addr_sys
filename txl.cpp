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
			cout << "\n目前没有任何信息" << "\n\n";
			return ; 
		}
		cout << "\n用户信息如下：" << endl; 
		for (int i = 0; i < len; ++i) {
			cout << endl << i + 1 << "\t" << p[i].name << "\t" << p[i].number << endl;
		}
		cout << "\n共" << len << "人\n" ; 
		cout << "\n";
		return ;
	};
	void add() {
		string name;
		string number;
		cout << "输入姓名： ";
		cin >> name;
		cout << "输入号码： ";
		cin >> number;
		person tem = {name, number};
		p.push_back(tem);
		len += 1;
	};
	void del() {
		int index;
		cout << "请输入需要删除的检索： " ;
		cin >> index;
		if (index < 1 || index > len) {
			cout << "\n输入超出范围" << endl; 
			return ;
		}
		p.erase(p.begin() + index - 1);
		cout << "\n目前已删除第" << index << "条\n\n" ; 
		len -= 1;
		return ;
	};
	void mod() {
		int index, i;
		cout << "请输入需要修改的检索： " ;
		cin >> index;
		if (index < 1 || index > len) {
			cout << "输入超出范围" << endl; 
			return ;
		}
		cout << "修改姓名请输入1， 修改号码输入2 ,输入其他则退出： " ;
		cin >> i;
		if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n输入错误，请重试" << endl;
        }
		if (i < 1 || i > 2) {
			cout << "\n退出修改模式" << endl; 
		} else if (i == 1) {
			cout << "检索： " << index << ", 姓名： " << p[index - 1].name << endl;
			cout << "请输入需要修改的姓名： " ;
			cin >> p[index - 1].name;
			cout << "修改成功！" << endl;
			cout << "检索： " << index << ", 姓名： " << p[index - 1].name << endl;
		} else if (i == 2) {
			cout << "检索： " << index << ", 号码： " << p[index - 1].number << endl;
			cout << "请输入需要修改的号码： " ;
			cin >> p[index - 1].number;
			cout << "修改成功！" << endl;
			cout << "检索： " << index << ", 号码： " << p[index - 1].number << endl;
		}
		return ;
	}
	void file();
};

void menus(menu m) {
	int key;
	while (1) {
		cout << spl << "\n欢迎使用通讯录系统" << endl;
		cout << "输入-1：退出程序" << endl;
		cout << "输入1：显示储存信息" << endl;
		cout << "输入2：添加用户信息" << endl;
		cout << "输入3：删除用户信息" << endl;
		cout << "输入4：修改用户信息" << endl;
		cout << "您的输入： " ;
		
		cin >> key;
		cout << spl << endl;
		if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n输入错误，请重试" << endl;
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
			cout << "\n输入错误，请重试" << endl;
			continue;
		}
	}
	cout << "\n\n您已退出该程序" << endl; 
}

int main() {
	menu m;
	menus(m); 
	return 0;
}

