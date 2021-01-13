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

using namespace std;

class Exception {
protected:
	string exception_text;
	string exception_sourse;
	int exception_line;
public:
	
	Exception() :exception_text(""), exception_sourse(""){}

	Exception(string exception_text,string exception_sourse)
	{

		set_Exception_text(exception_text);
		set_Exception_sourse(exception_sourse);

	}

	Exception( Exception& other)
	{

		set_Exception_text(other.exception_text);
		set_Exception_sourse(other.exception_sourse);

	}

	Exception& operator=( Exception& other)
	{

		set_Exception_text(other.exception_text);
		set_Exception_sourse(other.exception_sourse);

		return *this;

	}

	Exception(Exception&& other)
	{

		set_Exception_text(other.exception_text);
		set_Exception_sourse(other.exception_sourse);
		set_Exception_line(other.exception_line);

		other.exception_text = nullptr;
		other.exception_sourse = nullptr;
		other.exception_line = 0;

	}

	string get_Exception_text() {
		return this->exception_text;
	}

	void set_Exception_text(string& exception_text)
	{
		this->exception_text = exception_text;
	}

	string get_Exception_sourse() {
		return this->exception_sourse;
	}

	void set_Exception_sourse(string& exception_sourse)
	{
		this->exception_sourse = exception_sourse;
	}

	int get_Exception_line() {
		return this->exception_line;
	}

	void set_Exception_line(int& exception_line)
	{
		this->exception_line = exception_line;
	}

	bool operator ==(Exception& other) {
		if (this->get_Exception_text() == other.get_Exception_text()) {
			return true;
		}
		return false;

		if (this->get_Exception_sourse() == other.get_Exception_sourse()) {
			return true;
		}
		return false;

		if (this->get_Exception_line() == other.get_Exception_line()) {
			return true;
		}
		return false;

	}

	bool operator !=(Exception& other) {
		if (this->get_Exception_text() != other.get_Exception_text()) {
			return true;
		}
		return false;

		if (this->get_Exception_sourse() != other.get_Exception_sourse()) {
			return true;
		}
		return false;

		if (this->get_Exception_line() != other.get_Exception_line()) {
			return true;
		}
		return false;

	}

	void printExceptionMessage() {
		cout << endl<< endl;
		cout << " ***** Error Info ********************************************* " << endl;
		cout << " Error text: \t\t" << get_Exception_text() << endl;
		cout << " Error sourse: \t\t" << get_Exception_sourse() << endl;
		cout << " ************************************************************** " << endl<< endl;

	}



	virtual ~Exception()=0  {
	}
	
};

class Exception_RestaurantManagementSystem : public Exception {
public:
	Exception_RestaurantManagementSystem(string text, string sourse) : Exception(text, sourse) {}
};

class Exception_Admin : public Exception {
public:
	Exception_Admin() {};
	Exception_Admin(string text, string sourse) : Exception(text, sourse) {}



	string get_ExceptionAdmin_Logindata() {



		return string("\n Error text: " + get_Exception_text() + "\n" + " Error source: " + get_Exception_sourse() + "\n");
	}

	string get_ExceptionAdmin_joindata() {



		return string("\n Error text: " + get_Exception_text() + "\n" + " Error source: " + get_Exception_sourse() + "\n");
	}
};




class Exception_Waiter : public Exception {
public:

	Exception_Waiter() {};
	Exception_Waiter(string text, string sourse) : Exception(text, sourse) {}



	string get_ExceptionWaiter_Logindata() {



		return string("\n Error text: " + get_Exception_text() + "\n" + " Error source: " + get_Exception_sourse() + "\n");
	}

	string get_ExceptionWaiter_joindata() {



		return string("\n Error text: " + get_Exception_text() + "\n" + " Error source: " + get_Exception_sourse() + "\n");
	}


};

class Exception_Chef : public Exception {
public:
	Exception_Chef() {};
	Exception_Chef(string text, string sourse) : Exception(text, sourse) {}

	string get_ExceptionChef_Logindata() {



		return string("\n Error text: " + get_Exception_text() + "\n" + " Error source: " + get_Exception_sourse() + "\n");
	}

	string get_ExceptionChef_joindata() {



		return string("\n Error text: " + get_Exception_text() + "\n" + " Error source: " + get_Exception_sourse() + "\n");
	}
};

class Exception_Warehouseman : public Exception {
public:
	Exception_Warehouseman() {};
	Exception_Warehouseman(string text, string sourse) : Exception(text, sourse) {}

	string get_ExceptionWarehouseman_Logindata() {



		return string("\n Error text: " + get_Exception_text() + "\n" + " Error source: " + get_Exception_sourse() + "\n");
	}

	string get_ExceptionWarehouseman_joindata() {



		return string("\n Error text: " + get_Exception_text() + "\n" + " Error source: " + get_Exception_sourse() + "\n");
	}
};

class Exception_Ingredient : public Exception {
public:
	Exception_Ingredient() {};
	Exception_Ingredient(string text, string sourse) : Exception(text, sourse) {}

	string get_Exception_IngredientAdddata() {

		return string("\n Error text: " + get_Exception_text() + "\n" + " Error source: " + get_Exception_sourse() + "\n");
	}

	string get_Exception_IngredientChangedata() {

		return string("\n Error text: " + get_Exception_text() + "\n" + " Error source: " + get_Exception_sourse() + "\n");
	}

	string get_Exception_IngredientFinddata() {

		return string("\n Error text: " + get_Exception_text() + "\n" + " Error source: " + get_Exception_sourse() + "\n");
	}

	string get_Exception_IngredientDeletedata() {

		return string("\n Error text: " + get_Exception_text() + "\n" + " Error source: " + get_Exception_sourse() + "\n");
	}

};

class Exception_Meal : public Exception {
public:
	Exception_Meal() {};
	Exception_Meal(string text, string sourse) : Exception(text, sourse) {}

	string get_Exception_MealAdddata() {

		return string("\n Error text: " + get_Exception_text() + "\n" + " Error source: " + get_Exception_sourse() + "\n");
	}

	string get_Exception_MealChangedata() {

		return string("\n Error text: " + get_Exception_text() + "\n" + " Error source: " + get_Exception_sourse() + "\n");
	}

	string get_Exception_MealFinddata() {

		return string("\n Error text: " + get_Exception_text() + "\n" + " Error source: " + get_Exception_sourse() + "\n");
	}

	string get_Exception_MealDeletedata() {

		return string("\n Error text: " + get_Exception_text() + "\n" + " Error source: " + get_Exception_sourse() + "\n");
	}
};

class Exception_Recipe : public Exception {
public:
	Exception_Recipe() {};
	Exception_Recipe(string text, string sourse) : Exception(text, sourse) {}

	string get_Exception_RecipeAdddata() {

		return string("\n Error text: " + get_Exception_text() + "\n" + " Error source: " + get_Exception_sourse() + "\n");
	}

	string get_Exception_RecipeChangedata() {

		return string("\n Error text: " + get_Exception_text() + "\n" + " Error source: " + get_Exception_sourse() + "\n");
	}

	string get_Exception_RecipeFinddata() {

		return string("\n Error text: " + get_Exception_text() + "\n" + " Error source: " + get_Exception_sourse() + "\n");
	}

	string get_Exception_RecipeDeletedata() {

		return string("\n Error text: " + get_Exception_text() + "\n" + " Error source: " + get_Exception_sourse() + "\n");
	}

	string get_Exception_MealRecipeFind() {

		return string("\n Error text: " + get_Exception_text() + "\n" + " Error source: " + get_Exception_sourse() + "\n");
	}
};

class Exception_Order : public Exception {
public:
	Exception_Order() {};
	Exception_Order(string text, string sourse) : Exception(text, sourse) {}

	string get_Exception_OrderAdddata() {

		return string("\n Error text: " + get_Exception_text() + "\n" + " Error source: " + get_Exception_sourse() + "\n");
	}
};



class Exception_Database : public Exception {
public:
	Exception_Database(string text, string sourse) : Exception(text, sourse) {}
};