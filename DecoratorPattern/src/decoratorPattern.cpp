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
class Coffee : public IBeverage{
public:
	Coffee(int coast);
	~Coffee();
	int GetCoast() const override;
protected:
	int coast;
};

Coffee::Coffee(int coast){
	this->coast = coast;
}

Coffee::~Coffee(){

}

int Coffee::GetCoast() const {
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
	std::cout << std::endl;
	std::cout << "\033[32mThis design pattern allows to wrap object to another to reduce subclasses creation\033[0m" << std::endl;
	std::cout << std::endl;

	// Coffee coast 10 //
	Coffee coffee(10);
	std::cout << "Price of a coffee: " << coffee.GetCoast() << std::endl;

	std::cout << std::endl;
	std::cout << " - Wrap with creation of decorator \"MilkDecorator milkyCoffee(coffe, 5);\"" << std::endl;
	std::cout << std::endl;

	// We add milk decorator on coffe //
	MilkDecorator milkyCoffee(coffee, 5);
	std::cout << "Price of milky coffe: " << milkyCoffee.GetCoast() << std::endl;

	std::cout << std::endl;
	std::cout << " - Wrap again with creation of decorator \"MilkDecorator doublemilkyCoffee(milkyCoffe, 5);\"" << std::endl;
	std::cout << std::endl;

	// We add again milk decorator on milky coffe //
	MilkDecorator doublemilkyCoffee(milkyCoffee, 5);
	std::cout << "Price of double milky coffe: "<< doublemilkyCoffee.GetCoast() << std::endl;
	/*
	 When we print coast of double milky coffe we have 20 
	 This is a price of coffe + milk + milk
	 Coffre is wrap twice by milk 
	*/
	return (0);
}