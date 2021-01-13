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
#include"Database.h"
#include"Ingredient.h"

using namespace std;
class Warehouseman {
	string name;
	string password;
	string confirmPasword;
	string email;
	string alternativeEmail;
	vector <Notification_SingUp> notifi_Warehouseman_SingUp;
	vector <Notification_SingIn> notifi_Warehouseman_SingIn;
public:
	string signIn_name;
	string signIn_password;

	int count = 3;

	int not_count = 10;




	Warehouseman() : name(""), password(""), confirmPasword(""), email(""), alternativeEmail("") {}

	Warehouseman(string name, string password, string confirmPasword, string email, string alternativeEmail)
	{
		set_WarehousemanName(name);
		set_WarehousemanPassword(password);
		set_WarehousemanPassword(confirmPasword);
		set_WarehousemanEmail(email);
		set_WarehousemanEmail(alternativeEmail);
	}

	Warehouseman(Warehouseman& other)
	{
		set_WarehousemanName(other.name);
		set_WarehousemanPassword(other.password);
		set_WarehousemanPassword(other.confirmPasword);
		set_WarehousemanEmail(other.email);
		set_WarehousemanAlternativeEmail(other.alternativeEmail);
	}

	Warehouseman& operator=(Warehouseman& other)
	{
		set_WarehousemanName(other.name);
		set_WarehousemanPassword(other.password);
		set_WarehousemanPassword(other.confirmPasword);
		set_WarehousemanEmail(other.email);
		set_WarehousemanAlternativeEmail(other.alternativeEmail);

		return *this;
	}

	Warehouseman(Warehouseman&& other)
	{

		set_WarehousemanName(other.name);
		set_WarehousemanPassword(other.password);
		set_WarehousemanPassword(other.confirmPasword);
		set_WarehousemanEmail(other.email);
		set_WarehousemanAlternativeEmail(other.alternativeEmail);

	}

	string get_WarehousemanName() throw (Exception_Warehouseman) {
		if (name == "") {
			throw Exception_Warehouseman(" Warehouseman's name Exception ", " Warehouseman.h ");
		}
		return this->name;
	}

	void set_WarehousemanName(string& name)
	{
		this->name = name;
	}

	string get_WarehousemanPassword() throw (Exception_Warehouseman) {
		if (password == "") {
			throw Exception_Warehouseman(" Warehouseman's password Exception ", " Warehouseman.h ");
		}
		return this->password;
	}

	void set_WarehousemanPassword(string& pasword)
	{
		this->password = password;
	}

	string get_WarehousemanConfirmPasword() throw (Exception_Warehouseman) {
		if (confirmPasword == "") {
			throw Exception_Warehouseman(" Warehouseman's confirm pasword Exception ", " Warehouseman.h ");
		}
		return this->confirmPasword;
	}

	void set_WarehousemanConfirmPasword(string& confirmPasword)
	{
		this->confirmPasword = confirmPasword;
	}

	string get_WarehousemanEmail() throw (Exception_Warehouseman) {
		if (email == "") {
			throw Exception_Warehouseman(" Warehouseman's email Exception ", " Warehouseman.h ");
		}
		return this->email;
	}

	void set_WarehousemanEmail(string& email)
	{
		this->email = email;
	}

	string get_WarehousemanAlternativeEmail() throw (Exception_Warehouseman) {
		if (alternativeEmail == "") {
			throw Exception_Warehouseman(" Warehouseman's alternative email Exception ", " Warehouseman.h ");
		}
		return this->alternativeEmail;
	}

	void set_WarehousemanAlternativeEmail(string& alternativeEmail)
	{
		this->alternativeEmail = alternativeEmail;
	}




	void singUp() throw (Exception_Warehouseman) {
		cout << "\n Enter Warehouseman's name: ";
		cin >> name;
		cin.ignore();
		cout << "\n Enter Warehouseman's password: ";
		cin >> password;
		cin.ignore();

		cout << "\n Enter Warehouseman's confirm pasword: ";
		cin >> confirmPasword;
		cin.ignore();


		for (size_t i = 0; i < count; i++)
		{
			if (confirmPasword != get_WarehousemanPassword())
			{
				cout << "\n " << i + 1 << "  chance " << endl;

				cout << " Repeat Warehouseman's confirm password: ";
				cin >> confirmPasword;
				cin.ignore();
			}
		}
		if (confirmPasword != get_WarehousemanPassword())
		{
			throw Exception_Warehouseman(" Warehouseman's confirm password incorrect ", " Warehouseman.h ");
		}

		cout << "\n Enter Warehouseman's email: ";
		cin >> email;
		cin.ignore();
		cout << "\n Enter Warehouseman's alternative email: ";
		cin >> alternativeEmail;
		cin.ignore();
		for (size_t i = 0; i < count; i++)
		{
			if (alternativeEmail == get_WarehousemanEmail())
			{
				cout << "\n " << i + 1 << "  chance " << endl;

				cout << " Warehouseman's alternative email is same: ";
				cin >> alternativeEmail;
				cin.ignore();
			}
		}
		if (alternativeEmail == get_WarehousemanEmail())
		{
			throw Exception_Warehouseman(" Warehouseman's alternative email incorrect ", " Warehouseman.h ");
		}

	}



	void singIn() throw (Exception_Warehouseman) {
		cout << "\n Enter Warehouseman's name: ";
		cin >> signIn_name;
		cin.ignore();
		for (size_t i = 0; i < count; i++)
		{
			if (signIn_name != get_WarehousemanName())
			{
				cout << "\n " << i + 1 << "  chance " << endl;
				cout << "\n Repeat Warehouseman's name for sing in: ";
				cin >> signIn_name;
				cin.ignore();
			}

		}
		if (signIn_name != get_WarehousemanName()) {
			throw Exception_Warehouseman(" Warehouseman's name incorrect ", " Warehouseman.h ");
		}
		cout << "\n Enter Warehouseman's password: ";
		cin >> signIn_password;
		cin.ignore();
		for (size_t i = 0; i < count; i++)
		{
			if (signIn_password != get_WarehousemanPassword())
			{
				cout << "\n " << i + 1 << "  chance " << endl;
				cout << "\n Repeat Warehouseman's password for sing in: ";
				cin >> signIn_password;
				cin.ignore();
			}

		}
		if (signIn_password != get_WarehousemanPassword()) {
			throw Exception_Warehouseman(" Warehouseman's password incorrect ", " Warehouseman.h ");
		}

		if (get_WarehousemanEmail() == get_WarehousemanAlternativeEmail()) {
			throw Exception_Admin(" Warehouseman's registation is fail ", " Warehouseman.h ");
		}


	}

	void addSingUp_Notification_Warehouseman() {

		notifi_Warehouseman_SingUp.push_back(Notification_SingUp("Sing up works successfully", "Warehouseman.h"));

	}

	void showSingUp_Notification_Warehouseman() {

		for (size_t i = 0; i < notifi_Warehouseman_SingUp.size(); i++)
		{
			notifi_Warehouseman_SingUp.at(i).printNotificationMessage();
		}
	}

	void addSingIn_Notification_Warehouseman() {

		notifi_Warehouseman_SingIn.push_back(Notification_SingIn("Sing in works successfully", "Warehouseman.h"));

	}

	void showSingIn_Notification_Warehouseman() {

		for (size_t i = 0; i < notifi_Warehouseman_SingIn.size(); i++)
		{
			notifi_Warehouseman_SingIn.at(i).printNotificationMessage();
		}
	}

	void showSingUp() {

		cout << " \n" << " Warehouseman's name: " << get_WarehousemanName();
		cout << " \n" << " Warehouseman's password: " << get_WarehousemanPassword();
		cout << " \n" << " Warehouseman's confirmPasword: " << get_WarehousemanPassword();
		cout << " \n" << " Warehouseman's email: " << get_WarehousemanEmail();
		cout << " \n" << " Warehouseman's alternativeEmail: " << get_WarehousemanAlternativeEmail();
	}

	void showSingIn() {
		cout << " \n" << " Warehouseman's name : " << signIn_name;
		cout << " \n" << " Warehouseman's password: " << signIn_password;
	}







	string get_Warehousemandata() {



		return string("\Warehouseman's name: " + name + "\n" + "Warehouseman's password: " + password + "\n" + "Warehouseman's confirmPasword: " + confirmPasword + "\n" + "Warehouseman's email: " + email + "\n" + "Warehouseman's alternative email: " + alternativeEmail);
	}
	friend ostream& operator<<(ostream& out, Warehouseman& other);
	friend istream& operator >> (istream& in, Warehouseman& other);

};


istream& operator >> (istream& in, Warehouseman& other)
{
	other.singUp();
	other.singIn();
	return in;
}


ostream& operator <<(ostream& out, Warehouseman& other)
{
	other.showSingUp();
	other.showSingIn();
	return out;
}