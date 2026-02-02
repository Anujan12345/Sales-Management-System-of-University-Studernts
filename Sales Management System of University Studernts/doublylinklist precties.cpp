
#include <iostream>
#include"doubly.h"
#include"doubly2.h"

using namespace std;

int main()
{
	doubly_link_lisk sll;
	doubly_link_lisk2 bll;
	int ch = 0;
	int ah;
	int choice;




	while (ch == 0) {
		cout << "\n SALES MANAGEMENT SYSTEM OF UNIVERSITY STUDENTS’ USED RESOURCES " << endl;
		cout << "================================================================"<<endl;
		cout << "\n 1. To Continue as Seller  :- press 1 ";
		cout << "\n 2. To Continue as Buyer   :- press 2 ==> ";
		cin >> ch;

		if (ch == 1) {
			while (ch == 1) {

				cout << "\n MENU ";
				cout << "\n 1.Add Product              :- press 1\n 2.Display Details          :- press 2\n 3.Order Details            :- press 3\n 4.Remove Product           :- press 4\n 5.Find order               :- press 5\n 0.Go to Menu               :- press 0\n";
				cout << "\nEnter your choice ==> ";
				cin >> choice;

				switch (choice) //switch case
				{
				case 1:
					sll.openAccount(); //createlist function is called
					break;
				case 2:
					sll.displayDetails(); //display function is called break;
					break;
				case 3:
					bll.displayDetails2();

					break;
				case 4:
					sll.Search_And_Delete();
					break;
				case 5:
					bll.Find_product2();
					break;
				case 0:
					ch = 0;

				}
			}
		}
		else if (ch == 2) {

			while (ch == 2) {

				cout << "\n MENU ";
				cout << "\n 1.Availabel Product Details  :- press 1\n 2.Search Product             :- press 2\n 3.Place Order                :- press 3\n 4.Remove Order               :- press 4\n 0.Go to Menu                 :- press 0\n";
				cout << "\nEnter your choice ==> ";
				cin >> choice;

				switch (choice) //switch case
				{

				case 1:
					sll.displayDetails(); //display function is called break;
					break;
				case 2:

					sll.Search_product();

					break;
				case 3:

					bll.order();
					break;
				case 4:

					bll.Search_And_Delete2();
					break;
				case 0:
					ch = 0;
				}

			}
		}

	}

	
}