#pragma once
#include <SDL2/SDL.h>

#define SPRITE_SIZE 20

class Vector2i {
public:
	int x, y;
	Vector2i() { x = y = 0; }
	Vector2i(int p_X = 0, int p_Y = 0) : x(p_X), y(p_Y) {}
};

class Sprite
{
protected:
	virtual void  initVariable();
public:
	Sprite() {}
	Sprite(SDL_Renderer* p_Renderer, const char* filePath, Vector2i p_SrcSpritePosition, Vector2i p_SrcSpriteSize);
	Sprite(SDL_Renderer* p_Renderer, const char* filePath, Vector2i p_SrcSpritePosition, Vector2i p_SrcSpriteSize, Vector2i p_DsntSpritePosition);
	//Sprite(const char* filePath, Vector2i srcPosition, Vector2i dsntPosition);
	virtual ~Sprite();

	virtual void setSourceImageSize(Vector2i p_SrcImgPos);
	virtual void setSourceImagePosition(Vector2i p_SrcImgSize);

	// setters
	//void setRenderer(SDL_Renderer* p_Renderer);
	void setDrawPosition(Vector2i p_Position);
	void setDrawSize(Vector2i p_Size);
	void setRotate(int p_Angle);
	void setFlip(SDL_RendererFlip p_Flip);
	void loadTexture(const char* p_FilePath);

	// getters
	Vector2i getDrawPosition();
	Vector2i getDrawSize();
	Vector2i getImgPosition();
	Vector2i getImgSize();
	int getRotate();


	//void setOrgin();
	virtual void update(int p_DeltaTime) = 0;
	virtual void render();
protected:
	SDL_Renderer* m_Renderer;
	SDL_Texture* m_SpriteTexture;
	SDL_RendererFlip m_SpriteFlip;
	int m_SpriteAngle;
	SDL_Rect m_SpriteDsntRect;
private:
	SDL_Rect m_SpriteSrcRect;
};
