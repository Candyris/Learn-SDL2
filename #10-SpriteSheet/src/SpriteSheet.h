#pragma once 
#include <Vector>
#include <SDL2/SDL.h>
#include "Sprite.h"
class SpriteSheet : public Sprite {
public:
	SpriteSheet();
	void setSourceImageSize(Vector2i p_SrcImgPos) override;
	void setSourceImagePosition(Vector2i p_SrcImgSize) override;
	void setSpriteSheetDelay(int p_ms);
	void update(int p_DeltaTime) override;
protected:
	std::vector<SDL_Rect> m_SpriteSheetDsntRect;
};
