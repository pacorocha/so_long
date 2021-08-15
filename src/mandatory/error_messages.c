#include "../../includes/mandatory/so_long.h"

void	print_error(int id_error)
{
	char	*error_msg;

	print_red();
	error_msg = check_error(id_error);
	printf("Error:\n%s", error_msg);
	exit(EXIT_FAILURE);
}

char	*check_error(int id_error)
{
	char	*error_msg;

	error_msg = "Undefined.";
	if (id_error == 0)
		error_msg = "file extension is not valid.";
	if (id_error == 1)
		error_msg = "line size is different.";
	if (id_error == 2)
		error_msg = "Map contains invalid characters.";
	if (id_error == 3)
		error_msg = "map is not closed.";
	if (id_error == 4)
		error_msg = "there must be just one player.";
	return (error_msg);
}
