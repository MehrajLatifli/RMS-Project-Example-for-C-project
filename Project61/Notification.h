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
#include <Windows.h>

using namespace std;

class Notification {
protected:
	string notification_text;
	string notification_sourse;
	int notification_line;
public:

	Notification() :notification_text(""), notification_sourse("") {}

	Notification(string notification_text, string notification_sourse)
	{

		set_Notification_text(notification_text);
		set_Notification_sourse(notification_sourse);

	}

	Notification(Notification& other)
	{

		set_Notification_text(other.notification_text);
		set_Notification_sourse(other.notification_sourse);

	}

	Notification& operator=(Notification& other)
	{

		set_Notification_text(other.notification_text);
		set_Notification_sourse(other.notification_sourse);

		return *this;

	}

	Notification(Notification&& other)
	{

		set_Notification_text(other.notification_text);
		set_Notification_sourse(other.notification_sourse);
		set_Notification_line(other.notification_line);

		

	}

	string get_Notification_text() {
		return this->notification_text;
	}

	void set_Notification_text(string& notification_text)
	{
		this->notification_text = notification_text;
	}

	string get_Notification_sourse() {
		return this->notification_sourse;
	}

	void set_Notification_sourse(string& notification_sourse)
	{
		this->notification_sourse = notification_sourse;
	}

	int get_Notification_line() {
		return this->notification_line;
	}

	void set_Notification_line(int& notification_line)
	{
		this->notification_line = notification_line;
	}

	virtual void printNotificationMessage() = 0;

	 virtual ~Notification() {};


};

class Notification_RestaurantManagementSystem : public Notification {
public:
	Notification_RestaurantManagementSystem(string text, string sourse) : Notification(text, sourse) {}

	void printNotificationMessage() {
		Sleep(1500);
		system("CLS");
		cout << endl << endl;
		cout << " ***** Notification Info ***************************************************** " << endl << endl;
		cout << " Text of Notification: \t\t" << get_Notification_text() << endl;
		cout << " Sourse of Notification: \t" << get_Notification_sourse() << endl;
		cout << " Time of Notification: \t\t" << __TIMESTAMP__ << endl << endl;
		cout << " ***************************************************************************** " << endl << endl;
		Sleep(500);
		system("CLS");
	}


};


class Notification_SingUp : public Notification {
public:

	Notification_SingUp(string text, string sourse) : Notification(text, sourse) {}
	
	void printNotificationMessage() {
		Sleep(1500);
		system("CLS");
		cout << endl << endl;
		cout << " ***** Notification Info ***************************************************** " << endl<<endl;
		cout << " Text of Notification: \t\t" << get_Notification_text() << endl;
		cout << " Sourse of Notification: \t" << get_Notification_sourse() << endl;
		cout << " Time of Notification: \t\t" << __TIMESTAMP__ << endl<<endl;
		cout << " ***************************************************************************** " << endl << endl;
		Sleep(500);
		system("CLS");
	}
	
};



class Notification_SingIn : public Notification {
public:
	
	Notification_SingIn(string text, string sourse) : Notification(text, sourse) {}

	void printNotificationMessage() {
		Sleep(1500);
		system("CLS");
		cout << endl << endl;
		cout << " ***** Notification Info ***************************************************** " << endl << endl;
		cout << " Text of Notification: \t\t" << get_Notification_text() << endl;
		cout << " Sourse of Notification: \t" << get_Notification_sourse() << endl;
		cout << " Time of Notification: \t\t" << __TIMESTAMP__ << endl<<endl;
		cout << " ***************************************************************************** " << endl << endl;
		Sleep(1500);
		system("CLS");

	}
};


class Notification_Ingredient : public Notification {
public:

	Notification_Ingredient(string text, string sourse) : Notification(text, sourse) {}

	void printNotificationMessage() {
		Sleep(1500);
		system("CLS");
		cout << endl << endl;
		cout << " ***** Notification Info ***************************************************** " << endl << endl;
		cout << " Text of Notification: \t\t" << get_Notification_text() << endl;
		cout << " Sourse of Notification: \t" << get_Notification_sourse() << endl;
		cout << " Time of Notification: \t\t" << __TIMESTAMP__ << endl << endl;
		cout << " ***************************************************************************** " << endl << endl;
		Sleep(500);
		system("CLS");
	}
};

class Notification_Recipe : public Notification {
public:

	Notification_Recipe(string text, string sourse) : Notification(text, sourse) {}

	void printNotificationMessage() {
		Sleep(1500);
		system("CLS");
		cout << endl << endl;
		cout << " ***** Notification Info ***************************************************** " << endl << endl;
		cout << " Text of Notification: \t\t" << get_Notification_text() << endl;
		cout << " Sourse of Notification: \t" << get_Notification_sourse() << endl;
		cout << " Time of Notification: \t\t" << __TIMESTAMP__ << endl << endl;
		cout << " ***************************************************************************** " << endl << endl;
		Sleep(500);
		system("CLS");
	}
};



class Notification_Table : public Notification {
public:

	Notification_Table(string text, string sourse) : Notification(text, sourse) {}

	void printNotificationMessage() {
		Sleep(1500);
		system("CLS");
		cout << endl << endl;
		cout << " ***** Notification Info ***************************************************** " << endl << endl;
		cout << " Text of Notification: \t\t" << get_Notification_text() << endl;
		cout << " Sourse of Notification: \t" << get_Notification_sourse() << endl;
		cout << " Time of Notification: \t\t" << __TIMESTAMP__ << endl << endl;
		cout << " ***************************************************************************** " << endl << endl;
		Sleep(500);
		system("CLS");
	}
};


class Notification_WarehouseAdd : public Notification {
public:

	Notification_WarehouseAdd(string text, string sourse) : Notification(text, sourse) {}

	void printNotificationMessage() {
		Sleep(1500);
		system("CLS");
		cout << endl << endl;
		cout << " ***** Notification Info ***************************************************** " << endl << endl;
		cout << " Text of Notification: \t\t" << get_Notification_text() << endl;
		cout << " Sourse of Notification: \t" << get_Notification_sourse() << endl;
		cout << " Time of Notification: \t\t" << __TIMESTAMP__ << endl << endl;
		cout << " ***************************************************************************** " << endl << endl;
		Sleep(500);
		system("CLS");

	}
};

class Notification_WarehouseChange : public Notification {
public:

	Notification_WarehouseChange(string text, string sourse) : Notification(text, sourse) {}

	void printNotificationMessage() {
		Sleep(1500);
		system("CLS");
		cout << endl << endl;
		cout << " ***** Notification Info ***************************************************** " << endl << endl;
		cout << " Text of Notification: \t\t" << get_Notification_text() << endl;
		cout << " Sourse of Notification: \t" << get_Notification_sourse() << endl;
		cout << " Time of Notification: \t\t" << __TIMESTAMP__ << endl << endl;
		cout << " ***************************************************************************** " << endl << endl;
		Sleep(500);
		system("CLS");

	}
};

class Notification_WarehouseDelete : public Notification {
public:

	Notification_WarehouseDelete(string text, string sourse) : Notification(text, sourse) {}

	void printNotificationMessage() {
		Sleep(1500);
		system("CLS");
		cout << endl << endl;
		cout << " ***** Notification Info ***************************************************** " << endl << endl;
		cout << " Text of Notification: \t\t" << get_Notification_text() << endl;
		cout << " Sourse of Notification: \t" << get_Notification_sourse() << endl;
		cout << " Time of Notification: \t\t" << __TIMESTAMP__ << endl << endl;
		cout << " ***************************************************************************** " << endl << endl;
		Sleep(500);
		system("CLS");

	}
};


class Notification_WarehouseFind : public Notification {
public:

	Notification_WarehouseFind(string text, string sourse) : Notification(text, sourse) {}

	void printNotificationMessage() {
		Sleep(1500);
		system("CLS");
		cout << endl << endl;
		cout << " ***** Notification Info ***************************************************** " << endl << endl;
		cout << " Text of Notification: \t\t" << get_Notification_text() << endl;
		cout << " Sourse of Notification: \t" << get_Notification_sourse() << endl;
		cout << " Time of Notification: \t\t" << __TIMESTAMP__ << endl << endl;
		cout << " ***************************************************************************** " << endl << endl;
		Sleep(500);
		system("CLS");

	}

};
	class Notification_MealAdd : public Notification {
	public:

		Notification_MealAdd(string text, string sourse) : Notification(text, sourse) {}

		void printNotificationMessage() {
			Sleep(1500);
			system("CLS");
			cout << endl << endl;
			cout << " ***** Notification Info ***************************************************** " << endl << endl;
			cout << " Text of Notification: \t\t" << get_Notification_text() << endl;
			cout << " Sourse of Notification: \t" << get_Notification_sourse() << endl;
			cout << " Time of Notification: \t\t" << __TIMESTAMP__ << endl << endl;
			cout << " ***************************************************************************** " << endl << endl;
			Sleep(500);
			system("CLS");

		}
	};

	class Notification_MealChange : public Notification {
	public:

		Notification_MealChange(string text, string sourse) : Notification(text, sourse) {}

		void printNotificationMessage() {
			Sleep(1500);
			system("CLS");
			cout << endl << endl;
			cout << " ***** Notification Info ***************************************************** " << endl << endl;
			cout << " Text of Notification: \t\t" << get_Notification_text() << endl;
			cout << " Sourse of Notification: \t" << get_Notification_sourse() << endl;
			cout << " Time of Notification: \t\t" << __TIMESTAMP__ << endl << endl;
			cout << " ***************************************************************************** " << endl << endl;
			Sleep(500);
			system("CLS");

		}
	};

	class Notification_MealDelete : public Notification {
	public:

		Notification_MealDelete(string text, string sourse) : Notification(text, sourse) {}

		void printNotificationMessage() {
			Sleep(1500);
			system("CLS");
			cout << endl << endl;
			cout << " ***** Notification Info ***************************************************** " << endl << endl;
			cout << " Text of Notification: \t\t" << get_Notification_text() << endl;
			cout << " Sourse of Notification: \t" << get_Notification_sourse() << endl;
			cout << " Time of Notification: \t\t" << __TIMESTAMP__ << endl << endl;
			cout << " ***************************************************************************** " << endl << endl;
			Sleep(500);
			system("CLS");

		}
	};


	class Notification_MealFind : public Notification {
	public:

		Notification_MealFind(string text, string sourse) : Notification(text, sourse) {}

		void printNotificationMessage() {
			Sleep(1500);
			system("CLS");
			cout << endl << endl;
			cout << " ***** Notification Info ***************************************************** " << endl << endl;
			cout << " Text of Notification: \t\t" << get_Notification_text() << endl;
			cout << " Sourse of Notification: \t" << get_Notification_sourse() << endl;
			cout << " Time of Notification: \t\t" << __TIMESTAMP__ << endl << endl;
			cout << " ***************************************************************************** " << endl << endl;
			Sleep(500);
			system("CLS");

		}
	};

	class Notification_ReceptAdd : public Notification {
	public:

		Notification_ReceptAdd(string text, string sourse) : Notification(text, sourse) {}

		void printNotificationMessage() {
			Sleep(1500);
			system("CLS");
			cout << endl << endl;
			cout << " ***** Notification Info ***************************************************** " << endl << endl;
			cout << " Text of Notification: \t\t" << get_Notification_text() << endl;
			cout << " Sourse of Notification: \t" << get_Notification_sourse() << endl;
			cout << " Time of Notification: \t\t" << __TIMESTAMP__ << endl << endl;
			cout << " ***************************************************************************** " << endl << endl;
			Sleep(500);
			system("CLS");

		}
	};

	class Notification_ReceptChange : public Notification {
	public:

		Notification_ReceptChange(string text, string sourse) : Notification(text, sourse) {}

		void printNotificationMessage() {
			Sleep(1500);
			system("CLS");
			cout << endl << endl;
			cout << " ***** Notification Info ***************************************************** " << endl << endl;
			cout << " Text of Notification: \t\t" << get_Notification_text() << endl;
			cout << " Sourse of Notification: \t" << get_Notification_sourse() << endl;
			cout << " Time of Notification: \t\t" << __TIMESTAMP__ << endl << endl;
			cout << " ***************************************************************************** " << endl << endl;
			Sleep(500);
			system("CLS");

		}
	};

	class Notification_ReceptFind : public Notification {
	public:

		Notification_ReceptFind(string text, string sourse) : Notification(text, sourse) {}

		void printNotificationMessage() {
			Sleep(1500);
			system("CLS");
			cout << endl << endl;
			cout << " ***** Notification Info ***************************************************** " << endl << endl;
			cout << " Text of Notification: \t\t" << get_Notification_text() << endl;
			cout << " Sourse of Notification: \t" << get_Notification_sourse() << endl;
			cout << " Time of Notification: \t\t" << __TIMESTAMP__ << endl << endl;
			cout << " ***************************************************************************** " << endl << endl;
			Sleep(500);
			system("CLS");

		}
	};

	class Notification_ReceptDelete : public Notification {
	public:

		Notification_ReceptDelete(string text, string sourse) : Notification(text, sourse) {}

		void printNotificationMessage() {
			Sleep(1500);
			system("CLS");
			cout << endl << endl;
			cout << " ***** Notification Info ***************************************************** " << endl << endl;
			cout << " Text of Notification: \t\t" << get_Notification_text() << endl;
			cout << " Sourse of Notification: \t" << get_Notification_sourse() << endl;
			cout << " Time of Notification: \t\t" << __TIMESTAMP__ << endl << endl;
			cout << " ***************************************************************************** " << endl << endl;
			Sleep(500);
			system("CLS");

		}
	};
	class Notification_OrderAdd : public Notification {
	public:

		Notification_OrderAdd(string text, string sourse) : Notification(text, sourse) {}

		void printNotificationMessage() {
			Sleep(1500);
			system("CLS");
			cout << endl << endl;
			cout << " ***** Notification Info ***************************************************** " << endl << endl;
			cout << " Text of Notification: \t\t" << get_Notification_text() << endl;
			cout << " Sourse of Notification: \t" << get_Notification_sourse() << endl;
			cout << " Time of Notification: \t\t" << __TIMESTAMP__ << endl << endl;
			cout << " ***************************************************************************** " << endl << endl;
			Sleep(500);
			system("CLS");

		}
	};

	class Notification_OrderFind : public Notification {
	public:

		Notification_OrderFind(string text, string sourse) : Notification(text, sourse) {}

		void printNotificationMessage() {
			Sleep(1500);
			system("CLS");
			cout << endl << endl;
			cout << " ***** Notification Info ***************************************************** " << endl << endl;
			cout << " Text of Notification: \t\t" << get_Notification_text() << endl;
			cout << " Sourse of Notification: \t" << get_Notification_sourse() << endl;
			cout << " Time of Notification: \t\t" << __TIMESTAMP__ << endl << endl;
			cout << " ***************************************************************************** " << endl << endl;
			Sleep(500);
			system("CLS");

		}
	};


	class Notification_OrderDelete : public Notification {
	public:

		Notification_OrderDelete(string text, string sourse) : Notification(text, sourse) {}

		void printNotificationMessage() {
			Sleep(1500);
			system("CLS");
			cout << endl << endl;
			cout << " ***** Notification Info ***************************************************** " << endl << endl;
			cout << " Text of Notification: \t\t" << get_Notification_text() << endl;
			cout << " Sourse of Notification: \t" << get_Notification_sourse() << endl;
			cout << " Time of Notification: \t\t" << __TIMESTAMP__ << endl << endl;
			cout << " ***************************************************************************** " << endl << endl;
			Sleep(500);
			system("CLS");

		}
	};


	class Notification_SearchRecipeMeal : public Notification {
	public:

		Notification_SearchRecipeMeal(string text, string sourse) : Notification(text, sourse) {}

		void printNotificationMessage() {
			Sleep(1500);
			system("CLS");
			cout << endl << endl;
			cout << " ***** Notification Info ***************************************************** " << endl << endl;
			cout << " Text of Notification: \t\t" << get_Notification_text() << endl;
			cout << " Sourse of Notification: \t" << get_Notification_sourse() << endl;
			cout << " Time of Notification: \t\t" << __TIMESTAMP__ << endl << endl;
			cout << " ***************************************************************************** " << endl << endl;
			Sleep(500);
			system("CLS");

		}
	};