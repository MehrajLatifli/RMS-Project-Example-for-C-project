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
class Admin {
	string name;
	string password;
	string confirmPasword;
	string email;
	string alternativeEmail;
	vector <Notification_SingUp> notifi_admin_SingUp;
	vector <Notification_SingIn> notifi_admin_SingIn;
public:
	string signIn_name;
	string signIn_password;

	int count = 3;

	int not_count = 10;



	Admin(): name(""), password(""), confirmPasword(""), email(""), alternativeEmail(""){}

	Admin(string name, string password, string confirmPasword, string email, string alternativeEmail)
	{
		set_AdminName(name);
		set_AdminPassword(password);
		set_AdminConfirmPasword(confirmPasword);
		set_AdminEmail(email);
		set_AdminAlternativeEmail(alternativeEmail);
	}

	Admin(Admin& other)
	{
		set_AdminName(other.name);
		set_AdminPassword(other.password);
		set_AdminConfirmPasword(other.confirmPasword);
		set_AdminEmail(other.email);
		set_AdminAlternativeEmail(other.alternativeEmail);
	}

	Admin& operator=(Admin& other)
	{
		set_AdminName(other.name);
		set_AdminPassword(other.password);
		set_AdminConfirmPasword(other.confirmPasword);
		set_AdminEmail(other.email);
		set_AdminAlternativeEmail(other.alternativeEmail);

		return *this;
	}

	Admin(Admin&& other)
	{

		set_AdminName(other.name);
		set_AdminPassword(other.password);
		set_AdminConfirmPasword(other.confirmPasword);
		set_AdminEmail(other.email);
		set_AdminAlternativeEmail(other.alternativeEmail);

	}

	string get_AdminName() throw (Exception_Admin) {
		if (name == "") {
			throw Exception_Admin(" Admin's name Exception ", " Admin.h ");
		}
		return this->name;
	}

	void set_AdminName(string& name)
	{
		this->name = name;
	}

	string get_AdminPassword() throw (Exception_Admin) {
		if (password == "") {
			throw Exception_Admin(" Admin's password Exception ", " Admin.h ");
		}
		return this->password;
	}

	void set_AdminPassword(string& pasword)
	{
		this->password = password;
	}

	string get_AdminConfirmPasword() throw (Exception_Admin) {
		if (confirmPasword == "") {
			throw Exception_Admin(" Admin's confirm pasword Exception ", " Admin.h ");
		}
		return this->confirmPasword;
	}

	void set_AdminConfirmPasword(string& confirmPasword)
	{
		this->confirmPasword = confirmPasword;
	}

	string get_AdminEmail() throw (Exception_Admin) {
		if (email == "") {
			throw Exception_Admin(" Admin's email Exception ", " Admin.h ");
		}
		return this->email;
	}

	void set_AdminEmail(string& email)
	{
		this->email = email;
	}

	string get_AdminAlternativeEmail() throw (Exception_Admin) {
		if (alternativeEmail == "") {
			throw Exception_Admin(" Admin's alternative email Exception ", " Admin.h ");
		}
		return this->alternativeEmail;
	}

	void set_AdminAlternativeEmail(string& alternativeEmail)
	{
		this->alternativeEmail = alternativeEmail;
	}
	 



	void singUp() throw (Exception_Admin) {
		cout << "\n Enter Admin's name: ";
		cin >> name;
		cin.ignore();
		cout << "\n Enter Admin's password: ";
		cin >> password;
		cin.ignore();

		cout << "\n Enter Admin's confirm pasword: ";
		cin >> confirmPasword;
		cin.ignore();
	
			
			for (size_t i = 0; i < count; i++)
			{
 				if (confirmPasword != get_AdminPassword())
				{
				cout << "\n "<< i + 1 << "  chance "<< endl;

					cout << " Repeat Admin's confirm password: ";
					cin >> confirmPasword;
					cin.ignore();
				}
			}
					if (confirmPasword != get_AdminPassword())
					{
						throw Exception_Admin(" Admin's confirm password incorrect ", " Admin.h ");
					}
			
		cout << "\n Enter Admin's email: ";
		cin >> email;
		cin.ignore();
		cout << "\n Enter Admin's alternative email: ";
		cin >> alternativeEmail;
		cin.ignore();
		for (size_t i = 0; i < count; i++)
		{
			if (alternativeEmail == get_AdminEmail())
			{
				cout << "\n " << i + 1 << "  chance " << endl;

				cout << " Admin's alternative email is same: ";
				cin >> alternativeEmail;
				cin.ignore();
			}
		}
		if (alternativeEmail == get_AdminEmail())
		{
			throw Exception_Admin(" Admin's alternative email incorrect ", " Admin.h ");
		}

	}

	

	void singIn() throw (Exception_Admin) {
		cout << "\n Enter Admin's name: ";
		cin >> signIn_name;
		cin.ignore();
		for (size_t i = 0; i < count; i++)
		{
			if (signIn_name != get_AdminName())
			{
				cout << "\n " << i + 1 << "  chance " << endl;
				cout << "\n Repeat Admin's name for sing in: ";
				cin >> signIn_name;
				cin.ignore();
			}
			
		}
		if (signIn_name != get_AdminName()) {
			throw Exception_Admin(" Admin's name incorrect ", " Admin.h ");
		}
		cout << "\n Enter Admin's password: ";
		cin >> signIn_password;
		cin.ignore();
		for (size_t i = 0; i < count; i++)
		{
			if (get_AdminPassword() != get_AdminConfirmPasword() || signIn_password != get_AdminPassword() || get_AdminEmail() == get_AdminAlternativeEmail() )
			{
				cout << "\n " << i + 1 << "  chance " << endl;
				cout << "\n Repeat Admin's password for sing in: ";
				cin >> signIn_password;
				cin.ignore();
			}
			
		}
		if (signIn_password != get_AdminPassword() || get_AdminConfirmPasword() != get_AdminPassword() ) {
			throw Exception_Admin(" Admin's password incorrect ", " Admin.h ");
		}

		if ( get_AdminEmail() == get_AdminAlternativeEmail()) {
			throw Exception_Admin(" Admin's registation is fail ", " Admin.h ");
		}
	}

	void addSingUp_Notification_Admin() {

		notifi_admin_SingUp.push_back(Notification_SingUp("Sing up works successfully", "Admin.h"));

	}

	void showSingUp_Notification_Admin() {

		for (size_t i = 0; i < notifi_admin_SingUp.size(); i++)
		{
			notifi_admin_SingUp.at(i).printNotificationMessage();
		}
	}

	void addSingIn_Notification_Admin() {

		notifi_admin_SingIn.push_back(Notification_SingIn("Sing in works successfully", "Admin.h"));

	}

	void showSingIn_Notification_Admin() {

		for (size_t i = 0; i < notifi_admin_SingIn.size(); i++)
		{
			notifi_admin_SingIn.at(i).printNotificationMessage();
		}
	}

	void showSingUp() {

		cout << " \n" << " Admin's name: " << get_AdminName();
		cout << " \n" << " Admin's password: " << get_AdminPassword();
		cout << " \n" << " Admin's confirmPasword: " << get_AdminPassword();
		cout << " \n" << " Admin's email: " << get_AdminEmail();
		cout << " \n" << " Admin's alternativeEmail: " << get_AdminAlternativeEmail();
	}

	void showSingIn() {
		cout << " \n" << " Admin's name : " << signIn_name;
		cout << " \n" << " Admin's password: " << signIn_password;
	}

	string get_Admindata() {
		

		
		return string("\nAdmin's name: " + name + "\n" + "Admin's password: " + password + "\n" + "Admin's confirmPasword: " + confirmPasword + "\n" + "Admin's email: " + email + "\n" + "Admin's alternative email: " + alternativeEmail);
	}
	friend ostream& operator<<(ostream& out, Admin& other);
	friend istream& operator >> (istream& in, Admin& other);

};


istream& operator >> (istream& in, Admin& other)
{
	other.singUp();
	other.singIn();
	return in;
}


ostream& operator <<(ostream& out, Admin& other)
{
	other.showSingUp();
	other.showSingIn();
	return out;
}