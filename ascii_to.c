/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_to.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <mvelazqu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 20:48:01 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/03/19 17:54:53 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_separator(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	is_hexdigit(char c)
{
	if (c >= 'A' && c <= 'F')
		return (1);
	if (c >= 'a' && c <= 'f')
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_ahtoi(char **num)
{
	int	nbr;
	int	sign;

	nbr = 0;
	sign = 1;
	if (**num == '-' || **num == '+')
	{
		if (**num == '-')
			sign = -1;
		*num += 1;
	}
	while (is_hexdigit(**num))
	{
		if (**num >= 'a' && **num <= 'f')
			nbr = nbr * 16 + **num - 'a' + 10;
		else if (**num >= 'A' && **num <= 'F')
			nbr = nbr * 16 + **num - 'A' + 10;
		else if (**num >= '0' && **num <= '9')
			nbr = nbr * 16 + **num - '0';
		*num += 1;
	}
	return (nbr * sign);
}

int	ft_atoi(char **num)
{
	int	nbr;
	int	sign;

	nbr = 0;
	sign = 1;
	if (**num == '-' || **num == '+')
	{
		if (**num == '-')
			sign = -1;
		*num += 1;
	}
	while (**num >= '0' && **num <= '9')
	{
		nbr = nbr * 10 + **num - '0';
		*num += 1;
	}
	return (nbr * sign);
}

int	get_number(char **text)
{
	int	number;

	if (**text == '0' && ((*text)[1] == 'x' || (*text)[1] == 'X'))
	{
		*text += 2;
		number = ft_ahtoi(text);
	}
	else
		number = ft_atoi(text);
	return (number);
}
