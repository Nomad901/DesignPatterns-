#include <iostream>
#include <memory>

/*	
	Proxy design pattern - this is just using features of a class through interface of another class;
	You can consider this as a type-erasure form actually;

	AI's answer:
	The Proxy Design Pattern in C++ can be used to implement a form of type-erasure,;
	where you hide the concrete implementation behind an interface;
*/

class Weapon
{
public:
	virtual ~Weapon() = default;
	virtual void printModel() = 0;
};

class Pistol : public Weapon
{
public:
	void printModel() override
	{
		std::cout << "Im a pistol!\n";
	}
};

class Gun : public Weapon
{
public:
	Gun(std::unique_ptr<Weapon>&& pWeapon)
		: mWeapon{std::move(pWeapon)}
	{ }
	
	void printModel() override
	{
		std::cout << "Im a gun!\n";
		//
		// .. some code
		//
		mWeapon->printModel(); //  Proxy design pattern's feature
	}

private:
	std::unique_ptr<Weapon> mWeapon;
};


int main()
{
	std::unique_ptr<Gun> gun = std::make_unique<Gun>(std::make_unique<Pistol>());

	gun->printModel();

}
