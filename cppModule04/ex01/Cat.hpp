#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	private:
		Brain* _brain;
	public:
		Cat();
		Cat(const Cat& copy);
		Cat& operator=(const Cat& copy);
		virtual ~Cat();

		void makeSound() const;
};

#endif
