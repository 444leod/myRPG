##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile very cool
##

SRC	=	main.c \
		src/myrpg.c \
		src/init.c \
		src/display.c \
		src/utils.c \
		src/clean.c \
		src/intro.c \
		src/save/settings.c \
		src/save/player_data.c \
		src/save/utils.c \
		src/save/display_informations.c \
		src/save/load_player_data.c \
		src/init/buttons.c \
		src/init/window.c \
		src/init/menus.c \
		src/init/states.c \
		src/init/sound.c \
		src/init/texts.c \
		src/init/collision.c \
		src/init/fight.c \
		src/init/fight_bis.c \
		src/init/fight_utils.c \
		src/init/quest.c \
		src/map/display.c \
		src/map/clean.c \
		src/map/update_anim.c \
		src/map/loading/tutorial.c \
		src/map/loading/utils/generate_sprite.c \
		src/map/loading/utils/get_int_map.c \
		src/map/loading/utils/get_sprite.c \
		src/map/loading/utils/sprite_struct.c \
		src/map/loading/utils/tiles_struct.c \
		src/map/unload/tutorial.c \
		src/npc/am_i_near_a_npc.c \
		src/npc/npc_interaction.c \
		src/npc/get_npc_text.c \
		src/tooltip/init.c \
		src/tooltip/clean.c \
		src/tooltip/display.c \
		src/player/display.c \
		src/player/clean.c \
		src/player/move.c \
		src/player/init.c \
		src/player/update.c \
		src/player/collision.c \
		src/player/inventory/grab_coconut.c \
		src/player/inventory/coconut_utils.c \
		src/menus/display.c \
		src/menus/ig_display.c \
		src/menus/event.c \
		src/menus/ig_event.c \
		src/menus/hover.c \
		src/menus/options/screen.c \
		src/menus/options/sound.c \
		src/fight/loop.c \
		src/fight/display.c \
		src/fight/event.c \
		src/fight/attacks.c \
		src/fight/special_attack.c \
		src/fight/ally_attack.c \
		src/fight/ennemy_attack.c \
		src/fight/win_loose.c \
		src/fight/use_inv.c \
		src/fight/new_attack.c \
		src/tile/utils.c \
		src/quests/quest.c \
		src/sword/am_i_near_a_sword.c \
		src/sword/grab_sword.c \
		src/security.c

TEST_SRC = $(filter-out main.c, $(SRC)) tests/test.c
OBJ	=	$(SRC:.c=.o)
NAME =	my_rpg
LDFLAGS =	-L./lib -lmy -lsfml-graphics -lsfml-window -lsfml-system \
-lsfml-audio -lcsfml-graphics -lcsfml-window -lcsfml-system  -lcsfml-audio -lm
CFLAGS	= -I include/ -W -Wall -Wextra

all:	$(NAME) # Compile the project

$(NAME):	$(OBJ)
	$(MAKE) -C ./lib/
	gcc $(OBJ) -o $(NAME) $(LDFLAGS)

debug: # Compile the project with debug flags
	$(MAKE) -C ./lib/ debug
	gcc $(SRC) -o $(NAME) $(LDFLAGS) $(CFLAGS) -g

clean: # Clean the project
	$(MAKE) -C ./lib/ clean
	rm -f $(OBJ)

fclean:	clean # Clean the project and the binary
	$(MAKE) -C ./lib/ fclean
	rm -f ./$(NAME)

re: fclean all # Clean the project and recompile it

make_and_clean: all clean # Compile the project and clean it

branch: # Create a new branch
	@read -p "Enter the branch name: " branch_name && \
	git checkout -b $${branch_name} && \
	git push --set-upstream origin $${branch_name}
	@echo -e "\e[92mBranch created\e[39m"

merge: # Merge a branch into the current one
	@read -p "Enter the branch to merge name: " first_branch && \
	git merge $${first_branch}
	@git push > /dev/null
	@echo -e "\e[92mBranch merged\e[39m"

delete_branch: # Delete a branch
	@read -p "Enter the branch name: " branch_name && \
	git checkout main && \
	git branch -d $${branch_name} && \
	git push origin --delete $${branch_name}
	@echo -e "\e[92mBranch deleted\e[39m"

run_tests: # Run the tests
	$(MAKE) -C ./lib/my/
	gcc $(TEST_SRC) -o $(NAME) $(LDFLAGS) $(CFLAGS) -lcriterion --coverage
	./$(NAME)
	gcovr --exclude tests/

help: # Print help on Makefile
	@grep '^[^.#]\+:\s\+.*#' Makefile | \
	sed "s/\(.\+\):\s*\(.*\) #\s*\(.*\)/` \
	printf "\033[93m"`\1`printf "\033[0m"`	\3 [\2]/" | \
	expand -t22

coding_style: # Check the coding style
	@$(MAKE) fclean > /dev/null
	@sudo echo -e "\e[92mChecking coding style...\e[39m"
	@sudo coding-style . . > /dev/null
	@grep -r "MAJOR\|MINOR\|INFO" coding-style-reports.log | wc -l \
 	| grep -v "0" > /dev/null && \
	cat coding-style-reports.log || \
	echo -e "\e[92mCoding style OK\e[39m"
	@grep -r "MAJOR\|MINOR\|INFO" coding-style-reports.log | wc -l \
 	| grep -v "0" > /dev/null && \
	echo -e "\e[91mCoding style errors found\e[39m" || \
	echo "" > /dev/null
	@sudo rm -f coding-style-reports.log
