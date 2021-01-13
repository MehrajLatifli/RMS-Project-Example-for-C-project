#include "Exeption.h"
#include "Restaurant Management System.h"
#include "FileHelper.h"
#include "Notification.h"
#include "Admin.h"
#include "Waiter.h"
#include "Chef.h"
#include "Warehouseman.h"
#include "Ingredient.h"
#include "Meal.h"
#include "Order.h"
#include "Database.h"
#include "Recept.h"

using namespace std;

int main() {
	int choose = 0;
	int workercount = 0;
	int adminchoose = 0;
	int waiterchoose = 0;
	int chefchoose = 0;
	int warehousemanchoose = 0;
	string restaurant_name, restaurant_address, restaurant_phonenumber;
	double restaurant_budget = 0, restaurant_rating = 0;



	RestaurantManagementSystem rms(restaurant_name, restaurant_address, restaurant_phonenumber, restaurant_rating);
	Admin adminacount;
	Waiter	waiteracount;
	Chef chefacount;
	Warehouseman warehousemanacount;

	string  ingredient_name;
	double ingredient_measure = 0.0;
	string  recipe_name;
	int recipe_measure = 0;
	string meal_name;
	double meal_price = 0.0;
	int numberoftable = 0;
	int deleteindex = 0;


	Ingredient ingredient_info(ingredient_name, ingredient_measure);

	Meal meal_info;
	Database database_info;
	Order order_info;

	Recept recept_info;

	int warehouseOperation = 0;
	int chefOperation = 0;

	int waiterOperation = 0;
	int adminOperration = 0;

	for (int i = 0; i < 1000; i++)
	{



		cout << "\n  " << 1 << " <- Add data of Restaurant  " << endl;
		cout << "  " << 2 << " <- Read data of Restaurant  from RMS.txt " << endl;
		cout << "  " << 3 << " <- Control  " << endl;
		cout << " \n Enter: \t\t";
		cin >> choose;
		if (choose == 1) {
			try
			{
				rms.fill_RestaurantManagementSystem();
				rms.print_RestaurantManagementSystem();
				rms.addNotification_RestaurantManagementSystem();
				rms.showNotification_RestaurantManagementSystem();

			}
			catch (Exception_RestaurantManagementSystem& ex1)
			{
				ex1.printExceptionMessage();
				break;
			}
		}
		if (choose == 2) {
			Sleep(500);
			system("CLS");

			string rms_data = rms.get_RMSdata();
			cout << endl;
			FileHelper filehelper_rms;
			filehelper_rms.write_fileRMS(rms_data);
			cout << filehelper_rms.read_fileRMS() << " " << endl;
		}


		if (choose == 3) {

			Sleep(500);
			system("CLS");

			cout << "\n " << 1 << " <- Admin's control  " << endl;
			cout << " " << 2 << " <- Waiter's control   " << endl;
			cout << " " << 3 << " <- Chef's control   " << endl;
			cout << " " << 4 << " <- Warehouseman's control   " << endl;
			cout << " \n Enter: \t\t";
			cin >> workercount;

			if (workercount == 1) {
				cout << "\n " << 1 << " <- Join account  " << endl;
				cout << " " << 2 << " <- Read data from Admin.txt " << endl;
				cout << " " << 3 << " <- Log in account   " << endl;
				cout << " \n Enter: \t\t";
				cin >> adminchoose;
				cin.ignore();
				if (adminchoose == 1) {
					Sleep(500);
					system("CLS");
					try
					{

						adminacount.singUp();
						adminacount.showSingUp();
						adminacount.addSingUp_Notification_Admin();
						adminacount.showSingUp_Notification_Admin();




					}
					catch (Exception_Admin& ex2)
					{
						ex2.printExceptionMessage();


						string adminJoinError = ex2.get_ExceptionAdmin_joindata();
						cout << endl;
						FileHelper filehelper_adminError;

						filehelper_adminError.write_AdminJoinError(adminJoinError);
						cout << filehelper_adminError.read_AdminJoinError() << " " << endl;

					}
				}
				if (adminchoose == 2) {
					Sleep(500);
					system("CLS");
					string admin_data = adminacount.get_Admindata();
					cout << endl;
					FileHelper filehelper_admin;
					filehelper_admin.write_fileAdmin(admin_data);
					cout << filehelper_admin.read_fileAdmin() << " " << endl;
				}

				if (adminchoose == 3) {
					Sleep(500);
					system("CLS");
					try
					{

						adminacount.singIn();
						adminacount.showSingIn();

						adminacount.addSingIn_Notification_Admin();
						adminacount.showSingIn_Notification_Admin();


					}
					catch (Exception_Admin& ex3)
					{
						ex3.printExceptionMessage();


						string adminLoginError = ex3.get_ExceptionAdmin_Logindata();
						cout << endl;
						FileHelper filehelper_adminError;

						filehelper_adminError.write_AdminLoginError(adminLoginError);
						cout << filehelper_adminError.read_AdminLoginError() << " " << endl;

					}


					cout << "\n " << 1 << " <- View Kitchen   " << endl;
					cout << " " << 2 << " <- View Stock   " << endl;
					cout << " \n Enter: \t\t";
					cin >> adminOperration;

					if (adminchoose == 1) {
						Sleep(500);
						system("CLS");

						database_info.showMeal();


					}

					if (adminchoose == 2) {
						Sleep(500);
						system("CLS");

						database_info.showWarehouse();

					}
				}
			}
			if (workercount == 2) {
				cout << "\n " << 1 << " <- Join account  " << endl;
				cout << " " << 2 << " <- Read data from Waiter.txt " << endl;
				cout << " " << 3 << " <- Log in account   " << endl;

				cout << " \n Enter: \t\t";
				cin >> waiterchoose;
				if (waiterchoose == 1) {
					Sleep(500);
					system("CLS");
					try
					{

						waiteracount.singUp();
						waiteracount.showSingUp();
						waiteracount.addSingUp_Notification_Waiter();
						waiteracount.showSingUp_Notification_Waiter();


					}
					catch (Exception_Waiter& ex2)
					{
						ex2.printExceptionMessage();

						string waiterJoinError = ex2.get_ExceptionWaiter_joindata();
						cout << endl;
						FileHelper filehelper_waiterError;

						filehelper_waiterError.write_WaiterJoinError(waiterJoinError);
						cout << filehelper_waiterError.read_WaiterJoinError() << " " << endl;
					}
				}
				if (waiterchoose == 2) {
					Sleep(500);
					system("CLS");
					string waiteracount_data = waiteracount.get_Waiterdata();
					cout << endl;
					FileHelper filehelper_waiter;
					filehelper_waiter.write_fileWaiter(waiteracount_data);
					cout << filehelper_waiter.read_fileWaiter() << " " << endl;
				}

				if (waiterchoose == 3) {
					Sleep(500);
					system("CLS");
					try
					{

						waiteracount.singIn();
						waiteracount.showSingIn();

						waiteracount.addSingIn_Notification_Waiter();
						waiteracount.showSingIn_Notification_Waiter();


					}
					catch (Exception_Waiter& ex2)
					{
						ex2.printExceptionMessage();

						string waiterJoinError = ex2.get_ExceptionWaiter_joindata();
						cout << endl;
						FileHelper filehelper_waiterError;

						filehelper_waiterError.write_WaiterJoinError(waiterJoinError);
						cout << filehelper_waiterError.read_WaiterJoinError() << " " << endl;

					}


				
					cout << "\n " << 1 << " <- View Menu   " << endl;
					cout << " " << 2 << " <- View Menu with Recept   " << endl;
					cout << " " << 3 << " <- Meal search   " << endl;
					cout << " " << 4 << " <- Add Order   " << endl;
					cout << " " << 5 << " <- View Order   " << endl;

					cout << "\n  Enter: ";
					cin >> waiterOperation;

					if (waiterOperation == 1) {
						database_info.showMeal();
					}

					if (waiterOperation == 2) {
						database_info.showMeal();
						database_info.showRecept();
					}

					if (waiterOperation == 3) {
						database_info.showMeal();
						database_info.showRecept();
						database_info.findMealElement();
					}

					if (waiterOperation == 4) {
						Sleep(500);
						system("CLS");
						try
						{
							database_info.showMeal();
							database_info.showOrder();
							database_info.addOrder();
							Sleep(500);
							system("CLS");
							database_info.showOrder();
							database_info.addNotification_Order();
							database_info.showNotification_Order();



						}
						catch (Exception_Order& ex2)
						{
							ex2.printExceptionMessage();

							string OrderAddError = ex2.get_Exception_OrderAdddata();
							cout << endl;
							FileHelper filehelper_OrderError;

							filehelper_OrderError.write_Exception_OrderAdd(OrderAddError);
							cout << filehelper_OrderError.read_Exception_OrderAdd() << " " << endl;
						}

					}

					if (waiterOperation == 5) {


						database_info.showOrder();



					}
				}

			}

			if (workercount == 3) {
				cout << "\n " << 1 << " <- Join account  " << endl;
				cout << " " << 2 << " <- Read data from Chef.txt " << endl;
				cout << " " << 3 << " <- Log in account   " << endl;

				cout << " \n Enter: \t\t";
				cin >> chefchoose;
				if (chefchoose == 1) {
					Sleep(500);
					system("CLS");
					try
					{

						chefacount.singUp();
						chefacount.showSingUp();
						chefacount.addSingUp_Notification_Chef();
						chefacount.showSingUp_Notification_Chef();


					}
					catch (Exception_Chef& ex2)
					{
						ex2.printExceptionMessage();

						string ChefJoinError = ex2.get_ExceptionChef_joindata();
						cout << endl;
						FileHelper filehelper_ChefError;

						filehelper_ChefError.write_ChefJoinError(ChefJoinError);
						cout << filehelper_ChefError.read_ChefJoinError() << " " << endl;
					}
				}
				if (chefchoose == 2) {
					Sleep(500);
					system("CLS");
					string chefacount_data = chefacount.get_Chefdata();
					cout << endl;
					FileHelper filehelper_chef;
					filehelper_chef.write_fileChef(chefacount_data);
					cout << filehelper_chef.read_fileChef() << " " << endl;
				}

				if (chefchoose == 3) {
					Sleep(500);
					system("CLS");
					try
					{

						chefacount.singIn();
						chefacount.showSingIn();

						chefacount.addSingIn_Notification_Chef();
						chefacount.showSingIn_Notification_Chef();


					}
					catch (Exception_Chef& ex3)
					{
						ex3.printExceptionMessage();

						string ChefLogiNError = ex3.get_ExceptionChef_Logindata();
						cout << endl;
						FileHelper filehelper_ChefError;

						filehelper_ChefError.write_ChefLoginError(ChefLogiNError);
						cout << filehelper_ChefError.read_ChefLoginError() << " " << endl;

					}
				


					cout << " " << 1 << " <- Add Menu   " << endl;
					cout << " " << 2 << " <- View Menu   " << endl;
					cout << " " << 3 << " <- Change Meal   " << endl;
					cout << " " << 4 << " <- Change Recipe   " << endl;
					cout << " " << 5 << " <- Search Meal   " << endl;
					cout << " " << 6 << " <- Search Recipe   " << endl;
					cout << " " << 7 << " <- Delete Meal  " << endl;
					cout << " " << 8 << " <- Delete Recipe  " << endl;
					cout << " " << 9 << " <- Search Recipe for meal   " << endl;
					cout << " " << 10 << " <- Order operation   " << endl;
					cout << " " << 11 << " <- Read data from Recept.txt , Meal.txt \n" << endl;

					

				if (chefOperation == 1) {
					Sleep(500);
					system("CLS");

					try
					{


						database_info.showMeal();
						database_info.addMeal();
						database_info.DeletedublicateMeal();
						database_info.showMeal();

						database_info.addNotification_Meal();
						database_info.showNotification_MealAdd();


					}
					catch (Exception_Meal& ex3)
					{
						ex3.printExceptionMessage();

						string MealAddError = ex3.get_Exception_MealAdddata();
						cout << endl;
						FileHelper filehelper_MealError;

						filehelper_MealError.write_Exception_MealAdddata(MealAddError);
						cout << filehelper_MealError.read_Exception_MealAdddata() << " " << endl;
					}



					try
					{
						database_info.showWarehouse();
						database_info.addRecept();
						database_info.DeletedublicateRecept();
						database_info.showRecept();

						database_info.addNotification_Recept();
						database_info.showNotification_ReceptAdd();


					}
					catch (Exception_Recipe& ex3)
					{
						ex3.printExceptionMessage();


						string RecipeAddError = ex3.get_Exception_RecipeAdddata();
						cout << endl;
						FileHelper filehelper_RecipeError;

						filehelper_RecipeError.write_Exception_RecipeAdddata(RecipeAddError);
						cout << filehelper_RecipeError.read_Exception_RecipeAdddata() << " " << endl;
					}


				}

				if (chefOperation == 2) {
					Sleep(500);
					system("CLS");

					database_info.showMeal();
					database_info.showRecept();

				}

				if (chefOperation == 3) {
					Sleep(500);
					system("CLS");

					try
					{


						database_info.showMeal();
						bool result = database_info.changeMeal();
						database_info.changeMealError(result);
						database_info.showMeal();

						database_info.changeMeal_Notification_Menu();
						database_info.showchangeMeal_Notification_Menu();




					}
					catch (Exception_Meal& ex3)
					{
						ex3.printExceptionMessage();

						string MealChangeError = ex3.get_Exception_MealChangedata();
						cout << endl;
						FileHelper filehelper_MealError;

						filehelper_MealError.write_Exception_MealChangedata(MealChangeError);
						cout << filehelper_MealError.read_Exception_MealChangedata() << " " << endl;
					}
				}
				if (chefOperation == 4) {
					Sleep(500);
					system("CLS");

					try
					{



						database_info.showRecept();
						bool result2 = database_info.changeRecept();
						database_info.changeReceptError(result2);
						database_info.showRecept();

						database_info.changeRecept_Notification_Base();
						database_info.showChangeRecept_Notification_Base();


					}
					catch (Exception_Recipe& ex3)
					{
						ex3.printExceptionMessage();

						string RecipeChangeError = ex3.get_Exception_RecipeChangedata();
						cout << endl;
						FileHelper filehelper_RecipeError;

						filehelper_RecipeError.write_Exception_RecipeChangedata(RecipeChangeError);
						cout << filehelper_RecipeError.read_Exception_RecipeChangedata() << " " << endl;

					}

				}

				if (chefOperation == 5) {
					Sleep(500);
					system("CLS");

					try
					{




						database_info.showMeal();
						bool result = database_info.findMealElement();

						database_info.findMealElementError(result);


						database_info.findMeal_Notification_MealFind();
						database_info.showfindElement_Notification_Meal();


					}
					catch (Exception_Meal& ex3)
					{
						ex3.printExceptionMessage();

						string MealSearchError = ex3.get_Exception_MealFinddata();
						cout << endl;
						FileHelper filehelper_MealError;

						filehelper_MealError.write_Exception_MealFinddata(MealSearchError);
						cout << filehelper_MealError.read_Exception_MealFinddata() << " " << endl;
					}

				}

				if (chefOperation == 6) {
					Sleep(500);
					system("CLS");

					try
					{

						database_info.showRecept();
						bool result2 = database_info.findReceptElement();
						database_info.findRecepElementError(result2);

						database_info.findMeal_Notification_ReceptFind();
						database_info.showElement_Notification_ReceptFind();


					}
					catch (Exception_Recipe& ex3)
					{
						ex3.printExceptionMessage();

						string RecipeSearchError = ex3.get_Exception_RecipeFinddata();
						cout << endl;
						FileHelper filehelper_RecipeError;

						filehelper_RecipeError.write_Exception_RecipeFinddata(RecipeSearchError);
						cout << filehelper_RecipeError.read_Exception_RecipeFinddata() << " " << endl;
					}

				}

				if (chefOperation == 7) {
					Sleep(500);
					system("CLS");

					try
					{

						database_info.showMeal();
						meal_info.FillaxtarMeal();
						database_info.deleteMealByID();

						database_info.showMeal();

						database_info.deleteByIDRecept_Notification_Meal();
						database_info.showDeleteByID_Notification_Meal();


					}
					catch (Exception_Meal& ex3)
					{
						ex3.printExceptionMessage();

						string MealDeleteError = ex3.get_Exception_MealDeletedata();
						cout << endl;
						FileHelper filehelper_MealError;

						filehelper_MealError.write_Exception_MealDeletedata(MealDeleteError);
						cout << filehelper_MealError.read_Exception_MealDeletedata() << " " << endl;

					}

				}

				if (chefOperation == 8) {
					Sleep(500);
					system("CLS");

					try
					{

						database_info.showMeal();
						recept_info.FillaxtarRecept();
						database_info.deleteReceptByID();

						database_info.showMeal();

						database_info.showDeleteByID_Notification_Recept();
						database_info.deleteByIDRecept_Notification_Meal();


					}
					catch (Exception_Recipe& ex3)
					{
						ex3.printExceptionMessage();

						string RecipeDeleteError = ex3.get_Exception_RecipeDeletedata();
						cout << endl;
						FileHelper filehelper_RecipeError;

						filehelper_RecipeError.write_Exception_RecipeDeletedata(RecipeDeleteError);
						cout << filehelper_RecipeError.read_Exception_RecipeDeletedata() << " " << endl;
					}

				}

				if (chefOperation == 9) {
					Sleep(500);
					system("CLS");

					try
					{
						database_info.showRecept();

						bool result2 = database_info.findMealRecept();
						database_info.findMealReceptError(result2);


						database_info.findMealRecept_Notification_SearchRecipeMeal();
						database_info.showfindMealRecept_Notification_SearchRecipeMeal();

					}
					catch (Exception_Recipe& ex3)
					{
						ex3.printExceptionMessage();


						string MealRecipeFindError = ex3.get_Exception_MealRecipeFind();
						cout << endl;
						FileHelper filehelper_RecipeError;

						filehelper_RecipeError.write_Exception_MealRecipeFind(MealRecipeFindError);
						cout << filehelper_RecipeError.read_Exception_MealRecipeFind() << " " << endl;

					}

				}

				if (chefOperation == 10) {
					Sleep(500);
					system("CLS");

					try
					{
						database_info.showMeal();
						database_info.showOrder();
						int getorder;
						cout << " Sifarisi qebul etmek ucun 1-e, Imtina etmek ucun 2 -e basin: ";
						cin >> getorder;
						if (getorder == 1) {
							database_info.orderget();
						}

						if (getorder == 2) {
							database_info.deleteByIDofOrder();
						}

					}
					catch (Exception_Database& ex3)
					{
						ex3.printExceptionMessage();
						break;
					}

				}

				if (chefOperation == 11) {
					Sleep(500);
					system("CLS");

					try
					{

						database_info.fileMeal();
						database_info.fileRecept();

					}
					catch (Exception_Recipe& ex3)
					{
						ex3.printExceptionMessage();

					}

					

				}

			}





			}
		}





		if (workercount == 4) {
			cout << "\n " << 1 << " <- Join account  " << endl;
			cout << " " << 2 << " <- Read data from Warehouseman.txt " << endl;
			cout << " " << 3 << " <- Log in account   " << endl;

			cout << " \n Enter: \t\t";
			cin >> warehousemanchoose;
			cin.ignore();
			if (warehousemanchoose == 1) {
				Sleep(500);
				system("CLS");
				try
				{

					warehousemanacount.singUp();
					warehousemanacount.showSingUp();
					warehousemanacount.addSingUp_Notification_Warehouseman();
					warehousemanacount.showSingUp_Notification_Warehouseman();


				}
				catch (Exception_Warehouseman& ex4)
				{
					ex4.printExceptionMessage();

					string WarehousemanJoinError = ex4.get_ExceptionWarehouseman_joindata();
					cout << endl;
					FileHelper filehelper_ChefError;

					filehelper_ChefError.write_WarehousemanJoinError(WarehousemanJoinError);
					cout << filehelper_ChefError.read_WarehousemanJoinError() << " " << endl;
				}
			}
			if (warehousemanchoose == 2) {
				Sleep(500);
				system("CLS");
				string warehouseman_data = warehousemanacount.get_Warehousemandata();
				cout << endl;
				FileHelper filehelper_warehouseman;
				filehelper_warehouseman.write_fileWarehouseman(warehouseman_data);
				cout << filehelper_warehouseman.read_fileWarehouseman() << " " << endl;
			}

			if (warehousemanchoose == 3) {
				Sleep(500);
				system("CLS");
				try
				{

					warehousemanacount.singIn();
					warehousemanacount.showSingIn();

					warehousemanacount.addSingIn_Notification_Warehouseman();
					warehousemanacount.showSingIn_Notification_Warehouseman();


				}
				catch (Exception_Warehouseman& ex4)
				{
					ex4.printExceptionMessage();

					string WarehousemanLogInError = ex4.get_ExceptionWarehouseman_Logindata();
					cout << endl;
					FileHelper filehelper_WarehousemanError;

					filehelper_WarehousemanError.write_WarehousemanLoginError(WarehousemanLogInError);
					cout << filehelper_WarehousemanError.read_WarehousemanLoginError() << " " << endl;

					break;

				}


				cout << " " << 1 << " <- Add Ingredients   " << endl;
				cout << " " << 2 << " <- View Ingredients   " << endl;
				cout << " " << 3 << " <- Change Ingredients   " << endl;
				cout << " " << 4 << " <- Search Ingredients   " << endl;
				cout << " " << 5 << " <- Delete Ingredients   " << endl;
				cout << " " << 6 << " <- Write data from Warehouse.txt \n" << endl;
				cout << " \n Enter: ";
				cin >> warehouseOperation;
				if (warehouseOperation == 1) {
					Sleep(500);
					system("CLS");
					try
					{

						database_info.showWarehouse();
						database_info.addIngredient();;
						database_info.Deletedublicate();
						database_info.showWarehouse();







						database_info.addNotification_Warehouse();
						database_info.showNotification_Warehouse();


					}
					catch (Exception_Ingredient& ex4)
					{

						ex4.printExceptionMessage();

						string addIngredient = ex4.get_Exception_IngredientAdddata();
						cout << endl;
						FileHelper filehelper_AddIngredientError;

						filehelper_AddIngredientError.write_Exception_IngredientAdddata(addIngredient);
						cout << filehelper_AddIngredientError.read_Exception_IngredientAdddata() << " " << endl;

					}



				}

				if (warehouseOperation == 2) {
					Sleep(500);
					system("CLS");

					database_info.showWarehouse();



				}


				if (warehouseOperation == 3) {


					Sleep(500);
					system("CLS");
					try
					{


						database_info.showWarehouse();
						bool result = database_info.changeIngredient();
						database_info.changeElementError(result);


						database_info.changeIngredient_Notification_Warehouse();
						database_info.showChangeIngredient_Notification_Warehouse();



					}
					catch (Exception_Ingredient& ex4)
					{
						ex4.printExceptionMessage();


						string changeIngredient = ex4.get_Exception_IngredientChangedata();
						cout << endl;
						FileHelper filehelper_ChangeIngredientError;

						filehelper_ChangeIngredientError.write_Exception_IngredientChangedata(changeIngredient);
						cout << filehelper_ChangeIngredientError.read_Exception_IngredientChangedata() << " " << endl;
					}
				}





				if (warehouseOperation == 4) {
					Sleep(500);
					system("CLS");
					try
					{


						database_info.showWarehouse();
						bool result = database_info.findElement();

						database_info.findElementError(result);
						Sleep(2500);
						system("CLS");
						database_info.findElement_Notification_Warehouse();
						database_info.showfindElement_Notification_Warehouse();


					}
					catch (Exception_Ingredient& ex4)
					{
						ex4.printExceptionMessage();

						string FindIngredient = ex4.get_Exception_IngredientFinddata();
						cout << endl;
						FileHelper filehelper_FindIngredienttError;

						filehelper_FindIngredienttError.write_Exception_IngredientFinddata(FindIngredient);
						cout << filehelper_FindIngredienttError.read_Exception_IngredientFinddata() << " " << endl;
					}



				}

				if (warehouseOperation == 5) {
					try
					{
						Sleep(500);
						system("CLS");


						database_info.showWarehouse();
						ingredient_info.Fillaxtar();
						//ingredient_info.axtar();
						database_info.deleteByID();
						database_info.showWarehouse();

						Sleep(500);
						system("CLS");

						database_info.deleteByID_Notification_Warehouse();
						database_info.showDeleteByID_Notification_Warehouse();


					}
					catch (Exception_Ingredient& ex5)
					{
						ex5.printExceptionMessage();

						string DeleteIngredient = ex5.get_Exception_IngredientDeletedata();
						cout << endl;
						FileHelper filehelper_DeleteIngredienttError;

						filehelper_DeleteIngredienttError.write_Exception_IngredientDeletedata(DeleteIngredient);
						cout << filehelper_DeleteIngredienttError.read_Exception_IngredientDeletedata() << " " << endl;

					}


				}

				if (warehouseOperation == 6) {
					Sleep(500);
					system("CLS");

					database_info.file();

					Sleep(2500);
					system("CLS");

				}
			}

		





		}

	}

}
	

	












