

#include<iostream>
#include<cstddef>
#include<string>

using namespace std;

class node {

public:
	int Id;
	string product_name;
	string Name;
	int phone_number;
	double Price;
	node* next;
	node* prev;

	node() {
		Id = -1;
		product_name = "null";
		Name = "null";
		phone_number = -1;
		Price = -1;
		next = NULL;
		prev = NULL;
     }

	node(int id,string p_name,string name,int p_number,double price) {

		Id = id;
		product_name = p_name;
		Name = name;
		phone_number = p_number;
		Price = price;
		next = NULL;
		prev = NULL;
	}

};

class doubly_link_lisk {

public:
	node* head;
	node* tail;
	int size;

public:

	doubly_link_lisk() {

		head = NULL;
		tail = NULL;
		size = 0;

	}

	node* gethead() {
		return head;
	}
	node* gettail() {
		return tail;
	}



	void insert_last(int id, string p_name, string name, int p_number, double price) {

		node* temp = new node(id, p_name, name, p_number, price);

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

		node* temp = head;

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

		node* temp = tail;

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

	void delete_mid(int pos) {

		node* temp = head;
		node* current = head;

		if (pos<1 || pos>size) {

			cout << " invalide position" << endl;
		}

		else {

			if (pos == 1) {

				delete_first();

			}
			else if (pos == size) {

				delete_last();
			}
			else {
				for (int i = 1; i < pos - 1; i++) {

					current = current->next;
				}
				for (int i = 1; i < pos; i++) {

					temp = temp->next;
				}


				current->next = temp->next;
				(temp->next)->prev = current;
				delete temp;
				size--;





			}


		}



	}

	void openAccount()
	{

		int I;//id of the owner 
		string A;//product name
		string B;//name of the product owner
		int p_n;//phone number
		double p;//price of the product



		cout << " Enter Specific Id for your Product : ";
		cin >> I;

		node* current = head;
		while (current != NULL)
		{

			if (current->Id == I)
			{

				cout << "\n This id is already exist" << endl;

				openAccount();
				return;
			}
			current = current->next;

		}

		cout << " Enter Product Name : ";
		cin >> A;
		cout << " Enter your Name : ";
		cin >> B;
		cout << " Enter your contact number : ";
		cin >> p_n;
		cout << " Enter the price of the product : ";
		cin >> p;


		insert_last(I, A, B, p_n, p);
		cout << "\n PRODUCT ADDED SUCCESFULLY" << endl;

	}





	void Search_product()
	{
		string id;
		cout << " Enter the product Name : "; cin >> id;
		node* current = head;
		while (current != NULL)
		{
			if (current->product_name == id)
			{
				cout << " Id        : " << current->Id << " " << endl;
				cout << " product   : " << current->product_name << endl;
				cout << " name      : " << current->Name << endl;
				cout << " phone no  : " << current->phone_number << endl;
				cout << " price     : Rs " << current->Price << ".00" << endl;
				cout << " ======================" << endl;
			}
			
			current = current->next;
		}
	}







	void displayDetails() {

		node* current = head;

		while (current != NULL) {

			cout << " Id        : " << current->Id << " " << endl;
			cout << " product   : " << current->product_name << endl;
			cout << " name      : " << current->Name << endl;
			cout << " phone no  : " << current->phone_number << endl;
			cout << " price     : Rs " << current->Price << ".00" << endl;
			cout << " ======================" << endl;

			current = current->next;

		}
		cout << endl;



	}


	void Search_And_Delete()
	{
		int id;
		cout << " Enter the id for delete : "; cin >> id;
		node* current = head;
		while (current != NULL)
		{
			if (head->Id == id) delete_first();
			else if (tail->Id == id) delete_last();
			else if (current->Id == id)
			{
				(current->next)->prev = current->prev;
				(current->prev)->next = current->next;

				size--;
			}
			current = current->next;
		}
	}






};
