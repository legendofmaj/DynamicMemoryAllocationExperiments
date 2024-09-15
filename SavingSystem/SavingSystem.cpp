#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

//Global Variables
int* numbers; //Pointer to a numbers array.
string* strings; //Pointer to a string array.

class SaveSystem 
{
	public:
		string filename = "save.txt";
		string line;
		bool fileExists = false;
		int fileLength = 0;
};

SaveSystem generalInfo;

void checkForSave() 
{
	ifstream saveFile(generalInfo.filename);
	generalInfo.fileExists = saveFile.is_open();
	saveFile.close();
}

void writeFile() 
{
	string line;

	cout << "No save data exists yet." << endl;
	cout << "First enter the type of string you whish to use, then the names of each string" << endl;
	cout << "If you have entered all your strings, type esc to stop!" << endl;

	ofstream saveFile(generalInfo.filename);
	while(true)
	{
		cin >> line;
		if (line == "esc") 
		{
			break;
		}
		saveFile << line << endl;
	}
	saveFile.close();
}

void getFileLength()
{
	string line;

	ifstream saveFile(generalInfo.filename);
	while(getline(saveFile, line)) //As soon as no new lines can be read the function is quit
	{
		generalInfo.fileLength++;
	}
	saveFile.close();
}

void readFile(int numStrings)
{
	string line;
	int i = 0;

	//Allocate memory
	strings = new string[numStrings];

	ifstream saveFile(generalInfo.filename);
	while(getline(saveFile, line))
	{
		strings[i] = line;
		i++;
	}
	saveFile.close();
}

void writeToConsole()
{
	cout << "Content of the file:" << endl;
	for (int i=0; i < generalInfo.fileLength; i++)
	{
		cout << strings[i] << endl;
	}
}

int main () 
{
	checkForSave();
	cout << generalInfo.fileExists << endl; //debug only
	if (generalInfo.fileExists==false) 
	{
		writeFile();
	}
	else if (generalInfo.fileExists==true) 
	{
		getFileLength();
		cout << generalInfo.fileLength << endl; //debug only
		readFile(generalInfo.fileLength);
		writeToConsole(); //For demonstration purposes only
	}
	//deallocate memory
	delete[] strings;
	return 0;
}
