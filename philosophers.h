#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H



# include <fcntl.h>
# include <limits.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <strings.h>
# include <unistd.h>
#include <pthread.h>
#include <sys/time.h>


typedef struct s_data
{
    int time_to_eat;
    int time_to_die;
    int time_to_sleep;
    int time_think;
    pthread_mutex_t mutex_death;
    pthread_mutex_t mutex_print;
    int num_ph;
    unsigned long start;
    int count;
    int meal;
}           t_data;
typedef struct s_list
{

    unsigned long last_meal;
    pthread_mutex_t mutex_rfork;
    pthread_mutex_t mutex_eat;
    t_data *data;
    int id;
    int time_eat;
    pthread_t thread;
    struct s_list *next;
}					t_philo;

typedef struct element
{
	char	**args;
    char    *join;
}			t_push;




char	*ft_strdup(const char *s);
void    parsing(t_push *main_prog, char *str);
char	**ft_split(char *s, char c);
int	ft_atoi(char *str);
void	ft_error(void);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nitems, size_t size);
void	*ft_memset(void *str, int c, int n);
int        philo(t_push *main_prog);
t_philo	*lst_new(int content, t_data *data);
void	ft_lstadd_back(t_philo **lst, t_philo *new);
unsigned long get_time();
int	ft_print(t_philo *philo, char *str);
// void	ft_usleep(long time);
#endif