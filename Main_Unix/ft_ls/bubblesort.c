#include <ft_ls.h>

// CHANGE SORT TO PUT ISFILE FIRST THEN ABC ORDER

void	swap(t_file *a, t_file *b)
{
	char	*temp;

	temp = ft_strdup(a->name);
	a->name = ft_strdup(b->name);
	b->name = ft_strdup(temp);
	ft_strdel(&temp);
}

void	bubblesort(t_file *head)
{
	int		swapped;
	t_file	*one;
	t_file	*two;

	one = head;
	two = NULL;
	if (one == NULL)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		one = head;
		while (one->next->name)
		{
			if (ft_strcmp(one->name, one->next->name) > 0)
			{
				swap(one, one->next);
				swapped = 1;
			}
			one = one->next;
		}
		two = one;
	}
}

void	swap_dirs(t_all *lst, int i)
{
	char	*temp;

	temp = ft_strdup(lst->dirv[i]);
	lst->dirv[i] = ft_strdup(lst->dirv[i + 1]);
	lst->dirv[i + 1] = ft_strdup(temp);
	ft_strdel(&temp);
}

void	bubblesort_dirs(t_all *lst)
{
	int		i;
	int		swapped;

	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < lst->dirc - 1)
		{
			if (ft_strcmp(lst->dirv[i], lst->dirv[i + 1]) > 0)
			{
				swap_dirs(lst, i);
				swapped = 1;
			}
			i++;
		}
	}
}
