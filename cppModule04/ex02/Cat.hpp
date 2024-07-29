#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"

class Cat : public AAnimal
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
