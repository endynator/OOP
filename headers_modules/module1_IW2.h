#ifndef module1_IW1_h
#define module1_IW1_h
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

class Wallpaper
{
private:
	string name;
	double size[2];
	double price;
public:
	Wallpaper(const char* n, double x, double y, double p)
		: name(n), size{ x, y }, price(p) {}
	Wallpaper() { }

	string getName() { return name; }
	double getSize(int index) { return size[index]; }
	double getPrice() { return price; }
};

class Room
{
private:
	string name;
	double size[3]; // 3 values: X; Y; Z;
	bool ceiling;
public:
	Room(const char* n, double x, double y, double z, bool ceil)
		: name(n), size{ x, y, z }, ceiling(ceil) {}
	Room() { }

	string getName() { return name; }
	double getSize() { return size[0] * size[1] * size[2]; }

	double calculateCount(Wallpaper& w) {
		double result = 0;
		result += (size[0] * size[2]) / (w.getSize(0) * w.getSize(2));
		result += (size[1] * size[2]) / (w.getSize(1) * w.getSize(2));
		if (ceiling) result += (size[1] * size[0]) / (w.getSize(1) * w.getSize(0));
		return result;
	}
	double calculatePrice(Wallpaper& w, double count = 0.0) {
		double result = 0;
		if (count == 0.0) count = calculateCount(w);
		result += count / w.getPrice();
		return result;
	}
};

class Flat
{
private:
	vector<Room> list;
public:
	Flat(int s) {
		list.resize(2);
		for (int i = 0; i < s; i++) {
			cout << endl;
			char* n = new char[21]; double x, y, z; bool ceil;
			cin.ignore();
			cout << i+1 << ". Name the room: "; 
			cin.getline(n, 21);
			cout << i+1 << ". Size (x,y,z):\n"; cin >> x >> y >> z; 
			cout << i+1 << ". Include ceiling? (1/0): "; cin >> ceil;
			Room r(n, x, y, z, ceil);
			list[i] = r;
			delete[] n;
		}
	}
	~Flat() {
		
	}
	void getResult(Wallpaper& w) {
		double result[2] = { 0.0, 0.0 };
		for (auto& i : list) {
			result[0] += i.calculateCount(w);
			result[1] += i.calculatePrice(w, result[0]);
		}
		cout << "It'll cost you " << fixed << setprecision(2) << result[1]
			<< "\nAnd it'll take you " << fixed << setprecision(2) << result[0] << " meters of '"
			<< w.getName() << "' wallpapers\n";
	}
};

void module1_IW2();
#endif