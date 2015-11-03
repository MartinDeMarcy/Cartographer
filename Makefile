##
## Makefile for Makefile in /home/pras_m/rendu/cursus_dedie/Cartographer
## 
## Made by PRAS Martin
## Login   <pras_m@epitech.net>
## 
## Started on  Wed Oct 21 19:33:25 2015 PRAS Martin
## Last update Tue Nov  3 19:06:15 2015 PRAS Martin
##

RM		= rm -f

SRCS		= main.c \
		  src.c \
		  src2.c \
		  random.c \
		  algo.c \
		  print.c \
		  tab.c

NAME		= dedale

CFLAGS		= -w -pedantic -Werror -Wall -g

SAVE		= *~

EXE		= dedale

CC		= gcc

OBJS		= $(SRCS:.c=.o)

UNZIP		= gunzip

ZIP		= tar

ZIPFLAGS	= -cvf

UNZIPFLAGS	= xf

ARCHIVE		= $(EXE)$(shell date +'%Y-%m-%d-%S.tar.gz')

REP_SVG		= ./SAVE

GREEN		= "\033[33;32m"

WHITE		= "\033[0m"

BLUE		= "\033[33;33m"

RED		= "\033[33;31m"

all:	 	$(NAME)

$(NAME): 	$(OBJS)
	 	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)
	 	@echo $(GREEN)"[Compilation Completed]"$(WHITE)
clean:
	 	@$(RM) $(OBJS) $(SAVE)
	 	@echo $(BLUE)"[Objs Removed]"$(WHITE)

fclean: 	clean
	 	@$(RM) $(NAME)
	 	@echo $(RED)"[Exe Removed]"$(WHITE)

archive: 	clean
		@if [ ! -d $(REP_SVG)]
		then
		@mkdir $(REP_SVG)
		fi
	 	@echo "Creation de l'archive $(ARCHIVE)..."
	 	@$(ZIP) $(ZIPFLAGS) $(ARCHIVE) $(NAME) $(SRCS)
		@mv $(ARCHIVE) $(REP_SVG)
	 	@echo "Termine."

revert: 	clean
	 	@echo "Décompressage de l'archive $(ARCHIVE)..."
	 	@$(UNZIP) $(UNZIPFLAGS) $(ARCHIVE)
	 	@echo "Termine."

num:
		@echo "La dernière version est: "$(RED)$(ARCHIVE)$(WHITE)

delete:
		@echo  $(RED)"Suppression de "$(ARCHIVE)$(WHITE)
		@$(RM) $(REP_SVG)$(ARCHIVE)
		@echo "Termine."

re:		fclean all
