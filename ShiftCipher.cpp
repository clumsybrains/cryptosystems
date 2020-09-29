#include "ShiftCipher.h"

std::string ShiftCipher::encrypt(std::string text, int shift)
{
	int i = 0;
	text = remove_spaces(text);
	text = all_caps(text);
	while (text[i])
	{
		int value = (int)text[i] + (shift % 26);
		
		if ((value - 64) > 26)
			value = ((value - 64) % 26) + 64;
		
		text[i] = (char)value;
		i++;
	}

	return text;
}

std::string CaesarCipher::encrypt(std::string text)
{
	int i = 0;
	text = remove_spaces(text);
	text = all_caps(text);
	while (text[i])
	{
		int value = (int)text[i] + 3;

		if ((value - 64) > 26)
			value = ((value - 64) % 26) + 64;

		text[i] = (char)value;
		i++;
	}

	return text;
}

std::string ROT13::operator ()(std::string text)
{
	int i = 0;
	text = remove_spaces(text);
	text = all_caps(text);
	while (text[i])
	{
		int value = (int)text[i] + 13;

		if ((value - 64) > 26)
			value = ((value - 64) % 26) + 64;

		text[i] = (char)value;
		i++;
	}

	return text;
}

std::string ROT47::operator ()(std::string text)
{
	int i = 0;
	text = remove_spaces(text);
	while (text[i])
	{
		int value = (int)text[i] + 47;

		if ((value - 32) > 94)
			value = ((value - 32) % 94) + 32;
		text[i] = (char)value;
		i++;
	}

	return text;
}


std::string remove_spaces(std::string text)
{
	int i = 0, j = 0;
	while (text[i])
	{
		if (text[i] != ' ')
			text[j++] = text[i];
		i++;
	}
	text[j] = '\0';
	text = text.substr(0, j);
	return text;
}

std::string all_caps(std::string text)
{
	int i = 0;

	while (text[i])
	{
		if (text[i] != ' ')
			text[i] = toupper(text[i]);
		i++;
	}

	return text;
}