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
#include <time.h>
#include "Exeption.h"
#include"FileHelper.h"
#include"Notification.h"
#include "Meal.h"
#include "Ingredient.h"
#include "Recept.h"
#include "Order.h"

using namespace std;

class Database {

	vector <Notification_WarehouseAdd> notifi_WarehouseAdd;
	vector <Notification_WarehouseChange> notifi_WarehouseChange;
	vector <Notification_WarehouseDelete> notifi_WarehouseDelete;
	vector <Notification_WarehouseFind> notifi_Find;
	vector <Notification_MealAdd> notifi_Mealadd;
	vector <Notification_MealChange> notifi_Mealchange;
	vector <Notification_MealFind> notifi_Mealfind;
	vector <Notification_MealDelete> notifi_Mealdelete;
	vector <Notification_ReceptAdd> notifi_Notification_ReceptAdd;
	vector <Notification_ReceptChange> notifi_Notification_ReceptChange;
	vector <Notification_ReceptFind> notifi_Notification_ReceptFind;
	vector <Notification_ReceptDelete> notifi_Notification_ReceptDelete;
	vector <Notification_OrderAdd> notifi_Notification_OrderAdd;
	vector <Notification_OrderFind> notifi_Notification_OrderFind;
	vector <Notification_OrderDelete> notifi_Notification_OrderDelete;
	vector <Notification_SearchRecipeMeal> notifi_SearchRecipeMeal;

public:
	vector<Ingredient*>ingredient_in_warehouse;
	vector<Recept*>Recept_in_base;
	vector<Meal*> meal_in_base;
	vector<Order*> Order_in_base;

	vector<FileHelper*>file_in_Ingredient;
	vector<FileHelper*>file_in_Meal;
	vector<FileHelper*>file_in_Recept;

	int count = 3;
	int kindofIngredient = 0;
	int kindofmeal = 0;
	int kindofrecept = 0;
	string meal_name;
	double meal_price;
	string recept_name;
	double recept_measure;
	int recept_mealid=0;
	string search;
	int mealrecept;
	int index = 0;
	double change = 0;
	string changename = "";
	int deyis;
	string deyisdirilecekInqName;
	double deyisdirilecekInqMeasure;
	int deyisR = 0;
	int deyisM;
	string deyisdirilecekMealName;
	double deyisdirilecekMealPrice;
	string deyisdirilecekRecName;
	double deyisdirilecekRecMeasure = 0.0;
	int deyisdirilecekRecMealID=0;

	int orderID=0;
	double price = 0;
	double sum = 0;
	double newInqmeasure = 0;
	int tableNo=0;
	int orderMealID;

	int searchID;
		string  ingredient_name;
		double ingredient_measure = 0;

	Database() {}
	void addIngredient() throw (Exception_Ingredient) {


		cout << "\n Inqridientlerin cesid sayini daxil edin: ";
		cin >> kindofIngredient;

		for (size_t i = 0; i < count; i++)
		{
			if (kindofIngredient == 0.0 || kindofIngredient == NULL) {
				cout << "\n " << i + 1 << "  sans " << endl;

				cout << " Cesid sayini yeniden daxil edin: ";
				cin >> kindofIngredient;
				cin.ignore();
			}
		}

		if (kindofIngredient == 0.0 || kindofIngredient == NULL)
		{
			throw Exception_Ingredient("  Inqridientin cesid sayi xetasi ", " Database.h ");
		}

		for (int i = 0; i < kindofIngredient; i++) {

			cout << "\n " << i + 1 << " -ci mehsulun adini daxil edin: ";
			cin >> ingredient_name;

			cout << "\n " << ingredient_name << " adli mehsulun cekisini (qram) daxil edin: ";
			cin >> ingredient_measure;
			cout << endl;

			for (size_t i = 0; i < count; i++)
			{
				if (ingredient_measure == 0.0 || ingredient_measure == NULL) {
					cout << "\n " << i + 1 << "  chance " << endl;

					cout << " Repeat measure of ingredient: ";
					cin >> ingredient_measure;
					cin.ignore();
				}
			}

			if (ingredient_measure == 0.0 || ingredient_measure == NULL)
			{
				throw Exception_Ingredient("  Inqridientlerin cekisi xetasi ", " Database.h ");
			}

			ingredient_in_warehouse.push_back(new Ingredient(ingredient_name, ingredient_measure));


		}


	}

	void addNotification_Warehouse() {

		notifi_WarehouseAdd.push_back(Notification_WarehouseAdd("Inqridientler uqurla elave edildi ", "Database.h"));

	}

	void showNotification_Warehouse() {


		for (size_t i = 0; i < notifi_WarehouseAdd.size(); i++)
		{
			notifi_WarehouseAdd.at(i).printNotificationMessage();
		}
	}




	void printIngredient() {
		for (auto iw : ingredient_in_warehouse) {
			cout << "\n " << iw->getCurrentId() << " " << iw->get_Ingredient_name() << " " << iw->get_Ingredient_measure() << " ";
		}


	}


	bool findElement() {

		cout << "\n Ingridienti axtar: ";
		cin >> search;
		for (size_t i = 0; i < ingredient_in_warehouse.size(); i++)
		{
			if (search == ingredient_in_warehouse.at(i)->get_Ingredient_name()) {
				cout << "\n ID: " << ingredient_in_warehouse.at(i)->getCurrentId() << "\n Ingredient name: " << ingredient_in_warehouse.at(i)->get_Ingredient_name() << "\n Ingredient measure: " << ingredient_in_warehouse.at(i)->get_Ingredient_measure() << endl;

				return true;
			}



		}
		return false;
	}




	void findElementError(bool result) throw (Exception_Ingredient) {

		if (result == false) {

			for (size_t i = 0; i < ingredient_in_warehouse.size(); i++)
			{
				if (ingredient_in_warehouse.at(i)->get_Ingredient_name() != search) {

					throw Exception_Ingredient("Inqridientin axtarisi xetasi ", " Database.h ");
				}


			}
		}
	}



	void findElement_Notification_Warehouse() {

		notifi_Find.push_back(Notification_WarehouseFind(" Inqridientin axtarisi uqurlu oldu ", "Database.h"));

	}

	void showfindElement_Notification_Warehouse() {

		for (size_t i = 0; i < notifi_Find.size(); i++)
		{
			notifi_Find.at(i).printNotificationMessage();
		}
	}

	bool  changeIngredient() throw (Exception_Ingredient) {

		cout << " Deyisdirilecek id : ";
		cin >> deyis;

		cout << " Deyisdirilecek inqredient adi : ";
		cin >> deyisdirilecekInqName;



		cout << " Deyisdirilecek inqredient cekisi : ";
		cin >> deyisdirilecekInqMeasure;

		cout << endl;

		for (int n = 0; n < ingredient_in_warehouse.size(); n++) {

			if (ingredient_in_warehouse.at(n)->getCurrentId() == deyis) {
				for (auto i : ingredient_in_warehouse) {
					if ((*i).get_Ingredient_name() != deyisdirilecekInqName || (*i).get_Ingredient_measure() != deyisdirilecekInqMeasure)
					{
						ingredient_in_warehouse.at(n)->set_Ingredient_name(deyisdirilecekInqName);
						ingredient_in_warehouse.at(n)->set_Ingredient_measure(deyisdirilecekInqMeasure);
						return true;
					}
				}
			}

		}


		return false;


	}

	void changeElementError(bool result) throw (Exception_Ingredient) {

		if (result == false) {

			for (size_t i = 0; i < ingredient_in_warehouse.size(); i++)
			{
				if (ingredient_in_warehouse.at(i)->get_Ingredient_name() != search) {

					throw Exception_Ingredient(" İnqredient deyisikliyi zamani xeta ", " Database.h ");
				}


			}
		}
	}



	void changeIngredient_Notification_Warehouse() {

		notifi_WarehouseChange.push_back(Notification_WarehouseChange("Inqridientler uqurla deyisildi ", "Database.h"));

	}

	void showChangeIngredient_Notification_Warehouse() {

		for (size_t i = 0; i < notifi_WarehouseChange.size(); i++)
		{
			notifi_WarehouseChange.at(i).printNotificationMessage();
		}
	}



	void showWarehouse() {

		for (auto w : ingredient_in_warehouse)
		{
			(*w).show_Ingredient();
		}



	}



	void deleteByID() {

		auto it = remove_if(ingredient_in_warehouse.begin(), ingredient_in_warehouse.end(), [](Ingredient* value) {
			if ((*value).getCurrentId() == (*value).axtar())
				return true;
			else {
				if ((*value).getCurrentId() != (*value).axtar()) {

					throw Exception_Ingredient(" Inqredient silme zamani xeta ", " Database.h ");
				}
			return false;
			}
			});

		ingredient_in_warehouse.erase(it, ingredient_in_warehouse.end());

		// ingredient_in_warehouse.erase(remove_if(ingredient_in_warehouse.begin(), ingredient_in_warehouse.end(), axtarID));
	}

	void deleteByID_Notification_Warehouse() {

		notifi_WarehouseDelete.push_back(Notification_WarehouseDelete("Ingredients delete in Warehouse ", "Warehouse.h"));

	}

	void showDeleteByID_Notification_Warehouse() {

		for (size_t i = 0; i < notifi_WarehouseDelete.size(); i++)
		{
			notifi_WarehouseDelete.at(i).printNotificationMessage();
		}
	}




	void Deletedublicate() {
		std::sort(ingredient_in_warehouse.begin(), ingredient_in_warehouse.end(), compare);
		ingredient_in_warehouse.erase(unique(ingredient_in_warehouse.begin(), ingredient_in_warehouse.end(), compare2forRemove), ingredient_in_warehouse.end());
	}




	void fileWrite() {
		for (auto w : ingredient_in_warehouse) {
			w->get_IngredientData();
			for (auto iw : file_in_Ingredient) {
				iw->write_fileIngredient(w->get_IngredientData());
			}
		}
	}

	void fileRead() {
		for (auto w : ingredient_in_warehouse) {
			w->get_IngredientData();
			for (auto iw : file_in_Ingredient) {
				iw->read_fileIngredient();
			}
		}
	}

	bool delete_fileIngredient() {
		if (remove("Ingredient.txt") != 0)
			perror("Ingredient.txt adli faylin silinmesinde xeta");
		else
			puts("kohne Ingredient.txt uqurla silindi");

		return true;
	}

	void file() {
		if (delete_fileIngredient() == true) {
			for (auto i : ingredient_in_warehouse) {
				string warehouse_data = i->get_İngredientdata();

				cout << endl;
				FileHelper filehelper_warehouse;
				filehelper_warehouse.write_fileIngredient(warehouse_data);
				cout << filehelper_warehouse.read_fileIngredient() << " " << endl;
			}
		}

		fileWrite();
		fileRead();
	}



	void addMeal() throw (Exception_Meal) {


		cout << "\n Menuya Daxil edilecek yemeklerin sayi: ";
		cin >> kindofmeal;

		for (size_t i = 0; i < count; i++)
		{
			if (kindofmeal == 0.0 || kindofmeal == NULL) {
				cout << "\n " << i + 1 << "  sans " << endl;

				cout << " Yemeklerin sayini yeniden daxil edin: ";
				cin >> kindofmeal;
				cin.ignore();
			}
		}

		if (kindofmeal == 0.0 || kindofmeal == NULL)
		{
			throw Exception_Meal("  Yemeklerin cesid sayi xetasi ", " Database.h ");
		}


		for (size_t i = 0; i < kindofmeal; i++)
		{

			cout << " \n Yemeyin adini yazin:  ";
			cin >> meal_name;
			cout << "\n Yemeyin qiymetini yazin:  ";
			cin >> meal_price;

			for (size_t i = 0; i < count; i++)
			{
				if (meal_price == 0.0 || meal_price == NULL) {
					cout << "\n " << i + 1 << "  chance " << endl;

					cout << " Yemeyin qiymetini tekrar daxil edin: ";
					cin >> meal_price;
					cin.ignore();
				}
			}

			if (meal_price == 0.0 || meal_price == NULL)
			{
				throw Exception_Meal("  Yemeyin qiymetinin xetasi ", " Database.h ");
			}

			cout << endl;
			meal_in_base.push_back(new Meal(meal_name, meal_price));

		}
	}




	void addNotification_Meal() {

		notifi_Mealadd.push_back(Notification_MealAdd("Yemekler uqurla elave edildi ", "Database.h"));

	}

	void showNotification_MealAdd() {


		for (size_t i = 0; i < notifi_Mealadd.size(); i++)
		{
			notifi_Mealadd.at(i).printNotificationMessage();
		}
	}



	void showMeal() {
		for (auto m : meal_in_base)
		{
			(*m).show_Meal();
		}
	}
	

	bool findMealElement() {

		cout << "\n Yemeyi axtar: ";
		cin >> search;
		for (size_t i = 0; i < meal_in_base.size(); i++)
		{
			if (search == meal_in_base.at(i)->get_Meal_name()) {
				cout << "\n ID: " << meal_in_base.at(i)->getCurrentId() << "\n Yemeyin adi: " << meal_in_base.at(i)->get_Meal_name() << "\n Yemeyin qiymeti: " << meal_in_base.at(i)->get_Meal_price() << endl;

				return true;
			}


		}
		return false;
	}


	void findMealElementError(bool result) throw (Exception_Meal) {

		if (result == false) {

			for (size_t i = 0; i < meal_in_base.size(); i++)
			{
				if (meal_in_base.at(i)->get_Meal_name() != search) {

					throw Exception_Meal("Yemekle axtarisi xetasi ", " Database.h ");
				}


			}
		}
	}


	void findMeal_Notification_MealFind() {

		notifi_Mealfind.push_back(Notification_MealFind(" Yemeyin axtarisi uqurlu oldu ", "Database.h"));

	}

	void showfindElement_Notification_Meal() {

		for (size_t i = 0; i < notifi_Mealfind.size(); i++)
		{
			notifi_Find.at(i).printNotificationMessage();
		}
	}


	bool  changeMeal() {

		
		cout << " Deyisdirilecek id : ";
		cin >> deyisM;

		cout << " Deyisdirilecek Yemek adi : ";
		cin >> deyisdirilecekMealName;



		cout << " Deyisdirilecek Yemeyin cekisi : ";
		cin >> deyisdirilecekMealPrice;

		cout << endl;

		for (int n = 0; n < meal_in_base.size(); n++) {

			if (meal_in_base.at(n)->getCurrentId() == deyisM) {
				for (auto i : meal_in_base) {
					if ((*i).get_Meal_name() != deyisdirilecekMealName || (*i).get_Meal_price() != deyisdirilecekMealPrice)
					{
						meal_in_base.at(n)->set_Meal_name(deyisdirilecekMealName);
						meal_in_base.at(n)->set_Meal_price(deyisdirilecekMealPrice);
						return true;
					}
				}
			}

		}


		return false;


	}

	void changeMealError(bool result) throw (Exception_Meal) {

		if (result == false) {

			for (size_t i = 0; i < meal_in_base.size(); i++)
			{
				if (meal_in_base.at(i)->get_Meal_name() != search) {

					throw Exception_Meal(" Yemek deyisikliyi zamani xeta ", " Database.h ");
				}


			}
		}
	}



	void changeMeal_Notification_Menu() {

		notifi_Mealchange.push_back(Notification_MealChange("Yemekler uqurla deyisildi ", "Database.h"));

	}

	void showchangeMeal_Notification_Menu() {

		for (size_t i = 0; i < notifi_Mealchange.size(); i++)
		{
			notifi_Mealchange.at(i).printNotificationMessage();
		}
	}




	void deleteMealByID() {

		auto it = remove_if(meal_in_base.begin(), meal_in_base.end(), [](Meal* value) {
			if ((*value).getCurrentId() == (*value).axtarMeal())
				return true;

			else {
				if ((*value).getCurrentId() != (*value).axtarMeal()) {

					throw Exception_Meal(" Yemek silme zamani xeta ", " Database.h ");
				}
				return false;
			}
			});

		meal_in_base.erase(it, meal_in_base.end());

	}


	void deleteByIDMeal_Notification_Meal() {

		notifi_Mealdelete.push_back(Notification_MealDelete("Yemek silindi ", "Database.h"));

	}

	void showDeleteByID_Notification_Meal() {

		for (size_t i = 0; i < notifi_Mealdelete.size(); i++)
		{
			notifi_Mealdelete.at(i).printNotificationMessage();
		}
	}


	void DeletedublicateMeal() {
		std::sort(meal_in_base.begin(), meal_in_base.end(), compareMeal);
		meal_in_base.erase(unique(meal_in_base.begin(), meal_in_base.end(), compare2forMealRemove), meal_in_base.end());
	}


	void fileWriteMeal() {
		for (auto w : meal_in_base) {
			w->get_MealData();
			for (auto iw : file_in_Meal) {
				iw->write_fileMeal(w->get_MealData());
			}
		}
	}

	void fileReadMeal() {
		for (auto w : meal_in_base) {
			w->get_MealData();
			for (auto iw : file_in_Meal) {
				iw->read_fileMeal();
			}
		}
	}

	bool delete_fileMeal() {
		if (remove("Meal.txt") != 0)
			perror("Meal.txt adli faylin silinmesinde xeta");
		else
			puts("Kohne Meal.txt uqurla silindi");

		return true;
	}

	void fileMeal() {
		if (delete_fileMeal() == true) {
			for (auto i : meal_in_base) {
				string meal_data = i->get_MealData();

				cout << endl;
				FileHelper filehelper_meal;
				filehelper_meal.write_fileMeal(meal_data);
				cout << filehelper_meal.read_fileMeal() << " " << endl;
			}
		}

		fileWriteMeal();
		fileReadMeal();
	}

	void addRecept() throw (Exception_Recipe) {
		cout << "\n Yemeklere daxil edilecek reseptlerin sayi: ";
		cin >> kindofrecept;
		



			for (size_t i = 0; i < count; i++)
			{
				if (kindofrecept == 0.0 || kindofrecept == NULL) {
					cout << "\n " << i + 1 << "  chance " << endl;

					cout << " Cesid sayini yeniden daxil edin: ";
					cin >> kindofrecept;
					cin.ignore();
				}
			}

			if (kindofrecept == 0.0 || kindofrecept == NULL)
			{
				throw Exception_Recipe("  Resept cesid sayi xetasi ", " Database.h ");
			}

		for (size_t i = 0; i < kindofrecept; i++)
		{

			cout << " " << "\n  Resepdin adi: ";
			cin >> recept_name;
			cout << " " << "\n  Reseptde daxil edilenin cekisi: ";
			cin >> recept_measure;
			for (size_t i = 0; i < count; i++)
			{
				if (recept_measure == 0.0 || recept_measure == NULL) {
					cout << "\n " << i + 1 << "  sans " << endl;

					cout << " Receptin cekisini yeniden daxil edin: ";
					cin >> recept_measure;
					cin.ignore();
				}
			}
			cout << " " << "\n\n  Receptin aid olduqu yemeyin ID -si: ";
			cin >> recept_mealid;


			if (recept_measure == 0.0 || recept_measure == NULL)
			{
				throw Exception_Recipe("  Reseptin cekisi xetasi ", " Database.h ");
			}

	

					Recept_in_base.push_back(new Recept(recept_name, recept_measure, recept_mealid));
				
				
			
		}
	}


	void addNotification_Recept() {

		notifi_Notification_ReceptAdd.push_back(Notification_ReceptAdd("Recept uqurla elave edildi ", "Database.h"));

	}

	void showNotification_ReceptAdd() {


		for (size_t i = 0; i < notifi_Mealadd.size(); i++)
		{
			notifi_Mealadd.at(i).printNotificationMessage();
		}
	}

	bool findReceptElement() {

		cout << "\n Resepti axtar: ";
		cin >> search;
		for (size_t i = 0; i < Recept_in_base.size(); i++)
		{
			if (search == Recept_in_base.at(i)->get_Recept_name()) {
				cout << "\n ID: " << Recept_in_base.at(i)->getCurrentId() << "\n Receptin adi: " << Recept_in_base.at(i)->get_Recept_name() << "\n Receptin cekisi: " << Recept_in_base.at(i)->get_Recept_name()<<"\n Receptin aid olduqu yemek ID -si: " << Recept_in_base.at(i)->get_Recept_mealID() << endl;

				return true;
			}


		}
		return false;
	}


	void findRecepElementError(bool result) throw (Exception_Recipe) {

		if (result == false) {

			for (size_t i = 0; i < Recept_in_base.size(); i++)
			{
				if (Recept_in_base.at(i)->get_Recept_name() != search) {

					throw Exception_Recipe("Recept axtarisi xetasi ", " Database.h ");
				}


			}
		}
	}


	void findMeal_Notification_ReceptFind() {

		notifi_Notification_ReceptFind.push_back(Notification_ReceptFind(" Receptin axtarisi uqurlu oldu ", "Database.h"));

	}

	void showElement_Notification_ReceptFind() {

		for (size_t i = 0; i < notifi_Notification_ReceptFind.size(); i++)
		{
			notifi_Find.at(i).printNotificationMessage();
		}
	}

	bool  changeRecept() {



		cout << " Deyisdirilecek id : ";
		cin >> deyisR;

		cout << " Deyisdirilecek Resept adi : ";
		cin >> deyisdirilecekRecName;

		cout << " Deyisdirilecek Reseptin cekisi : ";
		cin >> deyisdirilecekRecMeasure;

		cout << " Reseptin aid olduqu yemeyin ID deyisdir : ";
		cin >> deyisdirilecekRecMealID;

		cout << endl;

		for (int n = 0; n < Recept_in_base.size(); n++) {

			if (Recept_in_base.at(n)->getCurrentId() == deyisR) {
				for (auto i : Recept_in_base) {
					if ((*i).get_Recept_name() != deyisdirilecekRecName || (*i).get_Recept_measure() != deyisdirilecekRecMeasure)
					{
						Recept_in_base.at(n)->set_Recept_name(deyisdirilecekRecName);
						Recept_in_base.at(n)->set_Recept_measure(deyisdirilecekRecMeasure);
						Recept_in_base.at(n)->set_Recept_mealID(deyisdirilecekRecMealID);

						return true;
					}
				}
			}

		}


		return false;


	}

	void changeReceptError(bool result) throw (Exception_Recipe) {

		if (result == false) {

			for (size_t i = 0; i < Recept_in_base.size(); i++)
			{
				if (Recept_in_base.at(i)->get_Recept_name() != search) {

					throw Exception_Recipe(" Reseptde deyisiklik zamani xeta ", " Database.h ");
				}


			}
		}
	}


	void changeRecept_Notification_Base() {

		notifi_Notification_ReceptChange.push_back(Notification_ReceptChange("Reseptler uqurla deyisildi ", "Database.h"));

	}

	void showChangeRecept_Notification_Base() {

		for (size_t i = 0; i < notifi_Notification_ReceptChange.size(); i++)
		{
			notifi_Notification_ReceptChange.at(i).printNotificationMessage();
		}
	}


	void deleteReceptByID() {

		auto it = remove_if(Recept_in_base.begin(), Recept_in_base.end(), [](Recept* value) {
			if ((*value).getCurrentId() == (*value).axtarRecept())
				return true;
			else {
				if ((*value).getCurrentId() != (*value).axtarRecept()) {

					throw Exception_Recipe(" Recept silme zamani xeta ", " Database.h ");
				}
				return false;
			}
			});

		Recept_in_base.erase(it, Recept_in_base.end());

	}

	void deleteByIDRecept_Notification_Meal() {

		notifi_Notification_ReceptDelete.push_back(Notification_ReceptDelete("Resept silindi ", "Database.h"));

	}

	void showDeleteByID_Notification_Recept() {

		for (size_t i = 0; i < notifi_Notification_ReceptDelete.size(); i++)
		{
			notifi_Notification_ReceptDelete.at(i).printNotificationMessage();
		}
	}


	void DeletedublicateRecept() {
		std::sort(Recept_in_base.begin(), Recept_in_base.end(), compareRecept);
		Recept_in_base.erase(unique(Recept_in_base.begin(), Recept_in_base.end(), compare3forRemoveRecept), Recept_in_base.end());
	}


	bool findMealRecept() {

		cout << "\n\n Yemeye aid resepleri gormek ucun Yemeyin ID -sini yazin: ";
		cin >> mealrecept;
		for (size_t i = 0; i < Recept_in_base.size(); i++)
		{
			for (size_t i = 0; i < meal_in_base.size(); i++)
			{
				if (meal_in_base.at(i)->getCurrentId() == mealrecept && Recept_in_base.at(i)->get_Recept_mealID()== mealrecept) {
					Recept_in_base.at(i)->show_Recept();
					return true;
				}
			}
		}

		return false;
	}


	void findMealReceptError(bool result) throw (Exception_Recipe) {

		if (result == false) {

			for (size_t i = 0; i < meal_in_base.size(); i++)
			{
				if (meal_in_base.at(i)->getCurrentId() != mealrecept || Recept_in_base.at(i)->get_Recept_mealID() != mealrecept) {

					throw Exception_Recipe("Yemeyin Reseptinin axtarisi xetasi ", " Database.h ");
				}


			}
		}
	}

	void findMealRecept_Notification_SearchRecipeMeal() {

		notifi_SearchRecipeMeal.push_back(Notification_SearchRecipeMeal("Yemeyin Resepti tapildi ", "Database.h"));

	}

	void showfindMealRecept_Notification_SearchRecipeMeal() {

		for (size_t i = 0; i < notifi_SearchRecipeMeal.size(); i++)
		{
			notifi_SearchRecipeMeal.at(i).printNotificationMessage();
		}
	}

	void fileWriteRecept() {
		for (auto w : Recept_in_base) {
			w->get_Receptdata();
			for (auto iw : file_in_Recept) {
				iw->write_fileRecept(w->get_Receptdata());
			}
		}
	}


	void fileReadRecept() {
		for (auto w : Recept_in_base) {
			w->get_Receptdata();
			for (auto iw : file_in_Recept) {
				iw->read_fileMeal();
			}
		}
	}


	bool delete_fileRecept() {
		if (remove("Recept.txt") != 0)
			perror("Recept.txt adli faylin silinmesinde xeta");
		else
			puts("Kohne Recept.txt uqurla silindi");

		return true;
	}


	void fileRecept() {
		if (delete_fileRecept() == true) {
			for (auto i : Recept_in_base) {
				string recept_data = i->get_Receptdata();

				cout << endl;
				FileHelper filehelper_meal;
				filehelper_meal.write_fileRecept(recept_data);
				cout << filehelper_meal.read_fileRecept() << " " << endl;
			}
		}

		fileWriteRecept();
		fileReadRecept();
	}




	void showRecept() {
		for (auto r : Recept_in_base)
		{
			(*r).show_Recept();
		}
	}


	void addOrder() {
	
		cout << "\n Masa nomresi: ";
		cin >> tableNo;

		for (size_t i = 0; i < count; i++)
		{
			if (tableNo == 0.0 || tableNo == NULL) {
				cout << "\n " << i + 1 << "  sans " << endl;

				cout << " Masa nomresini yeniden daxil edin: ";
				cin >> tableNo;
				cin.ignore();
			}
		}

		if (tableNo == 0.0 || tableNo == NULL)
		{
			throw Exception_Recipe("   Masa nomresini xetasi ", " Database.h ");
		}

		cout << "\n Masanin sifaris etdiyi yemek ID -si: ";
		cin >> orderMealID;

		for (size_t i = 0; i < meal_in_base.size(); i++)
		{
			if (meal_in_base.at(i)->getCurrentId() == orderMealID) {
				Order_in_base.push_back(new Order(tableNo, meal_in_base.at(i)->getCurrentId()));
			}
		}
	}

	void addNotification_Order() {

		notifi_Notification_OrderAdd.push_back(Notification_OrderAdd("Sifaris uqurla elave edildi ", "Database.h"));

	}



	void showNotification_Order() {


		for (size_t i = 0; i < notifi_Mealadd.size(); i++)
		{
			notifi_Mealadd.at(i).printNotificationMessage();
		}
	}

	bool findOrderElement() {
		cout << "\n Yemeyi axtar: ";
		cin >> searchID;
		for (size_t i = 0; i < Order_in_base.size(); i++)
		{
			if (searchID == Order_in_base.at(i)->get_OrderMealID()) {
				cout << "\n ID: " << Order_in_base.at(i)->getCurrentId() << "\n Orderin adi: " << Order_in_base.at(i)->get_OrderMealID() << "\n Masanin nomresi: " << Order_in_base.at(i)->get_OrderTable() <<endl << endl;

				return true;
			}


		}
		return false;
	}

	void findOrderElementError(bool result) throw (Exception_Order) {

		if (result == false) {

			for (size_t i = 0; i < Order_in_base.size(); i++)
			{
				if (Order_in_base.at(i)->get_OrderMealID() != searchID) {

					throw Exception_Order("Sifaris axtarisi xetasi ", " Database.h ");
				}


			}
		}
	}

	void findMeal_Notification_OrderFind() {

		notifi_Notification_OrderFind.push_back(Notification_OrderFind(" Sifarisin axtarisi uqurlu oldu ", "Database.h"));

	}

	void showElement_Notification_OrderFind() {

		for (size_t i = 0; i < notifi_Notification_ReceptFind.size(); i++)
		{
			notifi_Find.at(i).printNotificationMessage();
		}
	}


	void deleteByIDofOrder() {

		auto it = remove_if(Order_in_base.begin(), Order_in_base.end(), [](Order* value) {
			if ((*value).getCurrentId() == (*value).axtarOrder())
				return true;
			else {
				if ((*value).getCurrentId() != (*value).axtarOrder()) {

					throw Exception_Order(" Sifaris silme zamani xeta ", " Database.h ");
				}
				return false;
			}
			});

		Order_in_base.erase(it, Order_in_base.end());

		// ingredient_in_warehouse.erase(remove_if(ingredient_in_warehouse.begin(), ingredient_in_warehouse.end(), axtarID));
	}

	void deleteByID_Notification_Order() {

		notifi_Notification_OrderDelete.push_back(Notification_OrderDelete("Ingredients delete in Warehouse ", "Warehouse.h"));

	}



	void showDeleteByID_Notification_Order() {

		for (size_t i = 0; i < notifi_Notification_OrderDelete.size(); i++)
		{
			notifi_Notification_OrderDelete.at(i).printNotificationMessage();
		}
	}

	void showOrder() {
		for (auto o : Order_in_base)
		{
			(*o).show_Order();
		}
	}


	void budget() {
		cout << "Sum: " << sum << endl;
	}


	

	void orderget() {

		cout << "\n Sifaris verilen yemek iD: ";
		cin >> orderID;

		for (int i = 0; i < meal_in_base.size(); i++) {
			if (meal_in_base.at(i)->getCurrentId() == orderID) {
				price = meal_in_base.at(i)->get_Meal_price();
				sum += price;

			}
		}
		



	
			for (auto j : Recept_in_base) {
				if (orderID == (*j).get_Recept_mealID()) {
					for (auto i : ingredient_in_warehouse) {
						if ((*j).get_Recept_name() == (*i).get_Ingredient_name()) {

							newInqmeasure = (*i).get_Ingredient_measure() - (*j).get_Recept_measure();

							(*i).set_Ingredient_measure(newInqmeasure);
						}
					}
				}

			}

		

	}

	friend ostream& operator<<(ostream& out, Database& other);
	friend istream& operator >> (istream& in, Database& other);
};


istream& operator >> (istream& in, Database& other)
{
	other.addIngredient();
	other.changeIngredient();
	other.findElement();
	other.deleteByID();
	return in;
}


ostream& operator <<(ostream& out, Database& other)
{
	other.showWarehouse();
	other.file();
	return out;
}





