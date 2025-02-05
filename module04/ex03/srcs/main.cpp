#include "main.hpp"

int main(void)
{

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	std::cout << std::endl << "====== CREATE MATERIA AND EQUIP TEST ======" << std::endl << std::endl;

	Character* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->equip(src->createMateria("ice")); 
	me->equip(src->createMateria("cure")); 


	// std::cout << std::endl << "====== USE MATERIA TEST ======" << std::endl << std::endl;

	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << std::endl << "====== UNEQUIP TEST ======" << std::endl << std::endl;

  AMateria* leftover = static_cast<Character*>(me)->getMateria(0);
	me->unequip(0);
	me->use(0, *bob);

	std::cout << std::endl << "====== TEST DEEP COPY ======" << std::endl << std::endl;

	Character* alice = new Character("alice");
	alice->equip(src->createMateria("ice"));

	std::cout << "Copying 'alice' into 'cloneAlice'..." << std::endl;
	Character* cloneAlice = new Character(*alice);

	std::cout << "Using slot 0 from 'alice' => " << std::endl;
	alice->use(0, *bob);

	std::cout << "Using slot 0 from 'cloneAlice' => " << std::endl;
	cloneAlice->use(0, *bob);

	delete bob;
	delete alice;
	delete cloneAlice;

	delete me;
	delete src;
	

  delete leftover;

	return 0;
}
