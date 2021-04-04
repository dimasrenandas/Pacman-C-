//#include <iostream>
//#include<fstream>
//#include<windows.h>
//#include<string>
//#include<time.h>
//#include<conio.h>
//#include<stdlib.h>
//#include<sstream>
//#include<math.h>
//using namespace std;
//
//int bar, kol, mapF[1000][1000], bm, FL, stage, score = 0, key, eat[100], ctr_level = 1;
//char map[1000][1000], n, level[1000];
//string enemy[1000], power[1000], Load_name;
//
//struct Pos {
//	int x, y;
//};
//struct str {
//	string x, y;
//};
//struct High {
//	string nama, skor;
//};
//struct S {
//	float w, a, s, d;
//};
//
//void new_game(char map[1000][1000], int& L) {
//	string line[1000], data[1000];
//	int ctr = 0, b = 0;
//	//semua isi file kumasukin dalam array
//	ifstream file("map.txt");
//	while (!file.eof()) {
//		getline(file, line[ctr]);
//		ctr++;
//	}
//	file.close();
//
//	//banyak map pool
//	bm = 0;
//	for (int a = 0; a < ctr; a++) {
//		if (line[a] == "-") {
//			bm++;
//		}
//	}for (int a = 0; a < bm; a++) {
//		level[a] = '1';
//	}
//
//	//pemilihan level
//	int x = rand() % bm + 1;
//	stage = x;
//	level[x - 1] = '0';
//
//	stringstream lv;
//	lv << x;
//	string lvl = lv.str(), tmap[1000];
//	bar = kol = 0;
//	for (int a = 0; a < ctr; a++) {
//		if (line[a] == lvl) {
//			a++;
//			kol = line[a].size();
//			while (line[a] != "-") {
//				tmap[bar] = line[a];
//				bar++; a++;
//			}
//			a = ctr;
//		}
//	}
//	//string jadi char mapnya
//	for (int a = 0; a < bar; a++) {
//		for (int b = 0; b < kol; b++) {
//			map[a][b] = tmap[a][b];
//		}
//	}
//	//info hantu dan power up
//	ctr = 0;
//	file.open("info.txt");
//	while (!file.eof()) {
//		getline(file, data[ctr]);
//		ctr++;
//	}
//	file.close();
//	for (int a = 0; a < ctr; a++) {
//		if (data[a] != "-") {
//			enemy[b] = data[a];
//			a++;
//			power[b] = data[a];
//			b++; a++;
//		}
//	}
//	score = 0; L = 3; n = 'z';
//}
//void Load(char map[1000][1000], Pos& p, int& L, int& load, Pos h[], int& pw) {
//	system("cls");
//	string name, data[1000], line[1000], dataL;
//	int ctr = 0, pil, c = 1, b = 0;
//	//import data nama
//	ifstream file("dataS.txt");
//	while (!file.eof()) {
//		getline(file, data[ctr]);
//		ctr++;
//	}
//	file.close();
//	//pembuatan list
//	for (int a = 0; a < ctr; a++) {
//		if (data[a].size() > 0) {
//			cout << c << ". " << data[a] << '\n';
//			c++;
//		}
//	}
//	cout << '\n';
//	cout << "Pilihan : "; cin >> pil;
//	pil--;
//	name = data[pil];
//	Load_name = name;
//	//data save
//	ctr = 0;
//	file.open("save.txt");
//	while (!file.eof()) {
//		getline(file, line[ctr]);
//		ctr++;
//	}
//	file.close();
//	//pemasukan ke array
//	string tmap[1000];
//	bar = kol = bm = 0;
//	for (int a = 0; a < ctr; a++) {
//		if (line[a] == name) {
//			a++;
//			stringstream(line[a]) >> L;//life
//			a++;
//			dataL = line[a];//map yang sudah dimainkan
//			bm = line[a].size();//banyak map pool
//			a++;
//			stringstream(line[a]) >> score;//import info last score
//			a++;
//			stringstream(line[a]) >> stage;//import info map ke -
//			a++;
//			stringstream(line[a]) >> ctr_level;//info level
//			a++;
//			kol = line[a].size();//import map
//			while (line[a] != "-") {
//				tmap[bar] = line[a];
//				bar++; a++;
//			}
//			a = ctr;
//		}
//	}
//	//pemasukan info musuh dan power up buat level selnjutnya
//	ctr = 0;
//	file.open("info.txt");
//	while (!file.eof()) {
//		getline(file, data[ctr]);
//		ctr++;
//	}
//	file.close();
//	for (int a = 0; a < ctr; a++) {
//		if (data[a] != "-") {
//			enemy[b] = data[a];
//			a++;
//			power[b] = data[a];
//			b++; a++;
//		}
//	}
//
//	if (bar == 0) {
//		cout << "Loading Failed ,Data Corrupted!" << '\n';
//		Sleep(3500);
//	}
//	else {
//		ctr = 0;
//		for (int a = 0; a < bar; a++) {
//			for (int b = 0; b < kol; b++) {
//				map[a][b] = tmap[a][b];
//			}
//		}for (int a = 0; a < bar; a++) {
//			for (int b = 0; b < kol; b++) {
//				if (map[a][b] == 'P') {
//					p.y = a;
//					p.x = b;
//				}
//				else if (map[a][b] == 'H' || map[a][b] == 'h') {
//					h[ctr].x = b;
//					h[ctr].y = a;
//					ctr++;
//					if (map[a][b] == 'h') {
//						load = 2;
//					}
//					else if (map[a][b] == 'H') {
//						load = 1;
//					}
//				}
//			}
//		}for (int a = 0; a < bm; a++) {
//			level[a] = dataL[a];
//		}
//	}
//}
//
//void cetak(char map[1000][1000], int L) {
//	cout << "Map : " << stage << "   Level : " << ctr_level << "    Life: " << L << '\n';
//	for (int a = 0; a < bar; a++) {
//		for (int b = 0; b < kol; b++) {
//			cout << map[a][b];
//		}
//		cout << '\n';
//	}
//}
//void inisiasi(char map[1000][1000], Pos& p, Pos& food, Pos h[], Pos pow[]) {
//	int ctr = 0, b;
//	//generate P
//	do {
//		p.x = (rand() % (kol - 2)) + 1;
//		p.y = (rand() % (bar - 2)) + 1;
//	} while (map[p.y][p.x] != ' ');
//	map[p.y][p.x] = 'P';
//	//generate enemy
//	ctr = 0;
//	stringstream(enemy[stage - 1]) >> b;
//	for (int a = 0; a < b; a++) {
//		do {
//			h[a].x = (rand() % (kol - 2)) + 1;
//			h[a].y = (rand() % (bar - 2)) + 1;
//		} while (map[h[a].y][h[a].x] != ' ');
//		map[h[a].y][h[a].x] = 'H';
//	}
//	//power up
//	stringstream(power[stage - 1]) >> b;
//	for (int a = 0; a < b; a++) {
//		do {
//			pow[a].x = (rand() % (kol - 2)) + 1;
//			pow[a].y = (rand() % (bar - 2)) + 1;
//		} while (map[pow[a].y][pow[a].x] != ' ');
//		map[pow[a].y][pow[a].x] = 'o';
//	}
//	//generate food
//	for (int a = 0; a < bar; a++) {
//		for (int b = 0; b < kol; b++) {
//			if (map[a][b] == ' ') {
//				ctr++;
//			}
//		}
//	}for (int a = ctr; a > 0; a--) {
//		do {
//			food.x = (rand() % (kol - 2)) + 1;
//			food.y = (rand() % (bar - 2)) + 1;
//		} while (map[food.y][food.x] != ' ');
//		map[food.y][food.x] = '.';
//	}
//}
//void movement(Pos& p, int& pause, int& save, int& countdown, int& load) {
//	if (kbhit()) {
//		n = getch();
//	}
//	if (n == 'w' && (map[p.y - 1][p.x] == ' ' || map[p.y - 1][p.x] == '.' || map[p.y - 1][p.x] == 'o' || map[p.y - 1][p.x] == 'h')) {
//		map[p.y][p.x] = ' ';
//		p.y--;
//	}
//	else if (n == 's' && (map[p.y + 1][p.x] == ' ' || map[p.y + 1][p.x] == '.' || map[p.y + 1][p.x] == 'o' || map[p.y + 1][p.x] == 'h')) {
//		map[p.y][p.x] = ' ';
//		p.y++;
//	}
//	else if (n == 'a' && (map[p.y][p.x - 1] == ' ' || map[p.y][p.x - 1] == '.' || map[p.y][p.x - 1] == 'o' || map[p.y][p.x - 1] == 'h')) {
//		map[p.y][p.x] = ' ';
//		p.x--;
//	}
//	else if (n == 'd' && (map[p.y][p.x + 1] == ' ' || map[p.y][p.x + 1] == '.' || map[p.y][p.x + 1] == 'o' || map[p.y][p.x + 1] == 'h')) {
//		map[p.y][p.x] = ' ';
//		p.x++;
//	}
//	else if (n == 'p' || n == 'P') {
//		pause = (pause - 1) * -1;
//	}
//	key = 0;
//	if (map[p.y][p.x] == 'o' || load == 2) {
//		key = 1;
//		countdown = 5;
//	}if (load == 1 || load == 2) {
//		load = 0;
//		save = 2;
//	}
//}
//
//void enemy_movement(Pos h[], int pw, Pos p, str move[]) {
//	int ctr, a, b, c, d, e, m;
//	float s;
//	S em;
//	char mapB[100][100], cek[4];
//	str path[10000];
//	Pos brain[10000];//memory
//	stringstream(enemy[stage - 1]) >> e;
//	if (pw == 0) {
//		for (a = 0; a < e; a++) {
//			for (b = 0; b < bar; b++) {
//				for (c = 0; c < kol; c++) {
//					if (map[b][c] != 'P') {
//						mapB[b][c] = map[b][c];//mengrefresh mapB
//					}
//					else if (map[b][c] == 'P') {
//						mapB[b][c] = ' ';
//					}
//				}
//			}
//			mapB[p.y][p.x] = 'P';
//			map[h[a].y][h[a].x] = ' ';
//			ctr = 0;
//			do {
//
//				s = sqrt((h[a].x - p.x) * (h[a].x - p.x) + (h[a].y - p.y) * (h[a].y - p.y));
//				em.w = sqrt((((h[a].y - 1) - p.y) * ((h[a].y - 1) - p.y)) + ((h[a].x - p.x) * (h[a].x - p.x)));
//				em.s = sqrt((((h[a].y + 1) - p.y) * ((h[a].y + 1) - p.y)) + ((h[a].x - p.x) * (h[a].x - p.x)));
//				em.a = sqrt((((h[a].x - 1) - p.x) * ((h[a].x - 1) - p.x)) + ((h[a].y - p.y) * (h[a].y - p.y)));
//				em.d = sqrt((((h[a].x + 1) - p.x) * ((h[a].x + 1) - p.x)) + ((h[a].y - p.y) * (h[a].y - p.y)));
//
//				for (d = 0; d < 4; d++) {
//					cek[d] = 'z';// 0 = w , 1 = s , 2 = a , 3 = d
//				}
//				m = 0;//kalo mandet
//				if (em.w <= s) {
//					cek[0] = 'w';
//				}if (em.s <= s) {
//					cek[1] = 's';
//				}if (em.a <= s) {
//					cek[2] = 'a';
//				}if (em.d <= s) {
//					cek[3] = 'd';
//				}
//
//				//PRIO  JARAK TERDEKAT
//				if (mapB[h[a].y - 1][h[a].x] != '#' && mapB[h[a].y - 1][h[a].x] != 'M' && cek[0] == 'w' && move[a].y != "s") {
//					h[a].y--; path[ctr].y = "w";
//					brain[ctr].y = h[a].y;
//					brain[ctr].x = h[a].x;
//					if (mapB[h[a].y][h[a].x] != 'P') {
//						mapB[h[a].y][h[a].x] = 'M';
//					}
//					ctr++; m++;
//				}
//				else if (mapB[h[a].y][h[a].x - 1] != '#' && mapB[h[a].y][h[a].x - 1] != 'M' && cek[2] == 'a' && move[a].x != "d") {
//					h[a].x--; path[ctr].x = "a";
//					brain[ctr].y = h[a].y;
//					brain[ctr].x = h[a].x;
//					if (mapB[h[a].y][h[a].x] != 'P') {
//						mapB[h[a].y][h[a].x] = 'M';
//					}
//					ctr++; m++;
//				}
//				else if (mapB[h[a].y + 1][h[a].x] != '#' && mapB[h[a].y + 1][h[a].x] != 'M' && cek[1] == 's' && move[a].y != "w") {
//					h[a].y++; path[ctr].y = "s";
//					brain[ctr].y = h[a].y;
//					brain[ctr].x = h[a].x;
//					if (mapB[h[a].y][h[a].x] != 'P') {
//						mapB[h[a].y][h[a].x] = 'M';
//					}
//					ctr++; m++;
//				}
//				else if (mapB[h[a].y][h[a].x + 1] != '#' && mapB[h[a].y][h[a].x + 1] != 'M' && cek[3] == 'd' && move[a].x != "a") {
//					h[a].x++; path[ctr].x = "d";
//					brain[ctr].y = h[a].y;
//					brain[ctr].x = h[a].x;
//					if (mapB[h[a].y][h[a].x] != 'P') {
//						mapB[h[a].y][h[a].x] = 'M';
//					}
//					ctr++; m++;
//				}
//				else {
//					//masuk sini jika yang terdekat jaraknay g memenuhi
//					if (mapB[h[a].y + 1][h[a].x] != '#' && mapB[h[a].y + 1][h[a].x] != 'M' && cek[1] == 'z' && move[a].y != "w") {
//						h[a].y++; path[ctr].y = "s";
//						brain[ctr].y = h[a].y;
//						brain[ctr].x = h[a].x;
//						if (mapB[h[a].y][h[a].x] != 'P') {
//							mapB[h[a].y][h[a].x] = 'M';
//						}
//						ctr++; m++;
//					}
//					else if (mapB[h[a].y][h[a].x + 1] != '#' && mapB[h[a].y][h[a].x + 1] != 'M' && cek[3] == 'z' && move[a].x != "a") {
//						h[a].x++; path[ctr].x = "d";
//						brain[ctr].y = h[a].y;
//						brain[ctr].x = h[a].x;
//						if (mapB[h[a].y][h[a].x] != 'P') {
//							mapB[h[a].y][h[a].x] = 'M';
//						}
//						ctr++; m++;
//					}
//					else if (mapB[h[a].y - 1][h[a].x] != '#' && mapB[h[a].y - 1][h[a].x] != 'M' && cek[0] == 'z' && move[a].y != "s") {
//						h[a].y--; path[ctr].y = "w";
//						brain[ctr].y = h[a].y;
//						brain[ctr].x = h[a].x;
//						if (mapB[h[a].y][h[a].x] != 'P') {
//							mapB[h[a].y][h[a].x] = 'M';
//						}
//						ctr++; m++;
//					}
//					else if (mapB[h[a].y][h[a].x - 1] != '#' && mapB[h[a].y][h[a].x - 1] != 'M' && cek[2] == 'z' && move[a].x != "d") {
//						h[a].x--; path[ctr].x = "a";
//						brain[ctr].y = h[a].y;
//						brain[ctr].x = h[a].x;
//						if (mapB[h[a].y][h[a].x] != 'P') {
//							mapB[h[a].y][h[a].x] = 'M';
//						}
//						ctr++; m++;
//					}
//				}
//				if (m == 0) {
//					if (move[a].y != "z" || move[a].x != "z") {
//						if (move[a].y == "s") {
//							h[a].y--; path[ctr].y = "w";
//							brain[ctr].y = h[a].y;
//							brain[ctr].x = h[a].x;
//							if (mapB[h[a].y][h[a].x] != 'P') {
//								mapB[h[a].y][h[a].x] = 'M';
//							}
//							ctr++; m++;
//						}
//						else if (move[a].y == "w") {
//							h[a].y++; path[ctr].y = "s";
//							brain[ctr].y = h[a].y;
//							brain[ctr].x = h[a].x;
//							if (mapB[h[a].y][h[a].x] != 'P') {
//								mapB[h[a].y][h[a].x] = 'M';
//							}
//							ctr++; m++;
//						}
//						else if (move[a].x == "d") {
//							h[a].x--; path[ctr].x = "a";
//							brain[ctr].y = h[a].y;
//							brain[ctr].x = h[a].x;
//							if (mapB[h[a].y][h[a].x] != 'P') {
//								mapB[h[a].y][h[a].x] = 'M';
//							}
//							ctr++; m++;
//						}
//						else if (move[a].x == "a") {
//							h[a].x++; path[ctr].x = "d";
//							brain[ctr].y = h[a].y;
//							brain[ctr].x = h[a].x;
//							if (mapB[h[a].y][h[a].x] != 'P') {
//								mapB[h[a].y][h[a].x] = 'M';
//							}
//							ctr++; m++;
//						}
//					}
//					else {
//						ctr--;
//						h[a].y = brain[ctr - 1].y;
//						h[a].x = brain[ctr - 1].x;
//						if (mapB[h[a].y][h[a].x] != 'P') {
//							mapB[h[a].y][h[a].x] = 'M';
//						}
//					}
//				}
//				move[a].x = "z";
//				move[a].y = "z";
//			} while (mapB[h[a].y][h[a].x] != 'P');
//			move[a].y = path[0].y;
//			move[a].x = path[0].x;
//			h[a].y = brain[0].y;
//			h[a].x = brain[0].x;
//		}
//	}
//	else {
//		for (a = 0; a < e; a++) {
//			int r = rand() % 4 + 1;
//			map[h[a].y][h[a].x] = ' ';
//			if (map[h[a].y - 1][h[a].x] != '#' && map[h[a].y - 1][h[a].x] != 'P' && r == 1) {
//				h[a].y--;
//			}
//			else if (map[h[a].y + 1][h[a].x] != '#' && map[h[a].y + 1][h[a].x] != 'P' && r == 2) {
//				h[a].y++;
//			}
//			else if (map[h[a].y][h[a].x - 1] != '#' && map[h[a].y][h[a].x - 1] != 'P' && r == 3) {
//				h[a].x--;
//			}
//			else if (map[h[a].y][h[a].x + 1] != '#' && map[h[a].y][h[a].x + 1] != 'P' && r == 4) {
//				h[a].x++;
//			}
//		}
//	}
//
//}
//void cek_death(Pos& p, Pos h[], int& L, int pw) {
//	int a, b;
//	stringstream(enemy[stage - 1]) >> b;
//	for (a = 0; a < b; a++) {
//		if (map[h[a].y][h[a].x] == 'P' && pw == 0) {
//			L--;
//			map[h[a].y][h[a].x] = ' ';
//			do
//			{
//				p.y = rand() % (bar - 2) + 1;
//				p.x = rand() % (kol - 2) + 1;
//			} while (map[p.y][p.x] != ' ');
//			map[p.y][p.x] = 'P';
//		}
//	}
//}
//void update_pos(char map[1000][1000], int mapF[1000][1000], Pos p) {
//	int a, b;
//	for (a = 0; a < bar; a++) {
//		for (b = 0; b < kol; b++) {
//			if (mapF[a][b] == 1 && (map[a][b] != 'H' || map[a][b] != 'h')) {
//				map[a][b] = '.';
//			}
//			else if (mapF[a][b] == 2 && (map[a][b] != 'H' || map[a][b] != 'h')) {
//				map[a][b] = 'o';
//			}
//		}
//	}
//	map[p.y][p.x] = 'P';
//}
//void cek_food(char map[1000][1000], int mapF[1000][1000]) {
//	FL = 0;
//	int a, b;
//	for (a = 0; a < bar; a++) {
//		for (b = 0; b < kol; b++) {
//			if (map[a][b] == '.') {
//				mapF[a][b] = 1;
//				FL++;
//			}
//			else if (map[a][b] == 'P') {
//				mapF[a][b] = 0;
//			}
//			else if (map[a][b] == 'o') {
//				mapF[a][b] = 2;
//			}
//		}
//	}
//	cout << "Food Left : " << FL << "     ";
//}
//void next() {
//	string line[1000]; int ctr = 0;
//	//pengambilan file pool map
//	ifstream file("map.txt");
//	while (!file.eof()) {
//		getline(file, line[ctr]);
//		ctr++;
//	}
//	file.close();
//	//update banyak map pool
//	bm = 0;
//	for (int a = 0; a < ctr; a++) {
//		if (line[a] == "-") {
//			bm++;
//		}
//	}
//	//random map baru
//	do {
//		stage = rand() % bm + 1;
//	} while (level[stage - 1] != '1');
//	level[stage - 1] = '0';
//
//	//ngeload map baru
//	stringstream lv;
//	lv << stage;
//	string lvl = lv.str(), tmap[1000];
//	bar = kol = 0;
//	for (int a = 0; a < ctr; a++) {
//		if (line[a] == lvl) {
//			a++;
//			kol = line[a].size();
//			while (line[a] != "-") {
//				tmap[bar] = line[a];
//				bar++; a++;
//			}
//			a = ctr;
//		}
//	}
//	//string jadi char mapnya
//	for (int a = 0; a < bar; a++) {
//		for (int b = 0; b < kol; b++) {
//			map[a][b] = tmap[a][b];
//		}
//	}
//}
//
//void cek_save(char map[1000][1000], int& save, int L) {
//	string nama, line[1000];
//	int ctr = 0;
//	if (save == 0) {
//		bool cek;
//		do {
//			cek = false;
//			cout << '\n' << "Nama save : "; cin >> nama;
//			ifstream filei("save.txt");
//			while (!filei.eof()) {
//				getline(filei, line[ctr]);
//				ctr++;
//			}
//			for (int a = 0; a < ctr; a++) {
//				if (line[a] == nama) {
//					cek = true;
//					cout << "Nama sudah pernah digunakan!";
//					Sleep(3000);
//					system("cls");
//				}
//			}
//			filei.close();
//		} while (cek);
//		ofstream data("dataS.txt", ios::app);
//		ofstream file("save.txt", ios::app);
//		data << nama << '\n';
//		file << nama << '\n';
//		file << L << '\n';
//		for (int a = 0; a < bm; a++) {
//			file << level[a];
//		}
//		file << '\n' << score << '\n';
//		file << stage << '\n';
//		file << ctr_level << '\n';
//		for (int a = 0; a < bar; a++) {
//			for (int b = 0; b < kol; b++) {
//				file << map[a][b];
//			}
//			file << '\n';
//		}
//		file << '-' << '\n';
//		data.close();
//		file.close();
//		cout << "Saving, please do not turn off your computer";
//		Sleep(3500);
//	}
//	else if (save == 2) {
//		//jika sudah ada data savenya
//		ifstream filei("save.txt");
//		while (!filei.eof()) {
//			getline(filei, line[ctr]);
//			ctr++;
//		}
//		filei.close();
//		for (int a = 0; a < ctr; a++) {
//			if (line[a] == Load_name) {
//				a++;
//				stringstream tmp;
//				tmp << L;
//				line[a] = tmp.str();
//				a++;
//				for (int b = 0; b < bm; b++) {
//					line[a][b] = level[b];
//				}
//				a++;
//				stringstream tmp2;
//				tmp2 << score;
//				line[a] = tmp2.str();
//				a++;
//				stringstream tmp3;
//				tmp3 << stage;
//				line[a] = tmp3.str();
//				a++;
//				stringstream tmp4;
//				tmp4 << ctr_level;
//				line[a] = tmp4.str();
//				a++;
//				for (int b = 0; b < bar; b++) {
//					for (int c = 0; c < kol; c++) {
//						line[a][c] = map[b][c];
//					}
//					a++;
//				}
//			}
//		}
//		ofstream fileo("save.txt");
//		for (int a = 0; a < ctr; a++) {
//			if (line[a] != "") {
//				fileo << line[a];
//				fileo << '\n';
//			}
//		}
//		fileo.close();
//		cout << "Saving, please do not turn off your computer";
//		Sleep(3500);
//	}
//}
//
//void HS(High hscore[], int life) {
//	ifstream high;
//	int ctr = 0;
//	high.open("highscore.txt");
//	if (high.is_open()) {
//		string line;
//		while (!high.eof()) {
//			getline(high, line);
//			int pos = line.find(" ");
//			if (pos > 0) {
//				hscore[ctr].nama = line.substr(0, pos);
//				hscore[ctr].skor = line.substr(pos + 1);
//				ctr++;
//			}
//		}high.close();
//	}
//	stringstream tmp;
//	tmp << score;
//	hscore[ctr].skor = tmp.str();
//	if (life == 0) {
//		cout << "Enter your name : "; cin >> hscore[ctr].nama;
//		ofstream write;
//		write.open("highscore.txt");
//		write << hscore[ctr].nama << " " << hscore[ctr].skor << "\n";
//		write.close();
//	}
//
//}
//void urut(High hscore[]) {
//	for (int i = 0; i <= 10; i++) {
//		for (int j = 0; j <= 10; j++) {
//			stringstream z(hscore[i].skor);
//			int n1; z >> n1;
//			stringstream zz(hscore[j].skor);
//			int n2; zz >> n2;
//			if (n1 > n2) {
//				string tmp = hscore[j].skor;
//				hscore[j].skor = hscore[i].skor;
//				hscore[i].skor = tmp;
//				string temp = hscore[j].nama;
//				hscore[j].nama = hscore[i].nama;
//				hscore[i].nama = temp;
//			}
//		}
//	}
//	cout << "--------------------------------------------------" << endl;
//	for (int i = 0; i < 10; i++) {
//		if (hscore[i].nama != "") {
//			cout << i + 1 << ". " << hscore[i].nama << " " << hscore[i].skor << endl;
//		}
//	}
//	cout << "--------------------------------------------------" << endl;
//}
//void saveHS(High hscore[]) {
//	ofstream write;
//	write.open("highscore.txt");
//	if (write.is_open()) {
//		for (int i = 0; i < 10; i++) {
//			if (hscore[i].nama != "") {
//				write << hscore[i].nama << " " << hscore[i].skor << "\n";
//			}
//		}write.close();
//	}
//}
//void cek_score(Pos p) {
//	if (map[p.y][p.x] == '.') {
//		score++;
//	}
//	cout << "Score : " << score << '\n';
//}
//void Power_Up(char map[1000][1000], Pos p, string enemy[], Pos h[], int& pw, int& countdown) {
//	int b;
//	stringstream(enemy[stage - 1]) >> b;
//	if (key == 1 || pw == 1) {
//		if (pw == 0) {
//			for (int a = 0; a < b; a++) {
//				eat[a] = 0;
//			}
//		}
//		pw = 1;
//		for (int a = 0; a < b; a++) {
//			if (map[h[a].y][h[a].x] == 'P') {
//				eat[a] = 1;
//			}
//			else if (eat[a] == 0) {
//				map[h[a].y][h[a].x] = 'h';
//			}
//		}
//	}
//	else {
//		for (int a = 0; a < b; a++) {
//			map[h[a].y][h[a].x] = 'H';
//		}
//		countdown = 5;
//	}
//}
//
//int main()
//{
//	srand(time(0));
//	int pause = 1, save = 0, pil, load = 0, L, timer = 0, time = 0, pw = 0;
//	High hscore[11];
//	int countdown = 5;
//	Pos p, food, h[100], pow[1000];
//	str move[100];
//	for (int a = 0; a < 100; a++) {
//		move[a].x = "z";
//		move[a].y = "z";
//	}
//	L = 3;
//	do {
//		save = 0;
//		if (load == 0) {
//			system("cls");
//			cout << "1. Play" << endl;
//			cout << "2. Load Game" << endl;
//			cout << "3. High Score" << endl;
//			cout << "4. Exit" << endl;
//			cout << "Pilihan : "; cin >> pil;
//		}if (pil == 1) {
//			if (load == 0) {
//				new_game(map, L);
//				inisiasi(map, p, food, h, pow);
//			}
//			do {
//				system("cls");
//				cetak(map, L);
//				cek_food(map, mapF);
//				movement(p, pause, save, countdown, load);//sekalian powerup trigger
//				enemy_movement(h, pw, p, move);// !!!!! MASIH KURANG EFEKTIF !!!!!
//				cek_score(p);//update score
//				update_pos(map, mapF, p);//update pos makanan dan player
//				cek_death(p, h, L, pw);
//				Power_Up(map, p, enemy, h, pw, countdown);//seklian update pos hantu
//
//				Sleep(100); timer++;
//				if (timer == 10) {
//					time++; timer = 0;
//					if (pw == 1) {
//						countdown--;
//					}
//				}if (countdown == 0) {
//					pw = 0;
//				}if (pause != 1) {
//					do {
//						char P;
//						P = getch();
//						if (P == 'p' || P == 'P') {
//							pause = (pause - 1) * -1;
//							n = 'z';
//						}
//					} while (pause == 0);
//				}if (FL == 0) {
//					for (int a = 0; a < bar; a++) {
//						for (int b = 0; b < kol; b++) {
//							map[a][b] = ' ';
//							mapF[a][b] = 0;
//						}
//					}
//					next();
//					inisiasi(map, p, food, h, pow);
//					ctr_level++; L++;
//				}if (n == 'O' || n == 'o') {
//					cek_save(map, save, L);
//					n = 'z'; save = 1;
//				}
//			} while (L > 0 && save != 1);
//			if (L == 0) {
//				pil = 3;
//			}for (int a = 0; a < bar; a++) {
//				for (int b = 0; b < kol; b++) {
//					mapF[a][b] = 0;
//				}
//			}
//		}if (pil == 2) {
//			Load(map, p, L, load, h, pw);
//			pil = 1;
//		}if (pil == 3) {
//			//HS
//			system("cls");
//			HS(hscore, L);
//			urut(hscore);
//			saveHS(hscore);
//			cout << "Press ENTER to continue";
//			char enter = getch();
//		}
//	} while (pil != 4);
//
//	return 0;
//}
