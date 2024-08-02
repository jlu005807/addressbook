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
	printf("      ����޸�ʱ�䣺%04d.%02d.%02d %02d:%02d:%02d", (p->tm_year + 1900), p->tm_mon + 1, p->tm_mday, p->tm_hour, p->tm_min, p->tm_sec);
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
	cout << "*******ͨѶ¼����ϵͳ*******" << endl
		<< "****************************" << endl
		<< "*****  1.������ϵ��    *****" << endl
		<< "*****  2.��ʾ��ϵ��    *****" << endl
		<< "*****  3.ɾ����ϵ��    *****" << endl
		<< "*****  4.������ϵ��    *****" << endl
		<< "*****  5.�޸���ϵ��    *****" << endl
		<< "*****  6.���ͨѶ¼    *****" << endl
		<< "*****  0.�˳�ͨѶ¼    *****" << endl
		<< "****************************" << endl;
	cout << "����ʾ���˵�" << endl;
	cout << "\n��ѡ����:" ;
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
		cout << "ͨѶ¼����,�޷����ӡ�" << endl;
		char c;
		while ((c = getchar()) != '\n');
		cin.clear();
		return;
	}
	else {
		cout << "������������" << flush;
		cin >> abs->personarray[abs->size].name;
		char c;
		while ((c = getchar()) != '\n');
		cin.clear();
		cout << "�������Ա�(��ȷ��������null)��"<<flush ;
		string sex;
		flag:
		cin >> sex;
		if (sex!="null"&&sex!="��"&&sex!="Ů") {
			cout << "�����������������룺" << flush;
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
		cout << "����������(��ȷ��������null)��" <<flush;
		string age;
		flag6:
		cin >> age;
		if (!isdigitall(age)&&age!="null") {
			cout << "�����������������룺" << flush;
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
				cout << "��ϵ�绰��������!" << endl;
				system("pause");
				flag1 = 0;
				continue;
			}
			char c;
			while ((c = getchar()) != '\n');
			cin.clear();
			cout << "��������ϵ�绰." << (abs->personarray[abs->size].phonesize)+1 << "(�����ȷ��������null):" << flush;
			flagphone:
			cin >> number;
			if (!isdigitall(number)&& number.compare("null") != 0) {
				cout << "�����������������룺" << flush;
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
				cout << "סַ��������!" << endl;
				system("pause");
				flag2 = 0;
				continue;
			}
			char c;
			while ((c = getchar()) != '\n');
			cin.clear();
			cout << "������סַ." << (abs->personarray[abs->size].addresssize)+1 << "(�����ȷ��������null):" << flush;
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
		cout << "���ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}

void showaddressbook(const addressbook*abs) {
	int i;
	if (abs->size == 0) {
		cout << "ͨѶ¼Ϊ��" << endl;
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
		cout << "*********************��ϵ��" << ++j <<"*********************"<< endl;
		cout << setiosflags(ios::left);
		cout << "*****������" << setw(33) << abs->personarray[i].name<<"*****"<<endl;
		cout << "*****�Ա�" << setw(33) << abs->personarray[i].sex << "*****" << endl;
		cout << "*****���䣺" << setw(33) << abs->personarray[i].age << "*****" << endl;
		for (int k = 0; k < abs->personarray[i].phonesize; k++) {
			cout << "*****��ϵ�绰" << k+1<<"��" << setw(28) << abs->personarray[i].phone[k]<< "*****" << endl;
		}
		for (int k = 0; k < abs->personarray[i].addresssize; k++) {
			cout << "*****סַ" << k + 1 << "��" << setw(32) << abs->personarray[i].address[k] << "*****" << endl;
		}
		cout <<"*****";showtime(abs->personarray[i].t); cout << "*****" << endl;
		cout << "*************************************************" << endl;
		
	   }
	if(i==abs->size)
	cout << "����ʾ������ϵ��" << endl;
	
	}
	system("pause");
	system("cls");
}

int namefind(addressbook*abs) {
	string name;
	cout << "��������Ҫ���ҵ���ϵ������:" << flush;
	char c;
	while ((c = getchar()) != '\n');
	cin.clear();
	cin >> name;
	for (int i=0; i< abs->size; i++) {
		if (name.compare(abs->personarray[i].name) == 0) {
			cout << "���ҳɹ�" << endl;
			return i;
		}

	}
	cout << "���޴���" << endl;
	system("pause");
	system("cls");
	return -1;
}


int phonefind(addressbook*abs) {
	string phone;
	cout << "��������Ҫ���ҵ���ϵ�˵绰:" << flush;
	char c;
	while ((c = getchar()) != '\n');
	cin.clear();
	cin >> phone;
	if (phone.compare("null") == 0) {
		cout << "�޷�����" << endl;
		system("pause");
		system("cls");
		return -1;
	}
	for(int i=0;i<abs->size;i++)
		for (int k = 0; k < abs->personarray[i].phonesize; k++) {
			if (phone.compare(abs->personarray[i].phone[k]) == 0)return i;
		}
	cout << "���޴���" << endl;
	system("pause");
	system("cls");
	return -1;

}



int addressfind(addressbook*abs) {
	string address;
	cout << "��������Ҫ���ҵ���ϵ��סַ:" << flush;
	char c;
	while ((c = getchar()) != '\n');
	cin.clear();
	cin >> address;
	if (address.compare("null") == 0) {
		cout << "�޷�����" << endl;
		system("pause");
		system("cls");
		return -1;
	}
	for (int i = 0; i < abs->size; i++)
		for (int k = 0; k < abs->personarray[i].addresssize; k++) {
			if (address.compare(abs->personarray[i].address[k]) == 0)return i;
		}
	cout << "���޴���" << endl;
	system("pause");
	system("cls");
	return -1;

}

void delectperson(addressbook*abs) {
	if (abs->size == 0) {
		cout << "ͨѶ¼Ϊ��" << endl;
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
		cout << "��ѡ����ҷ�ʽ��\n1.����  2.��ϵ�绰  3.סַ  4.����"<<endl;
	    flagdelect:
		cin >> v;
		if (size(v) == 1 && isdigit(v[0])) {
			choice = (int)v[0] - 48;
		}
		else {
			cout << "������������������:" << flush;
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
		case 4:cout << "���سɹ�" << endl; system("pause"); system("cls"); return;
		default:
			cout << "��������" << endl;
			system("pause");
			cout << "����������:" << flush;
			goto flag;
		}
		if (n != -1) {
			cout << "*************************************************" << endl;
			cout << "*********************��ϵ��" << n+1 << "*********************" << endl;
			cout<< setiosflags(ios::left);
			cout << "������" << setw(38) <<abs->personarray[n].name <<"*****"<< endl;
			cout << "�Ա�" << setw(38)  <<abs->personarray[n].sex << "*****" << endl;
			cout << "���䣺" << setw(38) <<abs->personarray[n].age << "*****" << endl;
			for (int k = 0; k < abs->personarray[n].phonesize; k++) {
				cout << "��ϵ�绰" <<   k + 1 << "��" << setw(33) << abs->personarray[n].phone[k] << "*****" << endl;
			}
			for (int k = 0; k < abs->personarray[n].addresssize; k++) {
				cout << "סַ" << k + 1 << "��" << setw(37) << abs->personarray[n].address[k] << "*****" << endl;
			}
			cout << "*****"; showtime(abs->personarray[n].t); cout << "*****" << endl;
			cout << "*************************************************" << endl;
			cout << "�Ƿ�ȷ��ɾ������ϵ��?" << endl << "1.ȷ��  2.ȡ��" << endl;
			int v;
			cin >> v;
			switch (v) {
			case 1:{
			for (int i = n; i < abs->size; i++)
				abs->personarray[i] = abs->personarray[i + 1];
			abs->size--;
			cout << "ɾ���ɹ�" << endl; break;
			}
			case 2:cout << "ȡ���ɹ�" << endl; system("pause"); system("cls"); return;
			}
			
		}
		system("pause");
		system("cls");
	}
}
void modifyperson(addressbook*abs){
	if (abs->size == 0) {
		cout << "ͨѶ¼Ϊ��" << endl;
		char c;
		while ((c = getchar()) != '\n');
		cin.clear();
		system("pause");
		system("cls");
	}
	else {
		int choice, n;
		string v;
		cout << "��ѡ����ҷ�ʽ��\n1.����  2.��ϵ�绰  3.סַ  4.����" << endl;
	    flagmodify:
		cin >> v;
		if (size(v) == 1 && isdigit(v[0])) {
			choice = (int)v[0] - 48;
		}
		else {
			cout << "������������������:";
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
		case 4:cout << "���سɹ�" << endl; system("pause"); system("cls"); return;
		default:
			cout << "��������" << endl;
			system("pause");
			cout << "����������:";
			goto flag;
		}
		if (n != -1) {
			int choose;
			cout << "*************************************************" << endl;
			cout << "*********************��ϵ��" << n + 1 << "*********************" << endl;
			cout << setiosflags(ios::left);
			cout << "������" << setw(38) << abs->personarray[n].name << "*****" << endl;
			cout << "�Ա�" << setw(38) << abs->personarray[n].sex << "*****" << endl;
			cout << "���䣺" << setw(38) << abs->personarray[n].age << "*****" << endl;
			for (int k = 0; k < abs->personarray[n].phonesize; k++) {
				cout << "��ϵ�绰" << k + 1 << "��" << setw(33) << abs->personarray[n].phone[k] << "*****" << endl;
			}
			for (int k = 0; k < abs->personarray[n].addresssize; k++) {
				cout << "סַ" << k + 1 << "��" << setw(37) << abs->personarray[n].address[k] << "*****" << endl;
			}
			cout << "*****"; showtime(abs->personarray[n].t); cout << "*****" << endl;
			cout << "*************************************************" << endl;
			cout << "��ѡ���޸����ݣ�\n1.����  2.�Ա�  3.����  4.��ϵ�绰  5.סַ  6.���±�д" << endl;
			cin >> choose;
			abs->personarray[n].t = time(0);
			switch (choose) {
			case 1:cout << "�������޸ĺ��������" << flush; cin >> abs->personarray[n].name; break;
			case 2:cout << "�������޸ĺ���Ա�" << flush; cin >> abs->personarray[n].sex; break;
			case 3:cout << "�������޸ĺ�����䣺" << flush; cin >> abs->personarray[n].age; break;
			case 4:{
				int flag1 = 1;
				string number;
				abs->personarray[n].phonesize = 0;
				while (flag1) {
					if (abs->personarray[n].phonesize == 5) {
						cout << "��ϵ�绰��������!" << endl;
						system("pause");
						flag1 = 0;
						continue;
					}
					cout << "�������޸ĺ����ϵ�绰." << flush << (abs->personarray[n].phonesize) + 1 << "(�����ȷ��������null)" << endl;

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
						cout << "סַ��������!" << endl;
						system("pause");
						flag2 = 0;
						continue;
					}
					cout << "������סַ." << (abs->personarray[n].addresssize) + 1 << "(�����ȷ��������null)" << endl;
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
				cout << "�������޸ĺ��������" << flush;
				cin >> abs->personarray[n].name;
				cout << "�������޸ĺ���Ա�" << flush;
				string sex;
			    flagsex:
				cin >> sex;
				if (sex != "null" && sex != "��" && sex != "Ů") {
					cout << "�����������������룺" << flush;
					char c;
					while ((c = getchar()) != '\n');
					cin.clear();
					goto flagsex;
				}
				else
				{
					abs->personarray[n].sex = sex;
				}
				cout << "�������޸ĺ�����䣺" << flush;
				cin >> abs->personarray[n].age;
				int flag1 = 1;
				string number;
				abs->personarray[n].phonesize = 0;
				while (flag1) {
					if (abs->personarray[n].phonesize == 5) {
						cout << "��ϵ�绰��������!" << endl;
						system("pause");
						flag1 = 0;
						continue;
					}
					cout << "�������޸ĺ����ϵ�绰." << (abs->personarray[n].phonesize) + 1 << "(�����ȷ��������null):" << flush;

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
						cout << "סַ��������!" << endl;
						system("pause");
						flag2 = 0;
						continue;
					}
					cout << "�������޸ĺ��סַ." << (abs->personarray[n].addresssize) + 1 << "(�����ȷ��������null):" << flush;
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
				cout << "��������" << endl;
				system("pause");
				system("cls");
				return;
			}	
		cout << "�޸ĳɹ�" << endl;
		system("pause");
		system("cls");
     }
	}
    
}
void findperson(addressbook*abs){
	if (abs->size == 0) {
		cout << "ͨѶ¼Ϊ��" << endl;
		system("pause");
		system("cls");

	}
	else {
		int choice, n;
		string v;
		cout << "��ѡ����ҷ�ʽ��\n1.����  2.��ϵ�绰  3.סַ  4.����" << endl;
	    flagfind:
		cin >> v;
		if (size(v) == 1 && isdigit(v[0])) {
			choice = (int)v[0] - 48;
		}
		else {
			cout << "������������������:" << flush;
			char c;
			while ((c = getchar()) != '\n');
			cin.clear();
			goto flagfind;
		}
		switch (choice) {
		case 1:n = namefind(abs); break;
		case 2:n = phonefind(abs); break;
		case 3:n = addressfind(abs); break;
		case 4:cout << "���سɹ�" << endl; system("pause"); system("cls"); return;
		default:
			cout << "��������" << endl;
			system("pause");
			system("cls");
			return;
		}
		if (n != -1) {
			cout << "*************************************************" << endl;
			cout << "*********************��ϵ��" << n+1<< "*********************" << endl;
			cout << setiosflags(ios::left);
			cout << "������" << setw(38) << abs->personarray[n].name <<"*****"<< endl;
			cout << "�Ա�" << setw(38) << abs->personarray[n].sex << "*****" << endl;
			cout << "���䣺" << setw(38) << abs->personarray[n].age << "*****" << endl;
			for (int k = 0; k < abs->personarray[n].phonesize; k++) {
				cout << "��ϵ�绰" << k + 1 << "��" << setw(33) << abs->personarray[n].phone[k] << "*****" << endl;
			}
			for (int k = 0; k < abs->personarray[n].addresssize; k++) {
				cout << "סַ" << k + 1 << "��" << setw(37) << abs->personarray[n].address[k] << "*****" << endl;
			}
			cout << "*****"; showtime(abs->personarray[n].t); cout << "*****" << endl;
			cout << "*************************************************" << endl;
	
			cout<<"����ʾ���" << endl;
		}
		system("pause");
		system("cls");
	}

}
void cleanaddressbook(addressbook*abs) {
	if (abs->size == 0) {
		cout << "ͨѶ¼Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "�Ƿ�ȷ�����ͨѶ¼��" << endl << "1.ȷ��  2.ȡ��" << endl;
	string v;
	int choice;
	flagclear:
	cin >> v;
	if (size(v) == 1 && isdigit(v[0])) {
		choice = (int)v[0] - 48;
	}
	else {
		cout << "������������������:";
		char c;
		while ((c = getchar()) != '\n');
		cin.clear();
		goto flagclear;
	}
	switch (choice) {
	case 1: {
		abs->size = 0;
		cout << "��������ͨѶ¼" << endl;
		system("pause");
		system("cls");
		break;
	}
	case 2:cout << "ȡ���ɹ�" << endl; system("pause"); system("cls"); return;
	}
}
void end() {
	cout << "�Ƿ�ȷ���˳�ͨѶ¼��" << endl << "1.ȷ��  2.ȡ��" << endl;
	int choice;
	string v;
    flagend:
	cin >> v;
	if (size(v) == 1 && isdigit(v[0])) {
		choice = (int)v[0] - 48;
	}
	else {
		cout << "������������������:";
		char c;
		while ((c = getchar()) != '\n');
		cin.clear();
		goto flagend;
	}
	switch (choice) {
	case 1: {	
		cout << "��ӭ�´�ʹ��" << endl;
		system("pause");
		system("cls");
		exit(0); 
		break;
	}
	case 2:cout << "ȡ���ɹ�" << endl; system("pause"); system("cls"); return;
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
		cout << "������������������:" ;
		char c;
		while ((c = getchar()) != '\n');
		cin.clear();
		goto flag;
	}
	
	cout << "*************************************************" << endl;
		switch (select) {
		case 0: end(); break;
		case 1:cout << "��������ϵ��" << endl; addperson(&abs); break;
		case 2:showaddressbook(&abs); break;
		case 3:delectperson(&abs); break;
		case 4:findperson(&abs); break;
		case 5:modifyperson(&abs); break;
		case 6:cleanaddressbook(&abs); break;
		default: 
			cout << "��������������������" << endl;
			system("pause");
			system("cls");
			continue;
		}
		cout << "�밴��������س�����" << endl;
		system("cls");
	}
}
