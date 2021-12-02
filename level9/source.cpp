#include <iostream>
#include <cstring>

class N
{
	public:
		N(int value) { this->n = value; }
		~N() {}
		int operator+(N const & rhs) { return this->n + rhs.n; }
		int operator-(N const & rhs) { return this->n - rhs.n; }

		void setAnnotation(char *str)
		{
			size_t size = strlen(str);
			memcpy(this->string, str, size);
			return ;
		}
		
		char	string[0x64];			// [this + 0x4]
		int	n;				// [this + 0x68]

};

int	main(int argc, char **argv)
{
	if (argc < 2)
		exit(1);
	
	N *a = new N(5);				// [esp + 0x1c]
	N *b = new N(6);				// [esp + 0x18]

	a->setAnnotation(argv[1]);
	return (b->operator+(*a));




}

// esp + 0x14 --> a
// esp + 0x10 --> b
//
