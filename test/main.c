#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_loco
{
	int	*i;
}	t_loco;

t_loco	what(t_loco loco)
{
	printf("my previous valuse was: %d\n", *loco.i);
	*loco.i = 5;
	printf("now my value is: %d\n", *loco.i);
	return (loco);
}

int main(void)
{
	t_loco	loco;

	loco.i = (int *)malloc(sizeof(loco.i) * 1);
	loco->i = 10;
	loco = what(loco);
	printf("my valus when i returned: %d\n", *loco.i);
}
