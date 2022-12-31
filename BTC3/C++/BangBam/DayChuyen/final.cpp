#include <bits/stdc++.h>
#include "anhViet.cpp"
#include <conio.h>
using namespace std;

int menu() 
{
	int n;
	cout << "=================MENU================\n";
	cout << "1. Nap tu dien tu file\n";
	cout << "2. Tra tu dien\n";
	cout << "3. Sua doi tu\n";
	cout << "4. Them tu moi\n";
	cout << "5. Xoa tu\n";
	cout << "6. Them tu dien vao file\n";
	cout << "7. Ket thuc\n";
	cout << "=====================================\n";
	cout << "Moi chon: ";
	cin >> n;
	return n;
}

void demo(anhViet aV) 
{
	int c;
	do 
	{
		system("cls");
		c = menu();
		system("cls");
		switch(c) 
		{
			case 1: 
			{
				cout << "1. Nap tu dien tu file\n";
				aV.readFile(); 
				cout << "Da nhap file tu dong thanh cong !!";
				break;
			}
			case 2: 
			{
				cout << "2. Tra tu dien\n";
				string word;
				cout << "Moi nhap tu tieng Anh can tim: ";
				fflush(stdin);
				getline(cin, word);
				Node <string, string> *p = aV.findWord(word);
				if(p)	cout << "Nghia cua tu vua nhap: " << p -> getVal();
				else	cout << "Tu vua nhap khong co trong tu dien !!";
				break;
			}
			case 3: 
			{
				cout << "3. Sua doi tu\n";
				string word, newMean;
				cout << "Moi nhap tu tieng Anh: ";
				fflush(stdin);
				getline(cin, word);
				cout << "Moi nhap nghia tieng Viet moi: ";
				fflush(stdin);
				getline(cin, newMean);
				if(aV.editWord(word, newMean))	cout << "Da sua tu thanh cong !!";
				else	cout << "tu tieng Anh khong co trong tu dien !!";
				break;
			}
			case 4: 
			{
				cout << "4. Them tu moi\n";
				string word, mean;
				cout << "Moi nhap tu tieng Anh: ";
				fflush(stdin);
				getline(cin, word);
				cout << "Moi nhap nghia tieng Viet: ";
				fflush(stdin);
				getline(cin, mean);
				if(aV.addWord(word, mean))	cout << "Da them vao tu dien thanh cong !!";
				else	cout << "tu tieng Anh da ton tai trong tu dien !!";
				break;
			}
			case 5: 
			{
				cout << "5. Xoa tu\n";
				string word;
				cout << "Moi nhap tu tieng Anh: ";
				fflush(stdin);
				getline(cin, word);
				aV.removeWord(word);
				cout << "Xoa tu thanh cong !!";
				break;
			}
			case 6: 
			{
				cout << "6. Them tu dien vao file\n";
				string s;
				cout << "Moi nhap ten file muon ghi tu dien vao: ";			
				fflush(stdin);
				cin >> s;
				aV.exportFile(s);
				cout << "Da xuat tu dien ra tep !!";
				break;
			}
			case 7: 
			{
				cout << "7. Ket thuc\n";
				cout << "Nhan nut bat ki de ket thuc!"; 
				break;
			}
		}
		getch();
	}while(c != 7);
}

int main()
{
	anhViet aV;
	demo(aV);
	return 0;
}


