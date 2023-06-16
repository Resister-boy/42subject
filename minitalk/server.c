#include "./minitalk.h"

void  init_alpha(t_alpha alpha)
{
  alpha.bit = 0 ;
  alpha.idx = 0;
}

void  sig_handler(int signal_no)
{
  static  t_alpha alpha;

  init_alpha(alpha);
  if (signal_no == SIGUSER1)
  {
    if (alpha.idx < 8)
      alpha.bit = (alpha.bit << 1) | 1;
  }
  else if (signal_no == SIGUSER2)
  {
    if (alpha.idx < 8)
      alpha.bit = (alpha.bit << 1) | 0;
  }
  alpha.idx++;
  if (alpha.idx == 8)
  {
    ft_printf("%c", alpha.bit);
    init_alpha(alpha);
  }
}

int main(void)
{
  pid_t pid;

  pid = getpid();
  ft_printf("Server Process ID: %d\n", pid);
  signal(SIGUSER1, proess_signal);
  signal(SIGUSER2, proces_signal);
  while (1)
    pause();
  return (0);
}