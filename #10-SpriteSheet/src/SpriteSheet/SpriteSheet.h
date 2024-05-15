#pragma once
#include <Vector>
#include <SDL2/SDL.h>
#include "../Sprite/Sprite.h"

class SpriteSheet : public Sprite
{
public:
    SpriteSheet(SDL_Renderer *p_Renderer, const char *p_FilePath, Vector2i p_SrcSpritePosition, Vector2i p_SrcSpriteSize, int p_NumRows, int p_NumColumns);
    void setSpriteSheetDelay(int p_MilliSecond);
    void update(int p_DeltaTime) override;
    void render() override;

protected:
    std::vector<SDL_Rect> m_SpriteSheetSrcRect;
    int m_CurrentSpriteIndex;        // Index of the current sprite being displayed
    int m_SpriteSheetDelay;          // Delay between sprite changes in milliseconds
    int m_TimeSinceLastSpriteChange; // Time elapsed since last sprite change
    int m_NumRows;                   // Number of rows in the sprite sheet
    int m_NumColumns;                // Number of columns in the sprite sheet
};