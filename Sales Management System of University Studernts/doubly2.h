#pragma once
#include<iostream>
#include<cstddef>
#include<string>

using namespace std;

class node2 {

public:
	
	string Name;
	int phone_number;
	string product_name;
	int Id;
	node2* next;
	node2* prev;

	node2() {

		Id = -1;
		Name = "null";
		phone_number = -1;
		product_name = "null";
		next = NULL;
		prev = NULL;

	}

	node2(string name, int p_number, string p_name, int id) {

		
		Name = name;
		phone_number = p_number;
		product_name = p_name;
		Id = id;

		next = NULL;
		prev = NULL;


	}

};

class doubly_link_lisk2 {

private:
	node2* head;
	node2* tail;
	int size;

public:

	doubly_link_lisk2() {

		head = NULL;
		tail = NULL;
		size = 0;

	}

	node2* gethead() {
		return head;
	}
	node2* gettail() {
		return tail;
	}



	void insert_last2(string name, int p_number, string p_name, int id) {

		node2* temp = new node2(name, p_number, p_name,id);

		if (head == NULL) {

			head = temp;
			tail = temp;
			size = 1;

		}

		else {

			tail->next = temp;
			temp->prev = tail;
			tail = temp;
			size++;

		}

	}
	void delete_first() {

		node2* temp = head;

		if (head == NULL) {

			cout << "list is empty" << endl;
		}
		else {

			if (size == 1) {

				delete temp;
				head = NULL;
				tail = NULL;
				size = 0;
			}
			else {
				head = head->next;
				(temp->next)->prev = NULL; //head->prev=NULL
				delete temp;
				size--;
			}
		}

	}


	void delete_last() {

		node2* temp = tail;

		if (head == NULL) {

			cout << "list is empty" << endl;
		}
		else {

			if (size == 1) {

				delete temp;
				head = NULL;
				tail = NULL;
				size = 0;
			}
			else {
				tail = tail->prev;
				(temp->prev)->next = NULL; //tail->next=NULL;
				delete temp;
				size--;
			}
		}

	}

	


	void order() {

		int I;//id of the owner 
		string A;//product name
		string B;//name of the buyer
		int p_n;//phone number


		cout << " Enter your Name" << endl;
		cin >> B;

		cout << " Enter your phone Number" << endl;
		cin >> p_n;

		cout << " Enter the product Name" << endl;
		cin >> A;

		cout << " Enter the Id of the selected Product" << endl;
		cin >> I;
		
		



		insert_last2(B,p_n,A,I);
		cout << "\n ORDER COMPLECTE SUCCESFULLY"<<endl;

	}


	void Find_product2()
	{
		string id;
		cout << " Enter the Ordered product Name : "; cin >> id;
		node2* current = head;
		while (current != NULL)
		{
			if (current->product_name == id)
			{

				cout << " Name     : " << current->Name << endl;
				cout << " phone no : " << current->phone_number << endl;
				cout << " product  : " << current->product_name << endl;
				cout << " Id       : " << current->Id << " " << endl;
				cout << "===================" << endl;
			}

			current = current->next;
		}
	}





	void displayDetails2() {

		node2* current = head;

		while (current != NULL) {

			cout << " Name     : " << current->Name << endl;
			cout << " phone no : " << current->phone_number << endl;
			cout << " product  : " << current->product_name << endl;
			cout << " Id       : " << current->Id << " " << endl;
			cout << "===================" << endl;

			current = current->next;

		}
		cout << endl;



	}

	void Search_And_Delete2()
	{
		string n;
		cout << " Enter your Name for delete : "; cin >> n;
		node2* current = head;
		while (current != NULL)
		{
			if (head->Name == n) delete_first();
			else if (tail->Name == n) delete_last();
			else if (current->Name == n)
			{
				(current->next)->prev = current->prev;
				(current->prev)->next = current->next;

				size--;
			}
			current = current->next;
		}
	}











};