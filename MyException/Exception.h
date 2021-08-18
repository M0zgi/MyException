#pragma once

#include<iostream>
#include<fstream>
#include<exception>
#include<Windows.h>
#include<string>
//#include<stdio.h>

using namespace std;

class MyException: public exception
{
public:
	MyException(const char* mesg, int errorCode) : exception(mesg), errorCode(errorCode){};

	int GetErrorCode() { return errorCode; }

private:
	int errorCode;
};