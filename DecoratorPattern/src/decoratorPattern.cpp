#include <iostream>

// ABSTRACT CLASS FOR BEVERAGE //
class IBeverage {
public:
	virtual int GetCoast() const = 0;
protected:
	int coast;
};
// -------------------------- //

// COFFE CLASS -> WE PUT DECORATOR AROUND HER //
class Coffe : public IBeverage{
public:
	Coffe(int coast);
	~Coffe();
	int GetCoast() const override;
protected:
	int coast;
};

Coffe::Coffe(int coast){
	this->coast = coast;
}

Coffe::~Coffe(){

}

int Coffe::GetCoast() const {
	return this->coast;
}
// ------------------------------------------ //

// DECORATOR //
class AddonDecorator : public IBeverage{
public:
	int GetCoast() const = 0;

};

class MilkDecorator : public AddonDecorator {
public:
	MilkDecorator(IBeverage &b, int coast);
	~MilkDecorator() {};
	int GetCoast() const override;
private:
	IBeverage *b;
};

MilkDecorator::MilkDecorator(IBeverage &b, int coast){
	this->b = &b;
	this->coast = coast;
}

int MilkDecorator::GetCoast() const {
	return this->b->GetCoast() + this->coast;
}
// --------- //

int main(){
	// coffe coast 10 //
	Coffe coffe(10);
	std::cout << "Price of a coffe: " << coffe.GetCoast() << std::endl;
	// We add milk decorator on coffe //
	MilkDecorator milkyCoffe(coffe, 5);
	std::cout << "Price of milky coffe: " << milkyCoffe.GetCoast() << std::endl;
	// We add again milk decorator on milky coffe //
	MilkDecorator doublemilkyCoffe(milkyCoffe, 5);
	std::cout << "Price of double milky coffe: "<< doublemilkyCoffe.GetCoast() << std::endl;
	/*
	 When we print coast of double milky coffe we have 20 
	 This is a price of coffe + milk + milk
	 Coffre is wrap twice by milk 
	*/
	return (0);
}