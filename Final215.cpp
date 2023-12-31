// Final215.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;


void printMenu(int& choice) {      // printing out option menu
	cout << "Hello! This is my Final Project for CGT 215!"<< endl<< "My goal was to do code Image Processing\n\n " << endl;
	cout << "Please select from the list below what kind of Image Processing you would like: " << endl;
	cout << "********************************************************\n\n" << endl;
	cout << "1. Green Screen image" << endl;
	cout << "2. Grey Scale image" << endl;
	cout << "3. Blur image " << endl;
	cout << "\nYour Selection: "; 
	cin >> choice;
}

void getChoices(float& A, float& B) {
	// code gets weird if I dont leave this in
	
}

void firstChoice(float A, float B) {  // GREEN SCREEN
	string background = "images1/backgrounds/winter.png";
	string foreground = "images1/characters/LostMan.png";
	Texture backgroundTex;
	if (!backgroundTex.loadFromFile(background)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Texture foregroundTex;
	if (!foregroundTex.loadFromFile(foreground)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Image backgroundImage;
	backgroundImage = backgroundTex.copyToImage();
	Image foregroundImage;
	foregroundImage = foregroundTex.copyToImage();
	Vector2u sz = backgroundImage.getSize();

	

	Color greenScreen = foregroundImage.getPixel(0, 0);

	for (int y = 0; y < sz.y; y++) {

		for (int x = 0; x < sz.x; x++) {


			Color example = foregroundImage.getPixel(x, y);
			if (example == greenScreen) {

				Color backgroundColor = backgroundImage.getPixel(x, y);
				foregroundImage.setPixel(x, y, backgroundColor);
			}


		}
	}

	RenderWindow window(VideoMode(1024, 768), "This is the output");
	Sprite sprite1;
	Texture tex1;
	tex1.loadFromImage(foregroundImage);
	sprite1.setTexture(tex1);
	window.clear();
	window.draw(sprite1);
	window.display();
	while (true);
}

void secondChoice(float A, float B) { // GREY SCALE
	
	string background = "images1/backgrounds/winter.png";
	string foreground = "images1/characters/LostMan.png";
	Texture backgroundTex;
	if (!backgroundTex.loadFromFile(background)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Texture foregroundTex;
	if (!foregroundTex.loadFromFile(foreground)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Image backgroundImage;
	backgroundImage = backgroundTex.copyToImage();
	Image foregroundImage;
	foregroundImage = foregroundTex.copyToImage();
	Vector2u sz = backgroundImage.getSize();

	

	Color greenScreen = foregroundImage.getPixel(0, 0);

	for (int y = 0; y < sz.y; y++) {
		for (int x = 0; x < sz.x; x++) {
			Color c = foregroundImage.getPixel(x, y);
			int intensity = (c.r + c.g + c.b) / 3;
			Color bwColor(intensity, intensity, intensity);
			foregroundImage.setPixel(x, y, bwColor);
		}
	}

	RenderWindow window(VideoMode(1024, 768), "This is the output");
	Sprite sprite1;
	Texture tex1;
	tex1.loadFromImage(foregroundImage);
	sprite1.setTexture(tex1);
	window.clear();
	window.draw(sprite1);
	window.display();
	while (true);
}
void thirdChoice(float A, float B) { //BLUR
	
	

	string background = "images1/backgrounds/winter.png";
	string foreground = "images1/backgrounds/winter.png";
	Texture backgroundTex;

	if (!backgroundTex.loadFromFile(background)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	Texture foregroundTex;
	if (!foregroundTex.loadFromFile(foreground)) {
		cout << "Couldn't Load Image" << endl;
		exit(1);
	}
	
	Image backgroundImage;
	backgroundImage = backgroundTex.copyToImage();
	Image foregroundImage;
	foregroundImage= foregroundTex.copyToImage();
	Vector2u sz = backgroundImage.getSize();


	for (int y = 0; y <  682 - 1; y++) {
		for (int x = 0; x < 1024 - 1; x++) {
			int minX = max(x - 1, 0);
			int maxX = min(x + 1, 1024 - 1);
			int minY = max(y - 1, 0);
			int maxY = min(y + 1, 1024 - 1);
			int pixelCount = 0;
			int accR = 0;
			int accB = 0;
			int accG = 0;
			for (int pixY = minY; pixY <= maxY; pixY++) {
				for (int pixX = minX; pixX <= maxX; pixX++) {
					pixelCount++;
					Color pixColor = foregroundImage.getPixel(pixX, pixY);
					accR += pixColor.r;
					accG += pixColor.g;
					accB += pixColor.b;
				}
			}
			Color pixColor = Color(accR / pixelCount, accG / pixelCount, accB / pixelCount);
			foregroundImage.setPixel(x, y, pixColor);
		}
	}
	Color greenScreen = foregroundImage.getPixel(0, 0);
	RenderWindow window(VideoMode(1024, 768), "This is the output");
	Sprite sprite1;
	Texture tex1;
	tex1.loadFromImage(foregroundImage);
	sprite1.setTexture(tex1);
	window.clear();
	window.draw(sprite1);
	window.display();
	while (true);
}


int main() {
	int choice;
	float A;
	float B;
	
	printMenu(choice);
	getChoices(A, B);
	if (choice == 1) {
		firstChoice(A, B); // green screen
	}
	if (choice == 2) {
		secondChoice(A, B); // grey scale
	}
	if (choice == 3) {
		thirdChoice(A, B); // blur
	}
	return 0;
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
