#include <string>
#include <iostream>
#include "../headers/individual_work2.h"

using namespace std;

void module1_IW2() {
	int rooms, wallps;

	cout << "Room's amount: "; cin >> rooms;
	Flat flat(rooms);	

	cout << "Types of wallpapers: "; cin >> wallps;
	vector<Wallpaper> wallpapers(wallps);
	for (int i = 0; i < wallps; i++) {
		cout << endl;
		char* n = new char[21]; double x, y; double price;
		cin.ignore();
		cout << i + 1 << ". Name the wallpaper: ";
		cin.getline(n, 21);
		cout << i + 1 << ". Size (x, y) (in meters):\n"; cin >> x >> y;
		cout << i + 1 << ". Price: "; cin >> price;
		Wallpaper r(n, x, y, price);
		wallpapers[i] = r;
		delete[] n;
	}
	cout << "Now choose the wallpaper to use: \n";
	int j = 1;
	for (auto& i : wallpapers) {
		cout << j << ". " << i.getName() << "; Size: "
			<< i.getSize(0) << "x" << i.getSize(1) << "; Price: " << i.getPrice() << endl;
		j++;
	}
	cin >> j;
	flat.getResult(wallpapers[j - 1]);
}