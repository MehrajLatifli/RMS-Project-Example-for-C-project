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

class Ingredient
{
	int current_id;
	int axtardelete1;
    string ingredient_name;
    double ingredient_measure;


public:
	static int id;
	static int axtardelete;
    Ingredient() : current_id(0),ingredient_name(""), ingredient_measure(0), axtardelete1(0){}

	Ingredient(string ingredient_name, double ingredient_measure)
	{
		this->current_id = ++id;
		set_Ingredient_name(ingredient_name);
		set_Ingredient_measure(ingredient_measure);
		this->axtardelete1 = axtardelete;
	}


	Ingredient(Ingredient& other)
	{
		this->current_id = other.id;
		set_Ingredient_name(other.ingredient_name);
		set_Ingredient_measure(other.ingredient_measure);
		this->axtardelete1 = other.axtardelete;
	}

	Ingredient& operator=(Ingredient& other)
	{
		set_Ingredient_name(other.ingredient_name);
		set_Ingredient_measure(other.ingredient_measure);
		this->axtardelete1 = axtardelete;
		return *this;
	}

	Ingredient(Ingredient&& other)
	{
		set_Ingredient_name(other.ingredient_name);
		set_Ingredient_measure(other.ingredient_measure);
		other.ingredient_measure = 0;

		
	}

	string get_Ingredient_name() throw (Exception_Ingredient) {
		if (ingredient_name == "") {
			throw Exception_Ingredient(" Name of Ingredient is Exception ", " Ingredient.h ");
		}
		return this->ingredient_name;
	}


	void set_Ingredient_name(string& ingredient_name)
	{
		this->ingredient_name = ingredient_name;
	}


	double get_Ingredient_measure() throw (Exception_Ingredient) {
		if (ingredient_measure == 0) {
			throw Exception_Ingredient(" Measure of Ingredient is Exception ", " Ingredient.h ");
		}
		return this->ingredient_measure;
	}
   

	void set_Ingredient_measure(double& ingredient_measure)
	{
		this->ingredient_measure = ingredient_measure;
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

	bool operator==(Ingredient& other)
	{
		return ingredient_name == other.ingredient_name && ingredient_measure == other.ingredient_measure;
	}




	void show_Ingredient() {

		cout << "\n\n ID of Ingredient: \t" << this->current_id;
		cout << "\n Name of Ingredient: \t" << get_Ingredient_name() << endl;
		cout << " Measure of Ingredient: " << get_Ingredient_measure() << endl;
		cout << " ========================== " << endl << endl << endl;

	}

	string get_IngredientData() {
		string id = to_string(current_id);
		string measure = to_string(ingredient_measure);

		return string("\n ID : " + id + "\n Name of Ingredients: " + ingredient_name + "\n" + " Measure of Ingredients: " + measure + "\n" );
	}

	bool Fillaxtar() {
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



	static int axtar() {

		return axtardelete;
	}





	string get_İngredientdata() {
		string id = to_string(current_id);
		string measure = to_string(ingredient_measure);
		return string("\n ID: " + id + "\n" + " İnqridientin adi: " + ingredient_name + "\n" + " İnqridientin cekisi: " + measure + "\n \n" );
	}


};


int Ingredient::id = -2;
int Ingredient::axtardelete = Ingredient::axtar();





bool compare(Ingredient*& ingredient_in_warehouse1, Ingredient*& ingredient_in_warehouse2) {
	if (ingredient_in_warehouse1->get_Ingredient_name() != ingredient_in_warehouse2->get_Ingredient_name())
	return (ingredient_in_warehouse1->get_Ingredient_name() < ingredient_in_warehouse2->get_Ingredient_name());
	return (ingredient_in_warehouse1->get_Ingredient_measure() < ingredient_in_warehouse2->get_Ingredient_measure());

}


bool Unique_copyByModel(Ingredient*& other, Ingredient*& other2)
{

	if (other->get_Ingredient_name() == other2->get_Ingredient_name())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool compare2forRemove(Ingredient*& other, Ingredient*& other2) {
	if (other->get_Ingredient_name() == other2->get_Ingredient_name()) {
		
		return 1;
	}
	else
	{
		return 0;
	};
}



bool axtarID(Ingredient* other) {

	return other->getCurrentId() == other->axtardelete;
}


