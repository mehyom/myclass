#pragma once
class Goods
{
private:
	char name[20];
	char maker[20];
	int price;
	int rate;

protected:
	void updateRate() {
		scanf("%d", &rate);
	}

	int getSellingPrice() {
		return price - (price * rate)/100;
	}

public:
	Goods() : name(""), maker(""), price(0), rate(0) {}
	~Goods() {}

	void input(){
		scanf("%s %s %d %d", &name, &maker, &price, &rate);
	}

	void output(){
		printf("%d\n", getSellingPrice());
	}
};
