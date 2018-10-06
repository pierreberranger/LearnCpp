/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itiievsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 08:50:27 by itiievsk          #+#    #+#             */
/*   Updated: 2018/10/06 08:50:28 by itiievsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define COLOR_GREY 8
# define HELP_LINES 30
# define HELP_COLS 103
# define NUM_OF_ENEMIES 42

# include <iostream>
# include "SpaceShip.hpp"
# include "Enemy.hpp"
# include "Gamer.hpp"

class Game {

public:

	Game(void);
	Game(Game const &src);
	Game &operator=(Game const &src);
	~Game(void);

/*
**	Ncurses functions
*/
	void init_colors(void) const;
	void print_template(void) const;
	void check_button(void);
	static void sighandler(int signum);

/*
**	Game functions
*/



/*
**	Getters & Setters
*/

	int getResult(void) const;
	void setResult(int);
	int getScore(void) const;
	void setScore(int);

private:

	int			_result;
	int			_score;
	int			_pause;
	Enemy		*enemies[NUM_OF_ENEMIES];
	Gamer		*hero;

};

#endif
