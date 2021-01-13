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
#include "Database.h"
#include "Recept.h"


using namespace std;

class Meal {


	int current_id;
	string meal_name;
	double meal_price;
	int axtardelete1;
public:





	static int id;
	static int axtardelete;

	Meal() : current_id(0), meal_name(""), meal_price(0), axtardelete1(0) {}


	Meal(string meal_name, double meal_price)
	{
		this->current_id = ++id;
		set_Meal_name(meal_name);
		set_Meal_price(meal_price);
		this->axtardelete1 = axtardelete;

	}


	Meal(Meal& other)
	{
		this->current_id = other.id;
		set_Meal_name(meal_name);
		set_Meal_price(meal_price);
		this->axtardelete1 = other.axtardelete;

	}

	Meal& operator=(Meal& other)
	{
		set_Meal_name(other.meal_name);
		set_Meal_price(other.meal_price);
		this->axtardelete1 = other.axtardelete;

		return *this;
	}

	Meal(Meal&& other)
	{
		set_Meal_name(meal_name);
	set_Meal_price(meal_price);
		other.meal_price = 0;


	}



	string get_Meal_name() throw (Exception_Meal) {
		if (meal_name == "") {
			throw Exception_Meal(" Name of Meal is Exception ", " Ingredient.h ");
		}
		return this->meal_name;
	}


	void set_Meal_name(string& meal_name)
	{
		this->meal_name = meal_name;
	}


	double get_Meal_price() throw (Exception_Meal) {
		if (meal_price == 0) {
			throw Exception_Meal(" Measure of Ingredient is Exception ", " Ingredient.h ");
		}
		return this->meal_price;
	}


	void set_Meal_price(double& meal_price)
	{
		this->meal_price = meal_price;
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

	bool operator==(Meal& other)
	{
		return meal_name == other.meal_name && meal_price == other.meal_price;
	}


	void show_Meal() {

		cout << "\n\n ID of Meal: \t" << this->current_id;
		cout << "\n Name of Meal:  \t" << get_Meal_name() << endl;
		cout << " Price of Meal: \t" << get_Meal_price() << endl;
		cout << " ========================== " << endl << endl << endl;

	}

	bool FillaxtarMeal() {
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
	static int axtarMeal() {

		return axtardelete;
	}

	string get_MealData() {
		string id = to_string(current_id);
		string price = to_string(meal_price);

		return string("\n ID : " + id + "\n Yemeyin adi : " + meal_name + "\n" + " Yemeyin qiymeti: " + price + "\n");
	}




};

int Meal::id = -1;

int Meal::axtardelete = Meal::axtarMeal();





bool compareMeal(Meal*& meal1, Meal*& meal2) {
	if (meal1->get_Meal_name() != meal2->get_Meal_name())
		return (meal1->get_Meal_name() < meal2->get_Meal_name());
	return (meal1->get_Meal_price() < meal2->get_Meal_price());

}


bool compare2forMealRemove(Meal*& other, Meal*& other2) {
	if (other->get_Meal_name() == other2->get_Meal_name()) {

		return 1;
	}
	else
	{
		return 0;
	};
}



bool axtarIDforMeal(Meal* other) {

	return other->getCurrentId() == other->axtardelete;
}