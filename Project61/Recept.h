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

class Recept
{
	int current_id;
	int axtardelete1;
	string recept_name;
	double recept_measure;
	int recept_mealid;
	vector <Notification_Ingredient> notifi_Ingredient;


public:
	static int id;
	static int axtardelete;
	Recept() : current_id(0), recept_name(""), recept_measure(0), recept_mealid(0), axtardelete1(0) {}

	Recept(string ingredient_name, double ingredient_measure, int recept_mealid)
	{
		this->current_id = ++id;
		set_Recept_name(ingredient_name);
		set_Recept_measure(ingredient_measure);
		set_Recept_mealID(recept_mealid);
		this->axtardelete1 = axtardelete;
	}


	Recept(Recept& other)
	{
		this->current_id = other.id;
		set_Recept_name(other.recept_name);
		set_Recept_measure(other.recept_measure);
		set_Recept_mealID(other.recept_mealid);
		this->axtardelete1 = axtardelete;
	}

	Recept& operator=(Recept& other)
	{
		set_Recept_name(other.recept_name);
		set_Recept_measure(other.recept_measure);
		set_Recept_mealID(other.recept_mealid);
		this->axtardelete1 = axtardelete;
		return *this;
	}

	Recept(Recept&& other)
	{
		set_Recept_name(other.recept_name);
		set_Recept_measure(other.recept_measure);
		set_Recept_mealID(other.recept_mealid);
		other.recept_measure = 0;


	}

	string get_Recept_name() throw (Exception_Ingredient) {
		if (recept_name == "") {
			throw Exception_Ingredient(" Name of Ingredient is Exception ", " Ingredient.h ");
		}
		return this->recept_name;
	}


	void set_Recept_name(string& ingredient_name)
	{
		this->recept_name = ingredient_name;
	}


	int get_Recept_mealID() throw (Exception_Ingredient) {
		if (recept_mealid < 0) {
			throw Exception_Ingredient(" Name of Ingredient is Exception ", " Ingredient.h ");
		}
		return this->recept_mealid;
	}


	void set_Recept_mealID(int & recept_mealid)
	{
		this->recept_mealid = recept_mealid;
	}


	double get_Recept_measure() throw (Exception_Ingredient) {
		if (recept_measure == 0) {
			throw Exception_Ingredient(" Measure of Ingredient is Exception ", " Ingredient.h ");
		}
		return this->recept_measure;
	}


	void set_Recept_measure(double& ingredient_measure)
	{
		this->recept_measure = ingredient_measure;
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

	bool operator==(Recept& other)
	{
		return recept_name == other.recept_name && recept_measure == other.recept_measure;
	}


	void addFill_Notification_Recept() {

		notifi_Ingredient.push_back(Notification_Ingredient("Ingredients add successfully", "Ingredients.h"));

	}

	void show_Recept() {

		cout << "\n\n ID of Recept: \t" << this->current_id;
		cout << "\n Name of Recept: \t" << get_Recept_name() << endl;
		cout << " Measure of Recept: " << get_Recept_measure() << endl;
		cout << " Which Recept of mealID: " << get_Recept_mealID() << endl;
		cout << " ========================== " << endl << endl << endl;

	}



	bool FillaxtarRecept() {
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
	static int axtarRecept() {

		return axtardelete;
	}



	string get_Receptdata() {
		string id = to_string(current_id);
		string measure = to_string(recept_measure);
		string mealid = to_string(recept_mealid);
		return string("\n ID: " + id + "\n" + " Receptin adi: " + recept_name + "\n" + "Receptin cekisi: " + measure + "\n" + "Receptin aid olduqu yemek: " + mealid + "\n \n");
	}


};







bool compareRecept(Recept*& recepts1, Recept*& recepts2) {
	if (recepts1->get_Recept_name() != recepts2->get_Recept_name())
		return (recepts1->get_Recept_name() < recepts2->get_Recept_name());
	return (recepts1->get_Recept_measure() < recepts2->get_Recept_measure());
	return (recepts1->get_Recept_mealID() < recepts2->get_Recept_mealID());

}


bool Unique_copyByModelRecept(Recept*& other, Recept*& other2)
{

	if (other->get_Recept_name() == other2->get_Recept_name())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

bool compare3forRemoveRecept(Recept*& other, Recept*& other2) {
	if (other->get_Recept_mealID() == other2->get_Recept_mealID() && other->get_Recept_name() == other2->get_Recept_name()) {

		return 1;
	}
	else
	{
		return 0;
	};
}

int Recept::id = -1;

int Recept::axtardelete = Recept::axtarRecept();

bool axtarIDRecept(Recept* other) {

	return other->getCurrentId() == other->axtardelete;
}


