/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoub <ayoub@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:23:27 by ayoub             #+#    #+#             */
/*   Updated: 2024/08/26 16:23:36 by ayoub            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdbool.h>

# define WRONG_INPUT 1
# define MALLOC_ERROR 2

# define TAKE_FORKS "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"

typedef enum e_philo_state
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	DEAD = 3,
	FULL = 4,
	IDLE = 5
}	t_state;

struct	s_data;

typedef struct s_philo
{
	int				id;
	int				nb_meals_had;
	struct s_data	*data;
	t_state			state;
	pthread_mutex_t	*left_f;
	pthread_mutex_t	*right_f;
	pthread_mutex_t	mut_state;
	pthread_mutex_t	mut_nb_meals_had;
	pthread_mutex_t	mut_last_eat_time;
	uint64_t		last_eat_time;
}t_philo;

typedef struct s_data
{
	int				nb_philos;
	int				nb_meals;
	int				nb_full_p;
	bool			keep_iterating;
	uint64_t		eat_time;
	uint64_t		die_time;
	uint64_t		sleep_time;
	uint64_t		start_time;
	pthread_mutex_t	mut_eat_t;
	pthread_mutex_t	mut_die_t;
	pthread_mutex_t	mut_sleep_t;
	pthread_mutex_t	mut_print;
	pthread_mutex_t	mut_nb_philos;
	pthread_mutex_t	mut_keep_iter;
	pthread_mutex_t	mut_start_time;
	pthread_t		monit_all_alive;
	pthread_t		monit_all_full;
	pthread_t		*philo_ths;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}t_data;


void		*routine(void *philo_p);
bool		philo_died(t_philo *philo);
int			check_input(int argc, char **argv);
int			wrong_input_check(int argc, char **argv);
int			ft_atoi(char *str);
void		print_instruction(void);
int			init_data(t_data *data, int argc, char **argv);
int			init_philos(t_data *data);
int			init_forks(t_data *data);
uint64_t	get_time(void);
void		ft_usleep(uint64_t time);
void		wait_until(uint64_t wakeup_time);
void		*all_full_routine(void *data_p);
void		*all_alive_routine(void *data_p);
int			eat(t_philo *philo);
void		update_last_meal_time(t_philo *philo);
int			take_forks(t_philo *philo);
int			take_right_fork(t_philo *philo);
int			take_left_fork(t_philo *philo);
void		drop_right_fork(t_philo *philo);
void		drop_left_fork(t_philo *philo);
int			ft_sleep(t_philo *philo);
int			think(t_philo *philo);
uint64_t	get_die_time(t_data *data);
uint64_t	get_eat_time(t_data *data);
uint64_t	get_sleep_time(t_data *data);
bool		get_keep_iter(t_data *data);
uint64_t	get_start_time(t_data *data);
int			get_nb_philos(t_data *data);
t_state		get_philo_state(t_philo *philo);
int			get_nb_meals_philo_had(t_philo *philo);
uint64_t	get_last_eat_time(t_philo *philo);
void		set_keep_iterating(t_data *data, bool set_to);
void		set_philo_state(t_philo *philo, t_state state);
bool		nb_meals_option(t_data *data);
void		free_data(t_data *data);
void		print_msg(t_data *data, int id, char *msg);
void		print_mut(t_data *data, char *msg);
int			handle_1_philo(t_philo *philo);

#endif