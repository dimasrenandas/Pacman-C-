#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <string>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <thread>
#include <chrono>
#include<fstream>

using namespace std;

char tmp_map[18][33];//UNTUK MENYIMPAN DATA MAP SEMENTARA

char map[18][33] =
{
 "+############ map1 ############+",
 "|                              |",
 "|                              |",
 "|#########  #######   #########|",
 "|   |                          |",
 "| | |### |  |            |     |",
 "| |      |  | |## #  |   |  |  |",
 "| | #####|  | |       ## |     |",
 "| |           |# ##  |      |  |",
 "| |##### ## #         ##       |",
 "|          ##### #  ####### ###|",
 "|                              |",
 "|# ### ####    #  ###   #######|",
 "|                              |",
 "|                              |",
 "|                              |",
 "|                              |",
 "+##############################+"
};//GAMBAR MAP1

char map2[18][33] =
{
 "+########### map2 #############+",
 "|                              |",
 "|                              |",
 "|#   #####  #######   ###    ##|",
 "|   |                          |",
 "| | |### |    |          |     |",
 "| |      |  | |## #  |   |  |  |",
 "| | #####|  | |       ## |     |",
 "| |           |# ##  |      |  |",
 "| |## ## ## #         ##       |",
 "|      ###    ## #  ##  ### ###|",
 "|                              |",
 "|# ### ## #   ##  ### #  ######|",
 "|                              |",
 "|                              |",
 "|                              |",
 "|                              |",
 "+##############################+"
};//GAMBAR MAP2

char map3[18][33] =
{
 "+########## map3 ##############+",
 "|                              |",
 "|                              |",
 "|#   #####  #######   ###    ##|",
 "|   |    ####  ##### #####     |",
 "| | |### |    |          |     |",
 "| |      |  | |## #  |   |  |  |",
 "| | #####|  | |       ## |     |",
 "| |           |# ##  |      |  |",
 "| |## ## ## # ####### ##       |",
 "|      ###    ## #  ##  ### ###|",
 "| #####       #       #####    |",
 "|# ### ## ### ##  ### #  ######|",
 "|                              |",
 "|                              |",
 "|                              |",
 "|                              |",
 "+##############################+"
};//GAMBAR MAP3



class CPotition
{
protected:
int _x, _y;
string nama;
public:

	//gotoxy potition
	CPotition(int x = 0, int y = 0)
	{
		_x = x;
		_y = y;
	}
	void set_coord(int x, int y)
	{
		_x = x;
		_y = y;
	}

	int get_x() {

		return _x;
	}
	int get_y() {

		return _y;
	}
	//FUNGSI SET NAMA PLAYER
	void set_nama(string n)
	{
		nama = n;
	}
	//FUNGSI GET NAMA PLAYER
	string get_nama()
	{
		return nama;
	}

	void dot_coord(int x, int y)//FUNGSI GOTOXY DI DALAM CLASS CPOTITION
	{

		COORD coordinates;

		coordinates.X = x;

		coordinates.Y = y;

		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
	}

	void ShowMap()//FUNGSI PRINT MAP PACMAN
	{
		srand(time(NULL));
		for (int i = 0; i < 18; i++)
		{
			int a = rand() % 3;//RANDOM ANGKA SESUAI JUMLAH MAP
			if (a == 0)
			{
				cout << map[i] << endl;
			}
			else if (a == 1)
			{
				cout << map2[i] << endl;
				memcpy(map, map2, sizeof(map2));//MENGGANTI MAP MENJADI MAP2

			}
			else if (a == 2)
			{
				cout << map3[i] << endl;
				memcpy(map, map3, sizeof(map3));//MENGGANTI MAP MENJADI MAP3
			}

		}
	}

	//void slowPrint efek animasi;

	void slowPrint(const string& message, unsigned int millis_per_char)
	{
		for (const char c : message)
		{
			if  (GetAsyncKeyState(VK_SPACE) ) {
			    string message = "\n\n\n\t\t\tHello Player's welcome to our game ";
				string credits = "\n\t\t\t       This Game is Created By\n\t\t\tSIAUW VICARANO \t\t-  C14190222\n\t\t\tSIAUW SUCITRA \t\t-  C14190223\n\t\t\tDIMAS RENANDA\t\t-  C14190232\n\t\t\tGERVASIUS WISELY \t-  C14180118\n\n";
				system("color 02");
				system("cls");
				cout << message << credits;
				break;

			}
			else
			{
				system("color 02");
				cout << c << flush;
				Sleep(millis_per_char);
			}
				
			
		}
	}

	//polymorph untuk savetofile untuk save nama
	virtual void ReadFromFileStream(fstream& f)
	{
		getline(f, nama);
		f >> nama;
	}

	virtual void WriteToFileStream(fstream& f)
	{
		f << nama << ": ";
	}

	void intro()
	{
		SetConsoleTitle("OUR PACMAN PROJECT");
		system("color 09");
		cout << "==============\n";
		cout << "Player's Name ";
		cout << "\n==============\n";
		getline(cin, nama);
		nama.append("\n\n");
		system("cls");
		system("color 02");
		string message = "\n\n\n\t\t\tHello Player's welcome to our game ";
		string credits = "\t\t\t       This Game is Created By\n\t\t\tSIAUW VICARANO \t\t-  C14190222\n\t\t\tSIAUW SUCITRA \t\t-  C14190223\n\t\t\tDIMAS RENANDA\t\t-  C14190232\n\t\t\tGERVASIUS WISELY \t-  C14180118\n\n";
		slowPrint(message, 20);
		slowPrint(nama, 20);
		slowPrint(credits, 30);
		system("pause");
		system("cls");
	}

};

//composition lebih dari satu class

class CPackman :public CPotition //inheritance
{
protected:
	int x;
	int y;
public:
	CPackman()
	{
		x = 0;
		y = 0;
	}
	CPackman(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
	}

	void move_x(int p)//gerakkan x sesuai jumlah param

	{
		if (map[y][x + p] == ' ')
		{
			x += p;
		}
	
	}

	void move_y(int p)//gerakkan y sesuai jumlah param
	{
		if (map[y + p][x] == ' ')
		{

			y += p;

		}
	}

	void move(int p, int q) { // menggerakan x dan y sesuai jumlah param
		x += p;
		y += q;
	}

	int get_x()
	{
		return x;
	}
	int get_y()
	{
		return y;
	}

	void draw(char p) { //draw makanan dari musuh
		map[x][y] = p;
		CPotition::dot_coord(x, y);
		cout << p;
	}


};

struct walk //data walk player
{
	int walk_count;
	int x;
	int y;
	int back;
};

struct target //data player sehingga diikuti musuh
{
	int x;
	int y;
};

vector<target> Moving;//membuat vector walk agar target diikuti musuh sesuai xynya 

vector<walk> Direction;//membuat vector Direction sesuai xy walk count player

void AddArray(int x, int y, int wc, int back)//function untuk menambahkan data array sesuai koodinat data pada struct walk
{
	if (tmp_map[y][x] == ' ' || tmp_map[y][x] == '.') //jalan yang bisa dilalui atau ditabrak
	{
		tmp_map[y][x] = '#';//untuk tidak memakan batas #
		walk tmp;//semua data disimpan di walk tmp
		tmp.x = x;
		tmp.y = y;
		tmp.walk_count = wc;
		tmp.back = back;
		Direction.push_back(tmp);//menambahkan data kedalam belakang array
	}
}

void UpdateMap(int sx, int sy, int x, int y) {//untuk mengcopy atau update map ke tempmap
	
	memcpy(tmp_map, map, sizeof(map));
	Direction.clear();//mengkosongkan isi vector atau array walk queue
	walk tmp;//membuat tmp walk
	tmp.x = sx;
	tmp.y = sy;
	tmp.walk_count = 0;
	tmp.back = -1;
	Direction.push_back(tmp);//diisi pada data direction

	int i = 0;
	while (i <Direction.size()) //
	{
		if (Direction[i].x == x && Direction[i].y == y) 
		{
			Moving.clear();//mengkosongkan isi vector atau array walk queue

			target tmp2;//temp untuk musuh

			while (Direction[i].walk_count != 0) //

			{ 
				tmp2.x =Direction[i].x;
				tmp2.y =Direction[i].y;
				Moving.push_back(tmp2);
				i = Direction[i].back;
			}

			break;
		}
		AddArray(Direction[i].x + 1,Direction[i].y,Direction[i].walk_count + 1, i);//ke kanan
		AddArray(Direction[i].x - 1,Direction[i].y,Direction[i].walk_count + 1, i);//kekiri
		AddArray(Direction[i].x,Direction[i].y + 1,Direction[i].walk_count + 1, i);//keatas
		AddArray(Direction[i].x,Direction[i].y - 1,Direction[i].walk_count + 1, i);//kebawah
		i++;// increment i
	}

	Direction.clear();//reset direction
}

class CGameRun :public CPackman //inheritance
{
protected:
	int Gx, Gy;
	int score;
public:

	CGameRun(int x = 0, int y = 0, int z = 0, int a = 0) :CPackman(z, a)
	{
		Gx = x;
		Gy = y;
	}

	int get_gx()
	{
		return Gx;
	}
	int get_gy()
	{
		return Gy;
	}
	int get_score()
	{
		return score;
	}

	void Run()
	{
		CPotition::intro();
		bool over = false;
		//koordinat pacman
		int x = 15;
		int y = 16;
		//temporary x y
		int tmp_x;
		int tmp_y;
		///Enemy
		int ex = 1;
		int ey = 1;
		////////////
		//Score//////
		score = 0;
		/////////////
		menu:
		cout << "LastPlayed : " << endl;
		CGameRun::ReadFromFileStream();
		system("color 61");
		cout << "\n\t\t\t===========================================\n";
		cout << "\t\t\t\t    PACMAN GAME PROJECT";
		cout << "\n\t\t\t===========================================\n";
		cout << "===================\n";
		cout << "Difficulty\n";
		cout << "===================\n";
		cout << "0.EXIT GAME\n1.EASY\n2.NORMAL\n3.HARD\n4.INSANE\n5.RESET LAST PLAYED\n===================\nChoice : ";
		int level;
		int speed = 3;

		cin >> level;
		if (level == 0)
		{
			exit(0);
		}
		if (level == 2)
		{
			speed = 2;
		}
		else if (level == 3)
		{
			speed = 1;
		}
		else if (level == 4)
		{
			speed = -1;
		}
		else if (level == 5)
		{
			resetLast();
			goto menu;
		}
		system("color 4B");
		system("cls");
		play:
		CPotition::ShowMap();//showmap dari cpotition
		CPotition::dot_coord(x, y);// goto xy cpotition

		int frame = 0;

		UpdateMap(ex, ey, x, y);

		while (!over) {

			CPotition::dot_coord(x, y); cout << " ";//gotoxy koordinat dengan cout spasi

			tmp_x = x;

			tmp_y = y;

			if (GetAsyncKeyState(VK_UP))
			{
				if (map[y - 1][x] == '.') { y--; score++; }
				else
					if (map[y - 1][x] == ' ') y--;
			}
			if (GetAsyncKeyState(VK_DOWN)) 
			{
				if (map[y + 1][x] == '.') { y++; score++; }
				else
					if (map[y + 1][x] == ' ') y++;
			}
			if (GetAsyncKeyState(VK_LEFT)) {
				if (map[y][x - 1] == '.') { x--; score++; }
				else
					if (map[y][x - 1] == ' ') x--;
			}
			if (GetAsyncKeyState(VK_RIGHT)) {
				if (map[y][x + 1] == '.') { x++; score++; }
				else
					if (map[y][x + 1] == ' ') x++;
			}
			if (GetAsyncKeyState(VK_ESCAPE)) {
				CPotition::dot_coord(x, y);
				system("cls");
				cout << "The Game is Closing ";cout <<nama <<" last score is : " << score << endl;
				system("pause");
				exit(0);
			}
			if (GetAsyncKeyState(VK_TAB)) {

				system("cls");
				cout << "The Game is Paused ";cout << nama <<" current score is : " << score << endl;
				system("pause");
				system("cls");
				goto play;
				

			}

			if (tmp_x != x || tmp_y != y) {
				UpdateMap(ex, ey, x, y);
			}
			//Body Pacman
			CPotition::dot_coord(x, y); cout << "C";

			map[ey][ex] = '.';//makanan dari enemy
			CPotition::dot_coord(ex, ey); cout << ".";//makanan dari enemy
			//pergerakan musuh di dalam map sesuai player
			if (frame % speed == 0 && Moving.size() != 0) 
			{
				ex = Moving.back().x;
				ey = Moving.back().y;
				Moving.pop_back();
			}
			//Body Enemy
			CPotition::dot_coord(ex, ey); cout << "E";
			//kalau enemy ketemu x dan y pacman
			if (ex == x && ey == y) {
				break;
			}

			//Tampilan score
			CPotition::dot_coord(33, 18);
			CPotition::dot_coord(33, 1); cout << "Score :" << score;
			Sleep(100);
			frame++;
		}

		system("cls");

		string filename = "SaveGame";
		cout << "File Saved As "<<filename<<endl;
		SaveToFile(filename);
		cout << "Kamu Kalah Score Terakhir "; cout << nama << "Adalah : " << score << endl;
		system("pause");
		cout << "\nPlay Again?\n";
		char cek;
		cin >> cek;
		if (cek == 'y' || cek == 'Y')
		{
			CGameRun restart;
			cin.ignore();
			restart.Run();
			
		}

		else if (cek == 'n' || cek == 'N')
		{
			
			system("pause");
			exit(0);
		}
		


	}

	void ReadFromFileStream()
	{
		// Create a text string, which is used to output the text file
		string myText;

		// Read from the text file
		ifstream MyReadFile("SaveGame");

		//Mengambil perline
		while (getline(MyReadFile, myText)) {
			// Output the text from the file
			cout << myText<<" ";
		}

		// Close the file
		MyReadFile.close();
	}

	void WriteToFileStream(fstream& f)
	{
		CPotition::WriteToFileStream(f);
		f << score << endl;
	}

	void SaveToFile(string filename)
	{
		fstream f(filename,  ios::app);
		if (f.is_open())
		{
			CGameRun::WriteToFileStream(f);
			/*f << score << endl;
			CPotition::WriteToFileStream(f);*/
			f.close();
		}
	}

	void resetLast()
	{
		char filename[] = "SaveGame";
	
	/*	Deletes the file if exists */
	if (remove(filename) != 0)
		perror("Last Played deletion failed");
	else
		cout << "Last Played Cleared";
	system("pause");
	system("cls");
	}


};


int main()
{
	CGameRun Play;
	Play.Run();
	return 0;
}
