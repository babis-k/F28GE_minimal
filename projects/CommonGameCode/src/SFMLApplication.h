#pragma once

#include <string>
#include <optional>

namespace sf
{
	class RenderWindow;
	class Event;
}

namespace cgc
{
	class SFMLApplication
	{
	public:
		void Run(int windowWidth, int windowHeight, const std::string& title);
		virtual ~SFMLApplication() = default;

	private:
		virtual void Init(sf::RenderWindow& renderWindow) {}
		virtual void Update(float deltaTime) {}
		virtual void Render(sf::RenderWindow& renderWindow) {}
		virtual void HandleEvent(const std::optional<sf::Event>&) {}
	};
}