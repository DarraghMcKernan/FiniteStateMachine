#include <Events.h>

#include <RunLeftPlayerState.h>

#include <AttackPlayerState.h>
#include <ThrowAttackPlayerState.h>
#include <IdlePlayerState.h>
#include <AccendLadderPlayerState.h>
#include <DecendLadderPlayerState.h>
#include <JumpPlayerState.h>
#include <DiedPlayerState.h>

#include <SlidePlayerStateLeft.h>
#include <SlidePlayerState.h>

PlayerState* RunLeftPlayerState::handleInput(gpp::Events& input)
{
	if (input.getCurrent() == gpp::Events::Event::ATTACK_START_EVENT)
	{
		DEBUG_MSG("RunLeftPlayerState -> AttackPlayerState");
		return new AttackPlayerState();
	}
	if (input.getCurrent() == gpp::Events::Event::THROW_START_EVENT)
	{
		DEBUG_MSG("RunLeftPlayerState -> ThrowAttackPlayerState");
		return new ThrowAttackPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_WALL_EVENT || input.getCurrent() == gpp::Events::Event::RUN_LEFT_STOP_EVENT)
	{
		DEBUG_MSG("RunLeftPlayerState -> IdlePlayerState");
		return new IdlePlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_BOTTOM_EVENT)
	{
		DEBUG_MSG("RunLeftPlayerState -> AccendLadderPlayerState");
		return new AccendLadderPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::HIT_LADDER_TOP_EVENT)
	{
		DEBUG_MSG("RunLeftPlayerState -> DecendLadderPlayerState");
		return new DecendLadderPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::JUMP_UP_EVENT) {
		DEBUG_MSG("IdlePlayerState -> JumpPlayerState");
		return new JumpPlayerState();
	}
	else if (input.getCurrent() == gpp::Events::Event::SLIDE_EVENT_LEFT) {
		DEBUG_MSG("RunLeftPlayerState -> SlidePlayerState");
		return new SlidePlayerStateLeft();
	}
	else if (input.getCurrent() == gpp::Events::Event::DIED_EVENT) {
		DEBUG_MSG("RunLeftPlayerState -> DiedPlayerState");
		return new DiedPlayerState();
	}
	return nullptr;
}
void RunLeftPlayerState::update(Player& player) {
	DEBUG_MSG("RunLeftPlayerState::update");
	DEBUG_MSG(typeid(player).name());
}
void RunLeftPlayerState::enter(Player& player)
{
	DEBUG_MSG("Entering RunLeftPlayerState");
	player.getAnimatedSprite().clearFrames();

	player.getAnimatedSprite().addFrame(sf::IntRect(5712, 1724, 363, 458));//5712
	player.getAnimatedSprite().addFrame(sf::IntRect(5349, 1724, 363, 458));
	player.getAnimatedSprite().addFrame(sf::IntRect(4986, 1724, 363, 458));//4986

	player.getAnimatedSprite().addFrame(sf::IntRect(5712, 2182, 363, 458));//5712  1724+458
	player.getAnimatedSprite().addFrame(sf::IntRect(5349, 2182, 363, 458));
	player.getAnimatedSprite().addFrame(sf::IntRect(4986, 2182, 363, 458));//498

	player.getAnimatedSprite().addFrame(sf::IntRect(5712, 2640, 363, 458));//5712
	player.getAnimatedSprite().addFrame(sf::IntRect(5349, 2640, 363, 458));
	player.getAnimatedSprite().addFrame(sf::IntRect(4986, 2640, 363, 458));

	player.getAnimatedSprite().addFrame(sf::IntRect(5712, 3098, 363, 458));//

	player.getAnimatedSpriteFrame().setTime(seconds(0.05f));
}
void RunLeftPlayerState::exit(Player& player) 
{
	DEBUG_MSG("Exiting RunLeftPlayerState");
	DEBUG_MSG(typeid(player).name());
}