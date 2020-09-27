#include "ShiftCipher.h"

std::string ShiftCipher::encrypt(std::string text, int shift)
{
	int i = 0;
	text = remove_spaces_all_caps(text);
	while (text[i])
	{
		int value = (int)text[i] + shift;
		
		if ((value - 64) > 26)
			value = ((value - 64) % 26) + 64;
		
		text[i] = (char)value;
		i++;
	}

	return text;
}

std::string remove_spaces_all_caps(std::string text)
{
	int i = 0, j = 0;
	while (text[i])
	{
		if (text[i] != ' ')
			text[j++] = toupper(text[i]);
		i++;
	}
	text[j] = '\0';
	text = text.substr(0, j);
	return text;
}