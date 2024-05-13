#include <SDL2/SDL_image.h>
#include "SpriteSheet.h"
#include <iostream> // For debugging purposes
#include <vector>
#include <SDL2/SDL.h>

SpriteSheet::SpriteSheet(SDL_Renderer* p_Renderer, const char* p_FilePath, Vector2i p_SrcSpritePosition, Vector2i p_SrcSpriteSize, int p_NumRows, int p_NumColumns)
    : Sprite(p_Renderer, p_FilePath, p_SrcSpritePosition, p_SrcSpriteSize), m_CurrentSpriteIndex(0), m_SpriteSheetDelay(100), m_TimeSinceLastSpriteChange(0), m_NumRows(p_NumRows), m_NumColumns(p_NumColumns) {
    // Initialize SpriteSheet with sprites divided equally
    int spriteWidth = p_SrcSpriteSize.x;
    int spriteHeight = p_SrcSpriteSize.y;
    for (int row = 0; row < m_NumRows; ++row) {
        for (int col = 0; col < m_NumColumns; ++col) {
            SDL_Rect rect = { p_SrcSpritePosition.x + (col * spriteWidth), p_SrcSpritePosition.y + (row * spriteHeight), spriteWidth, spriteHeight };
            m_SpriteSheetDsntRect.push_back(rect);
        }
    }
}

void SpriteSheet::setSpriteSheetDelay(int p_MilliSecond) {
    m_SpriteSheetDelay = p_MilliSecond;
}

void SpriteSheet::update(int p_DeltaTime) {
    m_TimeSinceLastSpriteChange += p_DeltaTime;
    if (m_TimeSinceLastSpriteChange >= m_SpriteSheetDelay) {
        // Update current sprite index or change sprite here
        m_CurrentSpriteIndex = (m_CurrentSpriteIndex + 1) % m_SpriteSheetDsntRect.size(); // Move to the next sprite
        m_TimeSinceLastSpriteChange = 0; // Reset the time since last sprite change
    }
}

void SpriteSheet::render() {
    SDL_Rect destRect = { m_SpriteDsntRect.x, m_SpriteDsntRect.y, m_SpriteDsntRect.w, m_SpriteDsntRect.h };
    SDL_RenderCopyEx(m_Renderer, m_SpriteTexture, &m_SpriteSheetDsntRect[m_CurrentSpriteIndex], &destRect, m_SpriteAngle, m_AxisPointRotatoAgainst, m_SpriteFlip);
}
