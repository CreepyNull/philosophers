/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:21:40 by jergashe          #+#    #+#             */
/*   Updated: 2024/09/13 13:25:21 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
 
void	*routine(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *) philo_p;
	update_last_meal_time(philo);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->eat_time - 10);
	while (get_philo_state(philo) != DEAD)
	{
		if (eat(philo) != 0)
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (ft_sleep(philo) != 0)
			break ;
		if (get_philo_state(philo) == DEAD)
			break ;
		if (think(philo) != 0)
			break ;
	}
	return (NULL);
}

void	print_nb_meals_had(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->mut_print);
	printf("Philo %d ate %d times\n", philo->id, philo->nb_meals_had);
	pthread_mutex_unlock(&data->mut_print);
}
