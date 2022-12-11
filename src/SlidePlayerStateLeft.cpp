#include <Events.h>

#include <SlidePlayerStateLeft.h>

#include <RunLeftPlayerState.h>
#include <DiedPlayerState.h>
#include <IdlePlayerState.h>

PlayerState* SlidePlayerStateLeft::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::RUN_LEFT_START_EVENT)
	{
		DEBUG_MSG("SlidePlayerStateLeft -> RunLeftPlayerState");
		return new RunLeftPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("SlidePlayerStateLeft -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}
void SlidePlayerStateLeft::update(Player& player) {
	// Switch from SlidePlayerState to IdlePlayerState
	// There is a fixed time at which the slide switched
	// back to IdlePlayerState....as the gameplay programmer
	// you may wish to stop the slide and have an appropriate
	// state and animation at the end of the slide
	// this was added so sliding does not go one indefinitely
	if (m_clock.getElapsedTime().asSeconds() > 2.0f) {
		DEBUG_MSG("SlidePlayerStateLeft -> IdlePlayerState");
		PlayerState* temp = player.getPlayerState();
		PlayerState* state = new IdlePlayerState();
		player.getPlayerState()->exit(player);
		player.setPlayerState(state);
		player.getPlayerState()->enter(player);
		delete temp; // Delete previous
	}
}
void SlidePlayerStateLeft::enter(Player& player)
{
	DEBUG_MSG("Entering SlidePlayerStateLrft");
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame(sf::IntRect(746, 3963, 373, 351));
	player.getAnimatedSprite().addFrame(sf::IntRect(373, 3963, 373, 351));
	player.getAnimatedSprite().addFrame(sf::IntRect(0, 3963, 373, 351));

	player.getAnimatedSprite().addFrame(sf::IntRect(746, 4314, 373, 351));
	player.getAnimatedSprite().addFrame(sf::IntRect(373, 4314, 373, 351));
	player.getAnimatedSprite().addFrame(sf::IntRect(0, 4314, 373, 351));

	player.getAnimatedSprite().addFrame(sf::IntRect(746, 4665, 373, 351));
	player.getAnimatedSprite().addFrame(sf::IntRect(373, 4665, 373, 351));
	player.getAnimatedSprite().addFrame(sf::IntRect(0, 4665, 373, 351));

	player.getAnimatedSprite().addFrame(sf::IntRect(746, 5016, 373, 351));

	player.getAnimatedSpriteFrame().setTime(seconds(0.03f));
}
void SlidePlayerStateLeft::exit(Player& player)
{
	DEBUG_MSG("Exiting SlidePlayerStateLeft");
	DEBUG_MSG(typeid(player).name());
}