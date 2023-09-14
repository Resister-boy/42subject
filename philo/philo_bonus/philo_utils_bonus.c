#include "philo_bonus.h"

int eating(t_philo *philo)
{}

int thinking(t_philo *philo)
{
  if (check_philo_status(philo->table))
    return (1);
  print_state(philo, "is thinking");
  return (0);
}

int sleeping(t_philo *philo)
{
  if (check_philo_status(philo->table))
    return (1);
  print_state(philo, "is thinking");
  return (0);
}