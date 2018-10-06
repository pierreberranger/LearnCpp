/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 08:44:51 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/06 08:44:52 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "SpaceShip.hpp"
#include "Enemy.hpp"
#include "Good.hpp"
#include "Bullet.hpp"
#include <ncurses.h>
#include <csignal>
#include <ctime>
#include <unistd.h>

int main() {

	std::srand(std::time(nullptr));

	std::signal(SIGINT, Game::sighandler);
	setlocale(LC_ALL, "en_US.UTF-8");
	initscr();
	start_color();
	curs_set(0);
	cbreak();
	noecho();

	Game *game = new Game;
	game->init_colors();
	game->print_template();

	while (!game->getResult()) {
		nodelay(stdscr, TRUE);
		game->manage_bullets();
		game->updatePlayers();
		game->check_button();
		game->print_map();
		refresh();
		usleep(15000);
	}


	endwin();

//	print_template(0, 0, crwr);

	return 0;
}
