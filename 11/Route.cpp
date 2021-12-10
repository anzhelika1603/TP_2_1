#include "Route.h"

Route::Route() : startPoint("Не задано"), endPoint("Не задано"), number(0)
{
	cout << "Вызван конструктор Route" << endl;
}

Route::Route(string startPoint, string endPoint, int number) :
	startPoint(startPoint), endPoint(endPoint), number(number)
{
	cout << "Вызван конструктор Route" << endl;
}

Route::Route(const Route& route) : startPoint(route.startPoint), endPoint(route.endPoint), number(route.number)
{
	cout << "Вызван конструктор копирования Route" << endl;
}

Route::~Route()
{
	cout << "Вызван деструктор Route" << endl;
}

void Route::inputFromConsole()
{
	cout << "Введите начальный пункт маршрута: ";
	getline(cin, startPoint);
	cout << "Введите конечный пункт маршрута: ";
	getline(cin, endPoint);
	cout << "Введите номер маршрута: ";
	number = safeInput(1, INT32_MAX);
}

void Route::printToConsole()
{
	cout << "Начальный пункт маршрута: " << startPoint << endl;
	cout << "Конечный пункт маршрута: " << endPoint << endl;
	cout << "Номер маршрута: " << number << endl;
}

void Route::change()
{
	cout << "Введите новый начальный пункт маршрута: ";
	getline(cin, startPoint);
	cout << "Введите новый конечный пункт маршрута: ";
	getline(cin, endPoint);
	cout << "Введите новый номер маршрута: ";
	number = safeInput(1, INT32_MAX);
}

Route& Route::operator=(const Route& worker) {
	if (this == &worker)
		return *this;
	startPoint = worker.startPoint;
	endPoint = worker.endPoint;
	number = worker.number;
	return *this;
}

bool Route::operator>(Route& route) {
	return number > route.number;
}