#include "Route.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std; 

void printMenu();
void addObject(Marray<Route>& routes);
void changeObject(Marray<Route>& routes);
void deleteObject(Marray<Route>& routes);
void print(Marray<Route>& routes);
void searchObjects(Marray<Route>& routes);


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Marray<Route> routes;

	bool isExit = false;
	while (!isExit) {
		printMenu();
		int method = safeInput(0, 5);
		switch (method)
		{
		case 1:
			addObject(routes);
			break;
		case 2:
			changeObject(routes);
			break;
		case 3:
			deleteObject(routes);
			break;
		case 4:
			print(routes);
			break;
		case 5:
			searchObjects(routes);
			break;
		case 0:

			isExit = true;
			break;
		}
	}

}

void printMenu() {
	cout << "1. �������� ������" << endl;
	cout << "2. �������� ������" << endl;
	cout << "3. ������� ������" << endl;
	cout << "4. ������� ������" << endl;
	cout << "5. ������� ��������, ������� ���������� ��� ��������� � ������, �������� �������� ������� � ����������" << endl;
	cout << "0. �����" << endl;
	cout << "�������� ����� ����: ";
}

void addObject(Marray<Route>& routes) {
	Route route;
	route.inputFromConsole();
	routes += route;
	routes.sort();
}

void changeObject(Marray<Route>& routes) {
	if (routes.getSize() > 0) {
		print(routes);
		cout << "������� ����� �������� ��� ���������: ";
		routes[safeInput(1, routes.getSize()) - 1].change();
	}
	else
		cout << "������ ��������� ����. ������ ��������\n";
	routes.sort();
}

void deleteObject(Marray<Route>& routes) {
	if (routes.getSize() > 0) {
		print(routes);
		cout << "������� ������ �������� ��� ��������: ";
		routes -= safeInput(1, routes.getSize()) - 1;
	}
	else
		cout << "������ ��������� ����. ������ �������\n";
	routes.sort();
}

void print(Marray<Route>& routes) {
	if (routes.getSize() == 0)
		cout << "������ ��������� ����.\n";
	else {
		cout << "������ ���������\n";
		for (int i = 0; i < routes.getSize(); i++) {
			cout << i + 1 << ". �������\n";
			routes[i].printToConsole();
		}
	}
}

void searchObjects(Marray<Route>& routes) {
	if (routes.getSize() == 0)
		cout << "������ ��������� ����\n";
	else {
		bool isPrint = false;
		cout << "������� �������� ������: ";
		string punkt;
		getline(cin, punkt);
		for (int i = 0; i < routes.getSize(); i++) {
			if (routes[i].getEndPoint() == punkt || routes[i].getStartPoint() == punkt) {
				isPrint = true;
				routes[i].printToConsole();
			}
		}
			
		if (!isPrint)
			cout << "����� ��������� ���\n";
	}
}