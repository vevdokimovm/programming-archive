#include <iostream>

struct Unit {
	Unit(size_t id, int hp)
		: id_(id), hp_(hp) {}
	virtual size_t id() const { return id_; }
	virtual int hp() const { return hp_; }
private:
	size_t id_;
	int hp_;
};

struct Elf: virtual Unit {
	Elf(size_t id, int hp)
		: Unit(id, hp) {}

	size_t id() const override { return Unit::id(); }
	int hp() const override { return Unit::hp(); }
};

struct Archer: virtual Unit {
	Archer(size_t id, int hp)
		: Unit(id, hp) {}

	size_t id() const override { return Unit::id(); }
	int hp() const override { return Unit::hp(); }
};

struct ElfArcher: Elf, Archer {
	ElfArcher(size_t id, int hp)
		: Unit(8888, 9999), Elf(1111, 2222), Archer(1703, 8103) {}

	size_t id() const { return Archer::id(); }
	int hp() const { return Elf::hp(); }
};

int main(int argc, char* argv[]){
	srand((unsigned int)time(NULL));

	Unit* unit = new Unit(1, 100);
	Elf* elf = new Elf(2, 200);
	Archer* archer = new Archer(3, 300);
	ElfArcher* elfarcher = new ElfArcher(4, 400);
	ElfArcher& relfarch = *elfarcher;

	Elf * e = (rand() % 2) ? new Elf(0, 1) : new ElfArcher(2, 3);
	std::cout << e->id() << " " << e->hp() << std::endl;

	// Unit& polymorph = static_cast<Elf&>(relfarch);
	// std::cout << polymorph.id() << " " << polymorph.hp() << std::endl;
	// Archer* polymorph = elfarcher;
	// std::cout << polymorph->id() << " " << polymorph->hp() << std::endl;
	//std::cout << elfarcher->id() << " " << elfarcher->hp() << std::endl;
	return 0;
}