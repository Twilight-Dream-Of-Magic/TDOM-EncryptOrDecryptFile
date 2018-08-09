void ConsoleTableColorSet(int R, int G, int B)
{
	if (R < 0) R = 0;
	if (R > 1) R = 1;

	if (G < 0) G = 0;
	if (G > 1) G = 1;

	if (B < 0) B = 0;
	if (B > 1) B = 1;

	if (R == 1 && G == 1 && B == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
	else if (R == 1 && G == 1 && B == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
	}
	else if (R == 1 && G == 0 && B == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE);
	}
	else if (R == 0 && G == 1 && B == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
	else if (R == 1 && G == 0 && B == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_RED);
	}
	else if (R == 0 && G == 1 && B == 0)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN);
	}
	else if (R == 0 && G == 0 && B == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_BLUE);
	}
	else
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY);
	}
}
