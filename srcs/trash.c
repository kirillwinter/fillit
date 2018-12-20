char	**get_coordinates_fig(char *buf, int map_size)
{
	char	**axis;
	int		i;
	int		nb;
	int		start_pos;

	i = 0;
	nb = 0;
	if (!(axis = (char **)malloc(3 * sizeof(char *))))
		return (0);
	axis[0] = (char*)malloc(4 * sizeof(char));
	axis[1] = (char*)malloc(4 * sizeof(char));
	axis[0][0] = 0;
	axis[1][0] = 0;
	start_pos = -get_start_pos(buf, map_size);
	while (buf[i] != '\0')
	{
		if (buf[i] == '#' && i != -start_pos)
		{
			nb++;
			axis[0][nb] = i % map_size;
			axis[1][nb] = i / map_size;			
		}
		i++;
	}
	return (axis); 
}

char	*change_coord(char *a)
{
	char	*b;
	int		i;
	int		j;

	b = ft_strnew(6);
	while (a[i] != '\0')
	{
		if (a[i] < 0)
		{
			b[j] = a[i] % 4 + 4;		// для х
			b[j + 1] = a[i] / 4 - 1;	// для у
		}
		else
		{
			b[j] = a[i] % 4;			// для х
			b[j + 1] = a[i] / 4;		// для у
		}
		i++;
		j += 2;
	}
	b[j] = '\0';
	return (b);
}

// char	*check_fig(char *arr, int tet_count)
// {
// 	if (tet_count == 1 && (arr[0] == 1 && arr[1] == 4 && arr[2] == 5))
// 	{
// 		arr[0] = 1;
// 		arr[1] = 2;
// 		arr[2] = 3;
// 	}
// 	if (tet_count == 2)
// 	{
		
// 	}
// }

int    **get_coordinates_fig(char *buf, int map_size)
{
    int        **axis;
    int        i;
    int        nb;
    int        start_pos;

    i = 0;
    nb = 0;
    if (!(axis = (char **)malloc(3 * sizeof(char *))))
        return (0);
    axis[0] = (char*)malloc(4 * sizeof(char));
    axis[1] = (char*)malloc(4 * sizeof(char));
    axis[0][0] = 0;
    axis[1][0] = 0;
    start_pos = -get_start_pos(buf, map_size);
    while (buf[i] != '\0')
    {
        if (buf[i] == '#' && i != -start_pos)
        {
            nb++;
            axis[0][nb] = (i + start_pos) % map_size;
            axis[1][nb] = (i + start_pos) / map_size;            
        }
        i++;
    }
    return (axis);
}


char *get_left_up_coord(char *a)
{
	char	*b;
	int		min;
	int		i;

	i = 0;
	min = a[i];
	b = ft_strnew(4);
	while (a[i] != '\0')
	{
		if (a[i] < min)
			a[i] = min;
		i++;
	}
	i = 0;
	while (min > 20)
	{
		while (a[i] != '\0')
		{
			a[i] = a[i] - 10;
			i++;
		}
		min = min - 10;
	}
	i = 0;
	while (a[i] != '\0')
	{
		b[i] = a[i] % 10;
	}

}