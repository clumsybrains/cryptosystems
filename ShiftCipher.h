#pragma once
#include<iostream>
#include<string>

class ShiftCipher
{
public:
	std::string encrypt(std::string, int);
};

class CaesarCipher
{
public:
	std::string encrypt(std::string);
};

class ROT13
{
public:
	std::string operator ()(std::string);
};

class ROT47
{
public:
	std::string operator ()(std::string);
};

std::string remove_spaces(std::string text);
std::string all_caps(std::string text);