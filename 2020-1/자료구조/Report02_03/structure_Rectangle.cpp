#include <stdio.h>
#include <string.h>

struct Rectangle {
	int w;
	int h;
};

void inputRectangle(Rectangle* rect)
{
	scanf("%d", &rect->w);
	scanf("%d", &rect->h);
}

void outputRectangle(int area, int periphery)
{
	printf("%d\n", area);
	printf("%d\n", periphery);
}

int main()
{
	int numOfRectangle = 0;
	Rectangle input;

	scanf("%d", &numOfRectangle);
	Rectangle *array = new Rectangle[numOfRectangle];
	
	// data input
	for (int i = 0; i < numOfRectangle; i++) {
		inputRectangle(&array[i]);
	}

	// calculation & output
	for (int i = 0; i < numOfRectangle; i++) {
		int area = array[i].w * array[i].h;
		int periphery = 2*(array[i].w + array[i].h);
		outputRectangle(area, periphery);
	}
}