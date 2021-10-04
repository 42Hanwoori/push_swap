#include "../libft/libft.h"
#include <stdio.h>

int			num_only(char *s)//숫자로만 구성 알파벳, float 처리
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			continue;
		else if (s[i] == '-' || s[i] == '+')
		{
			if (i == 0 && ft_strlen(s) >= 2)
				continue;
			else
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

long long	ft_atoll(const char *str)
{
	long long	res;
	int			sign;
	int			i;

	res = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = (res * 10) + str[i++] - '0';
	return (res * sign);
}

int			is_int(char *s)//int 범위 내인지
{
	if (s[0] != '+' && s[0] != '-' && ft_strlen(s) > 10)
		return (0);
	else if (s[0] == '+' && ft_strlen(s) > 11)
		return (0);
	else if (s[0] == '-' && ft_strlen(s) > 11)
		return (0);
	else if (ft_atoll(s) > 2147483647 || ft_atoll(s) < -2147483648)
		return (0);
	return (1);
}

int		int_check(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 1)
		return (0);
	while (++i < argc)
		if (!num_only(argv[i]) || !is_int(argv[i]))
			return (0);
	return (1);
}

int		error_case(void)
{
	write(1, "error", 5);
	return (0);
}

int		set_in_list(int argc, char **argv, t_list **lst)
{
	int		i;
	t_list	*new;

	*lst = ft_lstnew(ft_atoi(argv[1]));
	if (!(*lst))
		return (0);
	i = 1;
	while (++i < argc)
	{
		new = ft_lstnew(ft_atoi(argv[i]));
		ft_lstadd_back(lst, new);
		if (!new)
		{	
			ft_lstclear(lst);
			return (0);
		}
	}
	return (1);
}

void	print_stacks(t_list *a, t_list *b)
{
	t_list *spot_a;
	t_list *spot_b;

	printf("\n\n");
	spot_a = a;
	spot_b = b;
	while (spot_a || spot_b)
	{
		if(!spot_a)
		{
			printf("\t");
			printf("%d\n", spot_b->content);
			spot_b = spot_b->next;
		}
		else if (!spot_b)
		{
			printf("%d\t", spot_a->content);
			printf(" \n");
			spot_a = spot_a->next;
		}
		else
		{
			printf("%d\t%d\n", spot_a->content, spot_b->content);
			spot_a = spot_a->next;
			spot_b = spot_b->next;
		}
	}
	printf("_\t_\n");
	printf("a\tb\n");
	printf("-------------------");
	printf("\n\n");
}

int		dupl_check(t_list *phead)
{
	t_list *i;
	t_list *j;

	i = phead->next;
	while(i)
	{
		j = phead;
		while (j != i)
		{
			if (j->content == i->content)
				return (0);
			j = j->next;
		}
		i = i->next;
	}
	return (1);
}

int     set_input(int argc, char **argv, t_list **lst)
{
	//if (str_check)

	//---------------------------------
	if (!(int_check(argc, argv)))
		return (error_case());
	if (!set_in_list(argc, argv, lst))
		return (error_case());
	if (!(dupl_check(*lst)))
		return (error_case());
	return (1);
}

void	sa(t_list **a, int is_ss)
{
	t_list *temp;
	
	if (!*a || !((*a)->next))
		return ;
	temp = ((*a)->next)->next;
	((*a)->next)->next = *a;
	*a = (*a)->next;
	((*a)->next)->next = temp;
	if (!is_ss)
		write(1, "sa\n", 3);
}

void	sb(t_list **b, int is_ss)
{
	t_list *temp;
	
	if (!*b || !((*b)->next))
		return ;
	temp = ((*b)->next)->next;
	((*b)->next)->next = *b;
	*b = (*b)->next;
	((*b)->next)->next = temp;
	if (!is_ss)
		write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	if (!*a || !((*a)->next))
	{
		sb(b, 1);
		write(1, "ss\n", 3);
		return ;
	}
	sa(a, 1);
	if (!*b || !((*b)->next))
	{
		write(1, "ss\n", 3);
		return ;
	}
	sb(b,1);
	write(1, "ss\n", 3);
	return ;
}

void	pb(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!*a)
		return ;
	temp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = temp;
	write(1, "pb\n", 3);
}

void	pa(t_list **a, t_list **b)
{
	t_list	*temp;

	if (!*b)
		return ;
	temp = (*b)->next;
	(*b)->next = *a;
	*a = *b;
	*b = temp;
	write(1, "pa\n", 3);
}

void	ra(t_list **a, int is_rr)
{
	t_list	*temp1;
	t_list	*temp2;

	if (!*a || !(*a)->next)
		return ;
	temp1 = (*a)->next;
	temp2 = *a;
	while (temp2->next)
		temp2 = temp2->next;
	temp2->next = *a;
	(*a)->next = NULL;
	*a = temp1;
	if (!is_rr)
		write(1, "ra\n", 3);
}

void	rb(t_list **b, int is_rr)
{
	t_list	*temp1;
	t_list	*temp2;

	if (!*b || !(*b)->next)
		return ;
	temp1 = (*b)->next;
	temp2 = *b;
	while (temp2->next)
		temp2 = temp2->next;
	temp2->next = *b;
	(*b)->next = NULL;
	*b = temp1;
	if (!is_rr)
		write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	if (!*a || !((*a)->next))
	{
		rb(b, 1);
		write(1, "rr\n", 3);
		return ;
	}
	ra(a, 1);
	if (!*b || !((*b)->next))
	{
		write(1, "rr\n", 3);
		return ;
	}
	rb(b,1);
	write(1, "rr\n", 3);
}

void	rra(t_list **a, int is_rrr)
{
	t_list	*temp1;
	t_list	*temp2;
	t_list	*temp3;

	if (!*a || !(*a)->next)
		return ;
	temp1 = *a;
	temp2 = *a;
	while ((temp2->next)->next)
		temp2 = temp2->next;
	temp3 = temp2->next;
	*a = temp3;
	temp2->next = NULL;
	(*a)->next = temp1;
	if (!is_rrr)
		write(1, "rra\n", 4);
}

void	rrb(t_list **b, int is_rrr)
{
	t_list	*temp1;
	t_list	*temp2;
	t_list	*temp3;

	if (!*b || !(*b)->next)
		return ;
	temp1 = *b;
	temp2 = *b;
	while ((temp2->next)->next)
		temp2 = temp2->next;
	temp3 = temp2->next;//이게 NULL?
	*b = temp3;
	temp2->next = NULL;
	(*b)->next = temp1;
	if (!is_rrr)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	if (!*a || !(*a)->next)
	{
		rrb(b, 1);
		write(1, "rrr\n", 4);
		return ;
	}
	rra(a, 1);
	if (!*b || !(*b)->next)
	{
		write(1, "rrr\n", 4);
		return ;
	}
	rrb(b, 1);
	write(1, "rrr\n", 4);
}

int     main(int argc, char **argv)
{
    t_list	*a;
	t_list	*b;
	char	order[4];
	int		i;

	i = 0;
	a = NULL;
	b = NULL;
	if (!(set_input(argc, argv, &a)))
		return (-1);
	while (1)
	{
		print_stacks(a, b);
		printf("type the order : ");
		scanf("%s", order);
		printf("->%s<-", order);
		if (order[0] == 's')
		{
			if (order[1] == 'a')
				sa(&a, 0);
			else if (order[1] == 'b')
				sb(&b, 0);
			else if (order[1] == 's')
				ss(&a, &b);
		}
		else if (order[0] == 'p')
		{
			if (order[1] == 'a')
				pa(&a, &b);
			else if (order[1] == 'b')
				pb(&a, &b);
		}
		else if (order[0] == 'r')
		{
			if (order[1] == 'r' && order[2] == 'r')
				rrr(&a, &b);
			else if (order[1] == 'r' && order[2] == 'a')
				rra(&a, 0);
			else if (order[1] == 'r' && order[2] == 'b')
				rrb(&b, 0);
			else if (order[1] == 'a')
				ra(&a, 0);
			else if (order[1] == 'b')
				rb(&b, 0);
			else if (order[1] == 'r')
				rr(&a, &b);
		}
		i++;
		printf("count : %d\n\n\n\n\n\n", i);
		order[0] = 0;
		order[1] = 0;
		order[2] = 0;
		order[3] = 0;
	}
	return (0);
}