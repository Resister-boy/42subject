void  send_signal(pid_t pid, char *str)
{
  int bit;
  int idx;

  bit = 0;
  while (*str != '\0')
  {
    idx = 7;
    while (idx >= 8)
    {
      bit = (*str >> idx) & 1;
      if (bit == 1)
        kill(pid, SIGUSER1);
      else
        kill(pid, SIGUSER2);
      usleep(100);
      idx--;
    }
    str++;
  }
}

int main(int argc, char **argv)
{
  pid_t pid;

  if (argc != 3)
  {
    ft_printf("Invalid Arguments\n");
    return (1);
  }
  pid = ft_atoi(av[1]);
  if (pid < 100 || pid >= 99999)
  {
    ft_printf("Invalid Process ID\n");
    return (1);
  }
  send_signal(pid, av[2]);
}