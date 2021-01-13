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
#include "Exeption.h"
#include"FileHelper.h"
#include"Admin.h"
#include"Notification.h"

using namespace std;


class RestaurantManagementSystem {
	string restaurant_name;
	string restaurant_address;
	string restaurant_phonenumber;

	double restaurant_rating;

	vector <Notification_RestaurantManagementSystem> notifi_rms;

public:
	int count = 3;
	RestaurantManagementSystem() :restaurant_name(""), restaurant_address(""), restaurant_phonenumber(""),  restaurant_rating(0){}

	RestaurantManagementSystem(string restaurant_name, string restaurant_address, string restaurant_phonenumber,  double restaurant_rating)
	{
		set_Restaurant_name(restaurant_name);
		set_Address(restaurant_address);

		set_Restaurant_rating(restaurant_rating);
		set_Restaurant_phonenumber(restaurant_phonenumber);
	}


	RestaurantManagementSystem(RestaurantManagementSystem& other)
	{
		set_Restaurant_name(other.restaurant_name);
		set_Address(other.restaurant_address);

		set_Restaurant_rating(restaurant_rating);
		set_Restaurant_phonenumber(restaurant_phonenumber);
	}

	RestaurantManagementSystem& operator=( RestaurantManagementSystem& other)
	{
		set_Restaurant_name(other.restaurant_name);
		set_Address(other.restaurant_address);

		set_Restaurant_rating(other.restaurant_rating);
		set_Restaurant_phonenumber(other.restaurant_phonenumber);

		return *this;
	}

	RestaurantManagementSystem(RestaurantManagementSystem&& other)
	{

		set_Restaurant_name(other.restaurant_name);
		set_Address(other.restaurant_address);

		set_Restaurant_rating(other.restaurant_rating);
		set_Restaurant_phonenumber(other.restaurant_phonenumber);


		other.restaurant_rating = 0;
		
	}

	string get_Restaurant_name() throw (Exception_RestaurantManagementSystem)  {
		if (restaurant_name == "")   {
			throw Exception_RestaurantManagementSystem(" Restaurant name Exception ", " Restaurant Management System.h ");
		}
			return this->restaurant_name;
	}

	void set_Restaurant_name(string& name) 
	{
		this->restaurant_name = restaurant_name;
	}

	string get_Address() throw (Exception_RestaurantManagementSystem) {
		if (restaurant_address == "")   {
			throw Exception_RestaurantManagementSystem(" Restaurant address Exception ", " Restaurant Management System.h ");
		}
		return this->restaurant_address;
	}

	void set_Address(string& address)
	{
		this->restaurant_address = address;
	}

	string get_Restaurant_phonenumber() throw (Exception_RestaurantManagementSystem) {
		if (restaurant_phonenumber == "")   {
			throw Exception_RestaurantManagementSystem(" Restaurant phonenumber Exception ", " Restaurant Management System.h ");
		}
		return this->restaurant_phonenumber;
	}

	void set_Restaurant_phonenumber(string& restaurant_phonenumber)
	{

		this->restaurant_phonenumber = restaurant_phonenumber;
	}


	double get_Restaurant_rating() throw (Exception_RestaurantManagementSystem) {
		if (restaurant_rating == 0.0)   {
			throw Exception_RestaurantManagementSystem(" Restaurant rating Exception ", " Restaurant Management System.h ");
		}
		return this->restaurant_rating;
	}

	void set_Restaurant_rating(double & restaurant_rating)
	{
		this->restaurant_rating = restaurant_rating;
	}

	bool operator ==(RestaurantManagementSystem& other) {
		if (this->get_Restaurant_rating() == other.get_Restaurant_rating()) {
			return true;
		}
		return false;

		if (this->get_Restaurant_name() == other.get_Restaurant_name()) {
			return true;
		}
		return false;

		if (this->get_Address() == other.get_Address()) {
			return true;
		}
		return false;

		if (this->get_Restaurant_phonenumber() == other.get_Restaurant_phonenumber()) {
			return true;
		}
		return false;
	}

	bool operator!=(RestaurantManagementSystem& other) {
		if (this->get_Restaurant_rating() != other.get_Restaurant_rating()) {
			return true;
		}
		return false;

		if (this->get_Restaurant_name() != other.get_Restaurant_name()) {
			return true;
		}
		return false;

		if (this->get_Address() != other.get_Address()) {
			return true;
		}
		return false;

		if (this->get_Restaurant_phonenumber() != other.get_Restaurant_phonenumber()) {
			return true;
		}
		return false;
	}

	//Increment prefix 
	RestaurantManagementSystem operator++ () {
		this->restaurant_rating++;
		return *this;
	}

	//Increment posifix 
	RestaurantManagementSystem operator++ (int) {
		RestaurantManagementSystem temp = *this;
		this->restaurant_rating++;
		return temp;
	}

	//Decrement prefix 
	RestaurantManagementSystem operator-- () {
		this->restaurant_rating--;
		return *this;
	}
	//Decrement posifix 
	RestaurantManagementSystem operator-- (int) {
		RestaurantManagementSystem temp = *this;
		this->restaurant_rating--;

		return temp;
	}



	void fill_RestaurantManagementSystem() {
	
				cout << "\n Enter Restaurant name: ";
				cin >> restaurant_name;
				cin.ignore();
		
		cout << "\n Enter Restaurant address: ";
		cin >> restaurant_address;
		cin.ignore();
		cout << "\n Enter Restaurant phonenumber: ";
		cin >> restaurant_phonenumber;
		cin.ignore();



		cout << "\n Enter Restaurant rating: ";
		cin >> restaurant_rating;
		cin.ignore();
		

		for (size_t i = 0; i < count; i++)
		{
			if (restaurant_rating  < 0 && restaurant_rating > 10)
			{
				cout << "\n " << i + 1 << "  chance " << endl;
				cout << "\n Repeat Restaurant rating: ";
				cin >> restaurant_rating;
				cin.ignore();
			}
		}

		if (restaurant_rating != get_Restaurant_rating())
		{
			throw Exception_RestaurantManagementSystem(" Rating of restaurant incorrect ", " Restaurant Management System.h ");
		}
		
	}

	void print_RestaurantManagementSystem()
	{
		cout << "\n Restaurant name: " << get_Restaurant_name();

		cout << "\n Restaurant address: " << get_Address();

		cout << "\n Restaurant phonenumber: " << get_Restaurant_phonenumber();

		cout << "\n Restaurant rating: " << get_Restaurant_rating();

	}


	void addNotification_RestaurantManagementSystem() {

		notifi_rms.push_back(Notification_RestaurantManagementSystem("Restaurant registrated ", "RestaurantManagementSystem.h"));

	}

	void showNotification_RestaurantManagementSystem() {

		for (size_t i = 0; i < notifi_rms.size(); i++)
		{
			notifi_rms.at(i).printNotificationMessage();
		}
	}


	string get_RMSdata() {

		string rating = to_string(restaurant_rating);
		return string("\n Restaurant name: " + restaurant_name + "\n" + "Restaurant address: " + restaurant_address +  "\n" + "Restaurant phonenumber: " + restaurant_phonenumber + "\n" +  "Restaurant rating: " + rating);
	}
	

	friend ostream& operator<<(ostream& out, RestaurantManagementSystem& other);
	friend istream& operator >> (istream& in, RestaurantManagementSystem& other);

};


istream& operator >> (istream& in, RestaurantManagementSystem& other)
{
	other.fill_RestaurantManagementSystem();
	return in;
}


ostream& operator <<(ostream& out, RestaurantManagementSystem& other)
{
	other.print_RestaurantManagementSystem();
	return out;
}