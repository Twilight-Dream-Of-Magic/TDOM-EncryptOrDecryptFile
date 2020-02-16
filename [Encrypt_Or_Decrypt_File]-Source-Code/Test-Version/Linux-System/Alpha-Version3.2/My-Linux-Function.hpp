#pragma once

void ConsoleTableColorUnset()
{
	system("echo -e '\033[0m'"); //Linux Console Reset Color
}

void ConsoleTableColorSet(int Use_ThisRed, int Use_ThisGreen, int Use_ThisBlue)
{
	if (Use_ThisRed < 0) Use_ThisRed = 0; //Set red color use status is false
	if (Use_ThisRed > 1) Use_ThisRed = 1; //Set red color use status is true

	if (Use_ThisGreen < 0) Use_ThisGreen = 0; //Set green color use status is false
	if (Use_ThisGreen > 1) Use_ThisGreen = 1; //Set green color use status is true

	if (Use_ThisBlue < 0) Use_ThisBlue = 0; //Set green color use status is false
	if (Use_ThisBlue > 1) Use_ThisBlue = 1; //Set green color use status is true

	/*Linux Shell Bold Color*/

	if (Use_ThisRed == 1 && Use_ThisGreen == 1 && Use_ThisBlue == 1)
	{
		system("echo -e '\033[1;37m'"); //Linux Shell Set Color: White || Hexadecimal Color Value: #FFFFFF
	}
	else if (Use_ThisRed == 1 && Use_ThisGreen == 1 && Use_ThisBlue == 0)
	{
		system("echo -e '\033[1;33m'"); //Linux Shell Color: Yellow || Hexadecimal Color Value: #FFFF00
	}
	else if (Use_ThisRed == 1 && Use_ThisGreen == 0 && Use_ThisBlue == 1)
	{
		system("echo -e '\033[1;35m'"); //Linux Shell Color: Purple || Hexadecimal Color Value: #FF00FF
	}
	else if (Use_ThisRed == 0 && Use_ThisGreen == 1 && Use_ThisBlue == 1)
	{
		system("echo -e '\033[1;36m'"); //Linux Shell Color: Cyan || Hexadecimal Color Value: #00FFFF
	}
	else if (Use_ThisRed == 1 && Use_ThisGreen == 0 && Use_ThisBlue == 0)
	{
		system("echo -e '\033[1;31m'"); //Linux Shell Color: Red || Hexadecimal Color Value: #FF0000
	}
	else if (Use_ThisRed == 0 && Use_ThisGreen == 1 && Use_ThisBlue == 0)
	{
		system("echo -e '\033[1;32m'"); //Linux Shell Color: Green || Hexadecimal Color Value: #00FF00
	}
	else if (Use_ThisRed == 0 && Use_ThisGreen == 0 && Use_ThisBlue == 1)
	{
		system("echo -e '\033[1;34m'"); //Linux Shell Color: Blue || Hexadecimal Color Value: #0000FF
	}
	else if (Use_ThisRed == 0 && Use_ThisGreen == 0 && Use_ThisBlue == 0)
	{
		system("echo -e '\033[30m'");
	}
	else
	{
		ConsoleTableColorUnset();
	}
}
