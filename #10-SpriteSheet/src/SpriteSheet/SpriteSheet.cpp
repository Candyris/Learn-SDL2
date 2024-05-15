#include <SDL2/SDL_image.h>
#include <SDL2/SDL.h>
#include "SpriteSheet.h"
#include <vector>

SpriteSheet::SpriteSheet(SDL_Renderer *p_Renderer, const char *p_FilePath, Vector2i p_SrcSpritePosition, Vector2i p_SrcSpriteSize, int p_NumRows, int p_NumColumns)
    : Sprite(p_Renderer, p_FilePath, p_SrcSpritePosition, p_SrcSpriteSize), m_CurrentSpriteIndex(0), m_SpriteSheetDelay(100), m_TimeSinceLastSpriteChange(0), m_NumRows(p_NumRows), m_NumColumns(p_NumColumns)
{
    // Initialize SpriteSheet with sprites divided equally
    int _spriteWidth = p_SrcSpriteSize.x;  // assigning the sprite according to the width
    int _spriteHeight = p_SrcSpriteSize.y; //  assigning the sprite according to the height
    for (int row = 0; row < m_NumRows; ++row)
    {
        for (int col = 0; col < m_NumColumns; ++col)
        {
            SDL_Rect rect = {p_SrcSpritePosition.x + (col * _spriteWidth), p_SrcSpritePosition.y + (row * _spriteHeight), _spriteWidth, _spriteHeight};
            m_SpriteSheetSrcRect.push_back(rect);
        }
    }
}

void SpriteSheet::setSpriteSheetDelay(int p_MilliSecond)
{
    m_SpriteSheetDelay = p_MilliSecond; // setting imgage time to load next sprite
}

void SpriteSheet::update(int p_DeltaTime)
{
    m_TimeSinceLastSpriteChange += p_DeltaTime;
    if (m_TimeSinceLastSpriteChange >= m_SpriteSheetDelay)
    {
        // Update current sprite index or change sprite here
        m_CurrentSpriteIndex = (m_CurrentSpriteIndex + 1) % m_SpriteSheetSrcRect.size(); // Move to the next sprite
        m_TimeSinceLastSpriteChange = 0;                                                 // Reset the time since last sprite change
    }
}

void SpriteSheet::render()
{
    SDL_Rect destRect = {m_SpriteDsntRect.x, m_SpriteDsntRect.y, m_SpriteDsntRect.w, m_SpriteDsntRect.h};
    SDL_RenderCopyEx(m_Renderer, m_SpriteTexture, &m_SpriteSheetSrcRect[m_CurrentSpriteIndex], &destRect, m_SpriteAngle, m_AxisPointRotatoAgainst, m_SpriteFlip);
}