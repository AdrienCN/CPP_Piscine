#include "Convert.hpp"

int		main(int argc, char **argv)
{
	Convert convertor(argv[1]);

	// Identifier le type de donner de la str (char / int / float / double)
	convertor.id_data();
	convertor.convert_data();
}
