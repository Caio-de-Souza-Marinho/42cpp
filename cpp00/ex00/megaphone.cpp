#include <cctype>
#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";

	std::string	text;
	for (int i = 1; i < argc; i++)
	{
		text = argv[i];
		for (std::size_t j = 0; j < text.size(); j++)
			text[j] = std::toupper(static_cast<unsigned char>(text[j]));
		std::cout << text;
	}
	std::cout << std::endl;
	return 0;
}
