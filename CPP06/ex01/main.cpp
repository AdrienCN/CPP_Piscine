#include <iostream>
#include <string>

typedef struct s_Data 
{
	int i = 42;
	int j = 43;
	std::string	str;
} Data;


uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}




int		main()
{
	uintptr_t	ui_ptr = 0;
	Data		*b = NULL;
	Data		a; // creer une struct;
	a.str = " | panda";

	std::cout << "ui_ptr = " << ui_ptr << std::endl;	
	std::cout << "&a = " << &a << " | " << a.i << " | " << a.j << a.str << std::endl;
	std::cout << "b = " << b << std::endl;
	ui_ptr = serialize(&a); // stocker les bits uinptr
	b = deserialize(ui_ptr); // On reinterpret ces bits dans un pointeur de data
	std::cout << std::endl;
	std::cout << "ui_ptr = " << ui_ptr << std::endl;	
	std::cout << "b  = " << b << " | " <<b->i << " | " << b->j << b->str << std::endl;
}
