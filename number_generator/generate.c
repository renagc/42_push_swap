#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void	print_array(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!(i == (size - 1)))
			printf("%d ", array[i]);
		i++;
	}
	printf("%d\n", array[i - 1]);
}

int	check_array_dup(int *array, int value, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (array[i] == value)
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	*array;
	int	i;
	int	size;
	int	x;

	if (ac != 2)
		return (0);
	i = 0;
	size = atoi(av[1]);
	x = rand() % size + 1;
	array = malloc(size * sizeof(int));
	while (i < size)
	{
		if (check_array_dup(array, x, i))
		{
			array[i] = x;
			i++;
		}
		x = rand() % size + 1;
	}
	print_array(array, size);
	free(array);
	return (0);
}
