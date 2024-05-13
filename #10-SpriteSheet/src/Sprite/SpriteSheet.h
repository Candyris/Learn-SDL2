#pragma once 
#include <Vector>
#include <SDL2/SDL.h>
#include "Sprite.h"
class SpriteSheet : public Sprite {
public:
	SpriteSheet();
	void setSourceImageSize(Vector2i p_SrcImgPos) override;
	void setSourceImagePosition(Vector2i p_SrcImgSize) override;
	void setSpriteSheetDelay(int p_MilliSecond);
	void update(int p_DeltaTime) override;
protected:
	std::vector<SDL_Rect> m_SpriteSheetDsntRect;
  int m_CurrentSpriteIndex; // Index of the current sprite being displayed
    int m_SpriteSheetDelay; // Delay between sprite changes in milliseconds
    int m_TimeSinceLastSpriteChange; // Time elapsed since last sprite change
};
