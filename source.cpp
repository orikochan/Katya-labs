#include <iostream> 
#include <fstream> 
#include <String> 
#include "List.h" 
#include<ctime>
using namespace std;
string fileInput = "";
string fileOutput = "";
string fileError = "";
int menu()
{
	int m = -1;
	system("cls");
	cout << "1. Add item to begin\n2. Add item to end\n3. Add item for index position" << endl;
	cout << "4. Print list\n5. Print the sum of multiplications\n6. Delete list\n7. Delete item in position\n";
	cout << "8. How much items in list\n0. Exit\nEnter the number of function:\t";
	while ((m > 8) || (m < 0))
	{
		cin >> m;
	}
	return m;
	system("cls");
}
int main(int argc, char* argv[])
{
	srand(unsigned(std::time(0)));
	/*cout << argv[1];
	cout << argv[2];
	cout << argv[3];*/
	fileInput = argv[1];
	fileOutput = argv[2];
	fileError = argv[3];
	/*fileInput = "1";
	fileOutput = "2";
	fileError = "3";*/
	//Sfstream in(fileInput + ".txt");
	List* list = new List();
	Node* top;
	int size, m, index;
	double item;
	ifstream in(fileInput + ".txt"); // окрываем файл для чтения
	if (in.is_open())
	{
		while (!in.eof()) {
			in >> size;
		}
	}
	in.close();
	cout << endl;
	/*cout << "Enter the number of items:\t";
	cin >> size;*/
	try
	{
		ofstream fErrors("Errors.txt");
		try
		{
			fstream fSource("Source.txt", ios_base::out);
			for (int i = 0; i < size; i++)
			{
				cout << "Enter an item:\t";
				cin >> item;
				fSource << item << "\t";
			}
			fSource.close();
			system("pause");
		}
		catch (exception FileOpenException)
		{
			fErrors << "File of source variables is not opened!\n";
		}
		try
		{
			fstream fSource("Source.txt", ios_base::in);
			for (int i = 0; i < size; i++)
			{
				fSource >> item;
				list->AddItemToEnd(item);
			}
			fSource.close();
		}
		catch (exception FileOpenException)
		{
			fErrors << "File of source variables is not opened for read!\n";
		}
		try
		{
			ofstream fTarget("Target.txt");
			m = menu();
			while (m != 0)
			{
				switch (m)
				{
				case 1:
					cout << "Enter item:\t";
					cin >> item;
					list->AddItemToBeg(item);
					break;
				case 2:
					cout << "Enter item:\t";
					cin >> item;
					list->AddItemToEnd(item);
					break;
				case 3:
					cout << "Enter item:\t";
					cin >> item;
					cout << "Enter the position:\t";
					cin >> index;
					list->AddItemToPos(item, index - 1);
					break;
				case 4:
					list->PrintList();
					system("pause");
					break;
				case 5:
					if (list->GetSize() < 2)
					{
						cout << "Please enter more items for this function of program!" << endl;
					}
					else
					{
						list->PrintList();
						cout << "The sum of multiplications is:\t" << list->sumOfMultiplications() << endl;
						fTarget << "The sum of multiplications is:\t" << list->sumOfMultiplications() << endl;
					}
					system("pause");
					break;
				case 6:
					top = list->GetTop();
					list->DeleteList(top);
					break;
				case 7:
					cout << "Enter the position:\t";
					cin >> index;
					list->DeleteItem(index);
					break;
				case 8:
					cout << "The size of list is:\t" << list->GetSize() << endl;
					fTarget << "The size of list is:\t" << list->GetSize() << endl;
					system("pause");
					break;
				case 0:
					break;
				default:
					cout << "Try entering the menu item again!";
					system("pause");
					break;
				}
				m = menu();
			}
			fTarget.close();
		}
		catch (exception FileOpenException)
		{
			fErrors << "File of targets variables is not opened for read!\n";
		}
	}
	catch (exception fileOpenException)
	{
		cout << "You crash the programm(-_-)\n";
	}
	system("pause");
}
