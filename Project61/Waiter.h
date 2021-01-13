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

using namespace std;
class Waiter {
	string name;
	string password;
	string confirmPasword;
	string email;
	string alternativeEmail;
	vector <Notification_SingUp> notifi_Waiter_SingUp;
	vector <Notification_SingIn> notifi_Waiter_SingIn;
public:
	string signIn_name;
	string signIn_password;

	int count = 3;

	int not_count = 10;



	Waiter() : name(""), password(""), confirmPasword(""), email(""), alternativeEmail("") {}

	Waiter(string name, string password, string confirmPasword, string email, string alternativeEmail)
	{
		set_WaiterName(name);
		set_WaiterPassword(password);
		set_WaiterConfirmPasword(confirmPasword);
		set_WaiterEmail(email);
		set_WaiterAlternativeEmail(alternativeEmail);
	}

	Waiter(Waiter& other)
	{
		set_WaiterName(other.name);
		set_WaiterPassword(other.password);
		set_WaiterConfirmPasword(other.confirmPasword);
		set_WaiterEmail(other.email);
		set_WaiterAlternativeEmail(other.alternativeEmail);
	}

	Waiter& operator=(Waiter& other)
	{
		set_WaiterName(other.name);
		set_WaiterPassword(other.password);
		set_WaiterConfirmPasword(other.confirmPasword);
		set_WaiterEmail(other.email);
		set_WaiterAlternativeEmail(other.alternativeEmail);

		return *this;
	}

	Waiter(Waiter&& other)
	{

		set_WaiterName(other.name);
		set_WaiterPassword(other.password);
		set_WaiterConfirmPasword(other.confirmPasword);
		set_WaiterEmail(other.email);
		set_WaiterAlternativeEmail(other.alternativeEmail);

	}

	string get_WaiterName() throw (Exception_Waiter) {
		if (name == "") {
			throw Exception_Waiter(" Waiter's name Exception ", " Waiter.h ");
		}
		return this->name;
	}

	void set_WaiterName(string& name)
	{
		this->name = name;
	}

	string get_WaiterPassword() throw (Exception_Waiter) {
		if (password == "") {
			throw Exception_Waiter(" Waiter's password Exception ", " Waiter.h ");
		}
		return this->password;
	}

	void set_WaiterPassword(string& pasword)
	{
		this->password = password;
	}

	string get_WaiterConfirmPasword() throw (Exception_Waiter) {
		if (confirmPasword == "") {
			throw Exception_Waiter(" Waiter's confirm pasword Exception ", " Waiter.h ");
		}
		return this->confirmPasword;
	}

	void set_WaiterConfirmPasword(string& confirmPasword)
	{
		this->confirmPasword = confirmPasword;
	}

	string get_WaiterEmail() throw (Exception_Waiter) {
		if (email == "") {
			throw Exception_Waiter(" Waiter's email Exception ", " Waiter.h ");
		}
		return this->email;
	}

	void set_WaiterEmail(string& email)
	{
		this->email = email;
	}

	string get_WaiterAlternativeEmail() throw (Exception_Waiter) {
		if (alternativeEmail == "") {
			throw Exception_Waiter(" Waiter's alternative email Exception ", " Waiter.h ");
		}
		return this->alternativeEmail;
	}

	void set_WaiterAlternativeEmail(string& alternativeEmail)
	{
		this->alternativeEmail = alternativeEmail;
	}




	void singUp() throw (Exception_Waiter) {
		cout << "\n Enter Waiter's name: ";
		cin >> name;
		cin.ignore();
		cout << "\n Enter Waiter's password: ";
		cin >> password;
		cin.ignore();

		cout << "\n Enter Waiter's confirm pasword: ";
		cin >> confirmPasword;
		cin.ignore();


		for (size_t i = 0; i < count; i++)
		{
			if (confirmPasword != get_WaiterPassword())
			{
				cout << "\n " << i + 1 << "  chance " << endl;

				cout << " Repeat Waiter's confirm password: ";
				cin >> confirmPasword;
				cin.ignore();
			}
		}
		if (confirmPasword != get_WaiterPassword())
		{
			throw Exception_Waiter(" Waiter's confirm password incorrect ", " Waiter.h ");
		}

		cout << "\n Enter Waiter's email: ";
		cin >> email;
		cin.ignore();
		cout << "\n Enter Waiter's alternative email: ";
		cin >> alternativeEmail;
		cin.ignore();
		for (size_t i = 0; i < count; i++)
		{
			if (alternativeEmail == get_WaiterEmail())
			{
				cout << "\n " << i + 1 << "  chance " << endl;

				cout << " Waiter's alternative email is same: ";
				cin >> alternativeEmail;
				cin.ignore();
			}
		}
		if (alternativeEmail == get_WaiterEmail())
		{
			throw Exception_Waiter(" Waiter's alternative email incorrect ", " Waiter.h ");
		}

	}



	void singIn() throw (Exception_Waiter) {
		cout << "\n Enter Waiter's name: ";
		cin >> signIn_name;
		cin.ignore();
		for (size_t i = 0; i < count; i++)
		{
			if (signIn_name != get_WaiterName())
			{
				cout << "\n " << i + 1 << "  chance " << endl;
				cout << "\n Repeat Waiter's name for sing in: ";
				cin >> signIn_name;
				cin.ignore();
			}

		}
		if (signIn_name != get_WaiterName()) {
			throw Exception_Waiter(" Waiter's name incorrect ", " Waiter.h ");
		}
		cout << "\n Enter Waiter's password: ";
		cin >> signIn_password;
		cin.ignore();
		for (size_t i = 0; i < count; i++)
		{
			if (signIn_password != get_WaiterPassword())
			{
				cout << "\n " << i + 1 << "  chance " << endl;
				cout << "\n Repeat Waiter's password for sing in: ";
				cin >> signIn_password;
				cin.ignore();
			}

		}
		if (signIn_password != get_WaiterPassword()) {
			throw Exception_Waiter(" Waiter's password incorrect ", " Waiter.h ");
		}

		if (get_WaiterEmail() == get_WaiterAlternativeEmail()) {
			throw Exception_Admin(" Waiter's registation is fail ", " Waiter.h ");
		}
	}

	void addSingUp_Notification_Waiter() {

		notifi_Waiter_SingUp.push_back(Notification_SingUp("Sing up works successfully", "Waiter.h"));

	}

	void showSingUp_Notification_Waiter() {

		for (size_t i = 0; i < notifi_Waiter_SingUp.size(); i++)
		{
			notifi_Waiter_SingUp.at(i).printNotificationMessage();
		}
	}

	void addSingIn_Notification_Waiter() {

		notifi_Waiter_SingIn.push_back(Notification_SingIn("Sing in works successfully", "Waiter.h"));

	}

	void showSingIn_Notification_Waiter() {

		for (size_t i = 0; i < notifi_Waiter_SingIn.size(); i++)
		{
			notifi_Waiter_SingIn.at(i).printNotificationMessage();
		}
	}

	void showSingUp() {

		cout << " \n" << " Waiter's name: " << get_WaiterName();
		cout << " \n" << " Waiter's password: " << get_WaiterPassword();
		cout << " \n" << " Waiter's confirmPasword: " << get_WaiterPassword();
		cout << " \n" << " Waiter's email: " << get_WaiterEmail();
		cout << " \n" << " Waiter's alternativeEmail: " << get_WaiterAlternativeEmail();
	}

	void showSingIn() {
		cout << " \n" << " Waiter's name : " << signIn_name;
		cout << " \n" << " Waiter's password: " << signIn_password;
	}

	string get_Waiterdata() {



		return string("\Waiter's name: " + name + "\n" + "Waiter's password: " + password + "\n" + "Waiter's confirmPasword: " + confirmPasword + "\n" + "Waiter's email: " + email + "\n" + "Waiter's alternative email: " + alternativeEmail);
	}
	friend ostream& operator<<(ostream& out, Waiter& other);
	friend istream& operator >> (istream& in, Waiter& other);

};


istream& operator >> (istream& in, Waiter& other)
{
	other.singUp();
	other.singIn();
	return in;
}


ostream& operator <<(ostream& out, Waiter& other)
{
	other.showSingUp();
	other.showSingIn();
	return out;
}