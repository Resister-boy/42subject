# 42Philosophers

Philosophers is an exercise where multiple threads must share resources equally.
Each philosopher is represented by a thread. Philosophers think, eat, sleep, think, eat, ...
There are as many forks as philosophers. In order to eat, a philosopher must take the fork at its left and the fork at its right.
Philosophers can't take a fork that is in use. Mutexes can be used to prevent that.
If a philosopher doesn't eat for too long, he dies.
The program's arguments are as follows:
        number_of_philosophers (and of forks)
        time_to_die (ms) max time between eat start
        time_to_eat (ms)
        time_to_sleep (ms)
        [number_of_times_each_philosopher_must_eat]
                optional
                if every philosopher has eaten that many times, end
                otherwise, end only when a philosopher dies

Every event is printed to the console, here's a graphical interpretation of those events for the following arguments
./philo 81 610 200 200 10
![](https://i.imgur.com/7ZFl7We.png)

In the bonus version, the philosophers are represented by child processes. The forks are represented by a semaphore initialized to the number of philosophers.
./philo_bonus 81 610 200 200 10
![](https://i.imgur.com/lFtJHm6.png)
