#ifndef SLIDE_PLAYER_STATE_LEFT_H
#define SLIDE_PLAYER_STATE_LEFT_H

#include <Player.h>
#include <PlayerState.h>

class SlidePlayerStateLeft : public PlayerState {
public:
	virtual PlayerState* handleInput(gpp::Events& input);
	virtual void update(Player&);
	virtual void enter(Player&);
	virtual void exit(Player&);
private:
	sf::Clock m_clock;
};

#endif