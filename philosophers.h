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

typedef struct s_list
{
    int time_to_eat;
    int time_to_die;
    int time_to_sleep;
    int time_think;
    int last_meal;
    int fork;
    pthread_mutex_t mutex_rfork;
    pthread_mutex_t mutex_death;
    unsigned long start;
    pthread_t *t;
    int id;
    struct s_list *next;
}					t_data;

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
void        philo(t_push *main_prog);
t_data	*lst_new(int content);
void	ft_lstadd_back(t_data **lst, t_data *new);
unsigned long get_time();
#endif