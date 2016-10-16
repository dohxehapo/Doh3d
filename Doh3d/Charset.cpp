#include "Doh3d.h"
#include "InputMan.h"


namespace Doh3d
{

	char g_chars[CHARSCOUNT * 2] =
	{
		' ', ' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
		'-', '=', ' ', '	',
		'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', ' ', ' ',
		'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', '`',
		' ', '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/',
		' ', '*', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', // F1 - F10
		' ', ' ',
		'7', '8', '9', '-', '4', '5', '6', '+', '1', '2', '3', '0', '.', '\\',
		' ', ' ', ' ', ' ', ' ', // F11 - F15
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ',
		'/',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
		'_', '+', ' ', '	',
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', ' ', ' ',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '\"', '~',
		' ', '|', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?',
		' ', '*', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', // F1 - F10
		' ', ' ',
		'7', '8', '9', '-', '4', '5', '6', '+', '1', '2', '3', '0', '.', '\\',
		' ', ' ', ' ', ' ', ' ', // F11 - F15
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ',
		'/',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ',
		' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '
	};

	bool g_prints[KBUTTONS_MAX] =
	{
		false, false, true, true, true, true, true, true, true, true, true, true,
		true, true, false, true,
		true, true, true, true, true, true, true, true, true, true, true, true, false, false,
		true, true, true, true, true, true, true, true, true, true, true, true,
		false, true, true, true, true, true, true, true, true, true, true, true,
		false, true, false, true, false,
		false, false, false, false, false, false, false, false, false, false, // F1 - F10
		false, false,
		true, true, true, true, true, true, true, true, true, true, true, true, true, true,
		false, false, false, false, false, // F11 - F15
		false, false, false, false, false, false, false, false, false, false,
		false, false, false, false, false, false, false, false, false, false,
		false, false, false, false, false, false,
		true,
		false, false, false, false, false, false, false, false, false, false, false, false, false, false,
		false, false, false, false, false, false, false, false, false, false, false, false, false, false,
		false, false, false, false, false, false, false, false, false, false, false, false, false, false,
		false, false, false, false, false, false, false, false, false, false, false, false, false, false,
		false, false, false, false, false, false, false, false, false, false, false, false, false, false,
		false, false, false, false, false, false, false, false, false, false, false, false, false, false,
		false, false, false, false, false, false, false, false, false, false, false, false, false, false,
		false, false, false, false, false, false, false, false, false, false, false, false, false, false,
		false, false, false, false, false, false, false, false, false, false, false, false, false, false,
		false, false, false, false, false, false, false, false, false, false, false, false, false
	};


	char InputMan::DikToChar(int pDik, bool pShift)
	{
		if (pShift)
			pDik += CHARSCOUNT;

		return g_chars[pDik];
	}

	char InputMan::DikToChar(int pDik)
	{
		return DikToChar(pDik, IsShift());
	}

	bool InputMan::IsPrintable(int pDik)
	{
		return g_prints[pDik];
	}

} // ns Doh3d