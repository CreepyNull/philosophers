/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:25:35 by ayoub             #+#    #+#             */
/*   Updated: 2024/09/12 16:56:31 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

bool	get_keep_iter(t_data *data)
{
	bool	keep_iterating;

	pthread_mutex_lock(&data->mut_keep_iter);
	keep_iterating = data->keep_iterating;
	pthread_mutex_unlock(&data->mut_keep_iter);
	return (keep_iterating);
}

int	get_nb_philos(t_data *data)
{
	int	nb_philos;

	pthread_mutex_lock(&data->mut_nb_philos);
	nb_philos = data->nb_philos;
	pthread_mutex_unlock(&data->mut_nb_philos);
	return (nb_philos);
}

t_state	get_philo_state(t_philo *philo)
{
	t_state	state;

	pthread_mutex_lock(&philo->mut_state);
	state = philo->state;
	pthread_mutex_unlock(&philo->mut_state);
	return (state);
}

int	get_nb_meals_philo_had(t_philo *philo)
{
	int	nb_meals_had;

	pthread_mutex_lock(&philo->mut_nb_meals_had);
	nb_meals_had = philo->nb_meals_had;
	pthread_mutex_unlock(&philo->mut_nb_meals_had);
	return (nb_meals_had);
}

uint64_t	get_start_time(t_data *data)
{
	uint64_t	time;

	pthread_mutex_lock(&data->mut_start_time);
	time = data->start_time;
	pthread_mutex_unlock(&data->mut_start_time);
	return (time);
}
