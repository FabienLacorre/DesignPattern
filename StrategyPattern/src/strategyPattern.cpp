#include <iostream>

// ABSTRACT BEHAVIOR //
class IStategy {
public:
	virtual void Run() = 0;
};
// ---------------- //

// BEHAVIOR A //
class StrategyA : public IStategy {
public:
	StrategyA();
	void Run() override;
};
// --------- //

StrategyA::StrategyA(){}

void StrategyA::Run(){
	std::cout << "Exectute StrategyA" << std::endl;
}

// BEHAVIOR B //
class StrategyB : public IStategy{
public:
	StrategyB();
	void Run() override;
};

StrategyB::StrategyB(){}

void StrategyB::Run(){
	std::cout << "Exectute StrategyB" << std::endl;
}
// --------- //

// EXECUTOR //
class AlgorithmExecutor {
public:
	AlgorithmExecutor();
	void SetStrategy(IStategy &s);
	void Run();
private:
	IStategy *strategy;
};

AlgorithmExecutor::AlgorithmExecutor(){ 
	this->strategy = NULL; 
}

void AlgorithmExecutor::SetStrategy(IStategy &s){
	this->strategy = &s;
}

void AlgorithmExecutor::Run(){
	if (this->strategy != NULL){
		this->strategy->Run();	
	}
}
// ------- //

int main() {
	std::cout << std::endl;
	std::cout << "\033[32mThis design pattern allows to change algorithm or behavior of an object dynamically\033[0m" << std::endl;
	std::cout << std::endl;

	StrategyA stratA;
	StrategyB stratB;
	AlgorithmExecutor executor;

	executor.SetStrategy(stratA);
	executor.Run();

	std::cout << std::endl;
	std::cout << " - Swap algorithm in same executor whit \"executor.SetStrategy(stratB)\"" << std::endl;
	std::cout << std::endl;

	executor.SetStrategy(stratB);
	executor.Run();

	std::cout << std::endl;
	return (0);
}