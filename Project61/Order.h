#pragma once
#include<iostream>
#include<assert.h>
#include<string>
#include<vector>
#include<list>
#include <algorithm>
#include<iterator>
#include <fstream>
#include <sstream>
#include <windows.h>
#include "Exeption.h"
#include"FileHelper.h"
#include"Notification.h"
#include "Meal.h"

#include "Database.h"

using namespace std;


using namespace std;

class Order {


	int current_id;
	int tableNo;
	int orderMealID;

	int axtardelete1;
public:

	static int id;
	static int axtardelete;



	Order() : current_id(0), tableNo(0), axtardelete1(0) {}


	Order( int tableNo, int orderMealID)
	{
		this->current_id = ++id;
		set_OrderTable(tableNo);
		set_OrderMealID(orderMealID);
		this->axtardelete1 = axtardelete;

	}


	Order(Order& other)
	{
		this->current_id = other.id;
		set_OrderTable(other.tableNo);
		set_OrderMealID(other.orderMealID);
		this->axtardelete1 = other.axtardelete;

	}

	Order& operator=(Order& other)
	{
		set_OrderTable(other.tableNo);
		set_OrderMealID(other.orderMealID);
		this->axtardelete1 = other.axtardelete;

		return *this;
	}

	Order(Order&& other)
	{
		set_OrderTable(other.tableNo);
		set_OrderMealID(other.orderMealID);
		other.tableNo = 0;
		other.orderMealID = 0;


	}



	int getCurrentId() {
		return current_id;
	}

	int getCurrentId2() {
		return id;
	}

	void setCurrentId(int id) {
		this->current_id = ++id;
	}


	int get_OrderTable() throw (Exception_Order) {
		if (tableNo == 0) {
			throw Exception_Meal(" Table no is Exception ", " Order.h ");
		}
		return this->tableNo;
	}


	void set_OrderTable(int& tableNo)
	{
		this->tableNo = tableNo;
	}


	int get_OrderMealID() throw (Exception_Order) {
		if (tableNo == 0) {
			throw Exception_Order(" Meal of Table is Exception ", " Order.h ");
		}
		return this->orderMealID;
	}


	void set_OrderMealID(int& orderMealID)
	{
		this->orderMealID = orderMealID;
	}

	
	void show_Order() {

		cout << "\n\n ID of Order: \t" << this->current_id;
		cout << "\n No of Table:  \t" << get_OrderTable() << endl;
		cout << "\n iD of Meal:  \t" << get_OrderMealID() << endl;
		cout << " ========================== " << endl << endl << endl;

	}

	bool FillaxtarOrder() {
		cout << " ID Sil: ";
		cin >> axtardelete;
		if (axtardelete == this->current_id) {
			return axtardelete;
		}
		else {

			return false;
		}

		return axtardelete;
	}
	static int axtarOrder() {

		return axtardelete;
	}

	string get_OrderData() {
		string id = to_string(current_id);
		string table = to_string(tableNo);
		string idOrderforMeal = to_string(orderMealID);

		return string("\n ID : " + id + "\n Sifarisin masasi : " + table + "\n" +"Sifarisin Nomresi: "+ idOrderforMeal + "\n");
	}




};

int Order::id = -1;

int Order::axtardelete = Order::axtarOrder();





bool compareOrder(Order*& o1, Order*& o2) {
	if (o1->get_OrderTable() != o2->get_OrderTable())
		return (o1->get_OrderTable() < o2->get_OrderTable());


}


bool compare4forOrderRemove(Order*& other, Order*& other2) {
	if (other->get_OrderTable() == other2->get_OrderTable()) {

		return 1;
	}
	else
	{
		return 0;
	};
}



bool axtarIDforOrder(Order* other) {

	return other->getCurrentId() == other->axtardelete;
}
