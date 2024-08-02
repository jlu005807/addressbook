#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include<iomanip>
#include<ctime>
#include<malloc.h>
using namespace std;

#define MAX 1000
void showtime(time_t x) {
	struct tm* p;
	p = localtime(&x);
	printf("      最后修改时间：%04d.%02d.%02d %02d:%02d:%02d", (p->tm_year + 1900), p->tm_mon + 1, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
}
bool isdigitall(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (!isdigit(str[i])) {
			return false;
		}
	}
	return true;
}
void showmenu() {
	cout << "*******通讯录管理系统*******" << endl
		<< "****************************" << endl
		<< "*****  1.添加联系人    *****" << endl
		<< "*****  2.显示联系人    *****" << endl
		<< "*****  3.删除联系人    *****" << endl
		<< "*****  4.查找联系人    *****" << endl
		<< "*****  5.修改联系人    *****" << endl
		<< "*****  6.清空通讯录    *****" << endl
		<< "*****  0.退出通讯录    *****" << endl
		<< "****************************" << endl;
	cout << "已显示主菜单" << endl;
	cout << "\n请选择功能:" ;
}
struct person {
	string name;
	string sex;
	string age;
	string phone[5];
	int phonesize=0;
	string address[5];
	int addresssize=0;
	time_t t;
};
struct addressbook {
	person personarray[MAX];
	int size;
};

void addperson(addressbook* abs) {
	if (abs->size == MAX) {
		cout << "通讯录已满,无法添加。" << endl;
		char c;
		while ((c = getchar()) != '\n');
		cin.clear();
		return;
	}
	else {
		cout << "请输入姓名：" << flush;
		cin >> abs->personarray[abs->size].name;
		char c;
		while ((c = getchar()) != '\n');
		cin.clear();
		cout << "请输入性别(不确认请填入null)："<<flush ;
		string sex;
		flag:
		cin >> sex;
		if (sex!="null"&&sex!="男"&&sex!="女") {
			cout << "输入有误，请重新输入：" << flush;
			while ((c = getchar()) != '\n');
			cin.clear();
			goto flag;
		}
		else 
		{
			abs->personarray[abs->size].sex = sex;
		}
		while ((c = getchar()) != '\n');
		cin.clear();
		cout << "请输入年龄(不确认请填入null)：" <<flush;
		string age;
		flag6:
		cin >> age;
		if (!isdigitall(age)&&age!="null") {
			cout << "输入有误，请重新输入：" << flush;
			while ((c = getchar()) != '\n');
			cin.clear();
			goto flag6;

		}
		else {
			abs->personarray[abs->size].age = age;
		}
		int flag1 = 1;
		string number;
		abs->personarray[abs->size].phonesize = 0;
		while (flag1) {
			if (abs->personarray[abs->size].phonesize == 5) {
				cout << "联系电话数量已满!" << endl;
				system("pause");
				flag1 = 0;
				continue;
			}
			char c;
			while ((c = getchar()) != '\n');
			cin.clear();
			cout << "请输入联系电话." << (abs->personarray[abs->size].phonesize)+1 << "(如果不确定请填入null):" << flush;
			flagphone:
			cin >> number;
			if (!isdigitall(number)&& number.compare("null") != 0) {
				cout << "输入有误，请重新输入：" << flush;
				char c;
				while ((c = getchar()) != '\n');
				cin.clear();
				goto flagphone;
			}
			else {
				if (number.compare("null") == 0) {
					abs->personarray[abs->size].phone[abs->personarray[abs->size].phonesize] = number;
					abs->personarray[abs->size].phonesize += 1;
					flag1 = 0;
				}
				else {
					abs->personarray[abs->size].phone[abs->personarray[abs->size].phonesize] = number;
					abs->personarray[abs->size].phonesize++;
				}
			}
		}
		int flag2 = 1;
		abs->personarray[abs->size].addresssize = 0;
		string address1;
		while (flag2) {
			if (abs->personarray[abs->size].addresssize == 5) {
				cout << "住址数量已满!" << endl;
				system("pause");
				flag2 = 0;
				continue;
			}
			char c;
			while ((c = getchar()) != '\n');
			cin.clear();
			cout << "请输入住址." << (abs->personarray[abs->size].addresssize)+1 << "(如果不确定请填入null):" << flush;
			cin >> address1;
			if (address1.compare("null") == 0) {
				abs->personarray[abs->size].address[abs->personarray[abs->size].addresssize] = address1;
				abs->personarray[abs->size].addresssize ++;
				flag2 = 0;
			}
			else {
				abs->personarray[abs->size].address[abs->personarray[abs->size].addresssize] = address1;
				abs->personarray[abs->size].addresssize++;
			}
		}
		abs->personarray[abs->size].t = time(0);
		abs->size++;
		cout << "添加成功" << endl;
		system("pause");
		system("cls");
	}
}

void showaddressbook(const addressbook*abs) {
	int i;
	if (abs->size == 0) {
		cout << "通讯录为空" << endl;
		char c;
		while ((c = getchar()) != '\n');
		cin.clear();
		system("pause");
		system("cls");
		return;
	}
	else{
	    for (i = 0; i < abs->size; i++) {
		int j = i;
		cout << "*************************************************" << endl;
		cout << "*********************联系人" << ++j <<"*********************"<< endl;
		cout << setiosflags(ios::left);
		cout << "*****姓名：" << setw(33) << abs->personarray[i].name<<"*****"<<endl;
		cout << "*****性别：" << setw(33) << abs->personarray[i].sex << "*****" << endl;
		cout << "*****年龄：" << setw(33) << abs->personarray[i].age << "*****" << endl;
		for (int k = 0; k < abs->personarray[i].phonesize; k++) {
			cout << "*****联系电话" << k+1<<"：" << setw(28) << abs->personarray[i].phone[k]<< "*****" << endl;
		}
		for (int k = 0; k < abs->personarray[i].addresssize; k++) {
			cout << "*****住址" << k + 1 << "：" << setw(32) << abs->personarray[i].address[k] << "*****" << endl;
		}
		cout <<"*****";showtime(abs->personarray[i].t); cout << "*****" << endl;
		cout << "*************************************************" << endl;
		
	   }
	if(i==abs->size)
	cout << "已显示所有联系人" << endl;
	
	}
	system("pause");
	system("cls");
}

int namefind(addressbook*abs) {
	string name;
	cout << "请输入您要查找的联系人姓名:" << flush;
	char c;
	while ((c = getchar()) != '\n');
	cin.clear();
	cin >> name;
	for (int i=0; i< abs->size; i++) {
		if (name.compare(abs->personarray[i].name) == 0) {
			cout << "查找成功" << endl;
			return i;
		}

	}
	cout << "查无此人" << endl;
	system("pause");
	system("cls");
	return -1;
}


int phonefind(addressbook*abs) {
	string phone;
	cout << "请输入您要查找的联系人电话:" << flush;
	char c;
	while ((c = getchar()) != '\n');
	cin.clear();
	cin >> phone;
	if (phone.compare("null") == 0) {
		cout << "无法查找" << endl;
		system("pause");
		system("cls");
		return -1;
	}
	for(int i=0;i<abs->size;i++)
		for (int k = 0; k < abs->personarray[i].phonesize; k++) {
			if (phone.compare(abs->personarray[i].phone[k]) == 0)return i;
		}
	cout << "查无此人" << endl;
	system("pause");
	system("cls");
	return -1;

}



int addressfind(addressbook*abs) {
	string address;
	cout << "请输入您要查找的联系人住址:" << flush;
	char c;
	while ((c = getchar()) != '\n');
	cin.clear();
	cin >> address;
	if (address.compare("null") == 0) {
		cout << "无法查找" << endl;
		system("pause");
		system("cls");
		return -1;
	}
	for (int i = 0; i < abs->size; i++)
		for (int k = 0; k < abs->personarray[i].addresssize; k++) {
			if (address.compare(abs->personarray[i].address[k]) == 0)return i;
		}
	cout << "查无此人" << endl;
	system("pause");
	system("cls");
	return -1;

}

void delectperson(addressbook*abs) {
	if (abs->size == 0) {
		cout << "通讯录为空" << endl;
		char c;
		while ((c = getchar()) != '\n');
		cin.clear();
		system("pause");
		system("cls");

	}
	else {
		int choice,n;
		string v;
		char c;
		while ((c = getchar()) != '\n');
		cin.clear();
		cout << "请选择查找方式：\n1.姓名  2.联系电话  3.住址  4.返回"<<endl;
	    flagdelect:
		cin >> v;
		if (size(v) == 1 && isdigit(v[0])) {
			choice = (int)v[0] - 48;
		}
		else {
			cout << "输入有误，请重新输入:" << flush;
			char c;
			while ((c = getchar()) != '\n');
			cin.clear();
			goto flagdelect;
		}
	    flag:
		switch(choice){
		case 1:n = namefind(abs); break;
		case 2:n = phonefind(abs); break;
		case 3:n = addressfind(abs); break;
		case 4:cout << "返回成功" << endl; system("pause"); system("cls"); return;
		default:
			cout << "输入有误" << endl;
			system("pause");
			cout << "请重新输入:" << flush;
			goto flag;
		}
		if (n != -1) {
			cout << "*************************************************" << endl;
			cout << "*********************联系人" << n+1 << "*********************" << endl;
			cout<< setiosflags(ios::left);
			cout << "姓名：" << setw(38) <<abs->personarray[n].name <<"*****"<< endl;
			cout << "性别：" << setw(38)  <<abs->personarray[n].sex << "*****" << endl;
			cout << "年龄：" << setw(38) <<abs->personarray[n].age << "*****" << endl;
			for (int k = 0; k < abs->personarray[n].phonesize; k++) {
				cout << "联系电话" <<   k + 1 << "：" << setw(33) << abs->personarray[n].phone[k] << "*****" << endl;
			}
			for (int k = 0; k < abs->personarray[n].addresssize; k++) {
				cout << "住址" << k + 1 << "：" << setw(37) << abs->personarray[n].address[k] << "*****" << endl;
			}
			cout << "*****"; showtime(abs->personarray[n].t); cout << "*****" << endl;
			cout << "*************************************************" << endl;
			cout << "是否确定删除此联系人?" << endl << "1.确定  2.取消" << endl;
			int v;
			cin >> v;
			switch (v) {
			case 1:{
			for (int i = n; i < abs->size; i++)
				abs->personarray[i] = abs->personarray[i + 1];
			abs->size--;
			cout << "删除成功" << endl; break;
			}
			case 2:cout << "取消成功" << endl; system("pause"); system("cls"); return;
			}
			
		}
		system("pause");
		system("cls");
	}
}
void modifyperson(addressbook*abs){
	if (abs->size == 0) {
		cout << "通讯录为空" << endl;
		char c;
		while ((c = getchar()) != '\n');
		cin.clear();
		system("pause");
		system("cls");
	}
	else {
		int choice, n;
		string v;
		cout << "请选择查找方式：\n1.姓名  2.联系电话  3.住址  4.返回" << endl;
	    flagmodify:
		cin >> v;
		if (size(v) == 1 && isdigit(v[0])) {
			choice = (int)v[0] - 48;
		}
		else {
			cout << "输入有误，请重新输入:";
			char c;
			while ((c = getchar()) != '\n');
			cin.clear();
			goto flagmodify;
		}
		flag:
		switch (choice) {
		case 1:n = namefind(abs); break;
		case 2:n = phonefind(abs); break;
		case 3:n = addressfind(abs); break;
		case 4:cout << "返回成功" << endl; system("pause"); system("cls"); return;
		default:
			cout << "输入有误" << endl;
			system("pause");
			cout << "请重新输入:";
			goto flag;
		}
		if (n != -1) {
			int choose;
			cout << "*************************************************" << endl;
			cout << "*********************联系人" << n + 1 << "*********************" << endl;
			cout << setiosflags(ios::left);
			cout << "姓名：" << setw(38) << abs->personarray[n].name << "*****" << endl;
			cout << "性别：" << setw(38) << abs->personarray[n].sex << "*****" << endl;
			cout << "年龄：" << setw(38) << abs->personarray[n].age << "*****" << endl;
			for (int k = 0; k < abs->personarray[n].phonesize; k++) {
				cout << "联系电话" << k + 1 << "：" << setw(33) << abs->personarray[n].phone[k] << "*****" << endl;
			}
			for (int k = 0; k < abs->personarray[n].addresssize; k++) {
				cout << "住址" << k + 1 << "：" << setw(37) << abs->personarray[n].address[k] << "*****" << endl;
			}
			cout << "*****"; showtime(abs->personarray[n].t); cout << "*****" << endl;
			cout << "*************************************************" << endl;
			cout << "请选择修改内容：\n1.姓名  2.性别  3.年龄  4.联系电话  5.住址  6.重新编写" << endl;
			cin >> choose;
			abs->personarray[n].t = time(0);
			switch (choose) {
			case 1:cout << "请输入修改后的姓名：" << flush; cin >> abs->personarray[n].name; break;
			case 2:cout << "请输入修改后的性别：" << flush; cin >> abs->personarray[n].sex; break;
			case 3:cout << "请输入修改后的年龄：" << flush; cin >> abs->personarray[n].age; break;
			case 4:{
				int flag1 = 1;
				string number;
				abs->personarray[n].phonesize = 0;
				while (flag1) {
					if (abs->personarray[n].phonesize == 5) {
						cout << "联系电话数量已满!" << endl;
						system("pause");
						flag1 = 0;
						continue;
					}
					cout << "请输入修改后的联系电话." << flush << (abs->personarray[n].phonesize) + 1 << "(如果不确定请填入null)" << endl;

					cin >> number;
					if (number.compare("null") == 0) {
						abs->personarray[n].phone[abs->personarray[n].phonesize] = number;
						abs->personarray[n].phonesize += 1;
						flag1 = 0;
					}
					else {
						abs->personarray[n].phone[abs->personarray[n].phonesize] = number;
						abs->personarray[n].phonesize++;
					}
				}
				break;
			}
			case 5:{
				int flag2 = 1;
				abs->personarray[n].addresssize = 0;
				string address1;
				while (flag2) {
					if (abs->personarray[n].addresssize == 5) {
						cout << "住址数量已满!" << endl;
						system("pause");
						flag2 = 0;
						continue;
					}
					cout << "请输入住址." << (abs->personarray[n].addresssize) + 1 << "(如果不确定请填入null)" << endl;
					cin >> address1;
					if (address1.compare("null") == 0) {
						abs->personarray[n].address[abs->personarray[n].addresssize] = address1;
						abs->personarray[n].addresssize++;
						flag2 = 0;
					}
					else {
						abs->personarray[n].address[abs->personarray[n].addresssize] = address1;
						abs->personarray[n].addresssize++;
					}
				}
				break;
			}
			case 6:{
				cout << "请输入修改后的姓名：" << flush;
				cin >> abs->personarray[n].name;
				cout << "请输入修改后的性别：" << flush;
				string sex;
			    flagsex:
				cin >> sex;
				if (sex != "null" && sex != "男" && sex != "女") {
					cout << "输入有误，请重新输入：" << flush;
					char c;
					while ((c = getchar()) != '\n');
					cin.clear();
					goto flagsex;
				}
				else
				{
					abs->personarray[n].sex = sex;
				}
				cout << "请输入修改后的年龄：" << flush;
				cin >> abs->personarray[n].age;
				int flag1 = 1;
				string number;
				abs->personarray[n].phonesize = 0;
				while (flag1) {
					if (abs->personarray[n].phonesize == 5) {
						cout << "联系电话数量已满!" << endl;
						system("pause");
						flag1 = 0;
						continue;
					}
					cout << "请输入修改后的联系电话." << (abs->personarray[n].phonesize) + 1 << "(如果不确定请填入null):" << flush;

					cin >> number;
					if (number.compare("null") == 0) {
						abs->personarray[n].phone[abs->personarray[n].phonesize] = number;
						abs->personarray[n].phonesize += 1;
						flag1 = 0;
					}
					else {
						abs->personarray[n].phone[abs->personarray[n].phonesize] = number;
						abs->personarray[n].phonesize++;
					}
				}
				int flag2 = 1;
				abs->personarray[n].addresssize = 0;
				string address1;
				while (flag2) {
					if (abs->personarray[n].addresssize == 5) {
						cout << "住址数量已满!" << endl;
						system("pause");
						flag2 = 0;
						continue;
					}
					cout << "请输入修改后的住址." << (abs->personarray[n].addresssize) + 1 << "(如果不确定请填入null):" << flush;
					cin >> address1;
					if (address1.compare("null") == 0) {
						abs->personarray[n].address[abs->personarray[n].addresssize] = address1;
						abs->personarray[n].addresssize++;
						flag2 = 0;
					}
					else {
						abs->personarray[n].address[abs->personarray[n].addresssize] = address1;
						abs->personarray[n].addresssize++;
					}
				}
				break;
			}
			default:
				cout << "输入有误" << endl;
				system("pause");
				system("cls");
				return;
			}	
		cout << "修改成功" << endl;
		system("pause");
		system("cls");
     }
	}
    
}
void findperson(addressbook*abs){
	if (abs->size == 0) {
		cout << "通讯录为空" << endl;
		system("pause");
		system("cls");

	}
	else {
		int choice, n;
		string v;
		cout << "请选择查找方式：\n1.姓名  2.联系电话  3.住址  4.返回" << endl;
	    flagfind:
		cin >> v;
		if (size(v) == 1 && isdigit(v[0])) {
			choice = (int)v[0] - 48;
		}
		else {
			cout << "输入有误，请重新输入:" << flush;
			char c;
			while ((c = getchar()) != '\n');
			cin.clear();
			goto flagfind;
		}
		switch (choice) {
		case 1:n = namefind(abs); break;
		case 2:n = phonefind(abs); break;
		case 3:n = addressfind(abs); break;
		case 4:cout << "返回成功" << endl; system("pause"); system("cls"); return;
		default:
			cout << "输入有误" << endl;
			system("pause");
			system("cls");
			return;
		}
		if (n != -1) {
			cout << "*************************************************" << endl;
			cout << "*********************联系人" << n+1<< "*********************" << endl;
			cout << setiosflags(ios::left);
			cout << "姓名：" << setw(38) << abs->personarray[n].name <<"*****"<< endl;
			cout << "性别：" << setw(38) << abs->personarray[n].sex << "*****" << endl;
			cout << "年龄：" << setw(38) << abs->personarray[n].age << "*****" << endl;
			for (int k = 0; k < abs->personarray[n].phonesize; k++) {
				cout << "联系电话" << k + 1 << "：" << setw(33) << abs->personarray[n].phone[k] << "*****" << endl;
			}
			for (int k = 0; k < abs->personarray[n].addresssize; k++) {
				cout << "住址" << k + 1 << "：" << setw(37) << abs->personarray[n].address[k] << "*****" << endl;
			}
			cout << "*****"; showtime(abs->personarray[n].t); cout << "*****" << endl;
			cout << "*************************************************" << endl;
	
			cout<<"已显示完成" << endl;
		}
		system("pause");
		system("cls");
	}

}
void cleanaddressbook(addressbook*abs) {
	if (abs->size == 0) {
		cout << "通讯录为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "是否确定清空通讯录：" << endl << "1.确定  2.取消" << endl;
	string v;
	int choice;
	flagclear:
	cin >> v;
	if (size(v) == 1 && isdigit(v[0])) {
		choice = (int)v[0] - 48;
	}
	else {
		cout << "输入有误，请重新输入:";
		char c;
		while ((c = getchar()) != '\n');
		cin.clear();
		goto flagclear;
	}
	switch (choice) {
	case 1: {
		abs->size = 0;
		cout << "已完成清空通讯录" << endl;
		system("pause");
		system("cls");
		break;
	}
	case 2:cout << "取消成功" << endl; system("pause"); system("cls"); return;
	}
}
void end() {
	cout << "是否确定退出通讯录：" << endl << "1.确定  2.取消" << endl;
	int choice;
	string v;
    flagend:
	cin >> v;
	if (size(v) == 1 && isdigit(v[0])) {
		choice = (int)v[0] - 48;
	}
	else {
		cout << "输入有误，请重新输入:";
		char c;
		while ((c = getchar()) != '\n');
		cin.clear();
		goto flagend;
	}
	switch (choice) {
	case 1: {	
		cout << "欢迎下次使用" << endl;
		system("pause");
		system("cls");
		exit(0); 
		break;
	}
	case 2:cout << "取消成功" << endl; system("pause"); system("cls"); return;
	}
}

int main(){
	addressbook abs;
	abs.size = 0;
	int select;
	string v;
	char c;
	system("cls");
	while (1) {
	showmenu();
    flag:
	cin >> v;
	if (size(v)==1&&isdigit(v[0])) {
		select = (int)v[0] - 48;
	}
	else {
		cout << "输入有误，请重新输入:" ;
		char c;
		while ((c = getchar()) != '\n');
		cin.clear();
		goto flag;
	}
	
	cout << "*************************************************" << endl;
		switch (select) {
		case 0: end(); break;
		case 1:cout << "请添加联系人" << endl; addperson(&abs); break;
		case 2:showaddressbook(&abs); break;
		case 3:delectperson(&abs); break;
		case 4:findperson(&abs); break;
		case 5:modifyperson(&abs); break;
		case 6:cleanaddressbook(&abs); break;
		default: 
			cout << "您输入有误，请重新输入" << endl;
			system("pause");
			system("cls");
			continue;
		}
		cout << "请按任意键并回车继续" << endl;
		system("cls");
	}
}

