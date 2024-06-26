/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabochko <dabochko@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:24:27 by dabochko          #+#    #+#             */
/*   Updated: 2024/05/27 15:26:07 by dabochko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int		sign;
	int		res;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (sign * res);
}

/*
int	main(void)
{
	const	char *str = "2147483649";
	int	result = ft_atoi(str);
	int	result2 = atoi(str);
	printf("ft_atoi: %d\n", result);
	printf("atoi: %d", result2);
}*/
