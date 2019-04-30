#include <unistd.h>
#include <wchar.h>

int main(void)
{
	wchar_t c;

	c = 2600;
	write(1, &c, 1);
	return (0);
}
