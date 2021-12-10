#include "Route.h"

Route::Route() : startPoint("�� ������"), endPoint("�� ������"), number(0)
{
	cout << "������ ����������� Route" << endl;
}

Route::Route(string startPoint, string endPoint, int number) :
	startPoint(startPoint), endPoint(endPoint), number(number)
{
	cout << "������ ����������� Route" << endl;
}

Route::Route(const Route& route) : startPoint(route.startPoint), endPoint(route.endPoint), number(route.number)
{
	cout << "������ ����������� ����������� Route" << endl;
}

Route::~Route()
{
	cout << "������ ���������� Route" << endl;
}

void Route::inputFromConsole()
{
	cout << "������� ��������� ����� ��������: ";
	getline(cin, startPoint);
	cout << "������� �������� ����� ��������: ";
	getline(cin, endPoint);
	cout << "������� ����� ��������: ";
	number = safeInput(1, INT32_MAX);
}

void Route::printToConsole()
{
	cout << "��������� ����� ��������: " << startPoint << endl;
	cout << "�������� ����� ��������: " << endPoint << endl;
	cout << "����� ��������: " << number << endl;
}

void Route::change()
{
	cout << "������� ����� ��������� ����� ��������: ";
	getline(cin, startPoint);
	cout << "������� ����� �������� ����� ��������: ";
	getline(cin, endPoint);
	cout << "������� ����� ����� ��������: ";
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