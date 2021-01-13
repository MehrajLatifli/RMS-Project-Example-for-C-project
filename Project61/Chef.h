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
class Chef {
	string name;
	string password;
	string confirmPasword;
	string email;
	string alternativeEmail;
	vector <Notification_SingUp> notifi_Chef_SingUp;
	vector <Notification_SingIn> notifi_Chef_SingIn;
public:
	string signIn_name;
	string signIn_password;

	int count = 3;

	int not_count = 10;



	Chef() : name(""), password(""), confirmPasword(""), email(""), alternativeEmail("") {}

	Chef(string name, string password, string confirmPasword, string email, string alternativeEmail)
	{
		set_ChefName(name);
		set_ChefPassword(password);
		set_ChefConfirmPasword(confirmPasword);
		set_ChefEmail(email);
		set_ChefAlternativeEmail(alternativeEmail);
	}

	Chef(Chef& other)
	{
		set_ChefName(other.name);
		set_ChefPassword(other.password);
		set_ChefConfirmPasword(other.confirmPasword);
		set_ChefEmail(other.email);
		set_ChefAlternativeEmail(other.alternativeEmail);
	}

	Chef& operator=(Chef& other)
	{
		set_ChefName(other.name);
		set_ChefPassword(other.password);
		set_ChefConfirmPasword(other.confirmPasword);
		set_ChefEmail(other.email);
		set_ChefAlternativeEmail(other.alternativeEmail);

		return *this;
	}

	Chef(Chef&& other)
	{

		set_ChefName(other.name);
		set_ChefPassword(other.password);
		set_ChefConfirmPasword(other.confirmPasword);
		set_ChefEmail(other.email);
		set_ChefAlternativeEmail(other.alternativeEmail);

	}

	string get_ChefName() throw (Exception_Chef) {
		if (name == "") {
			throw Exception_Chef(" Chef's name Exception ", " Chef.h ");
		}
		return this->name;
	}

	void set_ChefName(string& name)
	{
		this->name = name;
	}

	string get_ChefPassword() throw (Exception_Chef) {
		if (password == "") {
			throw Exception_Chef(" Chef's password Exception ", " Chef.h ");
		}
		return this->password;
	}

	void set_ChefPassword(string& pasword)
	{
		this->password = password;
	}

	string get_ChefConfirmPasword() throw (Exception_Chef) {
		if (confirmPasword == "") {
			throw Exception_Chef(" Chef's confirm pasword Exception ", " Chef.h ");
		}
		return this->confirmPasword;
	}

	void set_ChefConfirmPasword(string& confirmPasword)
	{
		this->confirmPasword = confirmPasword;
	}

	string get_ChefEmail() throw (Exception_Chef) {
		if (email == "") {
			throw Exception_Chef(" Chef's email Exception ", " Chef.h ");
		}
		return this->email;
	}

	void set_ChefEmail(string& email)
	{
		this->email = email;
	}

	string get_ChefAlternativeEmail() throw (Exception_Chef) {
		if (alternativeEmail == "") {
			throw Exception_Chef(" Chef's alternative email Exception ", " Chef.h ");
		}
		return this->alternativeEmail;
	}

	void set_ChefAlternativeEmail(string& alternativeEmail)
	{
		this->alternativeEmail = alternativeEmail;
	}




	void singUp() throw (Exception_Chef) {
		cout << "\n Enter Chef's name: ";
		cin >> name;
		cin.ignore();
		cout << "\n Enter Chef's password: ";
		cin >> password;
		cin.ignore();

		cout << "\n Enter Chef's confirm pasword: ";
		cin >> confirmPasword;
		cin.ignore();


		for (size_t i = 0; i < count; i++)
		{
			if (confirmPasword != get_ChefPassword())
			{
				cout << "\n " << i + 1 << "  chance " << endl;

				cout << " Repeat Chef's confirm password: ";
				cin >> confirmPasword;
				cin.ignore();
			}
		}
		if (confirmPasword != get_ChefPassword())
		{
			throw Exception_Chef(" Chef's confirm password incorrect ", " Chef.h ");
		}

		cout << "\n Enter Chef's email: ";
		cin >> email;
		cin.ignore();
		cout << "\n Enter Chef's alternative email: ";
		cin >> alternativeEmail;
		cin.ignore();
		for (size_t i = 0; i < count; i++)
		{
			if (alternativeEmail == get_ChefEmail())
			{
				cout << "\n " << i + 1 << "  chance " << endl;

				cout << " Chef's alternative email is same: ";
				cin >> alternativeEmail;
				cin.ignore();
			}
		}
		if (alternativeEmail == get_ChefEmail())
		{
			throw Exception_Chef(" Chef's alternative email incorrect ", " Chef.h ");
		}

	}



	void singIn() throw (Exception_Chef) {
		cout << "\n Enter Chef's name: ";
		cin >> signIn_name;
		cin.ignore();
		for (size_t i = 0; i < count; i++)
		{
			if (signIn_name != get_ChefName())
			{
				cout << "\n " << i + 1 << "  chance " << endl;
				cout << "\n Repeat Chef's name for sing in: ";
				cin >> signIn_name;
				cin.ignore();
			}

		}
		if (signIn_name != get_ChefName()) {
			throw Exception_Chef(" Chef's name incorrect ", " Chef.h ");
		}
		cout << "\n Enter Chef's password: ";
		cin >> signIn_password;
		cin.ignore();
		for (size_t i = 0; i < count; i++)
		{
			if (signIn_password != get_ChefPassword())
			{
				cout << "\n " << i + 1 << "  chance " << endl;
				cout << "\n Repeat Chef's password for sing in: ";
				cin >> signIn_password;
				cin.ignore();
			}

		}
		if (signIn_password != get_ChefPassword()) {
			throw Exception_Chef(" Chef's password incorrect ", " Chef.h ");
		}

		if (get_ChefEmail() == get_ChefAlternativeEmail()) {
			throw Exception_Admin(" Chef's registation is fail ", " Chef.h ");
		}
	}

	void addSingUp_Notification_Chef() {

		notifi_Chef_SingUp.push_back(Notification_SingUp("Sing up works successfully", "Chef.h"));

	}

	void showSingUp_Notification_Chef() {

		for (size_t i = 0; i < notifi_Chef_SingUp.size(); i++)
		{
			notifi_Chef_SingUp.at(i).printNotificationMessage();
		}
	}

	void addSingIn_Notification_Chef() {

		notifi_Chef_SingIn.push_back(Notification_SingIn("Sing in works successfully", "Chef.h"));

	}

	void showSingIn_Notification_Chef() {

		for (size_t i = 0; i < notifi_Chef_SingIn.size(); i++)
		{
			notifi_Chef_SingIn.at(i).printNotificationMessage();
		}
	}

	void showSingUp() {

		cout << " \n" << " Chef's name: " << get_ChefName();
		cout << " \n" << " Chef's password: " << get_ChefPassword();
		cout << " \n" << " Chef's confirmPasword: " << get_ChefPassword();
		cout << " \n" << " Chef's email: " << get_ChefEmail();
		cout << " \n" << " Chef's alternativeEmail: " << get_ChefAlternativeEmail();
	}

	void showSingIn() {
		cout << " \n" << " Chef's name : " << signIn_name;
		cout << " \n" << " Chef's password: " << signIn_password;
	}

	string get_Chefdata() {



		return string("\Chef's name: " + name + "\n" + "Chef's password: " + password + "\n" + "Chef's confirmPasword: " + confirmPasword + "\n" + "Chef's email: " + email + "\n" + "Chef's alternative email: " + alternativeEmail);
	}
	friend ostream& operator<<(ostream& out, Chef& other);
	friend istream& operator >> (istream& in, Chef& other);

};


istream& operator >> (istream& in, Chef& other)
{
	other.singUp();
	other.singIn();
	return in;
}


ostream& operator <<(ostream& out, Chef& other)
{
	other.showSingUp();
	other.showSingIn();
	return out;
}