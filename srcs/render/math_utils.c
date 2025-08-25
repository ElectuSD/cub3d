/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeleard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 11:22:34 by fdeleard          #+#    #+#             */
/*   Updated: 2025/08/22 11:23:05 by fdeleard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	min(double a, double b)
{
	if (a <= b)
		return (a);
	return (b);
}

double	max(double a, double b)
{
	if (a >= b)
		return (a);
	return (b);
}
