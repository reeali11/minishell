/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omali <omali@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:37:24 by omali             #+#    #+#             */
/*   Updated: 2024/06/11 17:37:25 by omali            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	pos_n;
	char	c;

	pos_n = n;
	if (pos_n < 0)
	{
		write(fd, "-", 1);
		pos_n = -pos_n;
	}
	if (pos_n < 10)
	{
		c = pos_n + '0';
		write(fd, &c, 1);
	}
	else
	{
		ft_putnbr_fd(pos_n / 10, fd);
		c = pos_n % 10 + '0';
		write(fd, &c, 1);
	}
}

// int	main()
// {
// 	ft_putnbr_fd(INT64_MAX, 1);
// }
// Prototype of the putnbr function (you need to provide this function)
// void ft_putnbr(int n);
// int main()
// {
//     // Test cases
//     int testCases[] = {0, 123, -456, 9999, -10000};

//     for (int i = 0; i < sizeof(testCases) / sizeof(testCases[0]); i++) {
//         int input = testCases[i];

//         // Redirect stdout to capture the function's output
//         freopen("output.txt", "w", stdout);

//         ft_putnbr_fd(input, 1);

//         // Restore the standard output
//         fclose(stdout);

//         // Read the output from the file
//         FILE *outputFile = fopen("output.txt", "r");
//         int result;
//         fscanf(outputFile, "%d", &result);
//         fclose(outputFile);

//         // Check if the result matches the expected output
//         assert(result == input);

//         printf("Test case %d passed.\n", i);
//     }
//     return 0;
// }
