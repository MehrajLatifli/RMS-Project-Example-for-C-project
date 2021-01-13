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
#include <time.h>
#include "Restaurant Management System.h"




class FileHelper {
public:


	void write_fileRMS(string cv) {
		ofstream fout("RMS.txt", ios_base::out);
		if (fout.is_open()) {
			fout << cv << endl;
			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}


	string read_fileRMS() {
		ifstream fin("RMS.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(" " + value + " ");
			}
		}
		cout << endl;

		return result;
	}

	void write_fileAdmin(string cv) {
		ofstream fout("Admin.txt", ios_base::out);
		if (fout.is_open()) {
			fout << cv << endl;
			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}
	string read_fileAdmin() {
		ifstream fin("Admin.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}

	void write_fileWaiter(string cv) {
		ofstream fout("Waiter.txt", ios_base::out);
		if (fout.is_open()) {
			fout << cv << endl;
			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_fileWaiter() {
		ifstream fin("Waiter.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}

	void write_fileChef(string cv) {
		ofstream fout("Chef.txt", ios_base::out);
		if (fout.is_open()) {
			fout << cv << endl;
			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_fileChef() {
		ifstream fin("Chef.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}

	void write_fileWarehouseman(string cv) {
		ofstream fout("Warehouseman.txt", ios_base::out);
		if (fout.is_open()) {
			fout << cv << endl;
			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_fileWarehouseman() {
		ifstream fin("Warehouseman.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}


	void write_fileIngredient(string cv) {

		ofstream fout("Ingredient.txt", ios_base::app);
		if (fout.is_open()) {
			fout << cv << endl;

			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_fileIngredient() {
		ifstream fin("Ingredient.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}


	void write_fileMeal(string cv) {

		ofstream fout("Meal.txt", ios_base::app);
		if (fout.is_open()) {
			fout << cv << endl;
			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_fileMeal() {
		ifstream fin("Meal.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}


	void write_fileRecept(string cv) {

		ofstream fout("Recept.txt", ios_base::app);
		if (fout.is_open()) {
			fout << cv << endl;

			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_fileRecept() {
		ifstream fin("Recept.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}


	void write_AdminJoinError(string cv) {

		ofstream fout("ErrorAdmin.txt", ios_base::app);
		if (fout.is_open()) {
			fout << cv << endl;

			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_AdminJoinError() {
		ifstream fin("ErrorAdmin.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}


	void write_AdminLoginError(string cv) {

		ofstream fout("ErrorAdmin.txt", ios_base::app);
		if (fout.is_open()) {
			fout << cv << endl;

			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_AdminLoginError() {
		ifstream fin("ErrorAdmin.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}



	void write_WaiterJoinError(string cv) {

		ofstream fout("ErrorWaiter.txt", ios_base::app);
		if (fout.is_open()) {
			fout << cv << endl;

			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_WaiterJoinError() {
		ifstream fin("ErrorWaiter.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}


	void write_WaiterLoginError(string cv) {

		ofstream fout("ErrorWaiter.txt", ios_base::app);
		if (fout.is_open()) {
			fout << cv << endl;

			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_WaiterLoginError() {
		ifstream fin("ErrorWaiter.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}











	void write_ChefJoinError(string cv) {

		ofstream fout("ErrorChef.txt", ios_base::app);
		if (fout.is_open()) {
			fout << cv << endl;

			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_ChefJoinError() {
		ifstream fin("ErrorChef.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}


	void write_ChefLoginError(string cv) {

		ofstream fout("ErrorChef.txt", ios_base::app);
		if (fout.is_open()) {
			fout << cv << endl;

			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_ChefLoginError() {
		ifstream fin("ErrorChef.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}









	void write_WarehousemanJoinError(string cv) {

		ofstream fout("ErrorWarehouseman.txt", ios_base::app);
		if (fout.is_open()) {
			fout << cv << endl;

			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_WarehousemanJoinError() {
		ifstream fin("ErrorWarehouseman.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}


	void write_WarehousemanLoginError(string cv) {

		ofstream fout("ErrorWarehouseman.txt", ios_base::app);
		if (fout.is_open()) {
			fout << cv << endl;

			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_WarehousemanLoginError() {
		ifstream fin("ErrorWarehouseman.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}






	void write_Exception_IngredientAdddata(string cv) {

		ofstream fout("ErrorIngredient.txt", ios_base::app);
		if (fout.is_open()) {
			fout << cv << endl;

			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_Exception_IngredientAdddata() {
		ifstream fin("ErrorIngredient.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}




	void write_Exception_IngredientChangedata(string cv) {

		ofstream fout("ErrorIngredient.txt", ios_base::app);
		if (fout.is_open()) {
			fout << cv << endl;

			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_Exception_IngredientChangedata() {
		ifstream fin("ErrorIngredient.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}

	void write_Exception_IngredientFinddata(string cv) {

		ofstream fout("ErrorIngredient.txt", ios_base::app);
		if (fout.is_open()) {
			fout << cv << endl;

			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_Exception_IngredientFinddata() {
		ifstream fin("ErrorIngredient.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}



	void write_Exception_IngredientDeletedata(string cv) {

		ofstream fout("ErrorIngredient.txt", ios_base::app);
		if (fout.is_open()) {
			fout << cv << endl;

			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_Exception_IngredientDeletedata() {
		ifstream fin("ErrorIngredient.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}




	void write_Exception_MealAdddata(string cv) {

		ofstream fout("ErrorMeal.txt", ios_base::app);
		if (fout.is_open()) {
			fout << cv << endl;

			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_Exception_MealAdddata() {
		ifstream fin("ErrorMeal.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}


	void write_Exception_RecipeAdddata(string cv) {

		ofstream fout("ErrorRecipe.txt", ios_base::app);
		if (fout.is_open()) {
			fout << cv << endl;

			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_Exception_RecipeAdddata() {
		ifstream fin("ErrorRecipe.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}


	void write_Exception_MealChangedata(string cv) {

		ofstream fout("ErrorMeal.txt", ios_base::app);
		if (fout.is_open()) {
			fout << cv << endl;

			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_Exception_MealChangedata() {
		ifstream fin("ErrorMeal.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}




		void write_Exception_RecipeChangedata(string cv) {

		ofstream fout("ErrorRecipe.txt", ios_base::app);
		if (fout.is_open()) {
			fout << cv << endl;

			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_Exception_RecipeChangedata() {
		ifstream fin("ErrorRecipe.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}



	void write_Exception_MealFinddata(string cv) {

		ofstream fout("ErrorMeal.txt", ios_base::app);
		if (fout.is_open()) {
			fout << cv << endl;

			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_Exception_MealFinddata() {
		ifstream fin("ErrorMeal.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}




	void write_Exception_RecipeFinddata(string cv) {

		ofstream fout("ErrorRecipe.txt", ios_base::app);
		if (fout.is_open()) {
			fout << cv << endl;

			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_Exception_RecipeFinddata() {
		ifstream fin("ErrorRecipe.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}

	void write_Exception_MealDeletedata(string cv) {

		ofstream fout("ErrorMeal.txt", ios_base::app);
		if (fout.is_open()) {
			fout << cv << endl;

			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_Exception_MealDeletedata() {
		ifstream fin("ErrorMeal.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}


		void write_Exception_RecipeDeletedata(string cv) {

		ofstream fout("ErrorRecipe.txt", ios_base::app);
		if (fout.is_open()) {
			fout << cv << endl;

			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_Exception_RecipeDeletedata() {
		ifstream fin("ErrorRecipe.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}




	void write_Exception_MealRecipeFind(string cv) {

		ofstream fout("ErrorRecipe.txt", ios_base::app);
		if (fout.is_open()) {
			fout << cv << endl;

			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_Exception_MealRecipeFind() {
		ifstream fin("ErrorRecipe.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}





	void write_Exception_OrderAdd(string cv) {

		ofstream fout("ErrorOrder.txt", ios_base::app);
		if (fout.is_open()) {
			fout << cv << endl;

			time_t a;
			char tt[26];
			time(&a);
			ctime_s(tt, sizeof(tt), &a);


			fout << "\Time: " << tt << endl << endl;
		}
	}

	string read_Exception_OrderAdd() {
		ifstream fin("ErrorOrder.txt", ios::in);
		string result = "";
		if (fin.is_open()) {
			while (!fin.eof()) {
				string value;
				fin >> value;
				result.append(value + " ");
			}
		}
		cout << endl;

		return result;
	}
};



