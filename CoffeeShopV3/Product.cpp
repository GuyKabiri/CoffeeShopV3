#pragma warning(disable : 4996)

#include <exception>
#include "Product.h"
#include "utils.h"

Product::Product(const string& name, int calories, double cost, double price) : name(""), cost(DBL_MIN), price(DBL_MAX)
{																			//	initiate with max and min values because of the setters validation
	setName(name);
	setCalories(calories);
	setCost(cost);
	setPrice(price);
}

void Product::setName(const string& name)
{
	int nameLen = (int)name.size();				//	save name length because needed in more than one place
	if (nameLen < 2)								//	if the name is too short
		throw exception("Product Name should contain at least 2 characters.");
	if (!isAlphaOnly(name))							//	if the name contains non-alphabetic characters
		throw exception("Product Name should contain characters only.");
	this->name = name;
	this->name[0] = toupper(name[0]);				//	upper case the first letter
}

void Product::setCalories(int calories)
{
	if (calories < 0)								//	calories should be non-negative
		throw exception("Calories can not be less than 0.");
	this->calories = calories;
}

void Product::addCalories(int amount) noexcept(false)
{
	if (amount < 0)									//	can not add negative amount of calories. should not add zero calories
		throw exception("Can not add less than 0 calories.");
	setCalories(calories + amount);
}

void Product::setCost(double cost)
{
	if (cost < 0 || cost > price)					//	cost should be positive and less than the price 
		throw exception("Cost can not be greater than the price.");
	this->cost = cost;
}

void Product::setPrice(double price)
{
	if (price < 0 || price < cost)					//	price should be positive and greater than the cost
		throw exception("Price can not be less than the cost.");
	this->price = price;
}

// operators
bool Product::operator==(const Product& other) const
{													//	if the name equals and the type of the products
	return ((name == other.name) && (typeid(*this) == typeid(other)));
}

ostream& operator<<(ostream& os, const Product& product)
{
	os << "(" << typeid(product).name() + 6 << ") " << product.name << " Calories: " <<
		product.calories << " Cost: " <<
		product.cost << " Price: " << product.price;
	product.toOs(os);
	return os;
}