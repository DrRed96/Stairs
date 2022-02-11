#include "Credits.h"

#include "Util/StdUtils.h"

Credits::Credits()
{

}

void Credits::init(Game& p_game, sf::Texture& p_backgroundTexture, sf::Font& p_font)
{
    std::vector<std::string> creditsText = {
        "Credits",
        " ",
        "Developer: Cal (DrRed96)",
        " ",
        "Made with C++ and Python",
        " ",
        "Libraries"
        "- SFML (sfml-dev.org)",
        "- JsonCpp (github.com/open-source-parsers/jsoncpp.git)",
        "- Python C API (python.org)",
        " ",
        "Tools",
        "- Visual Studio Code (code.visualstudio.com)",
        "- MinGW mingw-w64.org)",
        "- GNU Make (gnu.org/software/make)",
        " ",
        "Shout Outs",
        "- Griffpatch",
        "- SplicyX (twitch.tv/splicygaming)",
        " ",
        "Testers",
        "- You"
    };

    m_font = p_font;
    m_creditsText.setFont(m_font);
    m_creditsText.setString(concatStringVector(creditsText, "\n"));
    m_creditsText.setFillColor(sf::Color(255, 255, 255, 255));
    m_creditsText.setStyle(sf::Text::Bold);
    m_creditsText.setOrigin(sf::Vector2f(m_creditsText.getGlobalBounds().width/2, m_creditsText.getGlobalBounds().height/2));    
}

void Credits::update()
{
    
}

void Credits::draw(sf::RenderTarget* p_target) const
{
    p_target->draw(m_creditsText);
}
