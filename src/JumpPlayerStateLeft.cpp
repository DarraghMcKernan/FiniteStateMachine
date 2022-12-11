#include <Events.h>

#include <JumpPlayerStateLeft.h>

#include <DiedPlayerState.h>
#include <JumpAttackPlayerState.h>
#include <JumpThrowAttackPlayerState.h>
#include <GlidePlayerState.h>

#include <IdlePlayerState.h>

PlayerState* JumpPlayerStateLeft::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("JumpPlayerStateLeft -> DiedPlayerState");
		return new DiedPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::ATTACK_START_EVENT)
	{
		DEBUG_MSG("JumpPlayerStateLeft -> JumpAttackPlayerState");
		return new JumpAttackPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::THROW_START_EVENT)
	{
		DEBUG_MSG("JumpPlayerStateLeft -> JumpThrowAttackPlayerState");
		return new JumpThrowAttackPlayerState();
	}
	return nullptr;
}
void JumpPlayerStateLeft::update(Player& player) {
	DEBUG_MSG("JumpPlayerStateLeft::update");
	DEBUG_MSG(typeid(player).name());
	//DEBUG_MSG("JumpPlayerState -> GlidePlayerState");
	if (m_clock.getElapsedTime().asSeconds() > 1.2f) {
		PlayerState* temp = player.getPlayerState();
		PlayerState* state = new IdlePlayerState();
		player.getPlayerState()->exit(player);
		player.setPlayerState(state);
		player.getPlayerState()->enter(player);
		delete temp;
	}
}
void JumpPlayerStateLeft::enter(Player& player)
{
	DEBUG_MSG("Entering JumpPlayerState");
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().setPlayed(false);
	player.getAnimatedSprite().setLooped(false);

	player.getAnimatedSprite().addFrame(sf::IntRect(4624, 3675, 362, 483));//4624
	player.getAnimatedSprite().addFrame(sf::IntRect(4262, 3675, 362, 483));
	player.getAnimatedSprite().addFrame(sf::IntRect(3900, 3675, 362, 483));//3900

	player.getAnimatedSprite().addFrame(sf::IntRect(4624, 4158, 362, 483));//4624
	player.getAnimatedSprite().addFrame(sf::IntRect(4262, 4158, 362, 483));
	player.getAnimatedSprite().addFrame(sf::IntRect(3900, 4158, 362, 483));//3900

	player.getAnimatedSprite().addFrame(sf::IntRect(4624, 4641, 362, 483));//4624
	player.getAnimatedSprite().addFrame(sf::IntRect(4262, 4641, 362, 483));
	player.getAnimatedSprite().addFrame(sf::IntRect(3900, 4641, 362, 483));//3900
    
	player.getAnimatedSprite().addFrame(sf::IntRect(4624, 5124, 362, 483));//4624

	player.getAnimatedSpriteFrame().setTime(seconds(0.03f));
}
void JumpPlayerStateLeft::exit(Player& player)
{
	DEBUG_MSG("Exiting JumpPlayerStateLeft");
	player.getAnimatedSprite().setPlayed(false);
	player.getAnimatedSprite().setLooped(true);
}