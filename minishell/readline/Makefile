# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seonghle <seonghle@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/19 04:05:50 by seonghle          #+#    #+#              #
#    Updated: 2023/06/19 04:29:58 by seonghle         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

all: readline

clean:
	rm -rf tmp
	rm -rf readline-8.2
	rm -f readline

fclean: clean
	rm -rf bin include lib share

re:
	$(MAKE) fclean
	$(MAKE) all

readline:
	$(MAKE) fclean
	curl -O https://ftp.gnu.org/gnu/readline/readline-8.2.tar.gz
	tar -xzf ./readline-8.2.tar.gz
	cd readline-8.2 && sh ./configure --prefix="$$(cd .. && pwd)" && make -s && make -s install
	rm readline-8.2.tar.gz
	touch $@

.PHONY: all clean fclean re

.SILENT: all clean fclean re readline
