#pragma once
#include <SDL2/SDL.h>

class Vector2i {
public:
	int x, y;
	Vector2i() { x =  y = 0; }
	Vector2i(int p_X = 0 ,int p_Y = 0) : x(p_X) , y (p_Y){}
};

class Sprite
{
public:
	Sprite();
	Sprite(SDL_Renderer* p_Renderer,const char* filePath,Vector2i srcSpritePosition, Vector2i dsntSpritePosition);
	//Sprite(const char* filePath, Vector2i srcPosition, Vector2i dsntPosition);
	~Sprite();
	
	virtual void setSourceImageSize(Vector2i p_SrcImgPos);
	virtual void setSourceImagePosition(Vector2i p_SrcImgSize);

	// setters
	void setRenderer(SDL_Renderer* p_Renderer);
	void setPosition(Vector2i p_Position);
	void setSize(Vector2i p_Size);
	void loadTexture(const char* p_FilePath);
	// getters
	Vector2i getPosition();
	Vector2i getSize();

	//void setOrgin();
	virtual void update(int p_DeltaTime) = 0;
	virtual void render();
protected:
	SDL_Renderer* m_Renderer;
	SDL_Texture* m_SpriteTexture;
	SDL_RendererFlip m_SpriteFlip;
	int m_SpriteAngle;
	SDL_Rect m_SpritedsntRect;
private:
	SDL_Rect m_SpriteSrcRect;
};

